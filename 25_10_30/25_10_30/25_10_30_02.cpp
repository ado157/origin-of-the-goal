#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

class GreaterFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};

class Person {
public:
	Person(string name, int age) {
		this->m_Age = age;
		this->m_Name = name;
	}
	bool operator==(const Person& p) {
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
			return true;
		}
		return false;
	}
	string m_Name;
	int m_Age;
};
class Greater20 {
public:
	bool operator()(Person& p) {
		return p.m_Age > 20;
	}
};
void test1() {
		vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int>::iterator it=find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end()) {
		cout << "没有找到" << endl;
	}
	else {
		cout << "找到： " << *it << endl;
	}
}

void test2() {
	vector<Person> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());
	if (it == v.end()) {
		cout << "没有找到" << endl;
	}
	else {
		cout << "找到元素 姓名： " << it->m_Name << "年龄 ：" << it->m_Age << endl;
	}
}
int main() {
	test1();
	test2();
}