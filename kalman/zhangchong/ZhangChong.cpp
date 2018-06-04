/*
 * ZhangChong.cpp
 *
 *  Created on: 2018Äê5ÔÂ17ÈÕ
 *      Author: super
 */
#include <iostream>
#include <math.h>
#include "ZhangChong.h"
#define PI 3.1415926

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
	pc = 29.7;
	h[0] = 0.32;

	t[0] = 0.32;

	C = 1.0;

	Ci[0] = PI * (h[0] + t[0]);

	A[0] = PI * (h[0]/2 + t[0])*(h[0]/2 + t[0]) - PI*(h[0]/2)*(h[0]/2);
}

void ZhangChong::calculate()
{
	for(int i=1; i< 20; i++) {

		t[i] = 2*A[0]*w_/(C[i](w[i]+w_));

		delta_c[i] = pc*(h[i-1] + h[i])/(4*t[i]);

		delta_l[i] = pc*h[i-1]*h[i-1] / (16*t[i]*(t[i] + h[i-1]));

		delta_c[i] = 6.213*Ec[i]*Ec[i]*Ec[i] - 6.2552*Ec[i]*Ec[i] + 3.469*Ec[i] - 0.0534;

		delta_l[i] = 6.213*El[i]*El[i]*El[i] - 6.2552*El[i]*El[i] + 3.469*El[i] - 0.0534;

		w[i] = w_ * (El[i] + 1);

		h[i] = Ci[i] / PI - t[i];

		Ci[i] = Ci[0] * (Ec[i] + 1);



		theta = acos((-w[i]*w[i] + h[i]*h[i] + w_*w_ + h[i]*h[i])/(2*h[i]*sqrt(h[i-1]*h[i-1] + w[i]*w[i])))
				-atan(w_/h[i-1]);


		/*
		Ec[i] = pc * (h[i-1] / (2*t[i]));

		Ci[i] = Ci[0] * (Ec[i] + 1);

		El[i] = pc*h[i-1]*h[i-1] / (16*t[i]*(t[i] + h[i-1]));

		w[i] = C3 * (El[i] + 1);

		//t[i] = sqrt(2*w_*A[0]/(PI*(w[i] + w_)) + (h[i]/2)*(h[i]/2)) - h[i]/2;

		//h[i] = Ci[i] / PI - t[i];

		h[i] = sqrt(w_*A[0]/(PI*(w[i] + w_))) + 3*Ci[i]/(4*PI);

		t[i] = sqrt(2*w_*A[0]/(PI*(w[i] + w_)) + (h[i]/2)*(h[i]/2)) - h[i]/2;

		//h[i] = C1 * (Ec[i] +1) - C2 / (El[i] +1);

		std::cout << h[i] << "\t";

		theta = acos((-w[i]*w[i] + h[i]*h[i] + w_*w_ + h[i]*h[i])/(2*h[i]*sqrt(h[i-1]*h[i-1] + w[i]*w[i])))
				-atan(w_/h[i-1]);
		float angle = theta*180/PI;

		std::cout << angle << std::endl;
//		Ec[i] = pc * (h[i] / (2*t[i]));
//
//		El[i] = pc*h[i]*h[i] / (C*t*(t + h[i]));

		*/
	}
}
