#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Person {
public:
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};
class Greater20 {
public:
	bool operator()(int val) {
		return val > 20;
	}
};
class AgeGreator20 {
public:
	bool operator()(const Person& p) {
		return p.m_Age > 20;
	}
};
void test1() {
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	int num = count_if(v.begin(), v.end(), Greater20());
	cout << "大于20:" << num << endl;

}
void test2() {
	vector<Person> v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	int num = count_if(v.begin(), v.end(), AgeGreator20());
	cout << "大于20:" << num << endl;

}
int main() {
	test1();
	test2();
}