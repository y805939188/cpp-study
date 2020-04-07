import React, { useEffect, createRef } from 'react';

interface CustomRef<T> {
  current: T | null;
}

const grfanaRootRef = createRef<HTMLDivElement>();
interface IProps {
  iframeUrl: string;
};

const createIframe = (iframeUrl: string, oIframeRef: CustomRef<HTMLDivElement>) => {
  throw new Promise((res, rej) => {
    const oIframe = document.createElement('iframe');
    oIframe.src = iframeUrl;
    oIframe.width = "100%";
    oIframe.height = "100%";
    oIframe.frameBorder = "0";
    oIframe.style.display = 'none';
    oIframe.onload = () => {
      console.log('iframe加载成功');
      res();
    };
    oIframe.onerror = () => {
      console.warn('iframe加载失败');
      rej();
    }
    document.body.appendChild(oIframe);
    oIframeRef.current = oIframe;
  });
};

const FlinkMonitor: React.FC<IProps> = ((oIframeRef: CustomRef<HTMLDivElement>) => (props: IProps) => {
  const currentIframe = oIframeRef.current;
  if (!currentIframe) createIframe(props.iframeUrl, oIframeRef);
  useEffect(() => {
    grfanaRootRef.current?.appendChild(currentIframe as HTMLDivElement);
    (currentIframe?.style as ElementCSSInlineStyle['style']).display = 'block';
    return () => {
      console.log('卸载iframe')
      oIframeRef.current = null;
    };
  }, []);
  return (
    <div className="flink-monitor-grfana-wrapper">
      <div ref={grfanaRootRef} className="grfana-mount-root"></div>
    </div>
  )
})({ current: null });

export default React.memo(FlinkMonitor);
