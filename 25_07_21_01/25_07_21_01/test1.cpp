#include "iostream"
using namespace std;

int main() {
	//int i = 0;
	//loop:
	//cout << i << endl;
	//i++;
	//if (i <= 10)
	//{
	//	goto loop;
	//}
	int arr[] = { 1,2,3,4,5 };
	for (int element : arr) {
		cout << "高级循环取出的内容" << element << endl;
	}
	return 0;
}