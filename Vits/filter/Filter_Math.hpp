#ifndef VITS_FILTER_MATH
#define VITS_FILTER_MATH

#include "../math/Matrix.hpp";

class Filter_Math {
	static M4 srt(V2 s, float r, V2 t);
	static V4 hsl(float h, float s, float l) { return { h, s, l, 1 }; }
	static M3 protan(float a);
	static M3 deuteran(float a);
	static M3 tritan(float a);
};

#endif
