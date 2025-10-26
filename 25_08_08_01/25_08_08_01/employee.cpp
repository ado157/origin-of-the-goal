#include"employee.h"
employee::employee(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
};
void employee::showInfo() {
	cout << "职工编号： " << this->m_Id
		<< "\t职工姓名: " << this->m_Name
		<< "\t岗位： " << this->getDeptName()
		<< "\t岗位职责: 完成业务" << endl;
};
string employee::getDeptName() {
	return string("员工");
};