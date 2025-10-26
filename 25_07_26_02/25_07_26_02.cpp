#include "iostream"
#include "iomanip"
using namespace std;
void stage1() {
	cout <<left<<setw(13)<< "50%-100% 一阶段" << endl;
}
void stage2() {
	stage1();
	cout << left << setw(13) << "低于50%\t 二阶段" << endl;

}
void stage3() {
	stage2();
	cout << left << setw(13) << "低于20%\t 三阶段且回复至100%" << endl;
}
void boss() {
	stage3();
}
int main() {
	boss();
}