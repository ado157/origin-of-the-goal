#include<iostream>
#include<string>
using namespace std;
void test1() {
	string str1 = "abcdefg";
	int postion=str1.find("de");
	if (postion == -1)cout << "×Ö´®²»´æÔÚ" << endl;
	else
	cout << "postion: " << postion << endl;
	string str2 = "abcdefgde";
	int postion2 = str2.rfind("de");
	cout << "postion2: " << postion2 << endl;

}
void test2() {
	string str1 = "abcdefg";
	str1.replace(1, 3, "1111");
	cout << "str1= " << str1 << endl;
}
int main() {
	test1();
	test2();
}