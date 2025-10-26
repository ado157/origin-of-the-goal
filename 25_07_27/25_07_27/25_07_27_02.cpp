#include "iostream"
#include "string"
using namespace std;
class Cube {
public:
	void set_L(int L) {
		m_L = L;
	}
	int get_L() {
		return m_L;
	}	
	void set_W(int W) {
		m_W = W;

	}
	int get_W() {
		return m_W;
	}	
	void set_H(int H) {
		m_H = H;

	}
	int get_H() {
		return m_L;
	}
	int calculateS() {
		return 2 * (m_L * m_W + m_L * m_H + m_W * m_H);
	}
	int calculateV() {
		return m_L * m_W * m_H;
	}
private:
	int m_L;
	int m_W;
	int m_H;

};
int main() {
	class Cube C;
	C.set_H(3);
	C.set_L(4);
	C.set_W(5);
	cout << "c1的面积：" << C.calculateS() << endl;
	cout << "c1的体积：" << C.calculateV() << endl;
}