#ifndef LBB_MATH_COMPLEX
#define LBB_MATH_COMPLEX

#include "../Math.hpp"
#include "Vector.hpp"

class CX {
public:
	CX operator = (CX const &x) {this->i = x.i; this->r = x.r; return *this;}
	CX operator - () { return {-r, -i}; }
	CX operator ~ () { return {r, -i}; }

	CX operator + (CX const &x) { return {r + x.r, i + x.i}; }
	CX operator - (CX const &x) { return {r - x.r, i - x.i}; }
	CX operator * (CX const &x) { return {r*x.r - i*x.i, r*x.i + i*x.r}; }
 	CX operator / (CX const &x) { float C = x.r*x.r+x.i*x.i; CX q = { x.r / C,-x.i / C }; return *this * q; }
	CX operator * (float f) { return {r * f, i * f}; }
	CX operator / (float f) { return {r / f, i / f}; }

	CX operator += (CX const &x) { *this = *this + x; return *this; }
	CX operator -= (CX const &x) { *this = *this - x; return *this; }
	CX operator *= (CX const &x) { *this = *this * x; return *this; }
	CX operator /= (CX const &x) { *this = *this / x; return *this; }
	CX operator *= (float f) { *this = *this * f; return *this; }
	CX operator /= (float f) { *this = *this / f; return *this; }

	CX recip() { return ~(*this) / (r*r+i*i); }
	float arg() { return M::atan2(i, r); }
	float abs() { return M::hypot(r, i); }

	static CX exp(CX c) { float e = M::exp(c.r);  return  { M::cos(c.i) * e, M::sin(c.i) * e}; }
	static CX ln(CX c) { return  {M::ln(c.abs()), c.arg()}; }
	static CX pow(CX x, CX y) { return exp(ln(x) * y); }
	static CX sqrt(CX c) { return exp(ln(c) * 0.5); }

	float r, i;
protected:
private:
};

#endif
