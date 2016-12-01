
//********************************************************
//
//       FileName:      boost_client.cpp
//
//       Author:  huobingli - huobingli@outlook.com
//       Description:    
//       Create: 2016-12-01  16:11:51
//       Last Modified: 2016-12-01 16:11:51
//********************************************************
// 
#include <iostream>

#include <boost/asio.hpp>
#include <vector>

void client(boost::asio::io_service &ios) {

	try{
		std::cout << "client  start ." << std::endl;
		boost::asio::ip::tcp::socket sock(ios);
		boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string("127.0.0.1"), 6688);
		sock.connect(ep);

		std::vector<char>  str(100, 0);
		sock.read_some(boost::asio::buffer(str));
		std::cout << "recive from " << sock.remote_endpoint().address();
		std::cout << &str[0] << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {

	boost::asio::io_service ios;
	a_timer at(ios, 5, bind(client, ref(ios)));
	ios.run();
}
