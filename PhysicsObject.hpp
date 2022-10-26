
#pragma once

#include <SFML/Graphics.hpp>
#include "box2d/b2_world.h"
#include "box2d/b2_body.h"

class PhysicsObject : public sf::Drawable
{
	public:
													PhysicsObject(b2World& world, float x, float y, float w, float h, float angle = 0, bool staticBody = false);
		virtual                                     ~PhysicsObject() { DetachFromWorld(); }
		void                                        Update();
		void                                        AddImpulse(float x, float y);
		void                                        Move(float x, float y);
		void                                        SetBounciness(float bouncy);
		void                                        DetachFromWorld();
		
	protected:
		void                                        draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		[[nodiscard]] virtual const sf::Drawable*   GetDrawableItem() const = 0;
		virtual sf::Transformable*                  GetTransformableItem() = 0;
		
	private:
		b2Body*                                     _body;
};

