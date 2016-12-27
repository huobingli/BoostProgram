#include <iostream>
using namespace std;
template<class T>
class Test{
private:
	T n;
	const T i;
	static T cnt;
public:
	Test() :i(0){ cout << "this is 构造" << endl; }
	Test(T k) : i(k){ n = k; /*cnt++;*/ }
	~Test(){ cout << "this is 析构" << endl; }
	void print() {
		std::cout << "n=" << n << std::endl;
		std::cout << "i=" << i << std::endl;
		std::cout << "cnt=" << cnt << std::endl;
	}
	T operator+(T x){
		return n + x;
	}
};

template<class T>
int Test<T>::cnt = 0;

int main() {
	Test<int> *t = new Test<int>(2);

	t->print();
	delete t;
}