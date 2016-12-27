//********************************************************
//
//       FileName:      boost_tokenizer.cpp
//
//       Author:  huobingli - huobingli@outlook.com
//       Description:    
//       Create: 2016-12-27  14:44:47
//       Last Modified: 2016-12-27 14:44:47
//********************************************************
//

#include <iostream>
//分词的字符串处理库
#include <boost/tokenizer.hpp>

int main() {
	std::string str("Link raise the master-sword.");
	//使用缺省模板参数创建分词对象
	boost::tokenizer<> tok(str);

	//可以向遍历一个容器一样使用for循环获得分词结果
	for (auto x : tok){ std::cout << "[" << x << "]"; }
}