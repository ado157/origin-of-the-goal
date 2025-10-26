#include<iostream>
#include<vector>
using namespace std;
void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it) << " ";
	}
	cout << endl;
}
void test1() {
	vector<int> v1;
	int times = 0;
	int* p = NULL;
	for (int i = 0; i < 10000; i++) {
		v1.push_back(i);
		if (p != &v1[0]) {
			p = &v1[0];
			times++;
		}
	}
	cout << "times:" <<times<< endl;
}

int main() {
	test1();
	//test2();
}