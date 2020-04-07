import React, { useState, useCallback } from 'react';
import Spin from 'antd/es/spin';
import 'antd/es/spin/style/index.css';

interface IProps {
  iframeUrl: string;
  title?: string;
};

const FlinkMonitor: React.FC<IProps> = (props) => {
  const [ loading, setLoading ] = useState<boolean>(true);
  const handleLoaded = useCallback(() => setLoading(false), []);
  return (
    <div className="flink-monitor-grfana-wrappe" >
      <div className="flink-monitor-title" >{props.title || ''} :</div>
      { loading && <Spin size="large" /> }
      <iframe width="100%" style={{ display: loading ? 'none' : 'block' }} src={props.iframeUrl} frameBorder="0" onLoad={handleLoaded} ></iframe>
    </div>
  )
}

export default React.memo(FlinkMonitor);
