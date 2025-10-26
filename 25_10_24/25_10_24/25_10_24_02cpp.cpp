#include<iostream>
#include<string>
using namespace std;
class MyAdd {
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};
class MyPrint {
public:
	MyPrint() {
		this->count=0;
	}
	void operator()(string test) {
		cout << test << endl;
		count++;
	}
	int count;
};
void doPrint(MyPrint &myPrint,string text) {
	myPrint(text);
}
void test1() {
	MyAdd myAdd;
	
	cout << myAdd(10 , 11) << endl;
	MyPrint myPrint;
	myPrint("aaaa");
	myPrint("aaaa");
	myPrint("aaaa");
	myPrint("aaaa");
	myPrint("aaaa");
	cout << myPrint.count << endl;
}
void test2() {
	MyPrint myPrint;
	string text = "abcd";
	doPrint(myPrint, text);
}
int main() {
	test1();
	test2();
}