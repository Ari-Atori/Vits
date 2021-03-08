#include "Filter_Math.hpp"

M4 Filter_Math::srt(V2 s, float r, V2 t) {
	float _s = M::sin(MC_TODEG(r)), _c = M::cos(MC_TODEG(r));
	return {{{s.x * _c, -s.y * _s, 0, t.x}, {s.x * _s, s.y * _c, 0, t.y}, {0, 0, 1, 0}, {0, 0, 0, 1}}};
}