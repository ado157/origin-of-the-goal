#pragma once
#include"atlas.h"
#include"animation.h"
#include"Scene.h"
#include"scene_manager.h"
#include<iostream>
extern Atlas atlas_peashooter_run_right;
extern SceneManager scene_manager;
class MenuScene:public Scene
{
public:
	MenuScene() = default;
	~MenuScene() = default;
	/*virtual*/ void on_enter() 
	{
		animation_peashooter_run_right.set_atlas(&atlas_peashooter_run_right);
		animation_peashooter_run_right.set_interval(75);
		animation_peashooter_run_right.set_loop(true);
		animation_peashooter_run_right.set_callback(
			[]()
			{
				scene_manager.switch_to(SceneManager::SceneType::Game);
			}
		);
	}
	/*virtual*/ void on_update(int delta) 
	{
		animation_peashooter_run_right.on_update(delta);
	}
	/*virtual*/ void on_draw() 
	{
		animation_peashooter_run_right.on_draw(100, 100);
	}
	/*virtual*/ void on_input(const ExMessage& msg) { 
		if (msg.message == WM_KEYDOWN) {
			scene_manager.switch_to(SceneManager::SceneType::Game);
	}
	}
	/*virtual*/ void on_exit() 
	{ 
		std::cout << "Ö÷²Ëµ¥ÍË³ö" << std::endl;
	}
private:
	Animation animation_peashooter_run_right;
};