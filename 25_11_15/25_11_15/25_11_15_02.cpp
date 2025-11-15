#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
void myPrint(int val) {
	cout << val << " ";
}
void test1() {
	vector<int>v1;
	vector<int>v2;
	for (int i=0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 4);
	}
	vector<int>vTarget;
	vTarget.resize(min(sizeof(v1),sizeof(v2)));
	vector<int>::iterator itEnd=set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint);
	cout << endl;
}
void test2() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 4);
	}
	vector<int>vTarget;
	vTarget.resize(sizeof(v1) + sizeof(v2));
	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint);
	cout << endl;

}
void test3() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 4);
	}
	vector<int>vTarget;
	vTarget.resize(max(sizeof(v1) , sizeof(v2)));
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), itEnd, myPrint);
	cout << endl;

}
int main() {
	test1();
	test2();
	test3();
}