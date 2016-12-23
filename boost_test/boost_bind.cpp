
//********************************************************
//
//       FileName:      boost_bind.cpp
//
//       Author:  huobingli - huobingli@outlook.com
//       Description:    
//       Create: 2016-12-05  11:04:44
//       Last Modified: 2016-12-05 11:04:44
//********************************************************
// 
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/function.hpp>

void print(int i) {
	std::cout<<"print"<<i <<std::endl;
}

int main() {
	boost::function0<void> fobj;
	fobj=boost::bind(&print, 5);
	fobj();
	return 0;
}
