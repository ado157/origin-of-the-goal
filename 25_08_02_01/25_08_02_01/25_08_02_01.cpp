#include "iostream"
using namespace std;
//class Java {
//public:
//	void header() {
//		cout << "��ҳ�������Σ���¼ע��...������ͷ����" << endl;
//	}
//	void footer() {
//		cout << "�������ģ�����������վ�ڵ�ͼ...�������ײ���" << endl;
//	}
//	void left() {
//		cout << "Java,Python,C++...(���������б�)" << endl;
//	}
//	void content() {
//		cout << "Java ѧ����Ƶ" << endl;
//	}
//};
//class Python {
//public:
//	void header() {
//		cout << "��ҳ�������Σ���¼ע��...������ͷ����" << endl;
//	}
//	void footer() {
//		cout << "�������ģ�����������վ�ڵ�ͼ...�������ײ���" << endl;
//	}
//	void left() {
//		cout << "Java,Python,C++...(���������б�)" << endl;
//	}
//	void content() {
//		cout << "Python ѧ����Ƶ" << endl;
//	}
//};
//class CPP {
//public:
//	void header() {
//		cout << "��ҳ�������Σ���¼ע��...������ͷ����" << endl;
//	}
//	void footer() {
//		cout << "�������ģ�����������վ�ڵ�ͼ...�������ײ���" << endl;
//	}
//	void left() {
//		cout << "Java,Python,C++...(���������б�)" << endl;
//	}
//	void content() {
//		cout << "C++ ѧ����Ƶ" << endl;
//	}
//};
class Base {
public:
	void header() {
		cout << "��ҳ�������Σ���¼ע��...������ͷ����" << endl;
	}
	void footer() {
		cout << "�������ģ�����������վ�ڵ�ͼ...�������ײ���" << endl;
	}
	void left() {
		cout << "Java,Python,C++...(���������б�)" << endl;
	}
};
class Java:public Base {
public:
	void content() {
		cout << "Java ѧ����Ƶ" << endl;
	}
};
class Python :public Base {
public:
	void content() {
		cout << "Python ѧ����Ƶ" << endl;
	}
};
class CPP :public Base {
public:
	void content() {
		cout << "C++ ѧ����Ƶ" << endl;
	}
};
void test1() {
	Java ja;
	ja.header();
	ja.content();
	ja.footer();
	ja.left();
	cout << "----------------------------------------------------" << endl;
	Python p;
	p.header();
	p.content();
	p.footer();
	p.left();
	cout << "----------------------------------------------------" << endl;
	CPP cpp;
	cpp.header();
	cpp.content();
	cpp.footer();
	cpp.left();
}
int main()
{
	test1();
}