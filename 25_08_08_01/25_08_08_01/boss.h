#pragma once
#include"iostream"
using namespace std;
#include"Worker.h"
class boss :public Worker
{
public:
	boss(int id, string name, int did);
	virtual void showInfo();
	virtual string getDeptName();
};

