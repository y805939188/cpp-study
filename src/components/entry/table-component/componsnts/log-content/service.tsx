import axios from 'axios';
import * as consts from '../../utils/consts';

// 日志查询
const logSearch = (data: { [key: string]: string | number }) => (axios.post(consts.LO_SEARCH, data));

const service = {
  logSearch,
};

export default service;
