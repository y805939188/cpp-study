import React from 'react';
import Badge from 'antd/es/badge';
import 'antd/es/badge/style/index.css';

/** 获取信息类型 */
export function getinfotype(message: string) {
  let type = 'info';
  let lastcname = 'info';
  if (message) {
    if (/info/i.test(message)) {
      type = 'processing';
      lastcname = 'info';
    } else if (/warn/i.test(message)) {
      type = 'warning';
      lastcname = 'warning';
    } else if (/ERROR/i.test(message)) {
      type = 'error';
      lastcname = 'error';
    } else {
      type = 'default';
      lastcname = 'unknow';
    }
  }
  return { lastcname, type };
}

/** 生成格式化的日志显示 */
export function genelateLogHtml(list: any) {
  const losthtml = [];
  if (list && list.length > 0) {
    const len = list.length;
    for (let i = 0; i < len; i += 1) {
      if (list[i].message) {
        const item = list[i];
        losthtml.push(
          <dd key={`logs${i}`} className="other">
            <div className="header">
              <Badge
                count={getinfotype(item.message).lastcname.toLocaleUpperCase()}
              />
              <span className="timestamp">{item.timestamp}</span>
              <span className="getmore">更多</span>
            </div>
            <div
              className="content"
              dangerouslySetInnerHTML={{
                __html: item.message.trim().replace(/(\r\n)|(\n)/g, '<br/>'),
              }}
            />
            <div className="moremessage">{item.source}</div>
          </dd>,
        );
      }
    }
    return losthtml;
  }
  return '';
}
