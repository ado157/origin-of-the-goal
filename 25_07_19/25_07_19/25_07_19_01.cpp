//#include "iostream"
//#include "random"
//using namespace std;
//int random_num(int min, int max) {
//	random_device rd;
//	mt19937 gen(rd());
//	uniform_int_distribution<>dis(min, max);
//	int random_number = dis(gen);
//	return random_number;
//}
//int main() {
//	int num = random_num(1, 10);
//	string color = random_num(0, 1)?"��":"��";
//	string suit;
//	if (color == "��") {
//		suit = random_num(0, 1) ? "����" : "����";
//	}
//	else {
//		suit = random_num(0, 1) ? "����" : "÷��";
//	}
//	cout << num<<":" <<color<<":" << suit << endl;
//	int guess;
//	cout << "������²���˿�������:" << endl;
//	cin >> guess;
//	if (guess == num) {
//
//	}
//	else
//	{
//		cout << "���ִ��󣬽���" << endl;
//		return 0;
//	}
//	string guscolor;
//	cout << "������²���˿�����ɫ" << endl;
//	cin >> guscolor;
//	if (guscolor == color) {
//
//	}
//	else
//	{
//		cout << "��ɫ����,����" << endl;
//		return 0;
//	}	
//	cout << "������²���˿��ƻ�ɫ" << endl;
//	string gussuit;
//	cin >> gussuit;
//	if (gussuit == suit) {
//		cout << "��ϲ������" << endl;
//	}
//	else
//	{
//		cout << "��ɫ����,����" << endl;
//	}
//
//	return 0;
//}