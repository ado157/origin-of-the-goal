#include "iostream"
#include "random"
using namespace std;
int get_random_num(int min, int max) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(min, max);
	int random_number = dis(gen);
	return random_number;
}
int main() {
	int guess[10];
	int result[10];
	for (int i = 0; i < 10; i++) {
		cout << "请输入第" <<i+1<<"个数字（1-5）" << endl;
		cin >> guess[i];
	}
	int count = 0;
	for (int i =0; i < 10; i++) {
		if (guess[i] == get_random_num(1, 5)) {
			count++;
			cout << "猜中了第" << i << "个：" << guess[i] << endl;
		}
	}
	cout<<"猜中了"<<count <<"个" << endl;
}