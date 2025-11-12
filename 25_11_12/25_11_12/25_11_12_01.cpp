//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<functional>
//#include<ctime>
//using namespace std;
//
//void myPrint(int val) {
//	cout << val << " ";
//}
//void test1() {
//	vector<int>v;
//	v.push_back(10);
//	v.push_back(30);
//	v.push_back(20);
//	v.push_back(50);
//	v.push_back(40);
//	sort(v.begin(), v.end());
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//	sort(v.begin(), v.end(),greater<int>());
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//
//}
//void test2() {
//	srand((unsigned int)time(NULL));
//	vector<int>v;
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i);
//	}
//	random_shuffle(v.begin(), v.end());
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//
//}
//void test3() {
//	vector<int>v1;
//	vector<int>v2;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//		v2.push_back(i+1);
//	}
//	vector<int>v;
//	v.resize(20);
//	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//}
//void test4() {
//	vector<int>v;
//	v.push_back(10);
//	v.push_back(30);
//	v.push_back(20);
//	v.push_back(50);
//	v.push_back(40);
//	cout << "反转前:" << endl;
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//
//	cout << "反转后:" << endl;
//	reverse(v.begin(), v.end());
//	for_each(v.begin(), v.end(), myPrint);
//	cout << endl;
//
//}
//int main() {
//	test1();
//	test2();
//	test3();
//	test4();
//	return 0;
//}