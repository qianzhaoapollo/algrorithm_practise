/*
 * main.cpp
 *
 *  Created on: 2018Äê4ÔÂ26ÈÕ
 *      Author: super
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "kalman/kalman.h"
#include "gaussiannoise/gaussiannoise.h"
using namespace std;

void test_kalman()
{
	srand(time(NULL));
	kalman state;
	int count = 0;
	while (count < 400) {
//		float measure = 50.0 + rand()%1000 / 100;
		float measure = 50.0 + generateGaussianNoise(0, 5);
		cout << measure << "\t";
		state.kalman1_filter(measure);
		count++;
	}
}


int main()
{
	freopen("out.txt", "w", stdout);
	test_kalman();
	return 0;
}


