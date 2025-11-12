#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<ctime>
using namespace std;
class Greater30
{
public:
	bool operator()(int val)
	{
		return val >= 30;
	}
};
void myPrint(int val) {
	cout << val << " ";
}
void test1() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;

	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;
}
void test2() {
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(30);
	v.push_back(30);
	v.push_back(30);
	v.push_back(20);
	v.push_back(20);
	v.push_back(20);
	v.push_back(50);
	v.push_back(40);
	cout << "替换前:" << endl;
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	cout << "替换后:" << endl;
	replace(v.begin(), v.end(), 20, 2000);
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	cout << "替换前:" << endl;
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	cout << "替换后:" << endl;
	replace_if(v.begin(), v.end(), Greater30(), 3000);
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}
void test3() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	cout << "交换前：" << endl;
	cout << "v1:" << endl;
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;


	cout << "v2:" << endl;
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;

	swap(v1, v2);
	cout << "交换后：" << endl;


	cout << "v1:" << endl;
	for_each(v1.begin(), v1.end(), myPrint);
	cout << endl;


	cout << "v2:" << endl;
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;
}
int main() {
	test1();
	test2();
	test3();
	return 0;
}