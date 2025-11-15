//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<numeric>
//using namespace std;
//
//
//void myPrint(int val) {
//	cout << val << " ";
//}
//
//void test1() {
//	vector<int>v;
//	for (int i = 0; i <= 100; i++) {
//		v.push_back(i);
//	}
//	int total = accumulate(v.begin(), v.end(), 0);
//	cout << "total =" << total << endl;
//
//}
//void test2() {
//	vector<int>v;
//	v.resize(10);
//
//	fill(v.begin(), v.end(), 100);
//	fill(v.begin(), v.end(), 10);
//	for_each(v.begin(),v.end(),myPrint);
//	cout << endl;
//}
//int main() {
//	test1();
//	test2();
//}