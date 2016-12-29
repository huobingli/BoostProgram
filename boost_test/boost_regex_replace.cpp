
//********************************************************
//
//       FileName:      boost_regex_replace.cpp
//
//       Author:  huobingli - huobingli@outlook.com
//       Description:    
//       Create: 2016-12-29  20:02:59
//       Last Modified: 2016-12-29 20:02:59
//********************************************************
// 
#include <iostream>
#include <boost/xpressive/xpressive_dynamic.hpp>
int main(){
	using namespace boost::xpressive;

	std::string str("readme.txt");
	sregex reg1 = sregex::compile("(.*)(me)");
	sregex reg2 = sregex::compile("(t)(.)(t)");
	std::cout << regex_replace(str, reg1, "$2manual") << std::endl;
	std::cout << str << std::endl;
	std::cout << regex_replace(str, reg1, "$1you") << std::endl;
	std::cout << str << std::endl;
	std::cout << regex_replace(str, reg1, "$&$&") << std::endl;
	std::cout << str << std::endl;
	std::cout << regex_replace(str, reg2, "$1N$3") << std::endl;
	std::cout << str << std::endl;
	str = regex_replace(str, reg2, "$1$3");
	std::cout << str << std::endl;


	std::string str1("2010 Happy new Year!!!");
	//查找左边的数字
	sregex reg3 = sregex::compile("^(\\d| )*");
	//查找右边的符号
	sregex reg4 = sregex::compile("!*$");

	//相当于trim_left 修剪左边的数字
	std::cout << regex_replace(str1, reg3, "") << std::endl;
	//相当于trim_right 修剪右边的符号
	std::cout << regex_replace(str1, reg4, "") << std::endl;
	//相当于replace_all
	str1 = regex_replace(str1, reg3, "Y2000 ");
	std::cout << str1 << std::endl;
}
