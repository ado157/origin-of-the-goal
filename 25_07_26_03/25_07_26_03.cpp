//#include "iostream"
//#include "windows.h"
//using namespace std;
//#define defalutBalance 5000000
//void inquire(int money) {
//	cout << "余额：" << money << endl;
//}
//int deposit(int money) {
//	int input_money = 0;
//	cout << "请输入存款金额：" << endl;
//	cin >> input_money;
//	money += input_money;
//	inquire(money);
//	return money;
//}
//int withdrawal(int money) {
//	int output_money = 0;
//	cout << "请输入取款金额：" << endl;
//	cin >> output_money;
//	if (output_money <= money) {
//		money -= output_money;
//		inquire(money);
//	}
//	else {
//		cout << "余额不足" << endl;
//		inquire(money);
//	}
//	return money;
//}
//void menu() {
//	cout << "------------------------------------------" << endl;
//	cout << endl;
//	cout <<"|            欢迎来到天地银行              |" << endl;
//	cout <<"|请选择办理的业务:                         |"<<endl;
//	cout <<"|1.查询余额                                |"<<endl;
//	cout <<"|2.存款                                    |"<<endl;
//	cout <<"|3.取款                                    |"<<endl;
//	cout <<"|4.退出                                    |"<<endl;
//	cout << endl;
//	cout <<"--------------------------------------------" << endl;
//}
//void system() {
//	int choice=0;
//	int money = defalutBalance;
//	while(true) {
//		menu();
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:inquire(money); break;
//		case 2:money=deposit(money); break;
//		case 3:money=withdrawal(money); break;
//		case 4:break;
//		default:
//			cout << "输入错误" << endl;
//			break;
//		}
//	};
//	cout <<"已退出" << endl;
//}
//int main() {
//	system();
//}