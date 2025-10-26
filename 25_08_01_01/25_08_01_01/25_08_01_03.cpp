#include "iostream"
using namespace std;
class myint {
	friend ostream& operator<<(ostream& cout, myint inta);
public:
	myint& operator++() {
		a++;
		return *this;
	}	
	myint operator++(int) {
		myint temp = *this;
		a++;
		return temp;
	}
public:
	myint() {
		a = 10;
	}
private:
	int a;
};
void test1() {
	myint inta;
	cout << inta << endl;
	cout <<++inta << endl;
}
void test2() {
	myint intb;
	cout << intb++ << endl;
	cout << intb << endl;
}
ostream& operator<<(ostream& cout, myint inta) {
	cout << inta.a;
	return cout;
}

int main() {
	test1();
	test2();
}