#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

#define DEFAULT_BALANCE 5000000

// 显示消息弹窗
void ShowPopup(const char* title, const char* message) {
    MessageBoxA(NULL, message, title, MB_OK);
}

// 获取用户输入金额
int GetInputAmount(const char* title, const char* prompt) {
    char inputStr[100] = { 0 };

    // 使用输入框获取金额
    if (DialogBoxParamA(
        GetModuleHandle(NULL),
        MAKEINTRESOURCEA(1),  // 需要定义对话框资源
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
    sprintf_s(buffer, "当前余额：%d", money);
    ShowPopup("余额查询", buffer);
}

int deposit(int money) {
    int amount = GetInputAmount("存款", "请输入存款金额：");
    if (amount > 0) {
        money += amount;
        inquire(money);
    }
    return money;
}

int withdrawal(int money) {
    int amount = GetInputAmount("取款", "请输入取款金额：");
    if (amount > 0) {
        if (amount <= money) {
            money -= amount;
            inquire(money);
        }
        else {
            ShowPopup("错误", "余额不足！");
            inquire(money);
        }
    }
    return money;
}

// 显示主菜单并获取用户选择
int ShowMainMenu() {
    int choice = MessageBoxA(
        NULL,
        "请选择办理的业务：\n"
        "1. 查询余额\n"
        "2. 存款\n"
        "3. 取款\n"
        "4. 退出",
        "天地银行",
        MB_ICONQUESTION | MB_YESNOCANCEL | MB_DEFBUTTON1
    );

    // 转换MessageBox返回值
    switch (choice) {
    case IDYES: return 1;    // 查询余额
    case IDNO: return 2;     // 存款
    case IDCANCEL: return 3; // 取款
    default: return 4;       // 退出
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
            ShowPopup("提示", "已退出系统！");
            return;
        default:
            ShowPopup("错误", "无效选项！");
            break;
        }
    }
}

int main() {
    BankSystem();
    return 0;
}
