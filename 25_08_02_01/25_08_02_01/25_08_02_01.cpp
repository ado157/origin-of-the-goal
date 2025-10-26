#include "iostream"
using namespace std;
//class Java {
//public:
//	void header() {
//		cout << "首页，公开课，登录注册...（公共头部）" << endl;
//	}
//	void footer() {
//		cout << "帮助中心，交流合作，站内地图...（公共底部）" << endl;
//	}
//	void left() {
//		cout << "Java,Python,C++...(公共分类列表)" << endl;
//	}
//	void content() {
//		cout << "Java 学科视频" << endl;
//	}
//};
//class Python {
//public:
//	void header() {
//		cout << "首页，公开课，登录注册...（公共头部）" << endl;
//	}
//	void footer() {
//		cout << "帮助中心，交流合作，站内地图...（公共底部）" << endl;
//	}
//	void left() {
//		cout << "Java,Python,C++...(公共分类列表)" << endl;
//	}
//	void content() {
//		cout << "Python 学科视频" << endl;
//	}
//};
//class CPP {
//public:
//	void header() {
//		cout << "首页，公开课，登录注册...（公共头部）" << endl;
//	}
//	void footer() {
//		cout << "帮助中心，交流合作，站内地图...（公共底部）" << endl;
//	}
//	void left() {
//		cout << "Java,Python,C++...(公共分类列表)" << endl;
//	}
//	void content() {
//		cout << "C++ 学科视频" << endl;
//	}
//};
class Base {
public:
	void header() {
		cout << "首页，公开课，登录注册...（公共头部）" << endl;
	}
	void footer() {
		cout << "帮助中心，交流合作，站内地图...（公共底部）" << endl;
	}
	void left() {
		cout << "Java,Python,C++...(公共分类列表)" << endl;
	}
};
class Java:public Base {
public:
	void content() {
		cout << "Java 学科视频" << endl;
	}
};
class Python :public Base {
public:
	void content() {
		cout << "Python 学科视频" << endl;
	}
};
class CPP :public Base {
public:
	void content() {
		cout << "C++ 学科视频" << endl;
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