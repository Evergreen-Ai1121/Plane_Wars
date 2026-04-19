#include"FoeBig.h"
#include"../Config/Config.h"

#define INIT_BIG_SHOWID 4
FoeBig::FoeBig() {}
FoeBig::~FoeBig() {}
void FoeBig::init() {
	::loadimage(&m_img, L"./res/foebig.jpg");

	
	m_x  =  rd() %(BACK_WIDTH-FOEBIG_WIDTH);
	m_y = -FOEBIG_HEIGHT;
	m_blood = 5;//5滴血，打5次才会爆炸
	m_showld=INIT_BIG_SHOWID; 
}
void FoeBig::show() {
	::putimage(m_x, m_y, FOEBIG_WIDTH, FOEBIG_HEIGHT, &m_img, FOEBIG_WIDTH, FOEBIG_HEIGHT * (4 - m_showld),SRCPAINT);
	::putimage(m_x, m_y, FOEBIG_WIDTH, FOEBIG_HEIGHT, &m_img, 0, FOEBIG_HEIGHT * (4 - m_showld), SRCAND);
}
bool FoeBig::isHitPlayer(player& player) {
	//玩家飞机中间点
	int x1 = player.m_x + PLAYER_WIDTH / 2;
	//int y1=player.m_y; 
	if (m_x <= x1 && x1 <= (m_x + FOEMID_WIDTH) &&
		m_y <= player.m_y && player.m_y <= (m_y + FOEMID_HEIGHT)
		)
	{
		return true;
	}

	//int x2 = player.m_x + PLAYER_WIDTH / 2;
	int y2=player.m_y+PLAYER_HEIGHT/2; 
	if (m_x <= player.m_x && player.m_x <= (m_x + FOEMID_WIDTH) &&
		m_y <= y2 && y2 <= (m_y + FOEMID_HEIGHT)
		)
	{
		return true;
	}

	int x3 = player.m_x + PLAYER_WIDTH;
	int y3 = y2;
	if (m_x <= x3 && x3  <= (m_x + FOEMID_WIDTH) &&
		m_y <= y3 && y3 <= (m_y + FOEMID_HEIGHT)
		)
	{
		return true;
	}
	return false;
}