#include"PlaneApp.h"
#include"../FoeList/FoeBig.h"
#include"../FoeList/FoeMid.h"
#include"../FoeList/FoeSma.h"


WND_PARAM(600+16,800+39,400,30,L"飞机大战")
CREATE_OBJECT(PlaneApp)

PlaneApp::PlaneApp(){}
PlaneApp::~PlaneApp(){}
void PlaneApp::On_Init(){
	m_back.init();
	m_player.init();
	setTimer();
}
void PlaneApp::On_Paint(){
	m_back.show();
	m_player.show();
	m_gunList.showAll();
	m_foeList.showAll();
	showScore();
}
void PlaneApp::On_Close(){}
void PlaneApp::InitMsgMap(){
	INIT_MSGMAP(WM_KEYDOWN,EX_KEY,PlaneApp)
	INIT_MSGMAP(WM_TIMER,EX_WINDOW,PlaneApp)
}


void PlaneApp::setTimer() {
	//设定背景移动的定时器
	::SetTimer(m_hwnd,1,50,nullptr);
	//检测方向键
	::SetTimer(m_hwnd, 2, 10, nullptr);
	//炮弹
	::SetTimer(m_hwnd, 3, 15, nullptr);
	//敌人飞机定时移动
	::SetTimer(m_hwnd, 4, 50, nullptr);
	//定时器创建三种敌人飞机
	::SetTimer(m_hwnd, 5, 3000, nullptr);
	//检测是否碰撞
	::SetTimer(m_hwnd, 6, 5, nullptr);
	::SetTimer(m_hwnd, 7, 100, nullptr);
}
void PlaneApp::killTimer() {//停止定时器
	
	::KillTimer(m_hwnd, 1);
	::KillTimer(m_hwnd, 2);
	::KillTimer(m_hwnd, 3);
	::KillTimer(m_hwnd, 4);
	::KillTimer(m_hwnd, 5);
	::KillTimer(m_hwnd, 6);
}
void PlaneApp::showScore() {
	wstring sc = L"分数为: ";

	wchar_t arr[5] = { 0 };
	_itow_s(m_score,arr,10 );
	sc += arr;

	::settextcolor(RGB(30, 10, 200));
	RECT rect{ 0, 0, 120, 40 };
	::drawtext(sc.c_str(), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
void PlaneApp::On_WM_KEYDOWN(int vk) {
	//m_player.move(vk);
	if (vk == VK_SPACE) {//如果按下了空格
		Gun* pgun = m_player.sendGun();
		m_gunList.m_lstGun.push_back(pgun); //装入到炮弹列表中
	}
}
void PlaneApp::On_WM_TIMER(WPARAM w, LPARAM l) {
	if (w==1)//定时器的id
	{
		m_back.move();
	}
	else if(w == 2)  //检测玩家飞机是否按下方向键
	{
		if(::GetAsyncKeyState(VK_UP)) //条件为真则说明按下了方向键
		{
			m_player.move(VK_UP);
		}
		if (::GetAsyncKeyState(VK_DOWN)) //条件为真则说明按下了方向键
		{
			m_player.move(VK_DOWN);
		}
		if (::GetAsyncKeyState(VK_LEFT)) //条件为真则说明按下了方向键
		{
			m_player.move(VK_LEFT);
		}
		if (::GetAsyncKeyState(VK_RIGHT)) //条件为真则说明按下了方向键
		{
			m_player.move(VK_RIGHT);
		}

	}
	else if (w == 3) {
		m_gunList.moveAll();
	}
	else if (w == 4) {
		m_foeList.moveAll();
	}
	else if (w == 5) {
		int n = Foe::rd() % 100;
		Foe* pfoe = nullptr;
		if (0 < n && n <= 49) {
			//创建敌人小飞机
			pfoe = new FoeSma;
		}else if (50 < n && n <= 79) {
			//创建敌人中飞机
			pfoe = new FoeMid;
		}else if (80 < n && n <= 99) {
			//创建敌人大飞机
			pfoe = new FoeBig;
		}
		if (pfoe) {
			pfoe->init();//初始化
			m_foeList.m_lsFoe.push_back(pfoe); //添加到正常的敌人飞机链表中
		}
	}
	else if (w == 6) {

		bool isBoom = false; //每次循环 标识敌人飞机是否爆炸

		list <Foe*>::iterator itFoe = m_foeList.m_lsFoe.begin();
		while (itFoe != m_foeList.m_lsFoe.end() ) {

			//判断是否撞击了玩家飞机
			if ((*itFoe)->isHitPlayer(m_player)) {
				//撞到了
				killTimer();
				//弹出提示框
				MessageBox(m_hwnd, L"GameOver", L"提示",MB_OK);

				//程序自主的退出
				On_WM_CLOSE(0, 0);
				return;
			}

			//遍历取每个炮弹//判断是否撞击炮弹
			list <Gun*>::iterator itGun = m_gunList.m_lstGun.begin();
			while (itGun != m_gunList.m_lstGun.end()) {
				//判断是否碰撞
				if ((*itGun)->isHitFoe(*itFoe)) {
					//碰撞了
					//删除炮弹本身
					delete (*itGun);
					itGun = m_gunList.m_lstGun.erase(itGun);//返回删除的下一个

					//敌人飞机
					if (--(*itFoe)->m_blood <= 0) {
						//敌人飞机准备爆炸，将正常的敌人飞机转移到爆炸链表中

						//先添加
						m_foeList.m_lstBoomFoe.push_back((*itFoe));

						//后删除正常
						itFoe = m_foeList.m_lsFoe.erase(itFoe);

						isBoom = true;
						break;
					}
					continue;
				}


				++itGun;
			}
			if (isBoom) isBoom = false;//改为不爆炸
			else ++itFoe;

		}
		
	}
	else if (w == 7) {
	list<Foe*>::iterator it = m_foeList.m_lstBoomFoe.begin();
	while (it != m_foeList.m_lstBoomFoe.end()) {
		if (*it) {
			if (--(*it)->m_showld<0) {
				delete (*it);
				it = m_foeList.m_lstBoomFoe.erase(it);
				continue;
				
			}
		}
		++it;
	}
}
}
