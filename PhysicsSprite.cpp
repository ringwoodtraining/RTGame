
#include "PhysicsSprite.hpp"

PhysicsSprite::PhysicsSprite(b2World& world, sf::Texture& texture, float x, float y, float w, float h, float angle, bool staticBody)
: PhysicsObject(world, x, y, w, h, angle, staticBody)
{
	auto scaleX = w/texture.getSize().x;
	auto scaleY = h/texture.getSize().y;
	
	_sprite.setTexture(texture);
	_sprite.setOrigin((w/scaleX)/2, (h/scaleY)/2);
	_sprite.setPosition(x + w/2, y + h/2);
	_sprite.setScale(scaleX, scaleY);
	//_sprite.setTextureRect({0, 0, static_cast<int>(w), static_cast<int>(h)});
	_sprite.setRotation(angle);
}

const sf::Drawable* PhysicsSprite::GetDrawableItem() const
{
	return &_sprite;
}

sf::Transformable* PhysicsSprite::GetTransformableItem()
{
	return &_sprite;
}
