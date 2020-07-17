#pragma once
#include <vector>

template<typename T> struct esPoint2_ {
	esPoint2_() : x(0), y(0) {}
	esPoint2_(T _x, T _y) : x(_x), y(_y) {}
	esPoint2_ operator+(const esPoint2_<T> &pt) const {
		return esPoint2_<T>(x + pt.x, y + pt.y);
	}
	esPoint2_ operator-(const esPoint2_<T> &pt) const {
		return esPoint2_<T>(x - pt.x, y - pt.y);
	}

	esPoint2_ operator=(const esPoint2_<T> &pt) {
		x = pt.x;
		y = pt.y;
		return *this;
	}
	esPoint2_<T> operator * (const T &value) {
		return esPoint2_<T>(x * value, y * value);
	}
	esPoint2_<T> operator / (const T &value) {
		return esPoint2_<T>(x / value, y / value);
	}


	T x;
	T y;
};
typedef esPoint2_<int> esPoint2i;
typedef esPoint2_<float> esPoint2f;
typedef esPoint2_<double> esPoint2d;

template<typename T> struct esPoint3_ {
	esPoint3_() : x(0), y(0), z(0) {}
	esPoint3_(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
	T x;
	T y;
	T z;
};
typedef esPoint3_<int> esPoint3i;
typedef esPoint3_<float> esPoint3f;
typedef esPoint3_<double> esPoint3d;


struct vector_pxy//点集
{
	std::vector<esPoint2f> Pointxy;
};

struct esCircle //圆
{
	esCircle(float _x, float _y, float _r) :X(_x), Y(_y), R(_r) {}
	esCircle(): X(0), Y(0),R(0){}

	float X;
	float Y;
	float R;
};

struct esRect//矩形
{
	esRect(int _Left, int _Top, int _Width,int _Height) : Left(_Left), Top(_Top), Width(_Width), Height(_Height){}
	esRect(): Left(0), Top(0), Width(0), Height(0){}

	int Left;
	int Top;
	int Width;
	int Height;
};

struct esRotatedRect
{
	float CentorX;
	float CentorY;

	float Width;
	float Height;

	float Angle;

};



struct RGB3//颜色
{
	RGB3(int _R, int _G,int _B) : R(_R), G(_G) ,B(_B) {}

	int R;
	int G;
	int B;
};

struct RGB4//颜色
{
	RGB4(int _R, int _G, int _B,float _A) : R(_R), G(_G), B(_B),A(_A) {}
	int R;
	int G;
	int B;

	float A;
};