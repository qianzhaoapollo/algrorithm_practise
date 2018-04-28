/*
 * kalman.h
 *
 *  Created on: 2018��4��26��
 *      Author: super
 */

#ifndef KALMAN_H_
#define KALMAN_H_

class kalman {
private:
	float x;
	float A;
	float H;
	float q;
	float r;
	float p;
	float gain;

public:
	kalman();
	virtual ~kalman();

	void Kalman1_init(float init_x, float init_p);
	float kalman1_filter(float z_measure);

};

#endif /* KALMAN_H_ */
