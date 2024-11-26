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
		putimagePng(x, y, &ims_upgrade_button[aniId]);
		aniCount++;
		if (aniCount >= ANI_MAX_COUNT) {
			aniCount = 0;
			aniId++;
			aniId %= ims_upgrade_button.size();
		}
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
						if (pair.second->currentGrade < 3)// ������
						{
							show(ClickButtonType::Upgrade, coordinate);
							return;
						}

						// ��������
						return;
					}
				}
				show(ClickButtonType::Build, coordinate);
				return;
			}
			
			// ����������������ǿհ�����
			if (coordinate.row == lastClickCoordinate.row && coordinate.col == lastClickCoordinate.col + 1) {
                // ������ǽ��찴ť���ұ�
				// �����ｨ��
				//towers.insert(std::pair<Coordinate, Tower*>(coordinate, new Tower(TowerType::Attack, coordinate)));
				towers.insert(std::make_pair(lastClickCoordinate, new Tower(TowerType::Attack, lastClickCoordinate)));
			}
			if (coordinate.row == lastClickCoordinate.row && coordinate.col == lastClickCoordinate.col - 1) {
				// ������ǽ��찴ť�����
				// �����ｨ��
				towers.insert(std::make_pair(lastClickCoordinate, new Tower(TowerType::Coin, lastClickCoordinate)));
			}
			hide();
			break;
		case ClickButtonType::Upgrade:


			if ((coordinate.row == lastClickCoordinate.row - 1|| coordinate.row == lastClickCoordinate.row) && coordinate.col == lastClickCoordinate.col) {
				towers[lastClickCoordinate]->upgrade();
			}
			// �ж��Ƿ���Խ���
			if (towerMap[coordinate.row][coordinate.col] == 0) {
				// ���Խ���
				// ����Ƿ��Ѿ�����
				for (const auto& pair : towers) {
					// pair.first �Ǽ� (Coordinate)�� pair.second ��ֵ (Tower*)
					if (pair.first == coordinate) {
						// �����Ѿ�����
						// �ж��Ƿ�������
						if (pair.second->currentGrade < 3) {
							show(ClickButtonType::Upgrade, coordinate);
							return;
						}
						// ��������

						return;
					}
				}
				show(ClickButtonType::Build, coordinate);
				break;
			}

			hide();
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
						if (pair.second->currentGrade < 3) {
							show(ClickButtonType::Upgrade, coordinate);
							return;
						}
						// ��������

						return;
					}
				}
				show(ClickButtonType::Build, coordinate);
				break;
			}
			
            // ����������������ǿհ�����
			break;
	default:
		break;
	}
	

	
}

void ClickButton::show(ClickButtonType type, Coordinate coordinate)
{
	lastClickCoordinate = coordinate;
	this->type = type;
	switch (type) {
		case ClickButtonType::Build:
			
			this->width = 80 * 2 + BLOCK_WIDTH;
			this->height = BLOCK_HEIGHT;
			this->x = coordinate.col * BLOCK_WIDTH + BLOCK_WIDTH / 2 - this->width / 2;
			this->y = coordinate.row * BLOCK_HEIGHT;
			break;
		case ClickButtonType::Upgrade:

			this->width = BLOCK_WIDTH;
			this->height = BLOCK_HEIGHT * 2;
			this->x = coordinate.col * BLOCK_WIDTH;
			this->y = coordinate.row * BLOCK_HEIGHT - BLOCK_HEIGHT;
			break;
	}
}

void ClickButton::hide()
{
	this->type = ClickButtonType::Hide;
}
