#include<iostream>
#include<vector>
using namespace std;
void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test1() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);
	v1.pop_back();
	printVector(v1);
	v1.insert(v1.begin(), 100);
	printVector(v1);
	v1.insert(v1.begin(),2,100);
	printVector(v1);
	v1.erase(v1.begin());
	printVector(v1);
	//v1.erase(v1.begin(), v1.end());
	v1.clear();
	printVector(v1);
}
int main() {
	test1();
	return 0;
}