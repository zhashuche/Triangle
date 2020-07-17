#include"Triangle.h"


void Triangle::setPoint(esPoint2f _a, esPoint2f _b, esPoint2f _c)
{
	A = _a;
	B = _b;
	C = _c;

	return;
}

bool Triangle::IsTriangle()
{
	return  (!(IsThreePointInLine(A.x, A.y, B.x, B.y, C.x, C.y)));
}

void Triangle::Calc()
{
	ISTriangle = IsTriangle();
	if (!ISTriangle)
	{
		CalcF = 1;

		return;
	}

	//	L1 - CA 
	A1 = A.y - C.y;
	B1 = C.x - A.x;
	C1 = A.x * C.y - C.x * A.y;
	//直线向量
	V_L1_X = A.x - C.x;
	 V_L1_Y = A.y - C.y;



	 //	L2 - AB
	A2 = B.y - A.y;
	B2 = A.x - B.x;
	C2 = B.x * A.y - A.x * B.y;
	//直线向量
	V_L2_X = B.x - A.x;
	 V_L2_Y = B.y - A.y;


	 //	L3 - BC
	A3 = C.y - B.y;
	B3 = B.x - C.x;
	C3 = C.x * B.y - B.x * C.y;
	//直线向量
	V_L3_X = C.x - B.x;
	V_L3_Y = C.y - B.y;





	//对边长度
	a = Norm_p((C - B).x, (C - B).y);
	b = Norm_p((A - C).x, (A - C).y);
	c = Norm_p((B - A).x, (B - A).y);

	//三角形面积
	S = Cross_p12((B - A).x, (B - A).y, (C - A).x, (C - A).y) / 2;

	//内心
	PL.x = (a * A.x + b * B.x + c * C.x) / (a + b + c);
	PL.y = (a * A.y + b * B.y + c * C.y) / (a + b + c);

	//内接圆半径
	 r = PointToLineDistance(PL.x, PL.y, A1, B1, C1);

	//旁切圆半径
	 rA = (2 * S) / (b + c - a);
	 rB = (2 * S) / (a + c - b);
	 rC = (2 * S) / (a + b - c);

	float p = (a + b + c) / 2;

	//计算A-B垂直单位向量
	float v_ab_e_x = 0;
	float v_ab_e_y = 0;
	Verte((B - A).x, (B - A).y, v_ab_e_x, v_ab_e_y, 1);
	//A点对应旁心
	PW3_A.x = ((B - A).x / c) * p + A.x + rA * v_ab_e_x;
	PW3_A.y = ((B - A).y / c) * p + A.y + rA * v_ab_e_y;

	//计算B-C垂直单位向量
	float v_bc_e_x = 0;
	float v_bc_e_y = 0;
	Verte((C - B).x, (C - B).y, v_bc_e_x, v_bc_e_y, 1);
	//B点对应旁心
	PW3_B.x = ((C - B).x / a) * p + B.x + rB * v_bc_e_x;
	PW3_B.y = ((C - B).y / a) * p + B.y + rB * v_bc_e_y;

	//计算C-A垂直单位向量
	float v_ca_e_x = 0;
	float v_ca_e_y = 0;
	Verte((A - C).x, (A - C).y, v_ca_e_x, v_ca_e_y, 1);
	//C点对应旁心
	PW3_C.x = ((A - C).x / b) * p + C.x + rC * v_ca_e_x;
	PW3_C.y = ((A - C).y / b) * p + C.y + rC * v_ca_e_y;




	CalcF = 1;
	return;
}

int  Triangle::WhatTriangle()//三角形类型
{
	int Flag = 0;

	if (!(IsTriangle()))
	{
		return Flag;
	}

	//没空




	return Flag;
}

float Triangle::ZhouChang()
{
	if (!ISTriangle)
	{
		return 0;
	}

	//对边长度
	a = Norm_p((C - B).x, (C - B).y);
	b = Norm_p((A - C).x, (A - C).y);
	c = Norm_p((B - A).x, (B - A).y);

	return (a + b + c);
}

float Triangle::MianJi()
{
	if (!ISTriangle)
	{
		return 0;
	}

	S = Cross_p12((B - A).x, (B - A).y, (C - A).x, (C - A).y) / 2;

	return(S);
}

esCircle Triangle::NeiXin()
{
	esCircle NX(0,0,0);

	if (!ISTriangle)
	{
		return NX;
	}
	if (!CalcF)
	{
		Calc();
	}

	NX.X = PL.x;
	NX.Y = PL.y;
	NX.R = r;

	return NX;
}

esPoint2f Triangle::ChuiXin()
{
	if (!ISTriangle)
	{
		return PC;
	}
	if (!CalcF)
	{
		Calc();
	}

	//B点在CA线垂轴
	float B_CA_x = 0;
	float B_CA_y = 0;
	float ans33 = 0;
	Point2Line(B.x, B.y, A.x, A.y, C.x, C.y, B_CA_x, B_CA_y, ans33);

	//C点在AB线垂轴
	float C_BA_x = 0;
	float C_BA_y = 0;
	float ans34 = 0;
	Point2Line(C.x, C.y, A.x, A.y, B.x, B.y, C_BA_x, C_BA_y, ans34);

	//两条垂线交点
	float aa1 = 0;
	float bb1 = 0;
	float cc1 = 0;

	float aa2 = 0;
	float bb2 = 0;
	float cc2 = 0;

	P12ToABC(B.x, B.y, B_CA_x, B_CA_y, aa1, bb1, cc1);
	P12ToABC(C.x, C.y, C_BA_x, C_BA_y, aa2, bb2, cc2);

	float pcx = 0;
	float pcy = 0;

	LineCrossLine(aa1,bb1,cc1,aa2,bb2,cc2,pcx,pcy);
	PC.x = pcx;
	PC.y = pcy;

	return PC;
}

esPoint2f Triangle::ZhongXing()
{

	PZ.x = (A.x + B.x + C.x) / 3;
	PZ.y = (A.y + B.y + C.y) / 3;

	return PZ;
}

esCircle Triangle::WaiXin()
{
	esCircle WX(0,0,0);
	if (!ISTriangle)
	{
		return WX;
	}

	float WCX = 0;
	float WCY = 0;
	float WCR = 0;

	GetCircleFrom3Point(A.x,A.y,B.x,B.y,C.x,C.y,WCX,WCY,WCR);
	WX.X = WCX;
	WX.Y = WCY;
	WX.R = WCR;

	PW.x = WCX;
	PW.y = WCY;
	rW = WCR;


	return WX;
}

vector< esCircle> Triangle::PangXin()
{
	vector< esCircle> PX;

	if (!ISTriangle)
	{
		return PX;
	}
	if (!CalcF)
	{
		Calc();
	}

	PX.push_back(esCircle(PW3_A.x, PW3_A.y,rA));
	PX.push_back(esCircle(PW3_B.x, PW3_B.y, rB));
	PX.push_back(esCircle(PW3_C.x, PW3_C.y, rC));


	return PX;
}

vector<float> Triangle::BianChang()
{
	vector<float>BIANC;
	if (!ISTriangle)
	{
		return BIANC;
	}

	//对边长度
	a = Norm_p((C - B).x, (C - B).y);
	b = Norm_p((A - C).x, (A - C).y);
	c = Norm_p((B - A).x, (B - A).y);

	BIANC.push_back(a);
	BIANC.push_back(b);
	BIANC.push_back(c);

	return BIANC;

}