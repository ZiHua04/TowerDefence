#include "ClickButton.h"
#include "EasyXPng.h"
#include "Images.h"
#include "Global.h"
#include "Toolkit.h"
// ���캯��
ClickButton::ClickButton()
{
	// ����ͼƬ


	type = ClickButtonType::Hide;
}

void ClickButton::draw()
{
	if (this == nullptr) return;

	if (this->type == ClickButtonType::Hide) {
		// ���Ʋ���ͼƬ
		putimagePng(WIDHT - BLOCK_WIDTH, BLOCK_HEIGHT, &im_spade);
		return;
	}
	switch (type)
	{
	case ClickButtonType::Delete:
		putimagePng(WIDHT - BLOCK_WIDTH + im_wrong.getwidth()/2, BLOCK_HEIGHT + im_wrong.getheight()/2, &im_wrong);
		putimagePng(m.x - im_spade.getwidth() / 2, m.y - im_spade.getheight() / 2, &im_spade);
		
		break;
	case ClickButtonType::Build:
		putimagePng(x, y, &im_build);
		settextcolor(YELLOW);
		drawText("10", x+30, y+10, 15);
		drawText("10", x + width - 45, y + 10, 15);
		break;
	case ClickButtonType::Upgrade:
		putimagePng(x, y, &ims_upgrade_button[aniId]);
		aniCount++;
		if (aniCount >= ANI_MAX_COUNT) {
			aniCount = 0;
			aniId++;
			aniId %= ims_upgrade_button.size();
		}
		if (towers[lastClickCoordinate] == NULL) return;
		int cost = towers[lastClickCoordinate]->upgradeCost;
		settextcolor(YELLOW);
		drawText(std::to_string(cost), x + width / 2 - 7, y + 15, 15);
		break;

	
	}
}
void ClickButton::update()
{
	if (this == nullptr) return;
	//draw();
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
		case ClickButtonType::Delete:
			if (coordinate.row == 1 && coordinate.col == COL - 1) {
				hide();
			}
			// �ж��Ƿ���Խ���
			if (towerMap[coordinate.row][coordinate.col] == 0) {
				// ���Խ���
				// ����Ƿ��Ѿ�����
				for (const auto& pair : towers) {
					// pair.first �Ǽ� (Coordinate)�� pair.second ��ֵ (Tower*)
					if (pair.first == coordinate) {
						// �����Ѿ�����
						// ���ٸ���
						coinSystem->addCoin(5, pair.second->x, pair.second->y);
						destoryTowerById(pair.second->id);
						hide();
						return;
					}
				}
			}

			break;
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
						if (pair.second == nullptr) return;
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
				int cost = towerInfo[1].upgradeCost;
				if (!coinSystem->subCoin(cost)) return;
				towers.insert(std::make_pair(lastClickCoordinate, new Tower(TowerType::Attack, lastClickCoordinate)));
			}
			if (coordinate.row == lastClickCoordinate.row && coordinate.col == lastClickCoordinate.col - 1) {
				// ������ǽ��찴ť�����
				// �����ｨ��
				int cost = towerInfo[1].upgradeCost;
				if (!coinSystem->subCoin(cost)) return;
				towers.insert(std::make_pair(lastClickCoordinate, new Tower(TowerType::Coin, lastClickCoordinate)));
			}
			hide();
			break;
		case ClickButtonType::Upgrade:


			if ((coordinate.row == lastClickCoordinate.row - 1|| coordinate.row == lastClickCoordinate.row) && coordinate.col == lastClickCoordinate.col) {
				towers[lastClickCoordinate]->upgrade();
				hide();
				return;
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
						if (pair.second == nullptr) {
							show(ClickButtonType::Build, coordinate);
							return;
						}
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
			if (coordinate.row == 1 && coordinate.col == COL - 1) {
				show(ClickButtonType::Delete, coordinate);
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
						if (pair.second == nullptr) {
							show(ClickButtonType::Build, coordinate);
							return;
						}
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
	audioSystem->playAudio(AudioType::Click);
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
