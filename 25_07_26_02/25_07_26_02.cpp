#include "iostream"
#include "iomanip"
using namespace std;
void stage1() {
	cout <<left<<setw(13)<< "50%-100% һ�׶�" << endl;
}
void stage2() {
	stage1();
	cout << left << setw(13) << "����50%\t ���׶�" << endl;

}
void stage3() {
	stage2();
	cout << left << setw(13) << "����20%\t ���׶��һظ���100%" << endl;
}
void boss() {
	stage3();
}
int main() {
	boss();
}