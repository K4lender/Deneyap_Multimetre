/*
*****************************************************************************
@file         Deneyap_Multimetre.h
@mainpage     Deneyap Multimeter Arduino library header file
@version      v1.0.0
@date         July 27, 2024
@brief        This file contains all function prototypes and macros
              for multimeter Arduino Library for Deneyap Development Boards
*****************************************************************************
*/

#ifndef _DENEYAPMULTIMETER_H
#define _DENEYAPMULTIMETER_H

#include <Arduino.h>

#define NUM_READINGS 500
#define MEASUREMENT_INTERVAL 50
#define RESULATION 4095


class Multimeter {
public:
    float readVolt(int pin, float Vin, float R1, float R2);
    int readADC(int pin);
    float readOhm(int pin, float Vin, float R1);
private:
    int sum;
    uint16_t adcRawValue;
    float adcVoltValue;
    float adcOhmValue;
    int average;
};
#endif // _DENEYAPMULTIMETER_H