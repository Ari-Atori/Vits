#ifndef LBB_MATH_VECTOR
#define LBB_MATH_VECTOR

#include "../Math.hpp"

class V2 {
public:
	V2 operator = (V2 const &v) {this->x = v.x; this->y = v.y; return *this;}
	V2 operator - () { return {-x, -y}; }

	V2 operator + (V2 const &v) { return {x+v.x, y+v.y}; }
	V2 operator - (V2 const &v) { return {x-v.x, y-v.y}; }
	V2 operator * (V2 const &v) { return {x*v.x, y*v.y}; }
	V2 operator / (V2 const &v) { return {x/v.x, y/v.y}; }
	V2 operator * (float f) { return {x*f, y*f}; }
	V2 operator / (float f) { return {x/f, y/f}; }

	V2 operator += (V2 const &v) { *this = *this + v; return *this; }
	V2 operator -= (V2 const &v) { *this = *this - v; return *this; }
	V2 operator *= (V2 const &v) { *this = *this * v; return *this; }
	V2 operator /= (V2 const &v) { *this = *this / v; return *this; }
	V2 operator *= (float f) { *this = *this * f; return *this; }
	V2 operator /= (float f) { *this = *this / f; return *this; }

	float operator | (V2 const &v) {return x*v.x + y*v.y;}
	float operator ^ (V2 const &v) {return x*v.y - y*v.x;}

	float mag() {
		return M::sqrt(x*x + y*y);
	}

	static V2 norm(V2 v) {
		return v * M::rsqrt(v.x*v.x + v.y*v.y);
	}

	static V2 lerp(V2 p1, V2 p2, float f) {
		return p1 + (p2 - p1) * f;
	}

	float x, y;
};

class V3 {
public:
	V3 operator = (V3 const &v) {this->x = v.x; this->y = v.y; this->z = v.z; return *this;}
	V3 operator - () { return {-x, -y, -z}; }

	V3 operator + (V3 const &v) { return {x+v.x, y+v.y, z+v.z}; }
	V3 operator - (V3 const &v) { return {x-v.x, y-v.y, z-v.z}; }
	V3 operator * (V3 const &v) { return {x*v.x, y*v.y, z*v.z}; }
	V3 operator / (V3 const &v) { return {x/v.x, y/v.y, z/v.z}; }
	V3 operator * (float f) { return {x*f, y*f, z*f}; }
	V3 operator / (float f) { return {x/f, y/f, z/f}; }

	V3 operator += (V3 const &v) { *this = *this + v; return *this; }
	V3 operator -= (V3 const &v) { *this = *this - v; return *this; }
	V3 operator *= (V3 const &v) { *this = *this * v; return *this; }
	V3 operator /= (V3 const &v) { *this = *this / v; return *this; }
	V3 operator *= (float f) { *this = *this * f; return *this; }
	V3 operator /= (float f) { *this = *this / f; return *this; }

	float operator | (V3 const &v) {return x*v.x + y*v.y + z*v.z;}
	V3 operator ^ (V3 const &v) {return {y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x}; }

	float mag() {
		return M::sqrt(x*x + y*y + z*z);
	}

	static V3 norm(V3 v) {
		return v * M::rsqrt(v.x*v.x + v.y*v.y + v.z*v.z);
	}

	static V3 lerp(V3 p1, V3 p2, float f) {
		return p1 + (p2 - p1) * f;
	}

	float x, y, z;
};

class V4 {
public:
	V4 operator = (V4 const &v) {this->x = v.x; this->y = v.y; this->z = v.z; this->w = v.w; return *this;}
	V4 operator - () { return {-x, -y, -z, -w}; }

	V4 operator + (V4 const &v) { return {x+v.x, y+v.y, z+v.z, w+v.w}; }
	V4 operator - (V4 const &v) { return {x-v.x, y-v.y, z-v.z, w-v.w}; }
	V4 operator * (V4 const &v) { return {x*v.x, y*v.y, z*v.z, w*v.w}; }
	V4 operator / (V4 const &v) { return {x/v.x, y/v.y, z/v.z, w/v.w}; }
	V4 operator * (float f) { return {x*f, y*f, z*f, w*f}; }
	V4 operator / (float f) { return {x/f, y/f, z/f, w/f}; }

	V4 operator += (V4 const &v) { *this = *this + v; return *this; }
	V4 operator -= (V4 const &v) { *this = *this - v; return *this; }
	V4 operator *= (V4 const &v) { *this = *this * v; return *this; }
	V4 operator /= (V4 const &v) { *this = *this / v; return *this; }
	V4 operator *= (float f) { *this = *this * f; return *this; }
	V4 operator /= (float f) { *this = *this / f; return *this; }

	float operator | (V4 const &v) {return x*v.x + y*v.y + z*v.z + w*v.w;}

	float mag() {
		return M::sqrt(x*x + y*y + z*z + w*w);
	}

	static V4 norm(V4 v) {
		return v * M::rsqrt(v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w);
	}

	static V4 lerp(V4 p1, V4 p2, float f) {
		return p1 + (p2 - p1) * f;
	}

	float x, y, z, w;
};

#endif
