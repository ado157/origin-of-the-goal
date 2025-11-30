#pragma once
#include"atlas.h"
#include"animation.h"
#include"Scene.h"
#include"scene_manager.h"
#include"Camera.h"
#include"timer.h"
#include<iostream>
extern IMAGE img_menu_background;
extern SceneManager scene_manager;

//extern Atlas atlas_peashooter_run_right;
class MenuScene:public Scene
{
public:
	MenuScene() = default;
	~MenuScene() = default;
	/*virtual*/ void on_enter() 
	{

		mciSendString(_T("play bgm_menu repeat from 0"), NULL, 0, NULL);
		/*animation_peashooter_run_right.set_atlas(&atlas_peashooter_run_right);
		animation_peashooter_run_right.set_interval(75);
		animation_peashooter_run_right.set_loop(true);

		timer.set_wait_time(1000);
		timer.set_one_shot(false);
		timer.set_callback([]()
			{
				std::cout << "Shot!" << std::endl;
			}
		);*/
		//animation_peashooter_run_right.set_callback(
		//	[]()
		//	{
		//		scene_manager.switch_to(SceneManager::SceneType::Game);
		//	}
		//);

	}

	///*virtual*/ void on_update(int delta) 
	//{


	//	//timer.on_update(delta);
	//	//camera.on_updata(delta);
	//	//animation_peashooter_run_right.on_update(delta);

	//}

	/*virtual*/ void on_draw(const Camera& camera) 
	{
		putimage(0, 0, &img_menu_background);

		//const Vector2& pos_camera = camera.get_position();
		//animation_peashooter_run_right.on_draw((int)(100-pos_camera.x), (int)(100-pos_camera.y));

	}
	/*virtual*/ void on_input(const ExMessage& msg) 
	{ 
		if (msg.message == WM_KEYUP) {
			mciSendString(_T("play ui_confirm from 0"), NULL, 0, NULL);
			scene_manager.switch_to(SceneManager::SceneType::Selector);
		}

		//	if (msg.message == WM_KEYDOWN) {
	//		//scene_manager.switch_to(SceneManager::SceneType::Game);
	//		camera.shake(10, 350);
	//}

	}
	/*virtual*/ void on_exit() 
	{ 


		//11
		//std::cout << "Ö÷²Ëµ¥ÍË³ö" << std::endl;

	}
private:


	//Timer timer;
	//Animation animation_peashooter_run_right;
	//Camera camera;
};