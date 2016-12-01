
//********************************************************
//
//       FileName:      boost_deadline_asynctimer.cpp
//
//       Author:  huobingli - huobingli@outlook.com
//       Description:    
//       Create: 2016-12-01  15:01:43
//       Last Modified: 2016-12-01 15:01:43
//********************************************************
// 
#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
//using namespace boost;
//using namespace boost::asio;

//const asio::error_code &int;

void print(const boost::system::error_code& e) {
	cout<<"hello asio"<<endl;
}

int main() {
	boost::asio::io_service ios;
	boost::asio::deadline_timer t(ios, boost::posix_time::seconds(2));
	
	t.async_wait(print);

	cout<<"it show before t expired."<<endl;

	ios.run();
	return 0;
}
