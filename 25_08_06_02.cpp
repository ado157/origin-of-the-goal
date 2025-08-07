#include<iostream>
using namespace std;
class Animal {
public:
	virtual void speak() {
		cout << "说话" << endl;
	}
};
class Cat :public Animal {
public:
	void speak() {
		cout << "小猫在说话"<<endl;
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