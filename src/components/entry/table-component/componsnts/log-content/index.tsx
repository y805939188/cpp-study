import React, { useCallback, useEffect, useRef } from 'react';
import Pagination from 'antd/es/pagination';
import Spin from 'antd/es/spin';
import service from './service';
import { useSetState } from 'common/utils/react-use';
import { genelateLogHtml } from './assist';
import 'antd/es/spin/style/index.css';
import 'antd/es/pagination/style/index.css';
import './index.less';

interface IProps {
  params: any;
}

interface IState {
  logoList: any[];
  total: number;
  page: number;
  loading: boolean;
}

const LogCentent: React.FC<IProps> = (props: IProps) => {
  const [state, setState] = useSetState<IState>({ loading: true, page: 1, total: 0, logoList: [] });
  const { params } = props;
  const { page, loading, total, logoList } = state;
  const prevParamsRef = useRef<any>(params);
  const handlePageChange = useCallback((page: number) => setState({ page }), []);
  useEffect(() => {
    const isNewParams = prevParamsRef.current !== params;
    if (isNewParams) prevParamsRef.current = params;
    if (params) {
      setState({ loading: true });
      (async () => {
        const res = await service.logSearch({...params, size: 100, form: (page - 1) * 100});
        if (res && res.data) {
          const data = res.data;
          const list = data.data;
          const total = data.total;
          setState({
            loading: false,
            logoList: list,
            total: total > 10000 ? 10000 : total,
            page: isNewParams ? 0 : page,
          });
        }
      })();
    }
  }, [params, page]);

  const handleMoreClick = useCallback((event: any) => {
    const currenttarget = event.target;
    if (
      currenttarget.tagName === 'SPAN' &&
      currenttarget.className === 'getmore'
    ) {
      const nextnode = currenttarget.parentNode.nextSibling.nextSibling;
      const heihgt = nextnode.scrollHeight;
      if (heihgt === 0) {
        nextnode.style.display = 'block';
        currenttarget.innerHTML = '隐藏';
      } else {
        nextnode.style.display = 'none';
        currenttarget.innerHTML = '更多';
      }
    }
  }, []);

  return (
    <div className="pd-monitor-center-log-center-content-wrapper">
      <div className="content-logo-wrapper">
        <div className="content-logo">
          {loading ? (<span className="content-logo-loading"><Spin tip='正在加载中...' /></span>)
            : !logoList.length ? (<span>没有日志</span>) : (
              <div className="content-logo-list-wrapper" onClick={handleMoreClick} >
                <div className="content-logo-list">
                  <dl>{genelateLogHtml(logoList)}</dl>
                </div>
              </div>
            )
          }
        </div>
      </div>
      {total >= 100 && !loading && (
        <Pagination
          showSizeChanger={false}
          onChange={handlePageChange}
          total={total}
          pageSize={100}
          current={page}
        />
      )}
    </div>
  );
};

export default React.memo(LogCentent);
