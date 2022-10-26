
#include "PhysicsObject.hpp"
#include "box2d/b2_fixture.h"
#include "box2d/b2_polygon_shape.h"
#include "Physics.hpp"

PhysicsObject::PhysicsObject(b2World& world, float x, float y, float w, float h, float angle, bool staticBody)
: _body(Physics::CreateSquareBody(world, x, y, w, h, angle, staticBody))
{

}

void PhysicsObject::Update()
{
	GetTransformableItem()->setPosition(_body->GetPosition().x*30, _body->GetPosition().y*30);
	GetTransformableItem()->setRotation((float)(_body->GetAngle() * (180.0/M_PI)));
}

void PhysicsObject::AddImpulse(float x, float y)
{
	_body->ApplyLinearImpulseToCenter({x, y}, true);
}

void PhysicsObject::Move(float x, float y)
{
	_body->SetTransform({x/30, y/30}, 0);
	_body->SetAwake(true);
	_body->SetLinearVelocity({0, 0});
	_body->SetAngularVelocity(0);
}

void PhysicsObject::SetBounciness(float bouncy)
{
	_body->GetFixtureList()->SetRestitution(bouncy);
}

void PhysicsObject::DetachFromWorld()
{
	_body->GetWorld()->DestroyBody(_body);
}

void PhysicsObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*GetDrawableItem());
}
