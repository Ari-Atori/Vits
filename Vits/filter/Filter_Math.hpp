#ifndef VITS_FILTER_MATH
#define VITS_FILTER_MATH

#include "../math/Matrix.hpp"
#include "../math/Vector.hpp"

class Filter_Math {
	static M4 srt(V2 s, float r, V2 t);
	static V4 hsl(float h, float s, float l);
	static M4 protan(float a);
	static M4 deuteran(float a);
	static M4 tritan(float a);
};

#endif
