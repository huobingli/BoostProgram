#include <iostream>
#include <boost/shared_ptr.hpp>

class shared {
private:
	boost::shared_ptr <int> p;
public:
	shared(boost::shared_ptr<int> p_) : p(p_) {}
	void print() {
		std::cout << "count:" << p.use_count() << "v = " << *p << std::endl;
	}
};

void print_func(boost::shared_ptr<int> p) {
	std::cout << "count:" << p.use_count() << "v = " << *p << std::endl;
}

int main(){
	boost::shared_ptr <int> p(new int(10));
	shared s1(p), s2(p);
	s1.print();
	s2.print();

	*p = 20;
	print_func(p);
	s1.print();

	std::cout << sMessages[1] << std::endl;

	std::vector<int> arr[10];
	//std::vector<int>::iterator it = arr.begin();
	for (auto it = arr->cbegin(); it != arr->cend(); it++) {
		arr->push_back(1);
	}

	for (auto it = arr->cbegin(); it != arr->cend(); it++){
		std::cout << (*it) << std::endl;
	}
}