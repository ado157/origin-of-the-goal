#include "iostream"
using namespace std;
class person {
public:
	int age;
	person() {
		cout << "�޲ι��캯���ĵ���" << endl;
	}	
	person(int a){
		age = a;
		cout << "�вι��캯���ĵ���" << endl;
	}
	~person() {
		cout << "���������ĵ���" << endl;
	}
	person(const person &p) {
		age = p.age;
		cout << "�������캯���ĵ���" << endl;
	}
};
void dowork(person p) {

}
person dowork2() {
	person p1;
	return p1;
}
void test1() {
	person p1;
	person p2(10);
	person p3(p2);
	cout << p2.age << endl;
	cout << p3.age << endl;
}
void test2() {
	person p;
	dowork(p);
}
void test3() {
	person p=dowork2();
}
int main() {
	//test1();
	//person p;
	//test2();
	test3();
	system("pause");
	return 0;
}