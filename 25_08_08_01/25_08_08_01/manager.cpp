#include"manager.h"
manager::manager(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepId = did;
};
void manager::showInfo() {
	cout << "ְ����ţ� " << this->m_Id
		<< "\tְ������: " << this->m_Name
		<< "\t��λ�� " << this->getDeptName()
		<< "\t��λְ��: �·�����" << endl;
};
string manager::getDeptName() {
	return string("����");
};