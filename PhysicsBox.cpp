
#include "PhysicsBox.hpp"

PhysicsBox::PhysicsBox(b2World& world, float x, float y, float w, float h, float angle, bool staticBody)
: PhysicsObject(world, x, y, w, h, angle, staticBody)
{
	_shape.setOrigin(w/2, h/2);
	_shape.setPosition(x + w/2, y + h/2);
	_shape.setSize({w, h});
	_shape.setFillColor(sf::Color::Black);
	_shape.setRotation(angle);
}

const sf::Drawable* PhysicsBox::GetDrawableItem() const
{
	return &_shape;
}

sf::Transformable* PhysicsBox::GetTransformableItem()
{
	return &_shape;
}
