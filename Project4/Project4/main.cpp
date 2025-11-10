#include<graphics.h>
#include<iostream>
#include<string>
#include<vector>
int idx_current_anim = 0;
const int PLAYER_ANIM_NUM = 6;
const int PLAYER_SPEED = 5;

const int PLAYER_WIDTH = 80;
const int PLAYER_HEIGHT = 80;
const int SHADOW_WIDTH = 32;


const int WINDOW_WIDTH=1280;
const int WINDOW_HEIGHT=720;

IMAGE img_player_left[PLAYER_ANIM_NUM];
IMAGE img_player_right[PLAYER_ANIM_NUM];

POINT player_pos = { 500,500 };
IMAGE img_shadow;
void putimage_alpha(int x, int y, IMAGE* img);


class Animation
{
public:
	Animation(LPCTSTR path,int num,int interval) {
		interval_ms = interval;
		TCHAR path_file[256];
		for (size_t i = 0; i < num; i++)
		{
			_stprintf_s(path_file, path, i);
			IMAGE* frame = new IMAGE();
			loadimage(frame, path_file);
			frame_list.push_back(frame);
		}
	};
	~Animation() {
		for (size_t i = 0; i < frame_list.size(); i++) {
			delete frame_list[i];
		}

	};
	void Play(int x, int y, int delta) {
		timer += delta;
		if (timer >= interval_ms) {
			idx_frame = (idx_frame + 1) % frame_list.size();
			timer = 0;
		}
		putimage_alpha(x, y, frame_list[idx_frame]);
	}
private:
	std::vector<IMAGE*> frame_list;
	int interval_ms = 0;
	int timer = 0;
	int idx_frame = 0;
};
Animation anim_left_player(_T("img/player_left_%d.png"), 6, 45);
Animation anim_right_player(_T("img/player_right_%d.png"), 6, 45);
void DrawPlayer(int delta, int dir_x) {
	int pos_shadow_x = player_pos.x + (PLAYER_WIDTH / 2 - SHADOW_WIDTH / 2);
	int pos_shadow_y = player_pos.y + PLAYER_HEIGHT -8;

	putimage_alpha(pos_shadow_x, pos_shadow_y, &img_shadow);
	static bool facing_left = false;
	if (dir_x < 0)
		facing_left = true;
	else if (dir_x > 0)
		facing_left = false;

	if (facing_left)
		anim_left_player.Play(player_pos.x, player_pos.y, delta);
	else
		anim_right_player.Play(player_pos.x, player_pos.y, delta);

}

#pragma comment(lib,"MSIMG32.LIB")
inline void putimage_alpha(int x, int y, IMAGE* img) {
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h, GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}
void LoadAnimation() {
	for (size_t i = 0; i < PLAYER_ANIM_NUM; i++) {
		std::wstring path = L"img/player_left_" + std::to_wstring(i) + L".png";
		loadimage(&img_player_left[i], path.c_str());
	}
	for (size_t i = 0; i < PLAYER_ANIM_NUM; i++) {
		std::wstring path = L"img/player_right_" + std::to_wstring(i) + L".png";
		loadimage(&img_player_right[i], path.c_str());
	}
}
int main() {
	initgraph(1280, 720);

	bool running = true;
	ExMessage msg;

	IMAGE img_background;
	bool is_move_up = false;
	bool is_move_down = false;
	bool is_move_left = false;
	bool is_move_right = false;
	loadimage(&img_shadow, _T("img/shadow_player.png"));
	LoadAnimation();
	loadimage(&img_background, _T("img/background.png"));

	BeginBatchDraw();
	while (running) {
		DWORD start_time = GetTickCount();
		while (peekmessage(&msg)) {
			if (msg.message == WM_KEYDOWN) {
				switch (msg.vkcode)
				{
				case VK_UP:
					is_move_up = true;
					break;
				case VK_DOWN:
					is_move_down = true;
					break;
				case VK_LEFT:
					is_move_left = true;
					break;
				case VK_RIGHT:
					is_move_right = true;
					break;
				default:
					break;
				}
			}
			else if (msg.message == WM_KEYUP)
			{
				switch (msg.vkcode)
				{
				case VK_UP:
					is_move_up = false;
					break;
				case VK_DOWN:
					is_move_down = false;
					break;
				case VK_LEFT:
					is_move_left = false;
					break;
				case VK_RIGHT:
					is_move_right = false;
					break;
				default:
					break;
				}
			}
		} 
		if (is_move_up)player_pos.y -= PLAYER_SPEED;
		if (is_move_down)player_pos.y += PLAYER_SPEED;
		if (is_move_left)player_pos.x -= PLAYER_SPEED;
		if (is_move_right)player_pos.x += PLAYER_SPEED;
		static int counter = 0;
		if (++counter % 5==0) {
			idx_current_anim++;
		}
		idx_current_anim = idx_current_anim % PLAYER_ANIM_NUM;
		int dir_x = is_move_right - is_move_left;
		int dir_y = is_move_down - is_move_up;
		double len_dir = sqrt(dir_x * dir_x + dir_y * dir_y);
		if (len_dir != 0) {
			double normalized_x = dir_x / len_dir;
			double normalized_y = dir_y / len_dir;
			player_pos.x += (int)(PLAYER_SPEED * normalized_x);
			player_pos.y += (int)(PLAYER_SPEED * normalized_y);
		}
		if (player_pos.x < 0)player_pos.x = 0;
		if (player_pos.y < 0)player_pos.y = 0;
		if (player_pos.x + PLAYER_WIDTH > WINDOW_WIDTH)player_pos.x = WINDOW_WIDTH - PLAYER_WIDTH;
		if (player_pos.y + PLAYER_HEIGHT > WINDOW_HEIGHT)player_pos.y = WINDOW_HEIGHT - PLAYER_HEIGHT;
		cleardevice();
		putimage_alpha(0, 0, &img_background);
		DrawPlayer(1000 / 180, is_move_right - is_move_left);

		FlushBatchDraw();
		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;
		if (delta_time < 1000 / 180)
		{
			Sleep(1000 / 180 - delta_time);
		}
	}
	EndBatchDraw();
	return 0;
}