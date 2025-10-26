#include"iostream"
#include"workManager.h"
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;
int main() {
	Worker* worker = NULL;
	worker = new employee(1, "111", 1);
	worker->showInfo();
	delete worker;
	worker = new manager(2, "222", 2);
	worker->showInfo();	
	delete worker;
	worker = new boss(3, "333", 3);
	worker->showInfo();

	Workmanager wm;
	int choice = 0;
	while (true) {
		wm.show_menu();
		cout << "ÇëÑ¡Ôñ¹¦ÄÜ:" << endl;
		cin >> choice;
		switch (choice) {
		case 0:wm.ExitSystem(); break;
		case 1:wm.Add_Emp(); break;
		case 2:wm.show_Emp(); break;
		case 3:wm.Del_Emp(); break;
		case 4:wm.Mod_Emp(); break;
		case 5:wm.find_Emp(); break;
		case 6:wm.sort_emp(); break;
		case 7: break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}