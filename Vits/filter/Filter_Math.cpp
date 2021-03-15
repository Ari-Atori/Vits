#include "Filter_Math.hpp"

static M4 rgb2lms = { {{17.8824F, 43.5161F, 4.11935F, 0}, {3.45565F, 27.1554F, 3.86714F, 0}, {0.0299566F, 0.184309F, 1.46709F, 0}, {0, 0, 0, 1}} };
static M4 lms2rgb = { { {0.0809445F, -0.130504F, 0.116721F, 0}, { -0.0102485F, 0.0540193F, -0.113615F, 0 }, { -0.000365297F, -0.00412162F, 0.693511F, 0 }, { 0, 0, 0, 1 }} };

M4 Filter_Math::srt(V2 s, float r, V2 t) {
	float _s = M::sin((float) MC_TORAD(r)), _c = M::cos((float) MC_TORAD(r));
	return {{{s.x * _c, -s.y * _s, 0, t.x}, {s.x * _s, s.y * _c, 0, t.y}, {0, 0, 1, 0}, {0, 0, 0, 1}}};
}

V4 Filter_Math::hsl(float h, float s, float l) { return { h, s, l, 1 }; }

M4 Filter_Math::protan(float a) {
	M4 P = { {{(1 - a), 2.02344F * a, -2.52581F * a, 0},{0,1,0,0},{0,0,1,0}, {0,0,0,1}} };
	return lms2rgb * P * rgb2lms;
}

M4 Filter_Math::deuteran(float a) {
	M4 D = { {{1, 0, 0, 0},{0.49421F * a, (1-a), 1.24827F*a, 0},{0,0,1,0}, {0,0,0,1}} };
	return lms2rgb * D * rgb2lms;
}

M4 Filter_Math::tritan(float a) {
	M4 T = { {{1,0,0,0},{0,1,0,0},{-0.395913F * a, 0.801109F * a, (1-a),0}, {0,0,0,1}} };
	return lms2rgb * T * rgb2lms;
}