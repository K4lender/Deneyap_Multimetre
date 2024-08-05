/*
*************************************************************************************************
@file         Deneyap_Multimetre.cpp
@mainpage     Deneyap Multimeter Arduino library source file
@version      v1.0.0
@date         July 27, 2024
@brief        Includes functions multimeter for Deneyap Development Boards
*************************************************************************************************
*/

#include "Deneyap_Multimetre.h"

/**
 * @brief   Reading voltage value
 * @param   @pin : ADC pin
 *          @Vin : Maximum voltage value given
 *          @R1 : voltage divider resistance value
 *          @R2 : resistance value whose voltage is to be measure 
 * @retval  None
**/

float Multimeter::readVolt(int pin, float Vin, float R1, float R2) {
    adcVoltValue = (((readADC(pin) * Vin) / RESULATION) * ((R1 + R2) / R2));
    return adcVoltValue;
}

/**
 * @brief   Reading raw ADC value
 * @param   @pin : ADC pin
 * @retval  None
**/

int Multimeter::readADC(int pin) {
    sum = 0;
    adcRawValue = 0;

    for (int i = 0; i < NUM_READINGS; i++) {
        adcRawValue = analogRead(pin);
        sum += adcRawValue;
    }

    average = sum / NUM_READINGS;
    return average;
}

/**
 * @brief   Reading Ohm value
 * @param   @pin : ADC pin
 *          @Vin : Maximum voltage value given
 *          @R1 : voltage divider resistance value
 * @retval  None
**/

float Multimeter::readOhm(int pin, float Vin, float R1) {
    float Vout = ((readADC(pin) * Vin) / RESULATION;
    adcOhmValue = Vout / ((Vin - Vout) / R1);
    return adcOhmValue;
}