/**
 *
 * \file HeightSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HeightSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4-30-2023 09:18 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HeightSensor.h"


/**
 *
 * Runnable HeightSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHeightSensor_GetPosition
 *
 */

void HeightSensor_GetPosition (SensorPositionType* Position)
{
	IoPositionSensorReadingType position;

	/* Server Call Points */
	Rte_Call_rpIOGetHeight_IOGet(&position);

	if (position == 0)
		*Position = SENSOR_POSITION_STEP_0;
	else if (position > 0 && position <= 64)
		*Position = SENSOR_POSITION_STEP_1;
	else if (position > 64 && position <= 192)
		*Position = SENSOR_POSITION_STEP_2;
	else if (position > 192 && position <= 255)
		*Position = SENSOR_POSITION_STEP_3;
}

