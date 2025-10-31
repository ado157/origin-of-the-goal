//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//class Person {
//public:
//	Person(string name, int age) {
//		this->m_Name = name;
//		this->m_Age = age;
//	}
//	bool operator==(const Person& p) {
//		if (this->m_Age == p.m_Age) {
//			return true;
//		}
//		else return false;
//	}
//	string m_Name;
//	int m_Age;
//};
//void test1() {
//	vector<int> v;
//	v.push_back(10);
//	v.push_back(40);
//	v.push_back(30);
//	v.push_back(40);
//	v.push_back(50);
//	int num=count(v.begin(), v.end(), 40);
//	cout << num << endl;
//}
//void test2() {
//	vector<Person> v;
//	Person p1("aaa", 10);
//	Person p2("bbb", 20);
//	Person p3("ccc", 30);
//	Person p4("ddd", 40);
//	Person p5("eee", 50);
//	Person p("fff", 30);
//	v.push_back(p1);
//	v.push_back(p2);
//	v.push_back(p3);
//	v.push_back(p4);
//	v.push_back(p5);
//	int num = count(v.begin(), v.end(), p);
//	cout << "与fff相同的有几个:" << num<<endl;
//}
//
//int main() {
//	test1();
//	test2();
//}