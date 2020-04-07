type MonitorType = { name: string, panelId: number };

// flink 的监控的 grafana 的地址 需要绝对路径
export const FLINK_MONITO_GRAFANA_URL = '/grafana/d-solo/-coPDj9Wz/flink';

// 获取job列表的地址 需要相对路径
export const DATAFLOW_JOBS_URL = './api/dataflowjobs';

// 获取日志 也是绝对路径
export const LO_SEARCH = '/eslog-server/v2/logs/search';

export const MONITOR_TYPE: MonitorType[] = [
  { name: '已注册 task manager 数量', panelId: 69 },
  { name: 'task slot 总数', panelId: 67 },
  { name: 'task slot 可用数量', panelId: 65 },
  { name: '运行中的 job 数量', panelId: 71 },
  { name: 'live thread', panelId: 42 },
  { name: 'JobManager Memory Available', panelId: 5 },
  { name: 'JobManager CPU USE', panelId: 48 },
];

export const CHILDREN_COLUMNS: string[] = ['flinkJob', 'sidecarJob'];
export const CHILDREN_COLUMNS_FILTER: string[] = ['flinkJob', 'sidecarJob', 'logMeta', 'graphs', 'rootException'];
