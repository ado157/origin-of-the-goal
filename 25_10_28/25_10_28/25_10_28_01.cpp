#include<iostream>
using namespace std;
#include<functional>
void test1() {
	negate<int>n;
	plus<int> m;
	cout <<n(50) <<endl;
	cout <<m(50,10) <<endl;

}

int main() {
	test1();
}