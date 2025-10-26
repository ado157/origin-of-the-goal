#include<iostream>
#include<string>
using namespace std;
void test1() {
	string str1 = "hello";
	string str2 = "xello";
	if (str1.compare(str2) == 0) {
		cout << "str1 = str2" << endl;
	}
	else {
		cout << "str1 != str2" << endl;
	}
}

int main() {
	test1();

	system("pause");
	return 0;
}