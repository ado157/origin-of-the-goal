//#include "iostream"
//using namespace std;
//class person {
////public:
////	person operator+(person& p) {
////		person temp;
////		temp.m_a = this->m_a + p.m_a;
////		temp.m_b = this->m_b + p.m_b;
////		return temp;
////	}
//public:
//	int m_a;
//	int m_b;
//};
//person operator+(person& p1, person& p2) {
//	person temp;
//	temp.m_a = p1.m_a + p2.m_a;
//	temp.m_b = p1.m_b + p2.m_b;
//	return temp;
//}
//void test1() {
//	person p1;
//	p1.m_a = 10;
//	p1.m_b = 10;
//	person p2;
//	p2.m_a = 20;
//	p2.m_b = 20;
//	person p3 = p1 + p2;
//	cout << "p3.m_a" << p3.m_a << endl;
//	cout << "p3.m_b" << p3.m_b << endl;
//}
//int main() {
//	test1();
//	system("pause");
//}