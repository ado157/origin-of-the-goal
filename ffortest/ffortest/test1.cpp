#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

// 平滑插值函数
float lerp(float a, float b, float t) {
    return a + t * (b - a);
}

// 平滑映射函数
float fade(float t) {
    return t * t * t * (t * (t * 6 - 15) + 10);
}

// 梯度函数
float grad(int hash, float x) {
    return (hash & 1) ? x : -x;
}

// 1D Perlin Noise
float perlin(float x) {
    int xi = (int)floor(x) & 255;   // 网格坐标
    float xf = x - floor(x);        // 小数部分
    float u = fade(xf);             // 平滑曲线

    // 随机排列
    static int permutation[256] = {
        151,160,137,91,90,15,
        131,13,201,95,96,53,194,233,7,225,140,36,103,30,
        69,142, // 省略一些，剩下的重复一份
    };
    static bool initialized = false;
    static int p[512];

    if (!initialized) {
        for (int i = 0; i < 256; i++) p[256 + i] = p[i] = permutation[i % 20];
        initialized = true;
    }

    int a = p[xi];
    int b = p[xi + 1];

    return lerp(grad(a, xf), grad(b, xf - 1.0f), u);
}

int main() {
    const int width = 80;
    const int height = 25;
    const float scale = 0.15f;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            float n = perlin(x * scale);  // 得到噪声值 -1~1
            int lvl = (int)((n + 1) * 5); // 映射到 0~10

            // 使用不同字符展示高度层
            const char shades[] = " .:-=+*#%@";
            cout << shades[lvl];
        }
        cout << endl;
    }
    return 0;
}
