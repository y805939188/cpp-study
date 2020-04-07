import axios from 'axios';
import * as consts from './utils/consts';
// import * as data from './fakeData';
// 获取job列表
const getJobList = () => (axios.get(consts.DATAFLOW_JOBS_URL));
// const getJobList = () => {
//   return new Promise((res) => {
//     setTimeout(() => {
//       res(data.fakeData);
//     }, 500);
//   })
// };

// 根据jobid获取job信息
const getJobInfo = (jobId: string, data: any = { test: 'test' }) => (axios.post(`${consts.DATAFLOW_JOBS_URL}/${jobId}`, data));

// 日志查询
const logSearch = (data: { [key: string]: string | number }) => (axios.post(consts.LO_SEARCH, data));

// 删除job
const deleteJob = (jobId: number) => (axios.delete(`${consts.DATAFLOW_JOBS_URL}/${jobId}`));

// 更新job
const updateConfig = (jobId: number, data: any) => (axios.put(`${consts.DATAFLOW_JOBS_URL}/${jobId}`, data))

const service = {
  getJobList,
  logSearch,
  getJobInfo,
  deleteJob,
  updateConfig,
};

export default service;
