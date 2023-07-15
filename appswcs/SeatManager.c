/**
 *
 * \file SWC_SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SeatMngr
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4-30-2023 07:11 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatManager.h"


 /**
  *
  * Runnable SeatManager_AutoHeight
  *
  * Triggered By:
  *  - TimingEventImpl.TE_SeatManager_AutoHeight_200ms
  *
  */

void SeatManager_AutoHeight(void)
{
	SensorPositionType Position;
	SensorWeightType Weight;

	/* Server Call Points */
	Rte_Call_rpHeightSensor_GetPosition(&Position);
	Rte_Call_rpWeightSensor_GetWeight(&Weight);

	if (Weight >= 100)
	{
		while (Position != SENSOR_POSITION_STEP_3)
		{
			if (Position < SENSOR_POSITION_STEP_3)	/* If the Position is less than required, */
			{
				Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);	/* Increment until reaching the required step */
			}
			else if (Position > SENSOR_POSITION_STEP_3)	/* If the Position is higher than required */
			{
				Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS); /* Decrement until reaching the required step */
			}
			Rte_Call_rpHeightSensor_GetPosition(&Position);
		}
	}
	else if (Weight >= 80 && Weight < 100)
	{
		while (Position != SENSOR_POSITION_STEP_2)
		{
			if (Position < SENSOR_POSITION_STEP_2)	/* If the Position is less than required, */
			{
				Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);	/* Increment until reaching the required step */
			}
			else if (Position > SENSOR_POSITION_STEP_2)	/* If the Position is higher than required */
			{
				Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS); /* Decrement until reaching the required step */
			}
			Rte_Call_rpHeightSensor_GetPosition(&Position);
		}
	}
	else if (Weight >= 60 && Weight < 80)
	{
		while (Position != SENSOR_POSITION_STEP_1)
		{
			if (Position < SENSOR_POSITION_STEP_1)	/* If the Position is less than required, */
			{
				Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);	/* Increment until reaching the required step */
			}
			else if (Position > SENSOR_POSITION_STEP_1)	/* If the Position is higher than required */
			{
				Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS); /* Decrement until reaching the required step */
			}
			Rte_Call_rpHeightSensor_GetPosition(&Position);
		}
	}
	else if (Weight < 60)
	{
		while (Position != SENSOR_POSITION_STEP_0)
		{
			if (Position < SENSOR_POSITION_STEP_0)	/* If the Position is less than required, */
			{
				Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);	/* Increment until reaching the required step */
			}
			else if (Position > SENSOR_POSITION_STEP_0)	/* If the Position is higher than required */
			{
				Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS); /* Decrement until reaching the required step */
			}
			Rte_Call_rpHeightSensor_GetPosition(&Position);
		}
	}
}


/**
 *
 * Runnable SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoIncline_200ms
 *
 */

void SeatManager_AutoIncline(void)
{
	SensorPositionType Position;
	SensorWeightType Weight;

	/* Server Call Points */
	Rte_Call_rpInclineSensor_GetPosition(&Position);
	Rte_Call_rpWeightSensor_GetWeight(&Weight);

	if (Weight >= 100)
	{
		while (Position != SENSOR_POSITION_STEP_3)
		{
			if (Position < SENSOR_POSITION_STEP_3)	/* If the Position is less than required, */
			{
				Rte_Call_rpInclineMotor_Move(MOTOR_STEP_PLUS);	/* Increment until reaching the required step */
			}
			else if (Position > SENSOR_POSITION_STEP_3)	/* If the Position is higher than required */
			{
				Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS); /* Decrement until reaching the required step */
			}
			Rte_Call_rpInclineSensor_GetPosition(&Position);
		}
	}
	else if (Weight >= 80 && Weight < 100)
	{
		while (Position != SENSOR_POSITION_STEP_2)
		{
			if (Position < SENSOR_POSITION_STEP_2)	/* If the Position is less than required, */
			{
				Rte_Call_rpInclineMotor_Move(MOTOR_STEP_PLUS);	/* Increment until reaching the required step */
			}
			else if (Position > SENSOR_POSITION_STEP_2)	/* If the Position is higher than required */
			{
				Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS); /* Decrement until reaching the required step */
			}
			Rte_Call_rpInclineSensor_GetPosition(&Position);
		}
	}
	else if (Weight >= 60 && Weight < 80)
	{
		while (Position != SENSOR_POSITION_STEP_1)
		{
			if (Position < SENSOR_POSITION_STEP_1)	/* If the Position is less than required, */
			{
				Rte_Call_rpInclineMotor_Move(MOTOR_STEP_PLUS);	/* Increment until reaching the required step */
			}
			else if (Position > SENSOR_POSITION_STEP_1)	/* If the Position is higher than required */
			{
				Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS); /* Decrement until reaching the required step */
			}
			Rte_Call_rpInclineSensor_GetPosition(&Position);
		}
	}
	else if (Weight < 60)
	{
		while (Position != SENSOR_POSITION_STEP_0)
		{
			if (Position < SENSOR_POSITION_STEP_0)	/* If the Position is less than required, */
			{
				Rte_Call_rpInclineMotor_Move(MOTOR_STEP_PLUS);	/* Increment until reaching the required step */
			}
			else if (Position > SENSOR_POSITION_STEP_0)	/* If the Position is higher than required */
			{
				Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS); /* Decrement until reaching the required step */
			}
			Rte_Call_rpInclineSensor_GetPosition(&Position);
		}
	}
}


