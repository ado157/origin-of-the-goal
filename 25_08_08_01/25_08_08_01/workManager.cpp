#include"workManager.h"
Workmanager::Workmanager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArr = NULL;
		this->m_FileIsEmpt = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof() ){
		cout << "文件为空" << endl;
			this->m_EmpNum = 0;
			this->m_EmpArr = NULL;
			this->m_FileIsEmpt = true;
			ifs.close();
			return;
	}
		int num = this->get_Empnum();
		cout << "职工人数为：" << num << endl;
		this->m_EmpNum = num;
		this->m_EmpArr = new Worker * [this->m_EmpNum];
		this->init_Emp();
		for (int i = 0; i < this->m_EmpNum; i++) {
			cout << "职工编号: " << this->m_EmpArr[i]->m_Id
				<< "姓名: " << this->m_EmpArr[i]->m_Name
				<<"部门编号: "<<this->m_EmpArr[i]->m_DepId<<endl;
		}
	//this->m_EmpNum = 0;
	//this->m_EmpArr = NULL;
}
void Workmanager::show_menu() {
	cout << "**************************************" << endl;
	cout << "********欢迎使用职工管理系统！********" << endl;
	cout << "************0.退出管理程序************" << endl;
	cout << "************1.增加职工信息************" << endl;
	cout << "************2.显示职工信息************" << endl;
	cout << "************3.删除离职职工************" << endl;
	cout << "************4.修改职工信息************" << endl;
	cout << "************5.查找职工信息************" << endl;
	cout << "************6.按照编号排序************" << endl;
	cout << "************7.清空所有文档************" << endl;
	cout << "**************************************" << endl;
	cout << endl;
};
void Workmanager::ExitSystem() {
	cout << "已退出" << endl;
	system("pause");
	exit(0);
};
void Workmanager::Add_Emp() {
	cout << "请输入添加数量:" << endl;
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
			cout << "请输入第" << i + 1 << "个新员工的编号:" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新员工的名字:" << endl;
			cin >> name;
			cout << "请输入选择第" << i + 1 << "个新员工的部门:" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
		cout << "添加成功" << endl;
		this->m_FileIsEmpt = false;
		this->save();
		system("pause");
		system("cls");
	}
	else {
		cout << "输入有误 " << endl;
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
		cout << "文件为空" << endl;
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
		cout << "文件不存在" << endl;
	}
	else {
		cout << "请输入要删除的员工编号:" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index == -1) {
			cout << "员工不存在" << endl;
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
		cout << "文件不存在或者为空" << endl;
	}
	else {
		cout << "请输入修改的职工编号" << endl;
		int id;
		cin >> id;
		int ret=this->IsExist(id);
		if (ret != -1) {
			delete this->m_EmpArr[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "请输入新的职工号" << endl;
			cin >> newId;
			cout << "请输入新的姓名" << endl;
			cin >> newName;
			cout << "请输入新的职位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect) {
			case 1:worker = new employee(newId, newName, 1); break;
			case 2:worker = new manager(newId, newName, 2); break;
			case 3:worker = new boss(newId, newName, 3); break;
			default:break;
			}
			this->m_EmpArr[ret] = worker;
			cout << "修改成功" << endl;
			this->save();
		}
		else {
			cout << "查无此人" << endl;
		}

	}
	system("pause");
	system("cls");

};
void Workmanager::find_Emp() {
	if (this->m_FileIsEmpt) {
		cout << "文件不存在" << endl;
	}
	else {
		cout << "选择查找方式" << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			int id;
			cout << "请输入编号" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1) {
				this->m_EmpArr[ret]->showInfo();
			}
			else cout << "编号不存在" << endl;
		}
		else if (select == 2) {
			string name;
			cout << "请输入姓名" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++) {
				if (this->m_EmpArr[i]->m_Name == name) {
					this->m_EmpArr[i]->showInfo();
					flag = true;
				}
			}
			if (!flag) {
				cout << "姓名不存在" << endl; 
			}
		}
		system("pause");
		system("cls");
	}
};
void Workmanager::sort_emp() {
	if (this->m_FileIsEmpt) {
		cout << "文件不存在" << endl;
	}
	else {
		cout << "请选择排序方式:" << endl;
		cout << "1.升序" << endl;
		cout << "2.降序" << endl;
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
	cout << "确认清空" << endl;
	cout<<"1.确认" << endl;
	cout<<"2.返回" << endl;
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
		cout << "清空成功" << endl;

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
