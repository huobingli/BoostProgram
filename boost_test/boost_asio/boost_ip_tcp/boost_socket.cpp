
//********************************************************
//
//       FileName:      boost_socket.cpp
//
//       Author:  huobingli - huobingli@outlook.com
//       Description:    
//       Create: 2016-12-01  15:22:29
//       Last Modified: 2016-12-01 15:22:29
//********************************************************
// 
#include <iostream>


#include <boost/asio.hpp>


int main() {
	try{
		std::cout << "server start." << std::endl;

		boost::asio::io_service ios;
		boost::asio::ip::tcp::acceptor acceptor(ios, 
			boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 6688));

		std::cout << acceptor.local_endpoint().address() << std::endl;

		while (true) {
			boost::asio::ip::tcp::socket sock(ios);
			acceptor.accept(sock);
			std::cout << "client: ";
			std::cout << sock.remote_endpoint().address() << std::endl;

			sock.write_some(boost::asio::buffer("hello asio"));
		}
	}

	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
