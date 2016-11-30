#include<boost/progress.hpp>

using namespace boost;

int main() {
	{
		boost::progress_timer t;
		std::cout<<"1"<<std::endl;
	}
	{
		boost::progress_timer t;
		std::cout<<"2"<<std::endl;
	}
	return 0;
}
