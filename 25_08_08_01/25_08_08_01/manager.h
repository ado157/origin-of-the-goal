#pragma once
#include"iostream"
using namespace std;
#include"Worker.h"
class manager :public Worker
{
public:
	manager(int id, string name, int did);
	virtual void showInfo();
	virtual string getDeptName();
};
