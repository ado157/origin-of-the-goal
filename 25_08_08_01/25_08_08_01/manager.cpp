#include"manager.h"
manager::manager(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
};
void manager::showInfo() {
	cout << "职工编号： " << this->m_Id
		<< "\t职工姓名: " << this->m_Name
		<< "\t岗位： " << this->getDeptName()
		<< "\t岗位职责: 下发任务" << endl;
};
string manager::getDeptName() {
	return string("经理");
};