#pragma once
#include"Foe.h"
class FoeMid : public Foe {
public:
	FoeMid();
	~FoeMid();
	void init();
	void show();

	bool isHitPlayer(player& player);
};

