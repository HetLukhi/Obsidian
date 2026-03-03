#pragma once

#include "Components/Sprite.h"
#include "Maths/Vec2.h"

namespace obsidian {
	namespace physics {

		struct AABB {
			math::vec2 pos;
			math::vec2 size;
		};

		class Physics {
		public:
			static bool checkAABB(const AABB& a,const AABB& b);
		};
	}
}