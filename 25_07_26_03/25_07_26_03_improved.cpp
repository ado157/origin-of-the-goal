#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

#define DEFAULT_BALANCE 5000000

// ��ʾ��Ϣ����
void ShowPopup(const char* title, const char* message) {
    MessageBoxA(NULL, message, title, MB_OK);
}

// ��ȡ�û�������
int GetInputAmount(const char* title, const char* prompt) {
    char inputStr[100] = { 0 };

    // ʹ��������ȡ���
    if (DialogBoxParamA(
        GetModuleHandle(NULL),
        MAKEINTRESOURCEA(1),  // ��Ҫ����Ի�����Դ
        NULL,
        [](HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam) -> INT_PTR {
            if (msg == WM_INITDIALOG) {
                SetWindowTextA(hDlg, (LPCSTR)lParam);
                return TRUE;
            }
            else if (msg == WM_COMMAND && LOWORD(wParam) == IDOK) {
                char amount[100];
                GetDlgItemTextA(hDlg, 1001, amount, 100);
                EndDialog(hDlg, atoi(amount));
                return TRUE;
            }
            return FALSE;
        },
        (LPARAM)title) > 0) {
        return atoi(inputStr);
    }
    return 0;
}

void inquire(int money) {
    char buffer[100];
    sprintf_s(buffer, "��ǰ��%d", money);
    ShowPopup("����ѯ", buffer);
}

int deposit(int money) {
    int amount = GetInputAmount("���", "���������");
    if (amount > 0) {
        money += amount;
        inquire(money);
    }
    return money;
}

int withdrawal(int money) {
    int amount = GetInputAmount("ȡ��", "������ȡ���");
    if (amount > 0) {
        if (amount <= money) {
            money -= amount;
            inquire(money);
        }
        else {
            ShowPopup("����", "���㣡");
            inquire(money);
        }
    }
    return money;
}

// ��ʾ���˵�����ȡ�û�ѡ��
int ShowMainMenu() {
    int choice = MessageBoxA(
        NULL,
        "��ѡ������ҵ��\n"
        "1. ��ѯ���\n"
        "2. ���\n"
        "3. ȡ��\n"
        "4. �˳�",
        "�������",
        MB_ICONQUESTION | MB_YESNOCANCEL | MB_DEFBUTTON1
    );

    // ת��MessageBox����ֵ
    switch (choice) {
    case IDYES: return 1;    // ��ѯ���
    case IDNO: return 2;     // ���
    case IDCANCEL: return 3; // ȡ��
    default: return 4;       // �˳�
    }
}

void BankSystem() {
    int money = DEFAULT_BALANCE;
    while (true) {
        int choice = ShowMainMenu();
        switch (choice) {
        case 1: inquire(money); break;
        case 2: money = deposit(money); break;
        case 3: money = withdrawal(money); break;
        case 4:
            ShowPopup("��ʾ", "���˳�ϵͳ��");
            return;
        default:
            ShowPopup("����", "��Чѡ�");
            break;
        }
    }
}

int main() {
    BankSystem();
    return 0;
}
