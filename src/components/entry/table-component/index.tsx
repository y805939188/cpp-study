import React from 'react';
import Table, { TableProps, ColumnsType } from 'antd/es/table';
import Collapse from 'antd/es/collapse';;
import Button from 'antd/es/button';
import Modal from 'antd/es/modal';
import Card from 'antd/es/card';
import Drawer from 'antd/es/drawer';
import Descriptions from 'antd/es/descriptions';
import message from 'antd/es/message';
import ReactJson, { InteractionProps } from 'react-json-view';
import LogCentent from './componsnts/log-content';
import fetchData from 'common/utils/react-cache-custom';
import service from './service';
import FlinkMonitorGrafana from './componsnts/flink-iframe/index'; 
import { stringToJSON, getCurrentData, getColumns, RenderType, CustomRenderType, getGrafanaUrl } from './utils';
import * as consts from './utils/consts';
import 'antd/es/table/style/index.css';
import 'antd/es/collapse/style/index.css';
import 'antd/es/button/style/index.css';
import 'antd/es/modal/style/index.css';
import 'antd/es/card/style/index.css';
import 'antd/es/descriptions/style/index.css';
import 'antd/es/spin/style/index.css';
import 'antd/es/drawer/style/index.css';
import 'antd/es/message/style/index.css';
import './index.less';

type ChidlrenListType = { name: string, data: any };
type ExpandHandlersType = { [key: string]: (name: string, data: any, index: number, render?: CustomRenderType[]) => React.ReactElement | null };
interface IState {
  visible: boolean;
  jobList: any[];
}

interface IProps {
  initData: any;
}

const resource = fetchData(service.getJobList, res => res.err ? null : res);
const Home: React.FC<any> = () => {
  const { data: { data: res } = { data: null } } = resource.read(true) || [];
  if (!res) return null;
  return <HomeWrapper initData={res} />
};

class HomeWrapper extends React.PureComponent<IProps, IState> {
  private parentColumns: ColumnsType<any>;
  private workspaceId: number;
  private graphs: { title: string, url: string }[];
  private expandOptions: TableProps<any>['expandable'];
  private expandHandlers: ExpandHandlersType = {};
  private childrenExpandOptions: TableProps<any>['expandable'];
  private customRenderChildren: CustomRenderType[];
  private handleJobActions: CustomRenderType[];
  private flinkSqlConfig: string;

  constructor(props: IProps) {
    super(props);
    const { items = [], info = {} } = props.initData;
    const initList = getCurrentData(items);
    this.flinkSqlConfig = '';
    this.expandOptions = {};
    this.childrenExpandOptions = {};
    this.expandOptions['expandedRowRender'] = this.expandedRowRender(consts.CHILDREN_COLUMNS);
    this.childrenExpandOptions['expandIcon'] = this.expandLog;
    this.childrenExpandOptions['expandedRowRender'] = this.showLogContent;
    this.expandHandlers['flinkJobHandler'] = this.flinkJobHandler;
    this.expandHandlers['sidecarJobHandler'] = this.sidecarJobHandler;
    this.workspaceId = info.workspaceId;
    this.graphs = info.graphs;

    /**
     * getColumns是根据sourcedata中的第一个data字典的key 处理成一个 columns 格式的字典
     * 然后getColumns的第二个参数用来过滤data中不需要展示的title
     * 第三个参数表示需要对哪些column分别做处理
     * 比如有个column的key是ding 那第三个参数可以传个二维数组 [ [ key => key === 'ding' ], () => (null) ]
     * 这样当最后展示的效果就是 ding 这列下面都是 null
     */
    // 这里的this.handleActions是bind过的函数 他的typescript我不会写......求教
    this.handleJobActions = [[(key: string) => key === 'actions', (this.handleActions as any)]];
    this.customRenderChildren = [
      [(key, value) => !(typeof stringToJSON(value) === 'string'), this.handleJSON],
      [key => (key === 'trackingUrl' || key === 'monitorUrl'), this.handleTraceUrl],
    ] 
    this.parentColumns = getColumns({...items[0], actions: 'actions'}, this.columnsFilter, this.handleJobActions);
    
    this.state = { visible: false, jobList: initList };
  }

