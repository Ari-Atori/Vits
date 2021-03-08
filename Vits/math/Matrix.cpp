#include "Matrix.hpp"
#include "../Math.hpp"

M3 M3::operator = (M3 const& m) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			this->c[i][j] = m.c[i][j];
	return (*this);
}

M3 M3::operator - () {
	M3 d;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			d.c[i][j] = -this->c[i][j];
	}
	return d;
}

M3 M3::operator + (M3 const& m) {
	M3 d;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			d.c[i][j] = this->c[i][j] + m.c[i][j];
	return d;
}

M3 M3::operator - (M3 const& m) {
	M3 d;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			d.c[i][j] = this->c[i][j] - m.c[i][j];
	return d;
}

M3 M3::operator * (M3 const& m) {
	M3 d;
	for (int r = 0; r < 3; r++)
		for (int c = 0; c < 3; c++) {
			d.c[r][c] = 0;
			for (int i = 0; i < 3; i++)
				d.c[r][c] += this->c[r][i] * m.c[i][c];
		}
	return d;
}

M3 M3::operator * (float f) {
	M3 d;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			d.c[i][j] = this->c[i][j] * f;
	return d;
}

M3 M3::operator / (float f) {
	M3 d;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			d.c[i][j] = this->c[i][j] / f;
	return d;
}

float M3::det()
{
	return
		c[0][0] * c[1][1] * c[2][2] +
		c[0][1] * c[1][2] * c[2][0] +
		c[0][2] * c[1][0] * c[2][1] -
		c[2][0] * c[1][1] * c[0][2] -
		c[2][1] * c[1][2] * c[2][0] -
		c[2][2] * c[1][0] * c[2][1];
}

M4 M4::operator = (M4 const &m) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			this->c[i][j] = m.c[i][j];
	return (*this);
}

M4 M4::operator - () {
	M4 d;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            d.c[i][j] = -this->c[i][j];
	}
	return d;
}

M4 M4::operator + (M4 const &m) {
	M4 d;
	for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
			d.c[i][j] = this->c[i][j] + m.c[i][j];
	return d;
}

M4 M4::operator - (M4 const &m) {
	M4 d;
	for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
			d.c[i][j] = this->c[i][j] - m.c[i][j];
	return d;
}

M4 M4::operator * (M4 const &m) {
	M4 d;
	for (int r = 0; r < 4; r++)
		for (int c = 0; c < 4; c++) {
			d.c[r][c] = 0;
			for (int i = 0; i < 4; i++)
				d.c[r][c] += this->c[r][i] * m.c[i][c];
		}
	return d;
}

M4 M4::operator * (float f) {
	M4 d;
	for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
			d.c[i][j] = this->c[i][j] * f;
	return d;
}

M4 M4::operator / (float f) {
	M4 d;
	for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
			d.c[i][j] = this->c[i][j] / f;
	return d;
}

float M4::det()
{
	return
		c[0][3] * c[1][2] * c[2][1] * c[3][0] - c[0][2] * c[1][3] * c[2][1] * c[3][0] -
		c[0][3] * c[1][1] * c[2][2] * c[3][0] + c[0][1] * c[1][3] * c[2][2] * c[3][0] +
		c[0][2] * c[1][1] * c[2][3] * c[3][0] - c[0][1] * c[1][2] * c[2][3] * c[3][0] -
		c[0][3] * c[1][2] * c[2][0] * c[3][1] + c[0][2] * c[1][3] * c[2][0] * c[3][1] +
		c[0][3] * c[1][0] * c[2][2] * c[3][1] - c[0][0] * c[1][3] * c[2][2] * c[3][1] -
		c[0][2] * c[1][0] * c[2][3] * c[3][1] + c[0][0] * c[1][2] * c[2][3] * c[3][1] +
		c[0][3] * c[1][1] * c[2][0] * c[3][2] - c[0][1] * c[1][3] * c[2][0] * c[3][2] -
		c[0][3] * c[1][0] * c[2][1] * c[3][2] + c[0][0] * c[1][3] * c[2][1] * c[3][2] +
		c[0][1] * c[1][0] * c[2][3] * c[3][2] - c[0][0] * c[1][1] * c[2][3] * c[3][2] -
		c[0][2] * c[1][1] * c[2][0] * c[3][3] + c[0][1] * c[1][2] * c[2][0] * c[3][3] +
		c[0][2] * c[1][0] * c[2][1] * c[3][3] - c[0][0] * c[1][2] * c[2][1] * c[3][3] -
		c[0][1] * c[1][0] * c[2][2] * c[3][3] + c[0][0] * c[1][1] * c[2][2] * c[3][3];
}

M4 M4::model(V3 t, Q r, V3 s) {
	M4 T = M4_IDENTITY;
	T.c[0][3] = t.x; T.c[1][3] = t.y; T.c[2][3] = t.z;

	M4 S = M4_IDENTITY;
	S.c[0][0] = s.x; S.c[1][1] = s.y; S.c[2][2] = s.z;

	M4 R = M4_IDENTITY;
	R.c[0][0] = 1-2*r.y*r.y-2*r.z*r.z;  R.c[0][1] = 2*r.x*r.y - 2*r.z*r.w;  R.c[0][2] = 2*r.x*r.z + 2*r.y*r.w;
	R.c[1][0] = 2*r.x*r.y + 2*r.z*r.w;  R.c[1][1] = 1-2*r.x*r.x-2*r.z*r.z;  R.c[1][2] = 2*r.y*r.z - 2*r.x*r.w;
	R.c[2][0] = 2*r.x*r.z - 2*r.y*r.w;  R.c[2][1] = 2*r.y*r.z + 2*r.x*r.w;  R.c[2][2] = 1-2*r.x*r.x-2*r.y*r.y;

	return T * R * S;
}