/*
 * main.cpp
 *
 *  Created on: 2018Äê4ÔÂ26ÈÕ
 *      Author: super
 */

#include "kalman/kalman.h"
#include <time.h>
#include <iostream>
#include <stdlib.h>
using namespace std;


void test_kalman()
{
	srand(time(NULL));
	kalman state;
	int count = 0;
	while (count < 800) {
		float measure = 50.0 + rand()%1000 / 100;
		cout << measure << " ";
		state.kalman1_filter(measure);
		count++;
	}
}


int main()
{
	test_kalman();
	return 0;
}


