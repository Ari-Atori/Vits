#ifndef LBB_UTIL_MATH
#define LBB_UTIL_MATH

#define MC_E     (2.718281828459045)
#define MC_1_E   (0.367879441171442)
#define MC_2PI   (6.283185307179586)
#define MC_PI    (3.141592653589793)
#define MC_PI_2  (1.570796326794896)
#define MC_PI_4  (0.785398163397448)
#define MC_1_PI  (0.318309886179070)
#define MC_1_2PI (0.159154943091895)
#define MC_2_PI	 (0.636619772359141)
#define MC_LN2   (0.693147180559945)
#define MC_L2E   (1.442695040888963)
#define MC_PI2   (9.869604401089359)
#define MC_SPI   (1.772453850905516)
#define MC_TORAD(d) (d * 0.017453292519943)
#define MC_TODEG(r) (r * 57.29577951308232)


#include <math.h>
#include <stdint.h>

class M {
public:

/************************************ BASIC FUNCTIONS *************************************/

	static inline float abs(float f) {
		return (float) ::fabs(f);
	}

	static inline float recip(float f) {
		return (float) (1.0 / f);
	}

	static inline float ceil(float f) {
		return (float) ::ceil(f);
	}

	static inline float floor(float f) {
		return (float) ::floor(f);
	}

	static inline float trunc(float f) {
		return (float) ::trunc(f);
	}

	static inline float round(float f) {
		return (float) ::round(f);
	}

	static inline float div(float x, float y) {
		return (float) ::trunc(x / y);
	}

	static inline float mod(float x, float y) {
		return (float) ::fmod(x, y);
	}

	static inline float max(float x, float y) {
		return (float) ::fmax(x, y);
	}

	static inline float min(float x, float y) {
		return (float) ::fmin(x, y);
	}

	static inline float clamp(float x, float mi, float ma) {
		return max(min(x, ma), mi);
	}

	static inline float inf(void) {
		union { float f; uint32_t i; } u;
		u.i = 0x7F800000;
		return u.f;
	}

	static inline float nan(void) {
		union { float f; uint32_t i; } u;
		u.i = 0x7FFFFFFF;
		return u.f;
	}

	static inline bool isinf(float f) {
		union { float f; uint32_t i; } u;
		u.f = f;
		u.i &= 0x7FFFFFFF;
		return (u.i == 0x7F800000);
	}

	static inline bool isnan(float f) {
		union { float f; uint32_t i; } u;
		u.f = f;
		u.i &= 0x7FFFFFFF;
		return (u.i > 0x7F800000);
	}

/************************************ POWER FUNCTIONS *************************************/

	static inline float exp(float f) {
		return (float) ::exp(f);
	}

	static inline float ln(float f) {
		return (float) ::log(f);
	}

	static inline float logb(float x, float y) {
		return (float) (::log(x) / ::log(y));
	}

	static inline float rsqrt(float f) {
		return (float) (1.0f / ::sqrt(f));
	}

	static inline float sqrt(float f) {
		return (float) ::sqrt(f);
	}

	static inline float cbrt(float f) {
		return (float) ::cbrt(f);
	}

	static inline float hypot(float x, float y) {
		return (float) ::hypot(x, y);
	}

	static inline float pow(float x, float y) {
		return (float) ::pow(x, y);
	}

/******************************** TRIGONOMETRY FUNCTIONS **********************************/

	static inline float sin(float f) {
		return (float) ::sin(f);
	}

	static inline float cos(float f) {
		return (float) ::cos(f);
	}

	static inline float tan(float f) {
		return (float) ::tan(f);
	}

	static inline float asin(float f) {
		return (float) ::asin(f);
	}

	static inline float acos(float f) {
		return (float) ::acos(f);
	}

	static inline float atan(float f) {
		return (float) ::atan(f);
	}

	static inline float atan2(float y, float x) {
		return (float) ::atan2(y, x);
	}

/********************************* HYPERBOLIC FUNCTIONS ***********************************/

	static inline float sinh(float f) {
		return (float) ::sinh(f);
	}

	static inline float cosh(float f) {
		return (float) ::cosh(f);
	}

	static inline float tanh(float f) {
		return (float) ::atanh(f);
	}

	static inline float asinh(float f) {
		return (float) ::asinh(f);
	}

	static inline float acosh(float f) {
		return (float) ::acosh(f);
	}

	static inline float atanh(float f) {
		return (float) ::atanh(f);
	}

 /********************************** SPECIAL FUNCTIONS ************************************/

	static inline float erf(float f) {
		return (float) ::erf(f);
	}

	static inline float inverf(float f) {
		float f2 = f * f;
		float i = 0.05837250087F * f2 + 0.07329907936F;
		i *= f2 + 0.09766361950F;
		i *= f2 + 0.14393173084F;
		i *= f2 + 0.26179938779F;
		i *= f2 + 1;
		return (float) (i * f * 0.5 * MC_SPI);
	}

};

#endif
