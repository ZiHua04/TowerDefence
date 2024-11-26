#include "ClickButton.h"
#include "EasyXPng.h"
#include "Images.h"
#include "Global.h"
// ���캯��
ClickButton::ClickButton()
{
	// ����ͼƬ


	type = ClickButtonType::Hide;
}

void ClickButton::draw()
{
	if (this->type == ClickButtonType::Hide) return;
	switch (type)
	{
	case ClickButtonType::Build:
		putimagePng(x, y, &im_build);
		break;
	case ClickButtonType::Upgrade:
		break;
	default:
		break;
	}
}
void ClickButton::update()
{
	draw();
}
/*���ĳһ���飬�п��ܳ�����Ч������У�
1 - �ɽ��죬�����졣 
2 - �ɽ��죬�ѽ��죬��������
3 - �ɽ��죬�ѽ��죬����������
4 - ���찴ť���������ߡ� 
5 - ������ť���Ϸ�*/
void ClickButton::clickCoordinate(Coordinate coordinate)
{
	

	switch (this->type)
	{
		case ClickButtonType::Build:
			// �ж��Ƿ���Խ���
			if (towerMap[coordinate.row][coordinate.col] == 0) {
				// ���Խ���
				// ����Ƿ��Ѿ�����
				for (const auto& pair : towers) {
					// pair.first �Ǽ� (Coordinate)�� pair.second ��ֵ (Tower*)
					if (pair.first == coordinate) {
						// �����Ѿ�����
						// �ж��Ƿ�������

						// ��������
						return;
					}
				}
				show(ClickButtonType::Build, coordinate);
				break;
			}
			// ���ɽ���, �ж��ж��Ƿ��������
			if (false) {
				break;
			}
			// ����������������ǿհ�����
			if (coordinate.row == lastClickCoordinate.row && coordinate.col == lastClickCoordinate.col + 1) {
                // ������ǽ��찴ť���ұ�
				// �����ｨ��
				//towers.insert(std::pair<Coordinate, Tower*>(coordinate, new Tower(TowerType::Attack, coordinate)));
				towers.insert(std::make_pair(lastClickCoordinate, new Tower(TowerType::Attack, lastClickCoordinate)));
			}
			hide();
			break;
		case ClickButtonType::Upgrade:

			break;
        case ClickButtonType::Hide:
			// �ж��Ƿ���Խ���
			if (towerMap[coordinate.row][coordinate.col] == 0) {
				// ���Խ���
				// ����Ƿ��Ѿ�����
				for (const auto& pair : towers) {
					// pair.first �Ǽ� (Coordinate)�� pair.second ��ֵ (Tower*)
					if (pair.first == coordinate) {
						// �����Ѿ�����
						// �ж��Ƿ�������

						// ��������
						return;
					}
				}
				show(ClickButtonType::Build, coordinate);
				break;
			}
			// ���ɽ���, �ж��ж��Ƿ��������
			if (false) {
				break;
			}
            // ����������������ǿհ�����
			break;
	default:
		break;
	}
	

	lastClickCoordinate = coordinate;
}

void ClickButton::show(ClickButtonType type, Coordinate coordinate)
{
	this->type = type;
	switch (type) {
		case ClickButtonType::Build:
			
			this->width = 80 * 2 + BLOCK_WIDTH;
			this->height = BLOCK_HEIGHT;
			this->x = coordinate.col * BLOCK_WIDTH + BLOCK_WIDTH / 2 - this->width / 2;
			this->y = coordinate.row * BLOCK_HEIGHT;
			break;
		case ClickButtonType::Upgrade:

			break;
	}
}

void ClickButton::hide()
{
	this->type = ClickButtonType::Hide;
}