/**
 *
 * Runnable SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoSlide_200ms
 *
 */

void SeatManager_AutoSlide(void)
{
	SensorPositionType Position;
	SensorWeightType Weight;

	/* Server Call Points */
	Rte_Call_rpSlideSensor_GetPosition(&Position);
	Rte_Call_rpWeightSensor_GetWeight(&Weight);

	if (Weight >= 100)
	{
		while (Position != SENSOR_POSITION_STEP_3)
		{
			if (Position < SENSOR_POSITION_STEP_3)	/* If the Position is less than required, */
			{
				Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);	/* Increment until reaching the required step */
			}
			else if (Position > SENSOR_POSITION_STEP_3)	/* If the Position is higher than required */
			{
				Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS); /* Decrement until reaching the required step */
			}
			Rte_Call_rpSlideSensor_GetPosition(&Position);
		}
	}
	else if (Weight >= 80 && Weight < 100)
	{
		while (Position != SENSOR_POSITION_STEP_2)
		{
			if (Position < SENSOR_POSITION_STEP_2)	/* If the Position is less than required, */
			{
				Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);	/* Increment until reaching the required step */
			}
			else if (Position > SENSOR_POSITION_STEP_2)	/* If the Position is higher than required */
			{
				Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS); /* Decrement until reaching the required step */
			}
			Rte_Call_rpSlideSensor_GetPosition(&Position);
		}
	}
	else if (Weight >= 60 && Weight < 80)
	{
		while (Position != SENSOR_POSITION_STEP_1)
		{
			if (Position < SENSOR_POSITION_STEP_1)	/* If the Position is less than required, */
			{
				Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);	/* Increment until reaching the required step */
			}
			else if (Position > SENSOR_POSITION_STEP_1)	/* If the Position is higher than required */
			{
				Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS); /* Decrement until reaching the required step */
			}
			Rte_Call_rpSlideSensor_GetPosition(&Position);
		}
	}
	else if (Weight < 60)
	{
		while (Position != SENSOR_POSITION_STEP_0)
		{
			if (Position < SENSOR_POSITION_STEP_0)	/* If the Position is less than required, */
			{
				Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);	/* Increment until reaching the required step */
			}
			else if (Position > SENSOR_POSITION_STEP_0)	/* If the Position is higher than required */
			{
				Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS); /* Decrement until reaching the required step */
			}
			Rte_Call_rpSlideSensor_GetPosition(&Position);
		}
	}
}


/**
 *
 * Runnable SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_HeightBtnState
 *
 */

void SeatManager_SetHeight(void)
{
	MultiStateBtnType HeightBtnState;
	StepMotorStepType step;

	/* Data Receive Points */
	Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);

	switch (HeightBtnState)
	{
	case MULTI_STATE_BTN_MINUS:
		step = MOTOR_STEP_MINUS;
		break;
	case MULTI_STATE_BTN_PLUS:
		step = MOTOR_STEP_PLUS;
		break;
	}

	Rte_Call_rpHeightMotor_Move(step);
}


/**
 *
 * Runnable SeatManager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_InclineBtnState
 *
 */

void SeatManager_SetIncline(void)
{
	MultiStateBtnType InclineBtnState;
	StepMotorStepType step;

	/* Data Receive Points */
	Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);

	switch (InclineBtnState)
	{
	case MULTI_STATE_BTN_MINUS:
		step = MOTOR_STEP_MINUS;
		break;
	case MULTI_STATE_BTN_PLUS:
		step = MOTOR_STEP_PLUS;
		break;
	}

	Rte_Call_rpInclineMotor_Move(step);
}


/**
 *
 * Runnable SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_SlideBtnState
 *
 */

void SeatManager_SetSlide(void)
{
	MultiStateBtnType SlideBtnState;
	StepMotorStepType step;

	/* Data Receive Points */
	Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);

	switch (SlideBtnState)
	{
	case MULTI_STATE_BTN_MINUS:
		step = MOTOR_STEP_MINUS;
		break;
	case MULTI_STATE_BTN_PLUS:
		step = MOTOR_STEP_PLUS;
		break;
	}

	Rte_Call_rpSlideMotor_Move(step);
}