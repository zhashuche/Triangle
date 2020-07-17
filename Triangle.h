#pragma once

#include "math.h"
#include <stdio.h>
#include <vector>    

#include"esStruct.h"
#include"myMath.h"

using namespace std;



//分支1

/*
三角形分类:
	按角分
				直角
				钝角
				锐角
	按边分
				等边
				等腰
				不等边

共7种三角形:

				直角			钝角			锐角
	等边		X					X					1


	等腰		2					3					4


	不等边   5					6					7

	非三角形  0

*/

class Triangle
{
public:
	Triangle() : A(0, 0), B(0, 0), C(0, 0) {}
	Triangle(esPoint2f _a, esPoint2f _b, esPoint2f _c) : A(_a), B(_b), C(_c) {}
	~Triangle() {};
	void setPoint(esPoint2f _a, esPoint2f _b, esPoint2f _c);

	bool IsTriangle();//是否为三角形
	int  WhatTriangle();//三角形类型
	void Calc();

	float ZhouChang();//周长
	float MianJi();//面积
	esCircle NeiXin();//内接圆
	esPoint2f ChuiXin();//垂心
	esPoint2f ZhongXing();//重心
	esCircle WaiXin();//外接圆
	vector< esCircle> PangXin();//旁接圆,返回ABC三点对应的旁接圆
	vector<float> BianChang();//边长,返回ABC三点对应的边长

private:

	//中间数据
	//	L1 - CA
	float A1 = 0;
	float B1 = 0;
	float C1 = 0;
	//直线向量
	float V_L1_X = 0;
	float V_L1_Y = 0;


	//	L2 - AB
	float A2 = 0;
	float B2 = 0;
	float C2 = 0;
	//直线向量
	float V_L2_X = 0;
	float V_L2_Y = 0;

	//	L3 - BC
	float A3 = 0;
	float B3 = 0;
	float C3 = 0;
	//直线向量
	float V_L3_X = 0;
	float V_L3_Y = 0;




private:

	//三个顶点
	esPoint2f A;
	esPoint2f B;
	esPoint2f C;

	//三个顶点对应的边长
	float a = 0;
	float b = 0;
	float c = 0;

	//三角形面积
	float S = 0;

	//内心
	esPoint2f PL;
	float r = 0;

	//旁心
	esPoint2f PW3_A;
	esPoint2f PW3_B;
	esPoint2f PW3_C;
	float rA = 0;
	float rB = 0;
	float rC = 0;

	//重心
	esPoint2f PZ;

	//垂心
	esPoint2f PC;

	//外心
	esPoint2f PW;
	float rW;



	bool ISTriangle = 0;
	int CalcF = 0;
};

