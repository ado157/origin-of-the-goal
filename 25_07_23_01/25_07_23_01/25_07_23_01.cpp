#include "iostream"
using namespace std;
int main() {
	//struct Student {
	//	string name;
	//	int age;
	//	string gender;
	//};
	//struct Student stu;
	//stu = { "Ado",22,"Ů" };
	//cout << "����:" << stu.age << endl;
	//struct Student * p = new Student{ "nina",18,"Ů" };
	//cout << "����:" << p->age << endl;
	//delete p;
	typedef struct Student {
		string name;
		int age = 18;
		string gender = "Ů";

	}stu;
	stu* p = new stu[3]{ {"Ado"},{"nina"},{"aaa"} };
	cout << "name:"<<p[0].name<<endl;
	cout << "name:"<<p[1].name<<endl;
	cout << "name:"<<p[2].name<<endl;
}