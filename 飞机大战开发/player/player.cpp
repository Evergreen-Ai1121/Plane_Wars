#include"player.h"
#include"../Config/Config.h"
#include"../GunList/GunList.h"
player::player() :m_x(0), m_y(0) {}
player::~player() {}
void player::init() {
	m_x = (BACK_WIDTH - PLAYER_WIDTH) / 2;
	m_y = BACK_HEIGHT - PLAYER_HEIGHT;
	
	::loadimage(&m_img, L"./res/player.jpg");
	::loadimage(&m_maskimg , L"./res/player_mask.jpg");
}
void player::show() {
	::putimage(m_x,m_y,&m_maskimg,SRCPAINT); //屏蔽图 传输方式：位或
	::putimage(m_x, m_y, &m_img, SRCAND);//原图 传输方式：位与
}
void player::move(int direct) {
	if (direct == VK_UP) { //virtual-key code
		if ((m_y - PLAYER_MOVE_STEP) >= 0)
		{
			m_y -= PLAYER_MOVE_STEP;
		}
		else
		{
			m_y = 0;
		}
	}
	else if (direct == VK_DOWN) { //virtual-key code
		if ((m_y + PLAYER_MOVE_STEP) <= (BACK_HEIGHT-PLAYER_HEIGHT))
		{
			m_y += PLAYER_MOVE_STEP;
		}
		else
		{
			m_y = BACK_HEIGHT - PLAYER_HEIGHT;
		}
	}
	if (direct == VK_LEFT) { //virtual-key code
		if ((m_x - PLAYER_MOVE_STEP) >= 0)
		{
			m_x -= PLAYER_MOVE_STEP;
		}
		else
		{
			m_x = 0;
		}
	}
	else if (direct == VK_RIGHT) { //virtual-key code
		if ((m_x + PLAYER_MOVE_STEP) <= (BACK_WIDTH - PLAYER_WIDTH))
		{
			m_x += PLAYER_MOVE_STEP;
		}
		else
		{
			m_y = BACK_WIDTH - PLAYER_WIDTH;
		}
	}
}

Gun* player::sendGun()
{
	Gun* pgun = new Gun;
	pgun->init(*this);
	return pgun;
}
