#pragma once

#include "PhysicsObject.hpp"
#include "PhysicsBox.hpp"

class PhysicsSprite : public PhysicsObject
{
	public:
		PhysicsSprite(b2World& world, sf::Texture& texture, float x, float y, float w, float h, float angle = 0, bool staticBody = false);

        sf::Sprite& getSprite() { return _sprite;}

	protected:
		const Drawable* GetDrawableItem() const override;
		
		sf::Transformable* GetTransformableItem() override;
		
	private:
		sf::Sprite              _sprite;
};


