#pragma once
#include"Foe.h"
class FoeBig : public Foe {
public:
	FoeBig();
	~FoeBig();
	void init();
	void show();

	bool isHitPlayer(player& player);
};

