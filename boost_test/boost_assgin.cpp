
//********************************************************
//
//       FileName:      boost_assgin.cpp
//
//       Author:  huobingli - huobingli@outlook.com
//       Description:    
//       Create: 2016-12-27  13:11:13
//       Last Modified: 2016-12-27 13:11:13
//********************************************************
// 

// +=  插入到容器
//

#include <iostream>
#include <string>
#include <boost/assign.hpp>

int main(){
	using namespace boost::assign;
	std::vector<int> v;
	v += 1, 2, 3, 4, 5, 6, 7, 8;
	std::set<std::string> s;
	s += "c++", "java", "node.js", "jsp";

	std::map<int, std::string> m;
	m += std::make_pair(1,"one"), std::make_pair(2, "two");

}


#include <iostream>
#include <string>
#include <boost/assign.hpp>

int main() {
	using namespace boost::assign;
	std::vector<int> v = list_of(1) (1) (1) (1) (1);
	//v = [1,1,1,1,1];
	std::deque<std::string> d = (list_of("power") ("bomb"), "phazon", "suit");
	//d = [power bomb phazon suit]
	std::set<int> s = (list_of(10), 20, 30, 40, 50);
	//s = [10, 20, 30, 40, 50]
	std::map<int, std::string> m = list_of(std::make_pair(1, "one")) (std::make_pair(2, "two"));
	//m = [(1, "one") (2, "two")]

}
