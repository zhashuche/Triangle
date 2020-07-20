#pragma once
#include "math.h"
#include <cmath>

//基本C++数学函数

#define PI 3.1415926535897932384626433832795
#define EPSILON  0.000001


//向量长度
float Norm_p(float x1, float y1);
//向量点积//内积
float Dot_p12(float x1, float y1, float x2, float y2);
//外积 叉乘 平行四边形面积
float Cross_p12(float x1, float y1, float x2, float y2);
//计算向量与水平方向夹角 0 - 360度
float GetAngle_0_360_by_x(float x, float y);
//计算向量的垂直单位向量
void Verte(float x, float y, float &x_1, float &y_1, int type);
//判断点在向量左侧右侧:P1P2P3逆时针时为正，当P1P2P3顺时针时为负。
bool SideCheck(float x1, float y1, float x2, float y2, float x3, float y3);


//计算点与点之间距离
float TwoPointDistance(float x1, float y1, float x2, float y2);
//点到直线距离
float PointToLineDistance(float X0, float Y0, float A, float B, float C);
//计算点到直线垂线  垂足 x0,y0
void Point2Line(float x, float y, float p1_x, float p1_y, float p2_x, float p2_y, float &x0, float &y0, float &Distance);
//直线方程两点式转ABC式
void P12ToABC(float X1,float Y1, float X2,float Y2, float &A, float &B, float &C);
//两直线交点
void LineCrossLine(float A1, float B1, float C1, float A2, float B2, float C2, float &xx, float &yy);
//两直线是否平行夹角小于EPSILON即为平行
bool IsTwoLineParallel(float A1, float B1, float C1, float A2, float B2, float C2);
//三点是否共线
bool IsThreePointInLine(float X1, float Y1, float X2, float Y2, float X3, float Y3);

//判断某一点是否在多边形内部
int Pnpoly(int nVert, float *pVertX, float *pVertY, float fX, float fY);
//根据三个点计算圆
bool GetCircleFrom3Point(float X1, float Y1, float X2, float Y2, float X3, float Y3, float &CX, float &CY, float &radius);


//计算一列数据质心
float CentroidsofNumbers(float *Numbers, int Num, int Flag);
//计算一列数据梯度
void DiffofNumbers(const float *NumbersIn, float *NumbersOut, int Num);



