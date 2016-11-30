
//*****************************************************
//
//    FileName:      boost_string_algo.cpp
//
//    Author:         huobingli - huobingli@outlook.com
//    Description:    
//    Create:        2016-11-21 16:00:16
//    Last Modified: 2016-11-21 16:00:16
//****************************************************
//
//
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <string>
using namespace std;
using namespace boost;

int main() {
	string str("readme.txt");

	if(ends_with(str, "txt")) {
		cout<<to_upper_copy(str) + " UPPER"<<endl;
		assert(ends_with(str, "txt"));
	}
	
	replace_first(str, "readme", "followme");

	cout<<str<<endl;

	vector<char> v(str.begin(), str.end());
	vector<char> v2 = to_upper_copy(erase_first_copy(v, "txt"));
	for(auto ch : v2) 
	{
		cout<<ch;
	}
	return 0;
}


