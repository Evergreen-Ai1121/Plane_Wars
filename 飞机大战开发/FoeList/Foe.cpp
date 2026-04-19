#include"Foe.h"

//静态成员在类外定义及初始化
random_device Foe::rd;
Foe::Foe() {
	m_x=0;
	m_y=0;
	m_blood=0;
	m_showld=0;
}
Foe::~Foe() {}

void Foe::move(int step) {
	m_y += step;
}