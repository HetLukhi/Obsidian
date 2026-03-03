#include "Physics.h"

namespace obsidian {
	namespace physics {
		bool Physics::checkAABB(const AABB& a,const AABB& b) {
			math::vec2 aPos = a.pos;
			math::vec2 aSize = a.size;

			math::vec2 bPos = b.pos;
			math::vec2 bSize = b.size;

			return (aPos.x < bPos.x + bSize.x &&
					aPos.x + aSize.x > bPos.x &&
					aPos.y < bPos.y + bSize.y &&
					aPos.y + aSize.y > bPos.y);
		}
	}
}