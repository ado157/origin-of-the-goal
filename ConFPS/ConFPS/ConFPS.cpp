#include <iostream>
#include<chrono>
#include<Windows.h>
#include<vector>
#include<algorithm>

using namespace std;
//屏幕尺寸
int nScreenWidth = 120;
int nScreenHeight = 40;
//玩家位置
float fPlayerX = 8.0f;
float fPlayerY = 8.0f;
float fPlayerA = 0.0f;
//地图尺寸
int nMapHeight = 16;
int nMapWidth = 16;
//视角大小
float fFOV = 3.14159 / 4.0;

float fDepth = 16.0f;
int main()
{
	//创建屏幕
		wchar_t* screen = new wchar_t[nScreenHeight * nScreenWidth];
		//创建缓冲区，hConsole: 控制台输出句柄
		HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		//设置缓冲区
		SetConsoleActiveScreenBuffer(hConsole);
		//接收实际写入字符数的变量指针
		DWORD dwBytesWritten = 0;
	
		wstring map;
		map += L"################";
		map += L"#..............#";
		map += L"#..............#";
		map += L"#..............#";
		map += L"#..........#...#";
		map += L"#..........#...#";
		map += L"#..............#";
		map += L"#..............#";		
		map += L"#..............#";
		map += L"#..............#";
		map += L"#..............#";
		map += L"#..............#";		
		map += L"#.......########";
		map += L"#..............#";
		map += L"#..............#";
		map += L"################";
		//地图
		auto tp1 = chrono::system_clock::now();
		auto tp2 = chrono::system_clock::now();


			while (true) {
				//移动
				tp2 = chrono::system_clock::now();
				chrono::duration<float>elaspedTime = tp2 - tp1;// 计算两帧之间的时间差
				tp1 = tp2;
				float fElaspedTime = elaspedTime.count();//将时间间隔转换为浮点数（秒）
				if (GetAsyncKeyState((unsigned short)'A') & 0x8000)
					fPlayerA -= (0.8f)*fElaspedTime;
				if (GetAsyncKeyState((unsigned short)'D') & 0x8000)
					fPlayerA += (0.8f)*fElaspedTime;
				if (GetAsyncKeyState((unsigned short)'W') & 0x8000) {
					fPlayerX += sinf(fPlayerA) * 5.0f * fElaspedTime;
					fPlayerY += cosf(fPlayerA) * 5.0f * fElaspedTime;
					if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == '#') {
						fPlayerX -= sinf(fPlayerA) * 5.0f * fElaspedTime;
						fPlayerY -= cosf(fPlayerA) * 5.0f * fElaspedTime;
					}
				}
				if (GetAsyncKeyState((unsigned short)'S') & 0x8000) {
					fPlayerX -= sinf(fPlayerA) * 5.0f * fElaspedTime;
					fPlayerY -= cosf(fPlayerA) * 5.0f * fElaspedTime;
					if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == '#') {
						fPlayerX += sinf(fPlayerA) * 5.0f * fElaspedTime;
						fPlayerY += cosf(fPlayerA) * 5.0f * fElaspedTime;
					}
				}


				for (int x = 0; x < nScreenWidth; x++) {
					//视觉角度
					float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)x / (float)nScreenWidth) * fFOV;
					float fDistanceToWall = 0;//碰撞距离
					bool bHitWall = false;
					bool bBoundary = false;
					float fEyeX = sinf(fRayAngle);
					float fEyeY = cosf(fRayAngle);
					while (!bHitWall&&fDistanceToWall<fDepth) {
						fDistanceToWall += 0.1f;//逐步增加检测是否碰撞
						int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
						int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall);

						//边界检测
						if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight) {
							bHitWall = true;
							fDistanceToWall = fDepth;
						}
						else {
							if (map[nTestY * nMapWidth + nTestX] == '#') {
								bHitWall = true;

								vector<pair<float, float>>p;
								for (int tx = 0; tx < 2; tx++) {
									for (int ty = 0; ty < 2; ty++) {
										float vy = (float)nTestY + ty - fPlayerY;
										float vx = (float)nTestX + tx - fPlayerX;
										float d = sqrt(vx * vx + vy * vy);
										float dot = (fEyeX * vx / d) + (fEyeY * vy / d);
										p.push_back(make_pair(d, dot));
									}
								}
									sort(p.begin(), p.end(), [](const pair<float, float>& left, const pair<float, float>& right) {return left.first < right.first; });
									float fBound = 0.01;
									if (acos(p.at(0).second) < fBound)bBoundary = true;
									if (acos(p.at(1).second) < fBound)bBoundary = true;
									//if (acos(p.at(2).second) < fBound)bBoundary = true;
								
							}
						}
					}

					//天花板和地面以及墙壁
					int nCeiling = (float)(nScreenHeight / 2.0) - nScreenHeight / ((float)fDistanceToWall);
					int nFloor = nScreenHeight - nCeiling;
					//阴影
					short nShade = ' ';
					short nShade1 = ' ';
					if (fDistanceToWall <= fDepth / 4.0f)		nShade = 0x2588;
					else if (fDistanceToWall < fDepth / 3.0f)	nShade = 0x2593;
					else if (fDistanceToWall < fDepth / 2.0f)	nShade = 0x2592;
					else if (fDistanceToWall < fDepth)			nShade = 0x2591;
					else										nShade = ' ';
					if (bBoundary)								nShade = ' ';

					for (int y = 0; y < nScreenHeight;y++) {
						if (y < nCeiling)
							screen[y * nScreenWidth + x] = ' ';
						else if(y > nCeiling && y <= nFloor)
							screen[y * nScreenWidth + x] = nShade;
						else {
							float b = 1.0f - (((float)y - nScreenHeight / 2.0f) / ((float)nScreenHeight / 2.0f));
							if (b < 0.25)		nShade1 = '#';
							else if (b < 0.5)	nShade1 = 'x';
							else if (b < 0.75)	nShade1 = '.';
							else if (b < 0.9)	nShade1 = '-';
							else				nShade1 = ' ';
							screen[y * nScreenWidth + x] = nShade1;

						}
					}
				}
				swprintf_s(screen, 40, L"X=%3.2f, Y=%3.2f, A=%3.2f FPS=%3.2f", fPlayerX, fPlayerY, fPlayerA, 1.0f / fElaspedTime);
				for (int nx = 0; nx < nMapWidth; nx++) {
					for (int ny = 0; ny < nMapWidth; ny++) {
						screen[(ny + 1) * nScreenWidth + nx] = map[ny * nMapWidth + nx];
					}
				}
				screen[((int)fPlayerY + 1) * nScreenWidth + (int)fPlayerX] = 'p';
				//在屏幕缓冲区的最后一个位置添加空字符 \0
				screen[nScreenWidth * nScreenHeight - 1] = '\0';
				//输出到控制台
				WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
			}
}

