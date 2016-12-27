
//********************************************************
//
//       FileName:      boost_format_string_algo.cpp
//
//       Author:  huobingli - huobingli@outlook.com
//       Description:    
//       Create: 2016-12-27  13:12:01
//       Last Modified: 2016-12-27 13:12:01
//********************************************************
// 

#include <iostream>
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>

int main() {
	boost::format fmt("|%s|.pos = %d\n");

	std::string str = "Long long ago, there was a king.";
	//迭代器区间
	boost::iterator_range<std::string::iterator> rge;

	//找第一次出现
	rge = boost::find_first(str, "long");
	std::cout << fmt % rge % (rge.begin() - str.begin());

	//大小写无关找第一次出现
	rge = boost::ifind_first(str, "long");
	std::cout << fmt % rge % (rge.begin() - str.begin());

	//找第三次出现
	rge = boost::find_nth(str, "ng", 2);
	std::cout << fmt % rge % (rge.begin() - str.begin());

	//取出前四个字符
	rge = boost::find_head(str, 4);
	std::cout << fmt % rge % (rge.begin() - str.begin());

	//取末尾5个字符
	rge = boost::find_tail(str, 5);
	std::cout << fmt % rge % (rge.begin() - str.begin());

	//找第一次
	rge = boost::find_first(str, "samus");
	assert(rge.empty() && !rge);
}
