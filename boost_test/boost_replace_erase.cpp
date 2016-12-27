
//********************************************************
//
//       FileName:      boost_replace_erase.cpp
//
//       Author:  huobingli - huobingli@outlook.com
//       Description:    
//       Create: 2016-12-27  13:12:26
//       Last Modified: 2016-12-27 13:12:26
//********************************************************
// 

#include <iostream>
#include <boost/algorithm/string.hpp>

int main() {
	std::string str = "Samus beat the monster.\n";

	std::cout << boost::replace_first_copy(str, "Samus", "samus");

	boost::replace_last(str, "beat", "kill");
	std::cout << str;

	boost::replace_tail(str, 9, "ridley.\n");
	std::cout << str;

	std::cout << boost::ierase_all_copy(str, "samus");
	std::cout << boost::replace_nth_copy(str, "1", 1, "L");
	std::cout << boost::erase_tail_copy(str, 8);
}
