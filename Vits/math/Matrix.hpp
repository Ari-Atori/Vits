#ifndef LBB_MATH_MATRIX
#define LBB_MATH_MATRIX

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
	M4 inverse();
	float c[4][4];
};

static const M4 M4_ZERO = {{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}};
static const M4 M4_IDENTITY = {{{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}}};

#endif
