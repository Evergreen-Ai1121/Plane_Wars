#pragma once
#include<list>
#include"Foe.h"
using namespace std;

class FoeList {
public:
	list<Foe*> m_lsFoe;
    list<Foe*>m_lstBoomFoe;
public:
	FoeList();
	~FoeList();
	void showAll();
	void moveAll();
};

