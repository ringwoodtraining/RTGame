#pragma once

#include "box2d/b2_body.h"

class Physics
{
	public:
		static b2Body*      CreateSquareBody(b2World& world, float x, float y, float w, float h, float angle, bool staticBody);
};


