#ifndef LBB_MATH_QUATERNION
#define LBB_MATH_QUATERNION

#include "Vector.hpp"

class Q {
public:
	Q operator = (Q const &q) {this->x = q.x; this->y = q.y; this->z = q.z; this->w = q.w; return *this;}
	Q operator - () { return {-x, -y, -z, -w}; }
	Q operator ~ () { return {-x, -y, -z, w}; }

	Q operator + (Q const &q) { return {x+q.x, y+q.y, z+q.z, w+q.w}; }
	Q operator - (Q const &q) { return {x-q.x, y-q.y, z-q.z, w-q.w}; }
	Q operator * (Q const &q) { return {w*q.x + x*q.w + y*q.z - z*q.y, w*q.y - x*q.z + y*q.w + z*q.x, w*q.z + x*q.y - y*q.x + z*q.w, w*q.w - x*q.x - y*q.y - z*q.z}; }
	Q operator / (Q const& q) { float C = M::rsqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w); Q r = {-q.x * C * C, -q.y * C * C, -q.z * C * C, q.w* C* C }; return (*this) * r; }
	Q operator * (float f) { return {x*f, y*f, z*f, w*f}; }
	Q operator / (float f) { return {x/f, y/f, z/f, w/f}; }

	Q operator += (Q const &q) { *this = *this + q; return *this; }
	Q operator -= (Q const &q) { *this = *this - q; return *this; }
	Q operator *= (Q const &q) { *this = *this * q; return *this; }
	Q operator /= (Q const &q) { *this = *this / q; return *this; }
	Q operator *= (float f) { *this = *this * f; return *this; }
	Q operator /= (float f) { *this = *this / f; return *this; }

	float operator |(Q const &q) {return x*q.x + y*q.y + z*q.z + w*q.w;}

	float mag() {
		return M::sqrt(x*x + y*y + z*z + w*w);
	}

	static Q norm(Q q) {
		return q * M::rsqrt(q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w);
	}

	Q recip() {
		return ~(norm(*this)) * M::rsqrt(x*x + y*y + z*z + w*w);
	}

	static Q lerp(Q q1, Q q2, float f) {
		return q1 + (q2 - q1) * f;
	}

	static Q slerp(Q q1, Q q2, float f) {
		q1 = Q::norm(q1);
		q2 = Q::norm(q2);
		float d = q1 | q2;
		if (d < 0.0F) {
			q2 =-q2;
			d = -d;
		}

		float t0 = M::acos(d), t = t0 * f;
		float st0 = M::sin(t0), st = M::sin(t);

		float s1 = M::cos(t) - d * st / st0, s2 = st / st0;
    	return (q1 * s1) + (q2 * s2);
	}

	static Q V3a(V3 r, float a) {
		r = V3::norm(r);
		float c = M::cos(a * 0.5F), s = M::sin(a * 0.5F);
		return {r.x * s, r.y * s, r.z * s, c};
	}

	float x, y, z, w;
};

#endif
