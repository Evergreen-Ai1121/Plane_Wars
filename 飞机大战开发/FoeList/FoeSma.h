#pragma once
#include"Foe.h"
class FoeSma : public Foe {
public:
	FoeSma();
	~FoeSma();
public:
	void init();
	void show();

	bool isHitPlayer(player& player);
};
