#include "iostream"
using namespace std;
int* add(int a, int b) {
	int sum;
	sum = a + b;
	return &sum;//该地址会在add结束时被回收（被标记为可覆写，可能会出现问题）
}
int* add1(int a, int b) {
	int* sum = new int;//手动分配，动态分配可以正常返回，需手动释放
	*sum = a + b;
	return sum;
}
int* add2(int a, int b) {
	static int sum;//静态变量，num会持续存在直到程序结束
	sum = a + b;
	return &sum;
}
int main() {
	int* result1 = add2(2, 2);
	cout << *result1 << endl;
	
}