#include<iostream>
using namespace std;
#include<vector>
#include<functional>
#include<algorithm>
class Transform {
public:
	int operator()(int v) {
		return v+100;
	}
};
class print1 {
public:
	void operator()(int v) {
		cout << v << " ";
	}

};
void test1() {
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int>vTarget;
	vTarget.resize(v.size());
	transform(v.begin(), v.end(), vTarget.begin(),Transform());
	for_each(vTarget.begin(), vTarget.end(), print1());
	cout << endl;
}

int main() {
	test1();
}