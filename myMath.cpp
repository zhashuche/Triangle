#include"myMath.h"


float Norm_p(float x1, float y1)
{
	return sqrt(x1 * x1 + y1 * y1);
}

float Dot_p12(float x1, float y1, float x2, float y2)
{
	return (x1 * x2 + y1 * y2);
}

float Cross_p12(float x1, float y1, float x2, float y2)
{
	return fabs(x1 * y2 - x2 * y1);
}

float GetAngle_0_360_by_x(float x, float y)
{
	y = y * (-1);

	float angle = atan2(y, x);
	angle = angle * 180 / PI;
	if (y > 0)
	{
		return angle;
	}
	else if (y < 0)
	{
		return(360 + angle);
	}
	else
	{
		if (x >= 0)
		{
			return 0;
		}
		else
		{
			return 180;
		}
	}
	return 0;
}

void Verte(float x, float y, float &x_1, float &y_1, int type)
{
	//int type = 0 ��ʾ��������ʱ��

	//x_1 = x;
	//y_1 = -y;

	if (x == 0 && y == 0)
	{
		x_1 = 0;
		y_1 = 0;

		return;
	}
	if (x == 0)
	{
		if (0 == type)//��ֱ������y����С����0��������
		{
			x_1 = -1 * y;
			y_1 = 0;

			x_1 /= abs(x_1);
		}
		else
		{
			x_1 = y;
			y_1 = 0;

			x_1 /= abs(x_1);
		}

		return;
	}
	if (y == 0)
	{
		if (0 == type)//��ֱ������y����С����0��������
		{
			x_1 = 0;
			y_1 = x;
			y_1 /= abs(y_1);
		}
		else
		{
			x_1 = 0;
			y_1 = -1 * x;
			y_1 /= abs(y_1);
		}
		return;
	}



	if (type == 0)
	{
		x_1 = -1 * y;
		y_1 = x;
	}
	else
	{
		x_1 = y;
		y_1 = -1 * x;
	}

	x_1 = x_1 / Norm_p(x_1, y_1);
	y_1 = sqrt(1 - x_1 * x_1);



	return;
}

bool SideCheck(float x1, float y1, float x2, float y2, float x3, float y3)
{
	return ((x1 - x3)*(y2 - y3) - (y1 - y3)*(x2 - x3) <= 0);
}