  handleModal = (key: string, json: object) => {
    Modal.success({
      icon: null,
      className: 'custom-modal-2',
      maskClosable: true,
      content: (
        <Card title={key} bordered={false} >
          <ReactJson
            collapsed={2}
            src={json}
            iconStyle="circle"
            onEdit={false}
            enableClipboard={false}
            displayDataTypes={false}
            indentWidth={2}
          />
        </Card>
      ),
    })
  }

  handleTraceUrl: RenderType = (key, content) => ( <a href={content} target="__black" >查看链接</a>);

  // 这里的typescript有问题 因为handleJSON是经过bind的 所以参数其实对不上
  handleJSON: RenderType = (key, content) => (<Button onClick={this.handleModal.bind(null, key, stringToJSON(content))} >查看</Button>);

  handleJobUpdate = (record: any) => () => {
    const flinkSql = record?.config?.flinkSql;
    const id = record?.id;
    const json = stringToJSON(flinkSql);
    const prevConfig = this.flinkSqlConfig = flinkSql;
    Modal.confirm({
      icon: null,
      className: 'custom-modal-2',
      maskClosable: true,
      cancelText: '取消',
      okText: '更新',
      onOk: async () => {
        const flinkSqlConfig = this.flinkSqlConfig;
        if (flinkSqlConfig !== prevConfig && id) {
          const res = await service.updateConfig(id, {'flinkSql': flinkSqlConfig});
          message.success('成更新成功, 即将刷新页面', 2, () => window.location.reload());
        } else {
          return Promise.resolve();
        }
      },
      content: (
        <Card title='更新job' bordered={false} >
          <ReactJson
            collapsed={2}
            src={json}
            iconStyle="circle"
            onEdit={this.handleFlinkSqlEdit}
            enableClipboard={false}
            displayDataTypes={false}
            indentWidth={2}
          />
        </Card>
      ),
    })
  }

  handleDeleteJob = (record: any, index: number) => async () => {
    const temporaryJobList = [...this.state.jobList];
    const res = await service.deleteJob(record.id);
    if (res) temporaryJobList.splice(index, 1) && this.setState({ jobList: temporaryJobList });
  }

  handleFlinkSqlEdit = (edit: InteractionProps) => {
    const updatedSqlInfo = edit['updated_src'];
    const flinkSqlConfig = this.flinkSqlConfig;
    const updatedSqlStr = JSON.stringify(updatedSqlInfo);
    if (flinkSqlConfig !== updatedSqlStr) this.flinkSqlConfig = updatedSqlStr;
  }

  columnsFilter = (key: string, value: any): boolean => !consts.CHILDREN_COLUMNS_FILTER.includes(key);

  handleActions = (key: string, content: any, record: any, index: number) => {
    return (
      <>
        <a onClick={this.handleJobUpdate(record)} >更新</a>
        &nbsp;&nbsp;
        <a onClick={this.handleDeleteJob(record, index)} >删除</a>
      </>
    )
  }

  showLogContent = (record: any, index: number, indent: number, expanded: boolean) => {
    if (!expanded) return null; // 只有展开的时候才加载LogCentent
    return (<LogCentent params={record.logMeta} />);
  }

  getIframe = (graphs: {title: string, url: string}[], workspaceId: number) => {
    return graphs.map(({ title, url }: any, index: number) => (
      <div className="custom-iframe-wrapper" key={`${index}_${title}`} >
        <FlinkMonitorGrafana title={title} iframeUrl={`${url}&workspaceId=${workspaceId}`} />
      </div>
    ))
  }

  // 自定义展开按钮的icon
  expandLog = ({ expanded, onExpand, record }: any) => (<a onClick={e => onExpand(record, e)} >展开日志</a>);

  handleFlinkMonitor = (title: string, url: string) => {
    Modal.success({
      icon: null,
      className: 'custom-modal-1',
      maskClosable: true,
      content: (<FlinkMonitorGrafana title={title} iframeUrl={`${url}&workspaceId=${this.workspaceId}`} />),
    });
  };

  getFlinkMonitor = (data: any) => {
    const { graphs = [] } = data;
    return graphs.map(({ title, url }: { title: string, url: string }, index: number) => (
      <Descriptions.Item key={`${title}_${index}`} label={title} >
        <a onClick={this.handleFlinkMonitor.bind(this, title, url)} >查看</a>
      </Descriptions.Item>
    ));
  };

