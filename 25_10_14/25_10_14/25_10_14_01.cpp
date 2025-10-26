#include<iostream>
using namespace std;
#include <map>
class MyCompare {
public:
	bool operator()(int v1, int v2)const {
		return v1 > v2;
	}
};
void printMap(map<int, int, MyCompare>& m) {
	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key=" << it->first << " value=" << it->second << endl;;
	}
	cout << endl;
}

void test1() {
	map<int, int,MyCompare>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(map<int, int, MyCompare>::value_type(3, 30));
	m[4] = 40;
	cout << m[5] << endl;
	printMap(m);
	//m.erase(m.begin());
	//printMap(m);
	//m.erase(3);
	//printMap(m);
	//m.erase(m.begin(), m.end());
	//printMap(m);
	//map<int,int,MyCompare>::iterator pos= m.find(3);
	//if (pos != m.end()) {
	//	cout << "查到了元素 key=" << (*pos).first << " value= " << pos->second << endl;
	//}
	//else {
	//	cout<<"元素未找到" << endl;
	//}

	//int num = m.count(3);
	//cout << "num=" << num << endl;
}
int main() {
	test1();
}