//#include "iostream"
//#include "windows.h"
//using namespace std;
//#define defalutBalance 5000000
//void inquire(int money) {
//	cout << "��" << money << endl;
//}
//int deposit(int money) {
//	int input_money = 0;
//	cout << "���������" << endl;
//	cin >> input_money;
//	money += input_money;
//	inquire(money);
//	return money;
//}
//int withdrawal(int money) {
//	int output_money = 0;
//	cout << "������ȡ���" << endl;
//	cin >> output_money;
//	if (output_money <= money) {
//		money -= output_money;
//		inquire(money);
//	}
//	else {
//		cout << "����" << endl;
//		inquire(money);
//	}
//	return money;
//}
//void menu() {
//	cout << "------------------------------------------" << endl;
//	cout << endl;
//	cout <<"|            ��ӭ�����������              |" << endl;
//	cout <<"|��ѡ������ҵ��:                         |"<<endl;
//	cout <<"|1.��ѯ���                                |"<<endl;
//	cout <<"|2.���                                    |"<<endl;
//	cout <<"|3.ȡ��                                    |"<<endl;
//	cout <<"|4.�˳�                                    |"<<endl;
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
//			cout << "�������" << endl;
//			break;
//		}
//	};
//	cout <<"���˳�" << endl;
//}
//int main() {
//	system();
//}