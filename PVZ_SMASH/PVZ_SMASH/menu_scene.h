#pragma once
#include"Scene.h"
class MenuScene:public Scene
{
public:
	MenuScene() = default;
	~MenuScene() = default;
	virtual void on_enter() 
	{
		std::cout << "进入主菜单" << std::endl;
	}
	virtual void on_update() 
	{
		std::cout << "主菜单正在运行..." << std::endl;
	}
	virtual void on_draw() 
	{
		outtextxy(10, 10, _T("主菜单绘图内容"));
	}
	virtual void on_input(const ExMessage& msg) { }
	virtual void on_exit() 
	{ 
		std::cout << "主菜单退出" << std::endl;
	}
private:
};