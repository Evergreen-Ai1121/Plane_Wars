#pragma once
#include<list>
using namespace std;
#include"Gun.h"

class GunList
{
public:
	list<Gun*> m_lstGun;
public:
	GunList();
	~GunList();
	void showAll();
	void moveAll();
};

