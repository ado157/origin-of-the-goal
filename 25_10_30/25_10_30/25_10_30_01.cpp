//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//#include<string>
//void test1() {
//	vector<int>v;
//	for (int i = 0; i < 10; i++) {
//		v.push_back(i);
//	}
//	vector<int>::iterator it= find(v.begin(), v.end(),50);
//	if (it == v.end()) {
//		cout << "û���ҵ�" << endl;
//	}
//	else {
//		cout << "�ҵ��� " << *it << endl;
//	}
//}
//
//class Person {
//public:
//	Person(string name, int age) {
//		this->m_Age = age;
//		this->m_Name = name;
//	}
//	bool operator==(const Person& p) {
//		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
//			return true;
//		}
//		return false;
//	}
//	string m_Name;
//	int m_Age;
//};
//
//void test2() {
//	vector<Person> v;
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	Person p3("ccc", 30);
//	Person p4("ddd", 40);
//	Person p5("eee", 50);
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//	Person pp("bbb", 20);
//	vector<Person>::iterator it = find(v.begin(), v.end(),pp);
//	if (it == v.end()) {
//		cout << "û���ҵ�" << endl;
//	}
//	else {
//		cout << "�ҵ�Ԫ�� ������ " << it->m_Name<<"���� ��" <<it->m_Age<< endl;
//	}
//}
//
//
//int main() {
//	test1();
//	test2();
//}