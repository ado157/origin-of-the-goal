#pragma once
#include"Worker.h"
class employee :public Worker {
public:
	employee(int id,string name,int did);
	virtual void showInfo();
	virtual string getDeptName();
};
