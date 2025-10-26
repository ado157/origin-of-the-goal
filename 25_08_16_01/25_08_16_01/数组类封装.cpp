#include"iostream"
using namespace std;
#include"MyArray.hpp"
class Person {
public:
	Person() {};
	Person(string name, int age) {
		this->m_Age = age;
		this->m_Name = name;
	}
	string m_Name;
	int m_Age;
};
void printarr(MyArray <int>&arr1) {
	for (int i = 0; i < arr1.getSize(); i++) {
		cout << arr1[i] << endl;
	}
}
void printperson(MyArray<Person>&arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << "姓名：" << arr[i].m_Name << " 年龄:" << arr[i].m_Age << endl;
	}
}
void test1() {
	MyArray <int>arr1(5);
	//MyArray <int>arr3(100);
	//arr3 = arr1;
	for (int i = 0; i < 5; i++) {
		arr1.push_back(i);
	}
	cout << "arr1:"<<endl;
	printarr(arr1);
	cout << "arr1的容量" <<arr1.getCapacity() <<endl;
	MyArray <int>arr2(arr1);
	arr2.pop();
	cout << "arr2:" << endl;
	printarr(arr2);
}
void test2() {
	MyArray<Person> arr(10);
	Person p1("aaa", 10);
	Person p2("bbb", 11);
	Person p3("ccc", 12);
	Person p4("ddd", 13);
	Person p5("eee", 17);
	arr.push_back(p1);
	arr.push_back(p2);
	arr.push_back(p3);
	arr.push_back(p4);
	arr.push_back(p5);
	printperson(arr);
}
int main() {
	test1();
	test2();
	system("pause");
	return 0;
}