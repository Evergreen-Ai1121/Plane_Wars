#pragma once
#include<easyx.h>
#include"../player/player.h"
#include<random>
using namespace std;
class Foe{
public:
	IMAGE m_img;
	int m_x;
	int m_y;
	int m_blood;
	int m_showld;

	static random_device rd;
public:
	Foe();
	virtual ~Foe();//父类析构一定要虚析构
	virtual void init() = 0;
	virtual void show() = 0;
	void move(int step);
	virtual bool isHitPlayer(player& player) = 0;
};

