#include<iostream>
using namespace std;
class Animal {
public:
	virtual void speak() {
		cout << "˵��" << endl;
	}
};
class Cat :public Animal {
public:
	void speak() {
		cout << "Сè��˵��"<<endl;
	}
};
void doSpeak(Animal& animal) {
	animal.speak();
}
void test1() {

	Cat cat;
	doSpeak(cat);
}
int main() {
	test1();
}