#include "iostream"
using namespace std;
#include<string>
class buliding {
	friend void goodguy(buliding* bui);
public :
	buliding() {
		m_sittingroom = "����";
		m_bedroom = "����";
	}

public:
string m_sittingroom;
private:
string m_bedroom;
};
void goodguy(buliding *bui) {
	cout << "ȫ�ֺ�������" <<bui->m_sittingroom << endl;
	cout << "ȫ�ֺ�������" <<bui->m_bedroom<< endl;
}
void test1() {
	buliding bui;
	goodguy(&bui);
}
int main() {
	test1();
}