  flinkJobHandler = (name: string, data: any, index: number, render?: CustomRenderType[]) => {
    if (!data) return null;
    const currentData = Array.isArray(data) ? data[0] : data;
    const columns = render ? getColumns(currentData, this.columnsFilter, render) : getColumns(currentData);
    const dataSource = getCurrentData(data);
    return (
      <Collapse.Panel className={`child-expand child-expand-${name}`} header={name} key={`${name}_${index}`} >
        <Table expandable={this.childrenExpandOptions} columns={columns} dataSource={dataSource} pagination={false} />
      </Collapse.Panel>
    );
  };

  sidecarJobHandler = (name: string, data: any, index: number, render?: CustomRenderType[]) => {
    if (!data) return null;
    const currentData = Array.isArray(data) ? data[0] : data;
    const columns = render ? getColumns(currentData, this.columnsFilter, render) : getColumns(currentData);
    const dataSource = getCurrentData(data);
    return (
      <Collapse.Panel className={`child-expand child-expand-${name}`} header={name} key={`${name}_${index}`}>
        <Descriptions title="监控" >
          {this.getFlinkMonitor(dataSource[0])}
        </Descriptions>
        <Table expandable={this.childrenExpandOptions} columns={columns} dataSource={dataSource} pagination={false} />
      </Collapse.Panel>
    );
  };

  getChildrenElements = (childrenList: ChidlrenListType[], customRender?: CustomRenderType[]) => {
    return childrenList.map(({ name, data }, index) => {
      const handler = this.expandHandlers[`${name}Handler`];
      return handler && (customRender ? handler(name, data, index, customRender) : handler(name, data, index));
    });
  };

  expandedRowRender = (childTableList: string[]) => (record: any) => {
    if (!childTableList.length) return null;
    const ChildrenElements = this.getChildrenElements(
      childTableList
        .map(str => ({ name: str, data: record[str] }))
        .filter(item => !!item),
      this.customRenderChildren,
    );
    return (<Collapse>{ChildrenElements}</Collapse>);
  }

  handleVisible = () => this.setState({ visible: !this.state.visible });

  handleClose = () => this.setState({ visible: false });

  handleClassName = (
    jobStatus: string,
    flinkJobStatus: string,
    sidecarJobStatus: string,
    flinkJobException: string | null,
    sidecarJobException: string | null,
  ) => {
    if (
      (sidecarJobStatus === 'Online' || flinkJobStatus === 'Online')
      && (flinkJobStatus === 'RUNNING' || sidecarJobStatus === 'RUNNING')
      && !flinkJobException
      && !sidecarJobException
    ) return 'succeed';
    else if (
      (sidecarJobStatus !== 'Online' && sidecarJobStatus !== 'RUNNING')
      || (flinkJobStatus !== 'Online' && flinkJobStatus !== 'RUNNING')
    ) return 'error';
    else if (
      (sidecarJobStatus === 'Online' || flinkJobStatus === 'Online')
      && (flinkJobStatus === 'RUNNING' || sidecarJobStatus === 'RUNNING')
      && (flinkJobException || sidecarJobException)
    ) return 'warn';
    else return 'error';
  }

  handleRowBackground = (record: any, index: number) => {
    const { flinkJob = {}, sidecarJob = {}, status: jobStatus } = record;
    const { rootException: flinkJobException, status: flinkJobStatus } = flinkJob;
    const { rootException: sidecarJobException, status: sidecarJobStatus } = sidecarJob;
    return `custom-parent-row-${this.handleClassName(jobStatus, flinkJobStatus, sidecarJobStatus, flinkJobException, sidecarJobException)}`;
  }

  render() {
    const { visible, jobList } = this.state;
    return (
      <div className="home-page-wrapper" >
        {
          this.graphs && this.workspaceId && (
            <>
              <Button className="custom-btn" onClick={this.handleVisible}>Grafana Info</Button>
              <Drawer
                width={'40%'}
                title="Grafana"
                placement="right"
                closable={false}
                onClose={this.handleClose}
                visible={visible}
              >{this.getIframe(this.graphs, this.workspaceId)}</Drawer>
            </>
          )
        }
        <Table
          columns={this.parentColumns}
          expandable={this.expandOptions}
          rowClassName={this.handleRowBackground}
          dataSource={jobList}
          pagination={false}
        />
      </div>
    )
  }
}

export default React.memo(Home);
