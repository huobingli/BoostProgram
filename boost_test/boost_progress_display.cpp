#include <boost/progress.hpp>
#include <vector>
#include <fstream>
using namespace std;
using namespace boost;

int mian() {
	vector<string> v(100, "aaa");
	v[10] = ""; v[23] = "";
	ofstream fs("./test.txt");

	progress_display pd(v.size());

	vector<int>::iterator pos;
	for(auto pos = v.begin(); pos != v.end(); ++pos) {
		fs << *pos << endl;
		++pd;
		if(pos->empty()){
			cout<<"null string #"<<(pos-v.begin())<<endl;
		}
	}
}
