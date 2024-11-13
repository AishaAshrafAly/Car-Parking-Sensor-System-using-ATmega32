/*
 * ultrasonic.h
 *
 *  Created on: Oct 16, 2024
 *      Author: aisha
 */


#ifndef HAL_ULTRASONIC_ULTRASONIC_H_
#define HAL_ULTRASONIC_ULTRASONIC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ULTRASONIC_TRIG_PORTID             PORTD_ID
#define ULTRASONIC_TRIG_PINID              PIN7_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function to Initialize the Ultrasonic sensor
 * Input: void
 * Output: void
 */
void Ultrasonic_init(void);

/*
 * Description :
 * Function to Send the trigger pulse to the ultrasonic sensor.
 * Input: void
 * Output: void
 */
void Ultrasonic_Trigger(void);

/*
 * Description :
 * Function to Calculate The measured distance in centimeters.
 * Input: void
 * Output: void
 */
uint16 Ultrasonic_readDistance(void);

/*
 * Description :
 * Function to calculate the high time (pulse time) generated by the ultrasonic sensor.
 * Input: void
 * Output: void
 */
void Ultrasonic_edgeProcessing(void);

#endif /* HAL_ULTRASONIC_ULTRASONIC_H_ */
