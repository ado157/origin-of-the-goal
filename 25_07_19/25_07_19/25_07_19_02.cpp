#include "iostream"
using namespace std;
int main() {
	enum Color {
		RED,
		BLUE,
		PINK
	};
	int num;
	cout << "��ϲ��ʲô��ɫ" << endl;
	cin >> num;
	switch (num) {
	case RED:
		cout << "��ɫ" << endl;
		break;
	case BLUE:
		cout << "��ɫ" << endl;
		break;
	case PINK:
		cout << "��ɫ" << endl;
		break;
	default:
		cout << "�������" << endl;
	}
	return 0;
}