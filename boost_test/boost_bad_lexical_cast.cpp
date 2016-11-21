#include <boost/lexical_cast.hpp>
#include <iostream>
using namespace boost;
using namespace std;

int main() {
	try{
		cout<<lexical_cast<int>("0x100");
		cout<<lexical_cast<double>("helloworld");
		cout<<lexical_cast<long>("1000L");
		cout<<lexical_cast<bool>("false")<<endl;
	}	
	catch(bad_lexical_cast & e){
		cout<<"error:"<<e.what()<<endl;
	}
	return 0;
}
