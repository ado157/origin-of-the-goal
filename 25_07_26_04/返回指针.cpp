#include "iostream"
using namespace std;
int* add(int a, int b) {
	int sum;
	sum = a + b;
	return &sum;//�õ�ַ����add����ʱ�����գ������Ϊ�ɸ�д�����ܻ�������⣩
}
int* add1(int a, int b) {
	int* sum = new int;//�ֶ����䣬��̬��������������أ����ֶ��ͷ�
	*sum = a + b;
	return sum;
}
int* add2(int a, int b) {
	static int sum;//��̬������num���������ֱ���������
	sum = a + b;
	return &sum;
}
int main() {
	int* result1 = add2(2, 2);
	cout << *result1 << endl;
	
}