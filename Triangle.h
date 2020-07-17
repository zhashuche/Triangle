#pragma once

#include "math.h"
#include <stdio.h>
#include <vector>    

#include"esStruct.h"
#include"myMath.h"

using namespace std;



//��֧1

/*
�����η���:
	���Ƿ�
				ֱ��
				�۽�
				���
	���߷�
				�ȱ�
				����
				���ȱ�

��7��������:

				ֱ��			�۽�			���
	�ȱ�		X					X					1


	����		2					3					4


	���ȱ�   5					6					7

	��������  0

*/

class Triangle
{
public:
	Triangle() : A(0, 0), B(0, 0), C(0, 0) {}
	Triangle(esPoint2f _a, esPoint2f _b, esPoint2f _c) : A(_a), B(_b), C(_c) {}
	~Triangle() {};
	void setPoint(esPoint2f _a, esPoint2f _b, esPoint2f _c);

	bool IsTriangle();//�Ƿ�Ϊ������
	int  WhatTriangle();//����������
	void Calc();

	float ZhouChang();//�ܳ�
	float MianJi();//���
	esCircle NeiXin();//�ڽ�Բ
	esPoint2f ChuiXin();//����
	esPoint2f ZhongXing();//����
	esCircle WaiXin();//���Բ
	vector< esCircle> PangXin();//�Խ�Բ,����ABC�����Ӧ���Խ�Բ
	vector<float> BianChang();//�߳�,����ABC�����Ӧ�ı߳�

private:

	//�м�����
	//	L1 - CA
	float A1 = 0;
	float B1 = 0;
	float C1 = 0;
	//ֱ������
	float V_L1_X = 0;
	float V_L1_Y = 0;


	//	L2 - AB
	float A2 = 0;
	float B2 = 0;
	float C2 = 0;
	//ֱ������
	float V_L2_X = 0;
	float V_L2_Y = 0;

	//	L3 - BC
	float A3 = 0;
	float B3 = 0;
	float C3 = 0;
	//ֱ������
	float V_L3_X = 0;
	float V_L3_Y = 0;




private:

	//��������
	esPoint2f A;
	esPoint2f B;
	esPoint2f C;

	//���������Ӧ�ı߳�
	float a = 0;
	float b = 0;
	float c = 0;

	//���������
	float S = 0;

	//����
	esPoint2f PL;
	float r = 0;

	//����
	esPoint2f PW3_A;
	esPoint2f PW3_B;
	esPoint2f PW3_C;
	float rA = 0;
	float rB = 0;
	float rC = 0;

	//����
	esPoint2f PZ;

	//����
	esPoint2f PC;

	//����
	esPoint2f PW;
	float rW;



	bool ISTriangle = 0;
	int CalcF = 0;
};

