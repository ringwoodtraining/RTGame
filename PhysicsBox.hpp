#pragma once


#include "PhysicsObject.hpp"

class PhysicsBox : public PhysicsObject
{
	public:
										PhysicsBox(b2World& world, float x, float y, float w, float h, float angle = 0, bool staticBody = false);
	
	protected:
		const Drawable*                 GetDrawableItem() const override;
		sf::Transformable*              GetTransformableItem() override;
		
	private:
		sf::RectangleShape              _shape;
};


