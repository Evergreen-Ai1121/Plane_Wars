#pragma once
#include<easyx.h>
#include"../player/player.h"
#include"../FoeList/Foe.h"
class Gun
{
public:
	IMAGE m_img;
	int m_x;
	int m_y;
public:
	Gun();
	~Gun();
	void init(player& player);
	void show();
	void move();

	bool isHitFoe(Foe* foe);
};

