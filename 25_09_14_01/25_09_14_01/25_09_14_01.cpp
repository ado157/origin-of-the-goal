#include "iostream"
#include<vector>
#include<algorithm>

using namespace std;
void myprint(int val) {
	cout << val << endl;
}
void test1() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();
	//while (itBegin != itEnd) {
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}
	for_each(v.begin(),v.end(),myprint);
}
int main() {
	test1();
	return 0;
}