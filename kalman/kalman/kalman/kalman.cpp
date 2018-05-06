/*
 * kalman.cpp
 *
 *  Created on: 2018Äê4ÔÂ26ÈÕ
 *      Author: super
 */

#include <iostream>
#include "kalman.h"
using namespace std;

kalman::kalman(){
	// TODO Auto-generated constructor stub
	float init_x = 0.0;
	float init_p = 1.0;
	Kalman1_init(init_x, init_p);
}

kalman::~kalman() {
	// TODO Auto-generated destructor stub
}

void kalman::Kalman1_init(float init_x, float init_p)
{
	x = init_x;
	p = init_p;
	A = 1;
	H = 1;
	q = 5;
	r = 5;
}

float kalman::kalman1_filter(float z_measure)
{
	/* Predict */
	x = A * x;
	p = A * A * p + q;

	/* Measurement */
	gain = p * H / (p * H * H + r);
	x = x + gain * (z_measure - H * x);
	p = (1 - gain * H) * p;
	cout << x << endl;
	return x;
}
