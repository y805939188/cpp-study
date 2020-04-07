import React, { Suspense } from 'react';
import { ColumnsType } from 'antd/es/table';
import Table from 'antd/es/table';
import Collapse from 'antd/es/collapse';;
import Button from 'antd/es/button';
import Modal from 'antd/es/modal';
import Card from 'antd/es/card';
import Descriptions from 'antd/es/descriptions';
import Spin from 'antd/es/spin';
import ReactJson from 'react-json-view';
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
import './index.less';

type ChidlrenListType = { name: string, data: any };
type ExpandHandlersType = { [key: string]: (name: string, data: any, index: number, render?: CustomRenderType[]) => React.ReactElement | null };

const columnsFilter = (key: string, value: any): boolean => {
  return !consts.CHILDREN_COLUMNS_FILTER.includes(key);
}

const handleFlinkMonitor = (name: string, panelId: number, workspaceId: number) => {
  const iframeUrl = getGrafanaUrl(panelId, workspaceId);
  Modal.success({
    icon: null,
    className: 'custom-modal-1',
    maskClosable: true,
    content: (
      <Suspense fallback={<Spin size="large" />} >
        <FlinkMonitorGrafana  iframeUrl={iframeUrl} />
      </Suspense>
    ),
  })
};

const getFlinkMonitor = ((monitorTypeList) => (data: any) => {
  const config = stringToJSON(data.config, false) || {};
  const workspaceId = config.workspaceId;
  return monitorTypeList.map(({ name, panelId }, index) => (
    <Descriptions.Item key={`${name}_${index}`} label={name} >
      <a onClick={handleFlinkMonitor.bind(null, name, panelId, workspaceId)} >查看</a>
    </Descriptions.Item>
  ));
})(consts.MONITOR_TYPE);

const expandLog = ({ expanded, onExpand, record }: any) => (<a onClick={e => onExpand(record, e)} >展开日志</a>);
const childrenExpandOptions = {
  expandIcon: expandLog,
  expandIconColumnIndex: 0,
  expandedRowRender: (record: any, index: number, indent: number, expanded: boolean) => {
    if (!expanded) return null;    
    return (<LogCentent params={record.logMeta} />);
  },
};

const expandHandlers: ExpandHandlersType = {
  flinkJobHandler: ((columnsCache: ColumnsType<any> | null) => (name: string, data: any, index: number, render?: CustomRenderType[]) => {
    if (!data) return null;
    const currentData = Array.isArray(data) ? data[0] : data;
    const columns = columnsCache || (columnsCache = (render ? getColumns(currentData, columnsFilter, render) : getColumns(currentData)));
    const dataSource = getCurrentData(data);
    return (
      <Collapse.Panel className={`child-expand child-expand-${name}`} header={name} key={`${name}_${index}`} >
        <div className="flink-job-desc" >
          <Descriptions title="监控" >
            {getFlinkMonitor(dataSource[0])}
          </Descriptions>
        </div>
        <Table expandable={childrenExpandOptions} columns={columns} dataSource={dataSource} pagination={false} />
      </Collapse.Panel>
    );
  })(null),
  sidecarJobHandler: ((columnsCache: ColumnsType<any> | null) => (name: string, data: any, index: number, render?: CustomRenderType[]) => {
    if (!data) return null;
    const currentData = Array.isArray(data) ? data[0] : data;
    const columns = columnsCache || (columnsCache = (render ? getColumns(currentData, columnsFilter, render) : getColumns(currentData)));
    const dataSource = getCurrentData(data);
    return (
      <Collapse.Panel className={`child-expand child-expand-${name}`} header={name} key={`${name}_${index}`}>
        <Table expandable={childrenExpandOptions} columns={columns} dataSource={dataSource} pagination={false} />
      </Collapse.Panel>
    );
  })(null),
};

const getChildrenElements = (
  childrenList: ChidlrenListType[],
  customRender?: CustomRenderType[],
) => {
  return childrenList.map(({ name, data }, index) => {
    const handler = expandHandlers[`${name}Handler`];
    return handler && (customRender ? handler(name, data, index, customRender) : handler(name, data, index));
  });
};

const handleModal = (key: string, json: object) => {
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

// 这里的typescript有问题 因为handleJSON是经过bind的 所以参数其实对不上
const handleJSON: RenderType = (key, content) => {
  const json = stringToJSON(content);
  return (<Button onClick={handleModal.bind(null, key, json)} >查看</Button>);
};

const handleTraceUrl: RenderType = (key, content) => {
  return ( <a href={content} target="__black" >查看链接</a> );
}

const handleTest = (id: string) => async () => {
  const res = await service.getJobInfo(id);
  console.log(666666, res);
}

const customRenderChildren = [
  [(key, value) => !(typeof stringToJSON(value) === 'string'), handleJSON],
  [key => key === 'trackingUrl', handleTraceUrl],
] as CustomRenderType[];

const expandedRowRender = (childTableList: string[]) => (record: any) => {
  if (!childTableList.length) return null;
  return (
    <Collapse>
      {
        getChildrenElements(
          childTableList.map(str => ({ name: str, data: record[str] })).filter(item => !!item),
          customRenderChildren
        )
      }
    </Collapse>
  );

};

const expandOptions = {
  // expandRowByClick: true,
  expandedRowRender: expandedRowRender(consts.CHILDREN_COLUMNS),
};

const handleActions = (key: string, content: any, record: any) => {
  /**
   * TODO: 这里应该通过接口获取一些数据
   * 目前接口有些问题 日后在搞
   */
  // const { id } = record as any;
  return (
    // <a onClick={handleTest(id)} >操作</a>
    <a onClick={() => window.location.reload()} >刷新</a>
  )
};

const handleJobActions = [[(key: string) => key === 'actions', handleActions]] as CustomRenderType[];

const resource = fetchData(service.getJobList, res => res.err ? null : res);
const Home: React.FC<any> = ((columnsCache: ColumnsType<any> | null) => () => {
  const { data: { data: res } = { data: null } } = resource.read(true) || [];
  if (!res) return null;
  const { items = [], info = {} } = res;
  const columns = columnsCache || (columnsCache = (getColumns({...items[0], actions: 'actions'}, columnsFilter, handleJobActions)));
  const data = getCurrentData(items);

  return (
    <div className="home-page-wrapper" >
      <Table columns={columns} expandable={expandOptions} dataSource={data} pagination={false} />
    </div>
  )
})(null);

export default React.memo(Home);
