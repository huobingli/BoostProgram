
//********************************************************
//
//       FileName:      boost_regex.cpp
//
//       Author:  huobingli - huobingli@outlook.com
//       Description:    
//       Create: 2016-12-29  20:01:41
//       Last Modified: 2016-12-29 20:01:41
//********************************************************

#include <iostream>
#include <boost/xpressive/xpressive_dynamic.hpp>
int main() {
	using namespace boost::xpressive;

	//icase标志 表示在匹配字符串时忽略大小写
	cregex reg = cregex::compile(
		R"---(\d{6}(1|2)\d{3}(0|1)\d[0-3]\d\d{3}(X|\d))---", icase);
	assert(regex_match("999555197001019999", reg));
	std::cout << regex_match("999555197001019999", reg) << std::endl;
	assert(regex_match("99955519700101999X", reg));
	assert(regex_match("99955520100101999x", reg));
	
	assert(!regex_match("99955520100101999Z", reg));
	assert(!regex_match("99955530100101999X", reg));
	assert(!regex_match("999555201099019998", reg));
	assert(!regex_match("999555201012419991", reg));
	
	//比较增加子表达式  每个括号也是一个子表达式
	//((1|2)\\d{3})
	//((0|1)\\d)
	//([0-3]\\d)
	//(\\d{3}(X|\\d))
	cregex reg1 = cregex::compile(
		"\\d{6}((1|2)\\d{3})((0|1)\\d)([0-3]\\d)(\\d{3}(X|\\d))",icase);
	cmatch what;
	assert(regex_match("999555197001019999", what, reg1));
	for (auto x : what)
	{
		std::cout << "[" << x << "]";
	}
	std::cout << std::endl;
	std::cout << "date:" << what[1] << what[3] << what[5] << std::endl;


	std::string str("readme.txt");
	sregex start_reg = sregex::compile("^re.*");
	sregex end_reg = sregex::compile(".*txt$");
	assert(regex_match(str, start_reg));
	assert(regex_match(str, end_reg));

}
