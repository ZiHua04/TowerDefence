#
#ifndef TOOLKIT_H
#define TOOLKIT_H


#include <string>

#pragma region ���ߺ���
auto formatDobleValue(double val, int fixed);
// �ж�Բ�;����Ƿ��ཻ
bool isCircleRectangleIntersect(float cx, float cy, float r, float xmin, float ymin, float xmax, float ymax);
// ����ұ�����
int getRand(int min, int max);
bool getRate(float rate);
bool DetectTwoRectangle(float x1, float y1, float x2, float y2, int width1, int hight1, int width2, int hight2);
bool DetectTwoCircle(float x1, float y1, float x2, float y2, int r1, int r2);
// �� std::string ת��Ϊ std::wstring
std::wstring stringToWString(const std::string& str);

// ��ָ������ (x, y) ����ʾ�ַ���
void drawText(const std::string& text, int x, int y, int fontSize);


#endif // !TOOLKIT_H


	

