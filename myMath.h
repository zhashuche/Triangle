#pragma once
#include "math.h"
#include <cmath>

//����C++��ѧ����

#define PI 3.1415926535897932384626433832795
#define EPSILON  0.000001


//��������
float Norm_p(float x1, float y1);
//�������//�ڻ�
float Dot_p12(float x1, float y1, float x2, float y2);
//��� ��� ƽ���ı������
float Cross_p12(float x1, float y1, float x2, float y2);
//����������ˮƽ����н� 0 - 360��
float GetAngle_0_360_by_x(float x, float y);
//���������Ĵ�ֱ��λ����
void Verte(float x, float y, float &x_1, float &y_1, int type);
//�жϵ�����������Ҳ�:P1P2P3��ʱ��ʱΪ������P1P2P3˳ʱ��ʱΪ����
bool SideCheck(float x1, float y1, float x2, float y2, float x3, float y3);


//��������֮�����
float TwoPointDistance(float x1, float y1, float x2, float y2);
//�㵽ֱ�߾���
float PointToLineDistance(float X0, float Y0, float A, float B, float C);
//����㵽ֱ�ߴ���  ���� x0,y0
void Point2Line(float x, float y, float p1_x, float p1_y, float p2_x, float p2_y, float &x0, float &y0, float &Distance);
//ֱ�߷�������ʽתABCʽ
void P12ToABC(float X1,float Y1, float X2,float Y2, float &A, float &B, float &C);
//��ֱ�߽���
void LineCrossLine(float A1, float B1, float C1, float A2, float B2, float C2, float &xx, float &yy);
//��ֱ���Ƿ�ƽ�мн�С��EPSILON��Ϊƽ��
bool IsTwoLineParallel(float A1, float B1, float C1, float A2, float B2, float C2);
//�����Ƿ���
bool IsThreePointInLine(float X1, float Y1, float X2, float Y2, float X3, float Y3);

//�ж�ĳһ���Ƿ��ڶ�����ڲ�
int Pnpoly(int nVert, float *pVertX, float *pVertY, float fX, float fY);
//�������������Բ
bool GetCircleFrom3Point(float X1, float Y1, float X2, float Y2, float X3, float Y3, float &CX, float &CY, float &radius);


//����һ����������
float CentroidsofNumbers(float *Numbers, int Num, int Flag);
//����һ�������ݶ�
void DiffofNumbers(const float *NumbersIn, float *NumbersOut, int Num);



