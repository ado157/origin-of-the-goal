//#include<iostream>
//#include<vector>
//using namespace std;
//void printVector(vector<int>& v) {
//	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//		cout << (*it) << " ";
//	}
//	cout << endl;
//}
//void test1() {
//	vector<int>v1;
//	for (int i = 0; i < 10; i++) {
//		v1.push_back(i);
//	}
//	printVector(v1);
//	vector<int>v2;
//	for (int i = 9; i >= 0; i--) {
//		v2.push_back(i);
//	}
//	printVector(v2);
//	v1.swap(v2);
//	printVector(v1);
//	printVector(v2);
//
//}
//void test2() {
//	vector<int>v;
//	for (int i = 0; i < 10000; i++) {
//		v.push_back(i);
//	}
//	cout << "v的容量为:" << v.capacity() << endl;
//	cout << "v的大小为:" << v.size() << endl;
//	v.resize(3);
//	cout << "v的容量为:" << v.capacity() << endl;
//	cout << "v的大小为:" << v.size() << endl;
//	vector<int>(v).swap(v); 
//	cout << "v的容量为:" << v.capacity() << endl;
//	cout << "v的大小为:" << v.size() << endl;
//}
//int main() {
//	test1();
//	test2();
//}