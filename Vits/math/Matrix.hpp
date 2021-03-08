#ifndef LBB_MATH_MATRIX
#define LBB_MATH_MATRIX

#include "Quaternion.hpp"

class M3 {
public:
	M3 operator =(M3 const& m);
	M3 operator -();

	M3 operator + (M3 const& m);
	M3 operator - (M3 const& m);
	M3 operator * (M3 const& m);
	M3 operator * (float f);
	M3 operator / (float f);

	M3 operator += (M3 const& m) { *this = *this + m; return *this; }
	M3 operator -= (M3 const& m) { *this = *this - m; return *this; }
	M3 operator *= (M3 const& m) { *this = *this * m; return *this; }
	M3 operator *= (float f) { *this = *this * f; return *this; }
	M3 operator /= (float f) { *this = *this / f; return *this; }

	float det();
	float c[3][3];
};

class M4 {
public:
	M4 operator =(M4 const &m);
	M4 operator -();

	M4 operator + (M4 const &m);
	M4 operator - (M4 const &m);
	M4 operator * (M4 const &m);
	M4 operator * (float f);
	M4 operator / (float f);

	M4 operator += (M4 const &m) { *this = *this + m; return *this; }
	M4 operator -= (M4 const &m) { *this = *this - m; return *this; }
	M4 operator *= (M4 const &m) { *this = *this * m; return *this; }
	M4 operator *= (float f) { *this = *this * f; return *this; }
	M4 operator /= (float f) { *this = *this / f; return *this; }

	float det();

	static M4 model(V3, Q, V3);

	float c[4][4];
};

static const M3 M3_ZERO = { {{0,0,0},{0,0,0},{0,0,0}} };
static const M3 M3_IDENTITY = { {{1,0,0},{0,1,0},{0,0,1}} };

static const M4 M4_ZERO = {{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}};
static const M4 M4_IDENTITY = {{{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}};

#endif
