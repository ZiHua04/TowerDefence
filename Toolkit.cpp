#include "Toolkit.h"
#include <format>
#include <random>
#include <graphics.h>
#pragma region ���ߺ���
auto formatDobleValue(double val, int fixed) {
	auto str = std::to_string(val);
	return str.substr(0, str.find(".") + fixed + 1);
}
// �ж�Բ�;����Ƿ��ཻ
bool isCircleRectangleIntersect(float cx, float cy, float r, float xmin, float ymin, float xmax, float ymax) {
	// ����Բ�ĵ����ε������
	double closestX = cx;
	double closestY = cy;

	// �ж� x ����
	if (cx < xmin) {
		closestX = xmin;
	}
	else if (cx > xmax) {
		closestX = xmax;
	}

	// �ж� y ����
	if (cy < ymin) {
		closestY = ymin;
	}
	else if (cy > ymax) {
		closestY = ymax;
	}

	// ����Բ�ĵ������ľ���
	double dx = cx - closestX;
	double dy = cy - closestY;
	double distance = sqrt(dx * dx + dy * dy);

	// �������С�ڵ���Բ�İ뾶�����ཻ
	if (distance <= r) {
		return 1; // �ཻ
	}

	return 0; // ���ཻ
}
// ����ұ�����
int getRand(int min, int max) {
	// ��������豸����������Ӳ�����������
	std::random_device rd;

	// ʹ������豸��ʼ����������棨mt19937��
	std::mt19937 gen(rd());

	// ����һ�����ȷֲ�������ΧΪ[min, max]
	std::uniform_int_distribution<> distr(min, max);

	// �������ɵ������
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
	// �����������ε��ұ߽���±߽�
	float rect1_right = x1 + width1;
	float rect1_bottom = y1 + hight1;
	float rect2_right = x2 + width2;
	float rect2_bottom = y2 + hight2;
	// �ж��Ƿ����ཻ����
	return !(rect1_right < x2 ||    // ��һ��������ȫ�ڵڶ����������
		x1 > rect2_right ||    // ��һ��������ȫ�ڵڶ��������ұ�
		rect1_bottom < y2 ||   // ��һ��������ȫ�ڵڶ�����������
		y1 > rect2_bottom);    // ��һ��������ȫ�ڵڶ�����������
}
bool DetectTwoCircle(float x1, float y1, float x2, float y2, int r1, int r2) {
	return  DetectTwoRectangle(x1 - r1, y1 - r1, x2 - r2, y2 - r2, r1 * 2, r1 * 2, r2 * 2, r2 * 2);

}
// �� std::string ת��Ϊ std::wstring
std::wstring stringToWString(const std::string& str) {
	int len;
	int slength = (int)str.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), slength, 0, 0);
	std::wstring wstr(len, L'\0');
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), slength, &wstr[0], len);
	return wstr;
}

// ��ָ������ (x, y) ����ʾ�ַ���
void drawText(const std::string& text, int x, int y, int fontSize) {
	std::wstring wtext = stringToWString(text);  // ת�� std::string Ϊ std::wstring
	setbkmode(TRANSPARENT);
	settextstyle(fontSize, 0, _T("����"));//�����ֺš�����
	outtextxy(x, y, wtext.c_str());              // ʹ�� outtextxy ���ƿ��ַ��ַ���
	
}
#pragma endregion