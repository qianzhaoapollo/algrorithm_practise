/*
 * ZhangChong.h
 *
 *  Created on: 2018Äê5ÔÂ17ÈÕ
 *      Author: super
 */

#ifndef ZHANGCHONG_H_
#define ZHANGCHONG_H_

class ZhangChong {
private:
	float C1;
	float C2;
	float C3;

	float h[100];
	float Ec[100];
	float El[100];

	float w[100];

	float theta;
	float w_;
	float pc;
	float t;

	float C;

	void init();

public:
	ZhangChong();
	virtual ~ZhangChong();

	void calculate();
};

#endif /* ZHANGCHONG_H_ */
