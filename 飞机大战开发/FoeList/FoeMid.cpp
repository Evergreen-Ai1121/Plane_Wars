#include"FoeMid.h"
#include"../Config/Config.h"

#define INIT_MID_SHOWID 3
FoeMid::FoeMid() {}
FoeMid::~FoeMid() {}
void FoeMid::init() {
	::loadimage(&m_img, L"./res/foemid.jpg");


	m_x = rd() % (BACK_WIDTH - FOEMID_WIDTH);
	m_y = -FOEMID_HEIGHT;
	m_blood = 3;//3滴血，打3次才会爆炸
	m_showld = INIT_MID_SHOWID;
}
void FoeMid::show() {
	::putimage(m_x, m_y, FOEMID_WIDTH, FOEMID_HEIGHT, &m_img, FOEMID_WIDTH, FOEMID_HEIGHT * (INIT_MID_SHOWID - m_showld), SRCPAINT);
	::putimage(m_x, m_y, FOEMID_WIDTH, FOEMID_HEIGHT, &m_img, 0, FOEMID_HEIGHT * (INIT_MID_SHOWID - m_showld), SRCAND);
}
bool FoeMid::isHitPlayer(player& player) {
	return false;
}