import axios from 'axios';
import * as consts from './utils/consts';

// 获取job列表
const getJobList = () => (axios.get(consts.DATAFLOW_JOBS_URL));

// 根据jobid获取job信息
const getJobInfo = (jobId: string, data: any = { test: 'test' }) => (axios.post(`${consts.DATAFLOW_JOBS_URL}/${jobId}`, data));

// 日志查询
const logSearch = (data: { [key: string]: string | number }) => (axios.post(consts.LO_SEARCH, data));

const service = {
  getJobList,
  logSearch,
  getJobInfo,
};

export default service;
