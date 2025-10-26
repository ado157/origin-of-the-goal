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
//	string color = random_num(0, 1)?"ºì":"ºÚ";
//	string suit;
//	if (color == "ºì") {
//		suit = random_num(0, 1) ? "ºìÌÒ" : "·½¿é";
//	}
//	else {
//		suit = random_num(0, 1) ? "ºÚÌÒ" : "Ã·»¨";
//	}
//	cout << num<<":" <<color<<":" << suit << endl;
//	int guess;
//	cout << "ÇëÊäÈë²Â²âµÄÆË¿ËÅÆÊı×Ö:" << endl;
//	cin >> guess;
//	if (guess == num) {
//
//	}
//	else
//	{
//		cout << "Êı×Ö´íÎó£¬½áÊø" << endl;
//		return 0;
//	}
//	string guscolor;
//	cout << "ÇëÊäÈë²Â²âµÄÆË¿ËÅÆÑÕÉ«" << endl;
//	cin >> guscolor;
//	if (guscolor == color) {
//
//	}
//	else
//	{
//		cout << "ÑÕÉ«´íÎó,½áÊø" << endl;
//		return 0;
//	}	
//	cout << "ÇëÊäÈë²Â²âµÄÆË¿ËÅÆ»¨É«" << endl;
//	string gussuit;
//	cin >> gussuit;
//	if (gussuit == suit) {
//		cout << "¹§Ï²²ÂÖĞÁË" << endl;
//	}
//	else
//	{
//		cout << "ÑÕÉ«´íÎó,½áÊø" << endl;
//	}
//
//	return 0;
//}