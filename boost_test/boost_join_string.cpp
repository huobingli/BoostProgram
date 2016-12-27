
//********************************************************
//
//       FileName:      boost_join_string.cpp
//
//       Author:  huobingli - huobingli@outlook.com
//       Description:    
//       Create: 2016-12-27  13:43:37
//       Last Modified: 2016-12-27 13:43:37
//********************************************************
//

#include <iostream>
#include <boost/assign.hpp>
#include <boost/algorithm/string.hpp>

int main() {
	using namespace boost::assign;

	std::vector<std::string> v = list_of("Samus")("Link")("Zelda")("Mario");
	std::cout << boost::join(v, "+") << std::endl; //合并

	struct is_contains_a {
		bool operator() (const std::string &x) { return boost::contains(x, "a"); }
	};

	std::cout << boost::join_if(v, "**", is_contains_a());//合并
}

