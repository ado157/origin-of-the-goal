#include"iostream"
using namespace std;
int times = 3;
int guessing(int a,int num){
	if (times <=1) { cout << "游戏结束未猜中" << endl; return 0; }
	if (a == num) {
		cout << "猜中了" << endl;
		return 0;
	}
	else
	{
		times--;
		cout << "还剩下" << times << "次机会" << endl;
		if (a>num)
		{
			cout << "大了" << endl;
		}
		else {
			cout << "小了" << endl;

		}
		cout << "请再猜一次" << endl;

	}
	return 1;
}
int main() {
	int num = 5;
	int guess;
	int result = 1;

	while (result) {
		cout << "请输入1-10之间的一个整数" << endl;
		cin >> guess;
		if (guess > 10 || guess < 1) {
			cout << "输入不合规" << endl;
			continue;
		}
		result=guessing(guess, num);
	}
}