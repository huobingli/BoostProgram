
//********************************************************
//
//       FileName:      boost_deadline_timer.cpp
//
//       Author:  huobingli - huobingli@outlook.com
//       Description:    
//       Create: 2016-12-01  14:04:10
//       Last Modified: 2016-12-01 14:04:10
//********************************************************
// 
#include <iostream>

#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost;
using namespace boost::asio;
using namespace std;
int main() {
	io_service ios;

	deadline_timer t(ios,boost::posix_time::seconds(2));
	cout<<t.expires_at()<<endl;

	//调用wait，线程同步等待
	t.wait();
	t.cancel();
	cout<<"hello asio"<<endl;
}
