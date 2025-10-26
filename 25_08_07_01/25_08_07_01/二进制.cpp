#include<iostream>
using namespace std;
#include<fstream>
#include <string>
class person {
public:
	int age;
	char name[64];
};
void test1() {
	ofstream ofs;
	ofs.open("person.txt", ios::out, ios::binary);
	person p = { 18,'111' };
	ofs.write((const char*)&p, sizeof(person));
	ofs.close();
}
void test2() {
	ifstream ifs;
	ifs.open("person.txt", ios::in, ios::binary);
	if (!ifs.is_open()) {
		cout<<"error"<<endl;
		return;
	}
	person p;
	ifs.read((char*)&p, sizeof(person));
	cout << "ÐÕÃû£º" << p.name << "ÄêÁä:" << p.age << endl;
	ifs.close();
}
int main() {
	
	test2();
	system("pause");
}