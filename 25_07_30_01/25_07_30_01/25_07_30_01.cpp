//#include "iostream"
//using namespace std;
//class person {
//public:
//	static int a;
//	int age;
//	static void func() {
//		a= 100;
//		cout << "静态成员函数调用" << endl;
//		cout << a << endl;
//	}
//	person(int age) {
//		this->age = age;
//	}
//	person& personadd(person &p) {
//	this->age += p.age;
//	return *this;
//}
//};
//int person::a = 200;
//
////void test1() {
////	person p1;
////	cout << p1.a << endl;
////	person p2;
////	p2.a = 100;
////	cout << p1.a << endl;
////
////}
////void test2() {
////	cout << person::a << endl;
////}
//
//void test3() {
//	person p(10);
//	person p1(20);
//	p.personadd(p1).personadd(p1);
//	cout<< p.age << endl;
//}
//int main() {
//	//test1();
//	//test2();
//	test3();
//	person:: func();
//}