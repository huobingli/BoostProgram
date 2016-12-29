
//********************************************************
//
//       FileName:      boost_regex_search.cpp
//
//       Author:  huobingli - huobingli@outlook.com
//       Description:    
//       Create: 2016-12-29  20:03:20
//       Last Modified: 2016-12-29 20:03:20
//********************************************************
// 
#include <iostream>
#include <boost/xpressive/xpressive_dynamic.hpp>

int main() {
	using namespace boost::xpressive;
	char* str = "there is a POWER-suit item";
	cregex reg = cregex::compile("(power)-(.{4})", icase);

	//搜索到字符串
	assert(regex_search(str, reg));

	cmatch what;
	//保存搜索结果
	regex_search(str, what, reg);

	//三个表达式
	assert(what.size() == 3);
	std::cout<<what[0] << what[1] << what[2] << std::endl;
	assert(!regex_search("error message", reg));
		
	//regex_search()代替string_algo的contains 、starts_with、ends_with和查找算法
	std::string str1("readme.TXT");

	sregex start_reg = sregex::compile("^re");
	sregex end_reg = sregex::compile("txt$", icase);

	assert(regex_search(str1, start_reg));
	std::cout << regex_search(str1, start_reg) << std::endl;
	assert(regex_search(str1, end_reg));
	std::cout << regex_search(str1, end_reg) << std::endl;
	assert(regex_search(str1, sregex::compile("me"))); //boost书中写错了，sregex写成cregex
	std::cout << regex_search(str1, sregex::compile("me")) << std::endl;
}
