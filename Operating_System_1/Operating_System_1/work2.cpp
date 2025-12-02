//
//#include <graphics.h>
//#include <thread>
//#include <mutex>
//#include <chrono>
//#include <cmath>
//#include <iostream>
//
//using namespace std;
//
//mutex draw_mutex;
//
//#ifndef M_PI
//#define M_PI 3.14159265358979323846
//#endif
//
//void draw_point(int x, int y, COLORREF color) {
//    lock_guard<mutex> lk(draw_mutex);
//    setfillcolor(color);
//    solidcircle(x, y, 1);
//}
//
//// 画圆
//void draw_circle(int cx, int cy, int radius, COLORREF color) {
//    const int N = 720;
//    for (int i = 0; i < N; ++i) {
//        double angle = 2.0 * M_PI * i / N;
//        int x = int(cx + radius * cos(angle) + 0.5);
//        int y = int(cy + radius * sin(angle) + 0.5);
//        draw_point(x, y, color);
//
//        this_thread::sleep_for(chrono::milliseconds(400)); 
//    }
//}
//
//// 画正方形
//void draw_square(int cx, int cy, int side, COLORREF color) {
//    const int N = 720;
//    int per = N / 4;
//    int half = side / 2;
//
//    for (int i = 0; i < per; ++i) {  // 上
//        double t = double(i) / per;
//        int x = int((cx - half) + t * side + 0.5);
//        int y = cy - half;
//        draw_point(x, y, color);
//        this_thread::sleep_for(chrono::milliseconds(400));
//    }
//    for (int i = 0; i < per; ++i) {  // 右
//        double t = double(i) / per;
//        int x = cx + half;
//        int y = int((cy - half) + t * side + 0.5);
//        draw_point(x, y, color);
//        this_thread::sleep_for(chrono::milliseconds(400));
//    }
//    for (int i = 0; i < per; ++i) {  // 下
//        double t = double(i) / per;
//        int x = int((cx + half) - t * side + 0.5);
//        int y = cy + half;
//        draw_point(x, y, color);
//        this_thread::sleep_for(chrono::milliseconds(400));
//    }
//    for (int i = 0; i < per; ++i) {  // 左
//        double t = double(i) / per;
//        int x = cx - half;
//        int y = int((cy + half) - t * side + 0.5);
//        draw_point(x, y, color);
//        this_thread::sleep_for(chrono::milliseconds(400));
//    }
//}
//
//int main() {
//    initgraph(800, 800);
//    setbkcolor(WHITE);
//    cleardevice();
//
//    thread t1(draw_circle, 200, 200, 150, RED);
//    thread t2(draw_square, 520, 420, 300, BLUE);
//
//    t1.join();
//    t2.join();
//
//    cout << "绘制完成，按回车退出..." << endl;
//    getchar();
//    closegraph();
//    return 0;
//}
