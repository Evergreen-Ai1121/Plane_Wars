#pragma once
#include"../CGameFrame/CGameFrame.h"  //相对路径
#include"../Back/Back.h"
#include"../player/player.h"
#include"../GunList/GunList.h"
#include"../FoeList/FoeList.h"
class PlaneApp:public CGameFrame {
public:
	Back m_back;

	player m_player;

	GunList m_gunList;

	FoeList m_foeList;

	int m_score;
public:
	PlaneApp();
	~PlaneApp();
	void On_Init() override;//当前虚函数一定是重写父类的，否则报错
	void On_Paint()override;
	void On_Close()override;
	void InitMsgMap()override;
	


	void setTimer();
	void killTimer();
	void showScore();
	void On_WM_KEYDOWN(int);
	void On_WM_TIMER(WPARAM, LPARAM);


};

