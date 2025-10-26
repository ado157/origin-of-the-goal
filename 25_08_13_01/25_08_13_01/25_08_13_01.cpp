#include"iostream"
using namespace std;
#include"string"
//template<typename T>
//void myswap(T& a, T& b) {
//	T temp = a;
//	a = b;
//	b = temp;
//}
//void test1() {
//	int a = 10;
//	int b = 20;
//	myswap(a, b);
//	cout << "a=" << a << endl;
//	cout << "b=" << b << endl;
//}
template<class NameType,class AgeType>
class person {
public:
	person(NameType name, AgeType age) {
		this->m_Name = name;
		this->m_Age = age;
	};
	void showPerson() {
		cout << "name: " << this->m_Name << " age= " << this->m_Age << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};
void  test1() {
	person<string, int>p("aaa", 10);
	p.showPerson();
};
int main() {
	test1();
}
  