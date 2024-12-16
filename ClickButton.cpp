#include "ClickButton.h"
#include "EasyXPng.h"
#include "Images.h"
#include "Global.h"
#include "Toolkit.h"
// 构造函数
ClickButton::ClickButton()
{
	// 加载图片


	type = ClickButtonType::Hide;
}

void ClickButton::draw()
{
	if (this == nullptr) return;

	if (this->type == ClickButtonType::Hide) {
		// 绘制铲子图片
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
/*点击某一方块，有可能出现有效的情况有：
1 - 可建造，待建造。 
2 - 可建造，已建造，待升级。
3 - 可建造，已建造，不可升级。
4 - 建造按钮的左右两边。 
5 - 升级按钮的上方*/
void ClickButton::clickCoordinate(Coordinate coordinate)
{
	

	switch (this->type)
	{
		case ClickButtonType::Delete:
			if (coordinate.row == 1 && coordinate.col == COL - 1) {
				hide();
			}
			// 判断是否可以建造
			if (towerMap[coordinate.row][coordinate.col] == 0) {
				// 可以建造
				// 检查是否已经建造
				for (const auto& pair : towers) {
					// pair.first 是键 (Coordinate)， pair.second 是值 (Tower*)
					if (pair.first == coordinate) {
						// 这里已经建造
						// 销毁该塔
						coinSystem->addCoin(5, pair.second->x, pair.second->y);
						destoryTowerById(pair.second->id);
						hide();
						return;
					}
				}
			}

			break;
		case ClickButtonType::Build:
			// 判断是否可以建造
			if (towerMap[coordinate.row][coordinate.col] == 0) {
				// 可以建造
				// 检查是否已经建造
				for (const auto& pair : towers) {
					// pair.first 是键 (Coordinate)， pair.second 是值 (Tower*)
					if (pair.first == coordinate) {
						// 这里已经建造
						// 判断是否能升级
						if (pair.second == nullptr) return;
						if (pair.second->currentGrade < 3)// 能升级
						{
							show(ClickButtonType::Upgrade, coordinate);
							return;
						}

						// 不能升级
						return;
					}
				}
				show(ClickButtonType::Build, coordinate);
				return;
			}
			
			// 不可升级，点击的是空白土地
			if (coordinate.row == lastClickCoordinate.row && coordinate.col == lastClickCoordinate.col + 1) {
                // 点击的是建造按钮的右边
				// 在这里建造
				//towers.insert(std::pair<Coordinate, Tower*>(coordinate, new Tower(TowerType::Attack, coordinate)));
				int cost = towerInfo[1].upgradeCost;
				if (!coinSystem->subCoin(cost)) return;
				towers.insert(std::make_pair(lastClickCoordinate, new Tower(TowerType::Attack, lastClickCoordinate)));
			}
			if (coordinate.row == lastClickCoordinate.row && coordinate.col == lastClickCoordinate.col - 1) {
				// 点击的是建造按钮的左边
				// 在这里建造
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
			// 判断是否可以建造
			if (towerMap[coordinate.row][coordinate.col] == 0) {
				// 可以建造
				// 检查是否已经建造
				for (const auto& pair : towers) {
					// pair.first 是键 (Coordinate)， pair.second 是值 (Tower*)
					if (pair.first == coordinate) {
						// 这里已经建造
						// 判断是否能升级
						if (pair.second == nullptr) {
							show(ClickButtonType::Build, coordinate);
							return;
						}
						if (pair.second->currentGrade < 3) {
							show(ClickButtonType::Upgrade, coordinate);
							return;
						}
						// 不能升级

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

			// 判断是否可以建造
			if (towerMap[coordinate.row][coordinate.col] == 0) {
				// 可以建造
				// 检查是否已经建造
				for (const auto& pair : towers) {
					// pair.first 是键 (Coordinate)， pair.second 是值 (Tower*)
					if (pair.first == coordinate) {
						// 这里已经建造
						// 判断是否能升级
						if (pair.second == nullptr) {
							show(ClickButtonType::Build, coordinate);
							return;
						}
						if (pair.second->currentGrade < 3) {
							show(ClickButtonType::Upgrade, coordinate);
							return;
						}
						// 不能升级

						return;
					}
				}
				show(ClickButtonType::Build, coordinate);
				break;
			}
			
            // 不可升级，点击的是空白土地
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
