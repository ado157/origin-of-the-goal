#pragma once
#include"iostream"
using namespace std;
#include "Worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include"fstream"
#define FILENAME "empFile.txt"


class Workmanager {
public:
	Workmanager();
	void show_menu();
	void ExitSystem();
	int m_EmpNum;
	Worker** m_EmpArr;
	void Add_Emp();
	void save();
	bool m_FileIsEmpt;
	int get_Empnum();
	void init_Emp();
	void show_Emp();
	int IsExist(int id);
	void Del_Emp();
	void Mod_Emp();
	void find_Emp();
	void sort_emp();
	void clean_file();
	~Workmanager();
}; 
