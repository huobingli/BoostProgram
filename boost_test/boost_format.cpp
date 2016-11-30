#include <iostream>

#include <boost/format.hpp>
#include <iomanip>

using namespace boost;
using namespace std;
using boost::io::group;

int main() {
	format fmt("%1% %2% %3% %2% %1% \n");
	cout<<fmt %1 %2 %3;
	
	//将第二个输入参数固定为10
	fmt.bind_arg(2, 10);
	//输入其他两个参数
	cout<<fmt %1  %3;

	//清空缓冲，但绑定的参数不变
	fmt.clear();

	//在%操作符中使用group(),指定输入/输出流操纵符第一个参数显示为八进制
	cout<<fmt % group(showbase, oct, 111) % 333;

	//清楚所有绑定
	fmt.clear_binds();

	//设置第一个格式化项，十六进制，宽度为8，右对齐，不足位用*填充
	fmt.modify_item(1, group(hex, right, showbase, setw(8), setfill('*')));
	cout<<fmt % 49 % 20 % 100;

	return 0;
}