float TwoPointDistance(float x1, float y1, float x2, float y2)
{
	return (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}

float PointToLineDistance(float X0, float Y0, float A, float B, float C)
{
	float Distance = 0;
	if (sqrt(A * A + B * B) != 0)
	{
		Distance = abs(A * X0 + B * Y0 + C) / sqrt(A * A + B * B);
	}

	return Distance;
}

void Point2Line(float x, float y, float p1_x, float p1_y, float p2_x, float p2_y, float &x0, float &y0, float &Distance)
{
	//ֱ������
	float Lx = p2_x - p1_x;
	float Ly = p2_y - p1_y;
	//��λ����
	float eLx = Lx / Norm_p(Lx, Ly);
	float eLy = Ly / Norm_p(Lx, Ly);

	float t = 0;

	//x0 = p1_x + eLx * t;
	//y0 = p1_y + eLy * t;
	//float ex0x = x - x0;
	//float ey0y = y - y0;
	//��ֱ
	//Lx * ex0x + Ly * ey0y = 0;
	//Lx * (x - (p1_x + eLx * t)) + Ly * (y - (p1_y + eLy * t)) = 0;
	//��� t

	t = (Lx * x - Lx * p1_x + Ly * y - Ly * p1_y) / (Lx * eLx + Ly * eLy);

	x0 = p1_x + eLx * t;
	y0 = p1_y + eLy * t;

	Distance = TwoPointDistance(x, y, x0, y0);

	return;
}

void P12ToABC(float X1, float Y1, float X2, float Y2, float &A, float &B, float &C)
{

	A = Y2 - Y1;
	B = X1 - X2;
	C = X2 * Y1 - X1 * Y2;

}

void LineCrossLine(float A1, float B1, float C1, float A2, float B2, float C2, float &xx, float &yy)
{
	//ֱ�߽���
	//X = (B1 * C2 - B2 * C1) / (A1 * B2 - A2 * B1)
	//Y = (A2 * C1 - A1 * C2) / (A1 * B2 - A2 * B1)

	if (((A1 * B2 - A2 * B1) <EPSILON)  || ((A1 * B2 - A2 * B1) < EPSILON))
	{
		xx = 0;
		yy = 0;
		return;
	}

	xx = (B1 * C2 - B2 * C1) / (A1 * B2 - A2 * B1);
	yy = (A2 * C1 - A1 * C2) / (A1 * B2 - A2 * B1);
}

bool IsTwoLineParallel(float A1, float B1, float C1, float A2, float B2, float C2)
{


	if ((abs(A2) < EPSILON) || (abs(A1) < EPSILON))
	{
		if ((abs(A2) < EPSILON) && (abs(A1) < EPSILON))
		{
			return 1;
		}
		else
		{
			return 0;
		}

	}
	if ((abs(B2) < EPSILON) || (abs(B1) < EPSILON))
	{
		if ((abs(B2) < EPSILON) && (abs(B1) < EPSILON))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}


	float ans1 = abs(A1 / A2 - B1 / B2);

	if (ans1 < EPSILON)
	{
		if (abs(ans1 * C2 - C1) > EPSILON)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}



	return 1;
}

bool IsThreePointInLine(float X1, float Y1, float X2, float Y2, float X3, float Y3)
{
	return (abs((X1 - X2)  * (Y1 - Y3) - (X1 - X3) *  (Y1 - Y2)) < EPSILON);
}

int Pnpoly(int nVert, float *pVertX, float *pVertY, float fX, float fY)
{
	/************************
	�������ܣ��ж�ĳһ���Ƿ��ڶ�����ڲ�
	nVert: ����εĶ�����
	pVertX, pVertY: ����X�����Y����ֱ���ɵ�����
	fX, fY: ��Ҫ���Եĵ��X�����Y����

	ע�ⶥ������Ϊ��ʱ�����룬�������Ͽ������Ϊ0 0 100 100�ľ��Σ���
	int nVert = 4;
	float pVertX[] = {0, 0, 100, 100};
	float pVertY[] = {0,100, 100, 0};

	����ֵΪ0������Ե㲻�ڶ�����ڲ���Ϊ1������Ե��ڶ�����ڲ�
	******************************/
	int i = 0;
	int j = 0;
	int nC = 0;
	for (i = 0, j = nVert - 1; i < nVert; j = i++) {
		if (((pVertY[i] > fY) != (pVertY[j] > fY)) &&
			(fX < (pVertX[j] - pVertX[i]) * (fY - pVertY[i]) / (pVertY[j] - pVertY[i]) + pVertX[i]))
			nC = !nC;
	}
	return nC;
}

bool GetCircleFrom3Point(float X1, float Y1, float X2, float Y2, float X3, float Y3, float &CX, float &CY, float &radius)
{

	//����P1-P2  P2-P3�����߶δ�ֱƽ���߽��� ��ΪԲ��

	float A1 = 0;
	float B1 = 0;
	float C1 = 0;

	float A2 = 0;
	float B2 = 0;
	float C2 = 0;

	//����ʽתABC
	P12ToABC(X1, Y1, X2, Y2, A1, B1, C1);
	P12ToABC(X2, Y2, X3, Y3, A2, B2, C2);
	//��ֱ��ƽ���򷵻�NG
	bool ans1 = IsTwoLineParallel(A1, B1, C1, A2, B2, C2);
	if (ans1)
	{
		CX = 0;
		CY = 0;
		radius = 0;
		return 0;
	}

	//P1-2����
	float ep12_x = X2 - X1;
	float ep12_y = Y2 - Y1;
	//P12�е�
	float p12_x = (X2 + X1) / 2;
	float p12_y = (Y2 + Y1) / 2;
	//P1-2��ֱ��λ����
	float vp12_x = 0;
	float vp12_y = 0;
	Verte(ep12_x, ep12_y, vp12_x, vp12_y, 0);

	//P1-2 ��ֱ����ֱ��
	P12ToABC(p12_x, p12_y, p12_x + vp12_x, p12_y + vp12_y, A1, B1, C1);



	//P2-3����
	float ep23_x = X3 - X2;
	float ep23_y = Y3 - Y2;
	//P2-3�е�
	float p23_x = (X3 + X2) / 2;
	float p23_y = (Y3 + Y2) / 2;
	//P2-3��ֱ��λ����
	float vp23_x = 0;
	float vp23_y = 0;
	Verte(ep23_x, ep23_y, vp23_x, vp23_y, 0);

	//P2-3 ��ֱ����ֱ��
	P12ToABC(p23_x, p23_y, p23_x + vp23_x, p23_y + vp23_y, A2, B2, C2);


	//��ֱ�߽��㼴ΪԲ��
	float xx = 0;
	float yy = 0;
	LineCrossLine(A1, B1, C1, A2, B2, C2, xx, yy);
	CX = xx;
	CY = yy;

	radius = TwoPointDistance(xx, yy, X1, Y1);


	return 1;
}

float CentroidsofNumbers(float *Numbers, int Num, int Flag)
{
	float Mid_x = 0;
	if (Flag ==1)
	{
		float ans1 = 0;
		float ans2 = 0;
		for (int i = 0; i < Num; i++)
		{
			ans1 += Numbers[i] * i;
			ans2 += Numbers[i];
		}
		Mid_x = ans1 / ans2;
	}

	return Mid_x;
}

void DiffofNumbers(const float *NumbersIn, float *NumbersOut, int Num)
{
	for (int i = 1; i < Num-1; i++)
	{
		NumbersOut[i] = (NumbersIn[i+1] - NumbersIn[i-1]) / 2;
	}
	NumbersOut[0] = NumbersIn[1] - NumbersIn[0];
	NumbersOut[Num-1] = NumbersIn[Num-1] - NumbersIn[Num-2];

	return;
}




