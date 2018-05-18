/*
 * main.cpp
 *
 *  Created on: 2018Äê4ÔÂ26ÈÕ
 *      Author: super
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "kalman/kalman.h"
#include "gaussiannoise/gaussiannoise.h"
using namespace std;


int mag1[3000], mag2[3000], mag3[3000], mag4[3000];
int mag5[3000], mag6[3000], mag7[3000], mag8[3000];

void test_kalman()
{
	srand(time(NULL));
	kalman state;
	int count = 0;
	while (count < 400) {
//		float measure = 50.0 + rand()%1000 / 100;
		float measure = 50.0 + generateGaussianNoise(0, 2);
		cout << measure << "\t";
		state.kalman1_filter(measure);
		count++;
	}
}

void kalman_filter()
{
	kalman state2;
	int count = 0;
//	while(count < 3000) {
//		cout << mag1[count] << "\t";
//		state2.kalman1_filter(mag1[count]);
//		count++;
//	}
	for (int i=0; i<3000; i++) {
//		cout << mag1[count] << "\t";
		state2.kalman1_filter(mag1[count]);
		state2.kalman1_filter(mag2[count]);
		state2.kalman1_filter(mag3[count]);
		state2.kalman1_filter(mag4[count]);
		state2.kalman1_filter(mag5[count]);
		state2.kalman1_filter(mag6[count]);
		state2.kalman1_filter(mag7[count]);
		state2.kalman1_filter(mag8[count]);
		cout << endl;
		count++;
	}
}

void readFile()
{
	freopen("file.csv", "r", stdin);

	char str[100];

	memset(mag1, 0, sizeof(mag1));
	memset(mag2, 0, sizeof(mag2));
	memset(mag3, 0, sizeof(mag3));
	memset(mag4, 0, sizeof(mag4));
	memset(mag5, 0, sizeof(mag5));
	memset(mag6, 0, sizeof(mag6));
	memset(mag7, 0, sizeof(mag7));
	memset(mag8, 0, sizeof(mag8));

//	int linenum = 0;

	while(scanf("%s", str) == 1) {
//		if (linenum == 0) {
//			linenum++;
//			continue;
//		}
		int cache;
		for(int i=0; i < 3000; i++) {
			scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d\n",&cache, &mag1[i], &mag2[i], &mag3[i], &mag4[i]
											  ,&mag5[i], &mag6[i], &mag7[i], &mag8[i]);
		}
//		printf("%s\n", c);

//		int count = 0;
//		while(*c != '\n') {
//			cout << *c  << endl;
//
//			if(*c == ',') {
//				count++;
//				c++;
//			}
//			if(count == 0)
//				c++;
//			if(count == 1) {
//				mag1[linenum] = mag1[linenum] * 10 + *c - '0';
//			} else if(count == 2) {
//				mag2[linenum] = mag2[linenum] * 10 + *c - '0';
//			} else if(count == 3) {
//				mag3[linenum] = mag3[linenum] * 10 + *c - '0';
//			} else if(count == 4) {
//				mag4[linenum] = mag4[linenum] * 10 + *c - '0';
//			} else if(count == 5) {
//				mag5[linenum] = mag5[linenum] * 10 + *c - '0';
//			} else if(count == 6) {
//				mag6[linenum] = mag6[linenum] * 10 + *c - '0';
//			} else if(count == 7) {
//				mag7[linenum] = mag7[linenum] * 10 + *c - '0';
//			} else if(count == 8){
//				mag8[linenum] = mag8[linenum] * 10 + *c - '0';
//			}
//			c++;
//		}
//		linenum++;
	}

//	for(int i=0; i < 3000; i++) {
//		printf("%d,%d,%d,%d,%d,%d,%d,%d\n",mag1[i], mag2[i], mag3[i], mag4[i]
//										  ,mag5[i], mag6[i], mag7[i], mag8[i]);
//	}

}


int main()
{
//	freopen("out.csv", "w", stdout);
	test_kalman();
//	readFile();
//	kalman_filter();
	return 0;
}


