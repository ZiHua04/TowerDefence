#
#ifndef TOOLKIT_H
#define TOOLKIT_H


#include <string>

#pragma region 工具函数
auto formatDobleValue(double val, int fixed);
// 判断圆和矩形是否相交
bool isCircleRectangleIntersect(float cx, float cy, float r, float xmin, float ymin, float xmax, float ymax);
// 判断矩形和矩形是否相交
bool DetectTwoRectangle(float x1, float y1, float x2, float y2, int width1, int hight1, int width2, int hight2);
// 左闭右闭区间
int getRand(int min, int max);
bool getRate(float rate);

bool DetectTwoCircle(float x1, float y1, float x2, float y2, int r1, int r2);
// 将 std::string 转换为 std::wstring
std::wstring stringToWString(const std::string& str);

// 在指定坐标 (x, y) 处显示字符串
void drawText(const std::string& text, int x, int y, int fontSize = 20, int color = 0x000000);


#endif // !TOOLKIT_H


	

