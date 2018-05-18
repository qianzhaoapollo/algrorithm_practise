/*
 * ZhangChong.cpp
 *
 *  Created on: 2018Äê5ÔÂ17ÈÕ
 *      Author: super
 */
#include <iostream>
#include <math.h>
#include "ZhangChong.h"

ZhangChong::ZhangChong() : C1(1), C2(1), C3(1) {
	// TODO Auto-generated constructor stub
	init();
}

ZhangChong::~ZhangChong() {
	// TODO Auto-generated destructor stub
}

void ZhangChong::init()
{
	theta = 0.0;
	w_ = 0.47;
	pc = 1.0;
	h[0] = 0.32;

	t = 0.32;

	C = 1.0;
}

void ZhangChong::calculate()
{
	for(int i=0; i< 99; i++) {

		Ec[i] = pc * (h[i] / (2*t));

		El[i] = pc*h[i]*h[i] / (C*t*(t + h[i]));

		h[i+1] = C1 * (Ec[i] +1) - C2 / (El[i] +1);

		std::cout << h[i] << "\t";

		w[i] = C3 * (El[i] + 1);

		theta = acos((-w[i]*w[i] + h[i]*h[i] + w_*w_ + h[i]*h[i])/(2*h[i]*sqrt(h[i]*h[i] + w[i]*w[i])))
				-atan(w_/h[i]);

		std::cout << theta << std::endl;
//		Ec[i] = pc * (h[i] / (2*t[i]));
//
//		El[i] = pc*h[i]*h[i] / (C*t*(t + h[i]));
	}
}
