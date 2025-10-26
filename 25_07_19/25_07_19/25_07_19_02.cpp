#include "iostream"
using namespace std;
int main() {
	enum Color {
		RED,
		BLUE,
		PINK
	};
	int num;
	cout << "ÄãÏ²»¶Ê²Ã´ÑÕÉ«" << endl;
	cin >> num;
	switch (num) {
	case RED:
		cout << "ºìÉ«" << endl;
		break;
	case BLUE:
		cout << "À¶É«" << endl;
		break;
	case PINK:
		cout << "·ÛÉ«" << endl;
		break;
	default:
		cout << "ÊäÈë´íÎó" << endl;
	}
	return 0;
}