#include"employee.h"
employee::employee(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
};
void employee::showInfo() {
	cout << "ְ����ţ� " << this->m_Id
		<< "\tְ������: " << this->m_Name
		<< "\t��λ�� " << this->getDeptName()
		<< "\t��λְ��: ���ҵ��" << endl;
};
string employee::getDeptName() {
	return string("Ա��");
};