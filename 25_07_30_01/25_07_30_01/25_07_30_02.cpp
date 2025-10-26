#include "iostream"
using namespace std;
#include<string>
class buliding {
	friend void goodguy(buliding* bui);
public :
	buliding() {
		m_sittingroom = "客厅";
		m_bedroom = "卧室";
	}

public:
string m_sittingroom;
private:
string m_bedroom;
};
void goodguy(buliding *bui) {
	cout << "全局函数访问" <<bui->m_sittingroom << endl;
	cout << "全局函数访问" <<bui->m_bedroom<< endl;
}
void test1() {
	buliding bui;
	goodguy(&bui);
}
int main() {
	test1();
}