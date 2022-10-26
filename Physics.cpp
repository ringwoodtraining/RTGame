
#include "Physics.hpp"
#include "box2d/b2_world.h"
#include "box2d/b2_polygon_shape.h"
#include "box2d/b2_fixture.h"

b2Body* Physics::CreateSquareBody(b2World& world, float x, float y, float w, float h, float angle, bool staticBody)
{
	b2BodyDef bodyDef;
	bodyDef.type = staticBody ? b2_staticBody : b2_dynamicBody;
	bodyDef.position = {x/30 + w/60, y/30 + h/60};
    bodyDef.fixedRotation = true;
	bodyDef.angle = angle * (M_PI/180);
    bodyDef.linearDamping = 1;
	
	b2PolygonShape shape;
	shape.SetAsBox(w/2/30, h/2/30);
	
	b2FixtureDef fixture;
	fixture.shape = &shape;
	fixture.density = 1;
	fixture.friction = 0.5;
	fixture.restitution = 0.7;
	
	b2Body* body = world.CreateBody(&bodyDef);
	body->CreateFixture(&fixture);
	
	return body;
}
