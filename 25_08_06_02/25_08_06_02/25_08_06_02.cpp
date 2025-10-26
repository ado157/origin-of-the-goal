#include "iostream"
using namespace std;
class Calculator {
public:
	virtual int getResult() {
		return 0; 
	}
	int num1;
	int num2;
};
class AddCalculator :public Calculator {
public:
	int getResult() {
		return num1 + num2;
	}
};
class subCalculator :public Calculator {
public:
	int getResult() {
		return num1 - num2;
	}
};
class mulCalculator :public Calculator {
public:
	int getResult() {
		return num1 * num2;
	}
};
void test1()
{
	Calculator* abc = new AddCalculator;
	abc->num1 = 10;
	abc->num2 = 11;
	cout << abc->num1 << "+" << abc->num2 << "=" << abc->getResult() << endl;
}
	int main() {
		test1();
}