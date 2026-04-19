#include<typeinfo>
using namespace std;
#include"Gun.h"
#include"../Config/Config.h"
#include"../FoeList/Foe.h"
#include"../FoeList/FoeBig.h"
#include"../FoeList/FoeMid.h"
#include"../FoeList/FoeSma.h"


Gun::Gun():m_x(0),m_y(0){}
Gun::~Gun(){}
void Gun::init(player& player){
	::loadimage(&m_img, L"./res/gunner.jpg");
	m_x = player.m_x + (PLAYER_HEIGHT - GUN_WIDTH);
	m_y = player.m_y;
}
void Gun::show() {
	::putimage(m_x, m_y, GUN_WIDTH, GUN_HEIGHT, &m_img, GUN_WIDTH, 0, SRCPAINT);
	::putimage(m_x, m_y, GUN_WIDTH, GUN_HEIGHT, &m_img, 0, 0, SRCAND);
}
void Gun::move() {
	m_y -= GUN_MOVE_STEP;
}

bool Gun::isHitFoe(Foe* foe)
{
	//取出来炮弹的中心点
	int x = m_x + GUN_WIDTH / 2;
	int y = m_y + GUN_HEIGHT / 2;

	//判断敌人飞机类型

	if (typeid(*foe) == typeid(FoeSma)) {
		if (foe->m_x <= x && x <= (foe->m_x + FOESMA_WIDTH) &&
			foe->m_y <= y && y <= (foe->m_y + FOESMA_HEIGHT)
			)
		{
			return true;
		}
	}
	else if (typeid(*foe) == typeid(FoeMid)) {
		if (foe->m_x <= x && x <= (foe->m_x + FOEMID_WIDTH) &&
			foe->m_y <= y && y <= (foe->m_y + FOEMID_HEIGHT)
			)
		{
			return true;
		}
	}
	else if (typeid(*foe) == typeid(FoeBig)) {
		if (foe->m_x <= x && x <= (foe->m_x + FOEBIG_WIDTH) &&
			foe->m_y <= y && y <= (foe->m_y + FOEBIG_HEIGHT)
			)
		{
			return true;
		}
	}
	return false;
}
