import * as consts from './consts';
import { ColumnType, ColumnsType } from 'antd/es/table';


export type RenderType = ColumnType<any>['render'];
export type CustomRenderType = [boolean | ((key: string, value: any) => boolean), RenderType];

export const getGrafanaUrl = (panelId: number, workspaceId: number) => (`${consts.FLINK_MONITO_GRAFANA_URL}?panelId=${panelId}&theme=light&orgId=1&var-datasource=prometheus&var-wsid=${workspaceId}`);

export const stringToJSON = (str: any, recursive: boolean = false) => {
  if (!str) return {};
  if (typeof str === 'string') {
    const currentStr = str.trim();
    if (currentStr[0] !== '{' && currentStr[0] !== '[') return str;
    try {
      const json = JSON.parse(str);
      recursive && Object.entries(json).forEach(([ key, value ]) => {
        json[key] = stringToJSON(value, recursive);
      });
      return json;
    } catch (err) {
      return str;
    }
  } else if (typeof str === 'object') {
    return str;
  };
};

/**
* cr: 为二维数组 第一位表示条件 第二位是当第一位返回true的时候要把第二位当成render
*/
export const getColumns =(
  obj: object,
  exclude: ((key: string, value: any) => boolean) | null | undefined = () => true,
  cr?: CustomRenderType[],
): ColumnsType<any> => {
 const tempList = Object.entries(obj);
  if (!tempList.length) return [];
  return ( tempList.map(([key, value], index) => {
    const render = (cr && cr.find(([ondition]) => (typeof ondition === 'function' ? ondition(key, value) : ondition)) || [])[1];
    const column: { [prop: string]: any } = { title: key, dataIndex: key, key: `${key}_${index}` };
    render && (column.render = render.bind(null, key));
    return (exclude && !exclude(key, value)) ? null : column;
  }).filter(item => item)) as ColumnsType<any>;
};

export const getCurrentData = (res: any[]) => {
  if (!res || (Array.isArray(res) && !res.length)) return [];
  if (!(res instanceof Array) && typeof res === 'object') (res = [res]);
  return res.map((item, index) => ({ ...item, key: `${item.id || item.taskId}_${index}` }));
};
