#pragma once
#include <easyx.h>
class Gun;  //ÉùÃ÷
class player
{
public:
	IMAGE m_img;
	IMAGE m_maskimg;
	int m_x;
	int m_y;
public:
	player();
	~player();
	void init();
	void show();
	void move(int direct);
	Gun* sendGun();
};

