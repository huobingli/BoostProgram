#include <boost/lexical_cast.hpp>
#include <iostream>
#include <string.h>
using namespace boost;
using namespace std;

int main() {
	int x = lexical_cast<int>("100");
	long y = lexical_cast<long>("2000");
	float pai = lexical_cast<float>("3.14159e5");
	double e = lexical_cast<double>("2.71827");

	cout<<x<<y<<pai<<e<<endl;

	string str = lexical_cast<string>(456);
	cout<<str<<endl;

	cout<<lexical_cast<string>(0.618)<<endl;
	cout<<lexical_cast<string>(0x10)<<endl;

	return 0;
}
