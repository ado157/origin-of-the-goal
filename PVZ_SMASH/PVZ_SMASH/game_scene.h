#pragma once
#include"Scene.h"
class GameScene :public Scene
{
public:
	GameScene() = default;
	~GameScene() = default;
	virtual void on_enter()
	{
		std::cout << "进入游戏局内场景" << std::endl;
	}
	virtual void on_update()
	{
		std::cout << "游戏正在运行..." << std::endl;
	}
	virtual void on_draw()
	{
		outtextxy(10, 10, _T("游戏局内绘图内容"));
	}
	virtual void on_input(const ExMessage& msg) { }
	virtual void on_exit()
	{
		std::cout << "游戏局内退出" << std::endl;
	}
private:
};
