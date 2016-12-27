
//********************************************************
//
//       FileName:      boost_assgin_to_adapter.cpp
//
//       Author:  huobingli - huobingli@outlook.com
//       Description:    
//       Create: 2016-12-27  13:11:40
//       Last Modified: 2016-12-27 13:11:40
//********************************************************
// 

/*
stack queue 这些容器，不符合容器的定义，没有insert、push_back等函数
所以不能用赋值方式填入元素，只能用初始化，并在list_of表达式最后使用
to_adapter()成员函数来适配到非标准容器，如果用逗号还需要把整个表达式用括号括起来
然后用.to_adapter()来适配
*/

int main() {
	using namespace boost::assign;
	std::stack<int> stk = (list_of(1), 2, 3).to_adapter();
	while (!stk.empty()) {
		std::cout << stk.top() << " ";
		stk.pop();
	}
	std::cout << std::endl;

	std::queue<std::string> q = (list_of("china")("us")("uk")).repeat(2, "russia").to_adapter();
	while (!q.empty()) {
		std::cout << q.front() << " "; 
		q.pop();
	}
	std::cout << std::endl;

	std::priority_queue<double> pq = (list_of(1.414), 1.732, 2.236).to_adapter();
	while (!pq.empty()) {
		std::cout << pq.top() << " ";
		pq.pop();
	}
}
