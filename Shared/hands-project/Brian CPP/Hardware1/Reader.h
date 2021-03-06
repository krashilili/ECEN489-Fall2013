/*
 * Reader.h
 *
 *  Created on: Nov 4, 2013
 *      Author: Michael
 */

#ifndef READER_H_
#define READER_H_

#include "Reading.h"
#include "SerialClass.h"
#include <pthread.h>
#include <iostream>
#include <fstream>

class Reader {
public:
	Reader();
	Reader(int comPortNumber);
	Serial* GetSerial();
	void SetReading(Reading reading);
	Reading GetReading();
	void PrintReading();
	void TurnPrintOn();
	void TurnPrintOff();
	void SetFileName(string name);
	string GetFileName();


private:
	void SpinThread();
	int _comPortNumber;
	Reading _reading;
	Serial* _serial;
	pthread_t _thread;
	bool _print;
	string _fileName;
};

#endif /* READER_H_ */
