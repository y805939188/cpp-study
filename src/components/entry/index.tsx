import React, { Suspense } from 'react';
import Spin from 'antd/es/spin';
import TableComponent from './table-component';
import 'antd/es/spin/style/index.css';
import './index.less';

const Loading = (<div className="custom-loading-icon"><Spin size="large" /></div>);
const Home: React.FC<any> = () => {
  return (
    <div className="home-page-wrapper" >
      <Suspense fallback={Loading}>
        <TableComponent />
      </Suspense>
    </div>
  )
}

export default React.memo(Home);
