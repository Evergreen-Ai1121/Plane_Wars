#pragma once
#include<easyx.h>
class Back {
public:
	IMAGE m_img;
	int m_x;
	int m_y;
public:
	Back();
	~Back();
	void init();
	void show();
	void move();
};



