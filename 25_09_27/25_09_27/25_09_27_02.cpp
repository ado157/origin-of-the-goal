#include<iostream>
#include<list>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
void printSet(const set<int>& s) {
	for (set<int> ::const_iterator it = s.begin(); it != s.end(); it++) {
		cout << (*it) << " ";
	 }
	cout << endl;
}
void test1() {
	set<int>s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	s1.insert(30);
	printSet(s1);
}
int main() {
	test1();
}