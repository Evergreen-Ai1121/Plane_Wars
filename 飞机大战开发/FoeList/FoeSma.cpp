#include"FoeSma.h"
#include"../Config/Config.h"

#define INIT_SMA_SHOWID 2
FoeSma::FoeSma() {}
FoeSma::~FoeSma() {}
void FoeSma::init() {
	::loadimage(&m_img, L"./res/foesma.jpg");

	m_x = rd() % (BACK_WIDTH - FOESMA_WIDTH);
	m_y = -FOESMA_HEIGHT;
	m_blood = 1;//1µÎÑª£¬´ò1´Î±¬Õ¨
	m_showld = INIT_SMA_SHOWID;
}
void FoeSma::show() {
	::putimage(m_x, m_y, FOESMA_WIDTH, FOESMA_HEIGHT, &m_img, FOESMA_WIDTH, FOESMA_HEIGHT * (INIT_SMA_SHOWID - m_showld), SRCPAINT);
	::putimage(m_x, m_y, FOESMA_WIDTH, FOESMA_HEIGHT, &m_img, 0, FOESMA_HEIGHT * (INIT_SMA_SHOWID - m_showld), SRCAND);
}
bool FoeSma::isHitPlayer(player& player) {
	int x1 = player.m_x + PLAYER_WIDTH / 2;
	//int y1=player.m_y; 
	if (m_x <= x1 && x1 <= (m_x + FOESMA_WIDTH) &&
		m_y <= player.m_y && player.m_y <= (m_y + FOESMA_HEIGHT)
		)
	{
		return true;
	}

	//int x2 = player.m_x + PLAYER_WIDTH / 2;
	int y2 = player.m_y + PLAYER_HEIGHT / 2;
	if (m_x <= player.m_x && player.m_x <= (m_x + FOESMA_WIDTH) &&
		m_y <= y2 && y2 <= (m_y + FOESMA_HEIGHT)
		)
	{
		return true;
	}

	int x3 = player.m_x + PLAYER_WIDTH;
	int y3 = y2;
	if (m_x <= x3 && x3 <= (m_x + FOESMA_WIDTH) &&
		m_y <= y3 && y3 <= (m_y + FOESMA_HEIGHT)
		)
	{
		return true;
	}
	return false;
}