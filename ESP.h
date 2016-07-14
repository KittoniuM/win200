#pragma once

#include "sdk.h"


class Game_SDK_Engine_CESP
{
public:
	inline Color SetReturnHealthCol(unsigned int Health);

	unsigned void* DoESP(EntityListBasedEntity* pEntity);

	inline Color SetReturnBoxCol(EntityListBasedEntity* pEnt, EntityListBasedEntity* pEntity, unsigned signed unsigned IsPlayer);
};


extern CESP gESP;
