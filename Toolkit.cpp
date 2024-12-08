#include "Toolkit.h"
#include <format>
#include <random>
#include <graphics.h>
#pragma region 工具函数
auto formatDobleValue(double val, int fixed) {
	auto str = std::to_string(val);
	return str.substr(0, str.find(".") + fixed + 1);
}
// 判断圆和矩形是否相交
bool isCircleRectangleIntersect(float cx, float cy, float r, float xmin, float ymin, float xmax, float ymax) {
	// 计算圆心到矩形的最近点
	double closestX = cx;
	double closestY = cy;

	// 判断 x 坐标
	if (cx < xmin) {
		closestX = xmin;
	}
	else if (cx > xmax) {
		closestX = xmax;
	}

	// 判断 y 坐标
	if (cy < ymin) {
		closestY = ymin;
	}
	else if (cy > ymax) {
		closestY = ymax;
	}

	// 计算圆心到最近点的距离
	double dx = cx - closestX;
	double dy = cy - closestY;
	double distance = sqrt(dx * dx + dy * dy);

	// 如果距离小于等于圆的半径，则相交
	if (distance <= r) {
		return 1; // 相交
	}

	return 0; // 不相交
}
// 左闭右闭区间
int getRand(int min, int max) {
	// 创建随机设备，用于生成硬件随机数种子
	std::random_device rd;

	// 使用随机设备初始化随机数引擎（mt19937）
	std::mt19937 gen(rd());

	// 定义一个均匀分布器，范围为[min, max]
	std::uniform_int_distribution<> distr(min, max);

	// 返回生成的随机数
	return distr(gen);
}
bool getRate(float rate) {
	if (rate >= 1)return true;
	if (rate <= 0) return false;
	int randNum = getRand(0, 99);
	if (rate * 100 >= randNum) return true;
	return false;

}
bool DetectTwoRectangle(float x1, float y1, float x2, float y2, int width1, int hight1, int width2, int hight2) {
	// 计算两个矩形的右边界和下边界
	float rect1_right = x1 + width1;
	float rect1_bottom = y1 + hight1;
	float rect2_right = x2 + width2;
	float rect2_bottom = y2 + hight2;
	// 判断是否有相交区域
	return !(rect1_right < x2 ||    // 第一个矩形完全在第二个矩形左边
		x1 > rect2_right ||    // 第一个矩形完全在第二个矩形右边
		rect1_bottom < y2 ||   // 第一个矩形完全在第二个矩形上面
		y1 > rect2_bottom);    // 第一个矩形完全在第二个矩形下面
}
bool DetectTwoCircle(float x1, float y1, float x2, float y2, int r1, int r2) {
	return  DetectTwoRectangle(x1 - r1, y1 - r1, x2 - r2, y2 - r2, r1 * 2, r1 * 2, r2 * 2, r2 * 2);

}
// 将 std::string 转换为 std::wstring
std::wstring stringToWString(const std::string& str) {
	int len;
	int slength = (int)str.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), slength, 0, 0);
	std::wstring wstr(len, L'\0');
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), slength, &wstr[0], len);
	return wstr;
}

// 在指定坐标 (x, y) 处显示字符串
void drawText(const std::string& text, int x, int y, int fontSize) {
	std::wstring wtext = stringToWString(text);  // 转换 std::string 为 std::wstring
	setbkmode(TRANSPARENT);
	settextstyle(fontSize, 0, _T("黑体"));//设置字号、字体
	outtextxy(x, y, wtext.c_str());              // 使用 outtextxy 绘制宽字符字符串
	
}
#pragma endregion