#include"Back.h"
#include"../Config/Config.h"
Back::Back() :m_x(0),m_y(0){}
Back::~Back() {}
//具有实际意义，和业务相关的初始化
void Back::init() {
	m_x = 0;
	m_y = -BACK_HEIGHT;

	;
	::loadimage(&m_img, L"./res/back.jpg");  //相对于工程来说的路径
}
void Back::show() {
	::putimage(m_x, m_y, &m_img);
}
void Back::move() {
	m_y += BACK_MOVE_STEP;
	if (m_y >= 0)
	{//移动到边界了，则回复到最初的位置
		m_y = -BACK_HEIGHT;
	}
}