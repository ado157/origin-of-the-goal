#include"workManager.h"
Workmanager::Workmanager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArr = NULL;
		this->m_FileIsEmpt = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof() ){
		cout << "�ļ�Ϊ��" << endl;
			this->m_EmpNum = 0;
			this->m_EmpArr = NULL;
			this->m_FileIsEmpt = true;
			ifs.close();
			return;
	}
		int num = this->get_Empnum();
		cout << "ְ������Ϊ��" << num << endl;
		this->m_EmpNum = num;
		this->m_EmpArr = new Worker * [this->m_EmpNum];
		this->init_Emp();
		for (int i = 0; i < this->m_EmpNum; i++) {
			cout << "ְ�����: " << this->m_EmpArr[i]->m_Id
				<< "����: " << this->m_EmpArr[i]->m_Name
				<<"���ű��: "<<this->m_EmpArr[i]->m_DepId<<endl;
		}
	//this->m_EmpNum = 0;
	//this->m_EmpArr = NULL;
}
void Workmanager::show_menu() {
	cout << "**************************************" << endl;
	cout << "********��ӭʹ��ְ������ϵͳ��********" << endl;
	cout << "************0.�˳��������************" << endl;
	cout << "************1.����ְ����Ϣ************" << endl;
	cout << "************2.��ʾְ����Ϣ************" << endl;
	cout << "************3.ɾ����ְְ��************" << endl;
	cout << "************4.�޸�ְ����Ϣ************" << endl;
	cout << "************5.����ְ����Ϣ************" << endl;
	cout << "************6.���ձ������************" << endl;
	cout << "************7.��������ĵ�************" << endl;
	cout << "**************************************" << endl;
	cout << endl;
};
void Workmanager::ExitSystem() {
	cout << "���˳�" << endl;
	system("pause");
	exit(0);
};
void Workmanager::Add_Emp() {
	cout << "�������������:" << endl;
	int add_Num = 0;
	cin >> add_Num;
	if (add_Num > 0) {
		int newSize = this->m_EmpNum + add_Num;
		Worker** newSpace = new Worker * [newSize];
		if (this->m_EmpArr != NULL) {
			for(int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArr[i];
			}
		}
		for (int i = 0; i < add_Num; i++) {
			int id;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "����Ա���ı��:" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����Ա��������:" << endl;
			cin >> name;
			cout << "������ѡ���" << i + 1 << "����Ա���Ĳ���:" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect) {
			case 1:worker = new employee(id, name, 1); break;
			case 2:worker = new manager(id, name, 2); break;
			case 3:worker = new boss(id, name, 3); break;
			default:break;
			}
			newSpace[this->m_EmpNum+i] = worker;
		}
		delete[]this->m_EmpArr;
		this->m_EmpArr = newSpace;
		this->m_EmpNum = newSize;
		cout << "��ӳɹ�" << endl;
		this->m_FileIsEmpt = false;
		this->save();
		system("pause");
		system("cls");
	}
	else {
		cout << "�������� " << endl;
	}
};
void Workmanager::save() {
	ofstream ofs; 
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArr[i]->m_Id << " "
			<< this->m_EmpArr[i]->m_Name << " "
			<< this->m_EmpArr[i]->m_DepId << endl;
	}
	ofs.close();
};
int Workmanager::get_Empnum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>>did) {
		num++;
	}
	return num;
}
void Workmanager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		Worker* worker = NULL;
		if (did == 1) {
			worker = new employee(id, name, did);
		}
		else if (did == 2) {
			worker = new manager(id, name, did);
		}
		else if (did == 3) {
			worker = new boss(id, name, did);

		}
		this->m_EmpArr[index++] = worker;
	}
	ifs.close();
};

void Workmanager::show_Emp() {
	if (this->m_FileIsEmpt) {
		cout << "�ļ�Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			this->m_EmpArr[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
int Workmanager::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArr[i]->m_Id == id) {
			index = i;
			break;
		}
	}
	return index;
};
void Workmanager::Del_Emp() {
	if (this->m_FileIsEmpt) {
		cout << "�ļ�������" << endl;
	}
	else {
		cout << "������Ҫɾ����Ա�����:" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index == -1) {
			cout << "Ա��������" << endl;
		}
		else {
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArr[i] = this->m_EmpArr[i + 1];
			}
			this->m_EmpNum--;
			this->save();
		}
		system("pausse");
		system("cls");

	}
};
void Workmanager::Mod_Emp() {
	if (this->m_FileIsEmpt) {
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else {
		cout << "�������޸ĵ�ְ�����" << endl;
		int id;
		cin >> id;
		int ret=this->IsExist(id);
		if (ret != -1) {
			delete this->m_EmpArr[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "�������µ�ְ����" << endl;
			cin >> newId;
			cout << "�������µ�����" << endl;
			cin >> newName;
			cout << "�������µ�ְλ" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect) {
			case 1:worker = new employee(newId, newName, 1); break;
			case 2:worker = new manager(newId, newName, 2); break;
			case 3:worker = new boss(newId, newName, 3); break;
			default:break;
			}
			this->m_EmpArr[ret] = worker;
			cout << "�޸ĳɹ�" << endl;
			this->save();
		}
		else {
			cout << "���޴���" << endl;
		}

	}
	system("pause");
	system("cls");

};
void Workmanager::find_Emp() {
	if (this->m_FileIsEmpt) {
		cout << "�ļ�������" << endl;
	}
	else {
		cout << "ѡ����ҷ�ʽ" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.��ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			int id;
			cout << "��������" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1) {
				this->m_EmpArr[ret]->showInfo();
			}
			else cout << "��Ų�����" << endl;
		}
		else if (select == 2) {
			string name;
			cout << "����������" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++) {
				if (this->m_EmpArr[i]->m_Name == name) {
					this->m_EmpArr[i]->showInfo();
					flag = true;
				}
			}
			if (!flag) {
				cout << "����������" << endl; 
			}
		}
		system("pause");
		system("cls");
	}
};
void Workmanager::sort_emp() {
	if (this->m_FileIsEmpt) {
		cout << "�ļ�������" << endl;
	}
	else {
		cout << "��ѡ������ʽ:" << endl;
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++) {
			int minORmax = i;
			for (int j = i + 1; j < m_EmpNum; j++) {

				if (select == 1) {
					if (this->m_EmpArr[minORmax]->m_Id > this->m_EmpArr[j]->m_Id) {
						minORmax = j;
					}
				}
				else {
					if (this->m_EmpArr[minORmax]->m_Id < this->m_EmpArr[j]->m_Id) {
						minORmax = j;
					}
				}
			}
			if (i != minORmax) {
				Worker* temp = this->m_EmpArr[i];
				this->m_EmpArr[i] = this->m_EmpArr[minORmax];
				this->m_EmpArr[minORmax] = temp;
			}
		}
		this->save();
		this->show_Emp();
	}
};
void Workmanager::clean_file() {
	cout << "ȷ�����" << endl;
	cout<<"1.ȷ��" << endl;
	cout<<"2.����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArr != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				delete this->m_EmpArr[i];
				this->m_EmpArr[i] = NULL;
			}
			delete[] this->m_EmpArr;
			this->m_EmpArr = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpt = true;
		}
		cout << "��ճɹ�" << endl;

	}
		system("pause");
		system("cls");
};

	Workmanager::~Workmanager(){
		if (this->m_EmpArr != NULL) {
			delete[] this->m_EmpArr;
			this->m_EmpArr = NULL;
		}
	};
