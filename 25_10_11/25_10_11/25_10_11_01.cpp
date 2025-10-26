#include<iostream>

#include<string>
#include<set>
using namespace std;
class Person {
public:
	Person(string name, int age) {
		this->m_name = name;
		this->m_age = age;
	}
	string m_name;
	int m_age;
};
class comparePerson {
public:
	bool operator()(const Person& p1, const Person& p2)const {
		return p1.m_age > p2.m_age;
	}
};
void test1() {
	set<Person,comparePerson>s;
	Person p1("¹ØÓğ", 23);
	Person p2("ÕÅ·É", 24);
	Person p3("Áõ±¸", 25);
	Person p4("ÕÔÔÆ", 26);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	for (set<Person,comparePerson>::iterator it = s.begin(); it != s.end(); it++) {
		cout << "name:" << it->m_name << " age:" << it->m_age << endl;
	}
}
int main() {
	test1();
}