/**
 *
 * \file IoHwAbs_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: IoHwAbs
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4-30-2023 09:18 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_IoHwAbs.h"
#include "Adc.h"
#include "Spi.h"
#include "Dio.h"

static Adc_ValueGroupType IoHwAb_PositionSensorsReadings[ADC_GR0_NUM_CHANNELS] =
{
   /* Height */
   0,
   /* Incline */
   0,
   /* Slide */
   0
};

/**
 *
 * Runnable IoHwAbs_ECUGetHeight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetHeight_IOGet
 *
 */

void IoHwAbs_ECUGet_Height(IoPositionSensorReadingType* position)
{
	Std_ReturnType status;

	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp, IoHwAb_PositionSensorsReadings);
	
	if (status == E_OK)
	{
		*position = (IoPositionSensorReadingType)IoHwAb_PositionSensorsReadings[0];
	}
}


/**
 *
 * Runnable IoHwAbs_ECUGetIncline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetIncline_IOGet
 *
 */

void IoHwAbs_ECUGet_Incline (IoPositionSensorReadingType* position)
{
	Std_ReturnType status;

	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp, IoHwAb_PositionSensorsReadings);
	
	if (status == E_OK)
	{
		*position = (IoPositionSensorReadingType)IoHwAb_PositionSensorsReadings[1];
	}
}


/**
 *
 * Runnable IoHwAbs_ECUGetSlide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetSlide_IOGet
 *
 */

void IoHwAbs_ECUGet_Slide (IoPositionSensorReadingType* position)
{
	Std_ReturnType status;

	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp, IoHwAb_PositionSensorsReadings);
	
	if (status == E_OK)
	{
		*position = (IoPositionSensorReadingType)IoHwAb_PositionSensorsReadings[2];
	}
}


/**
 *
 * Runnable IoHwAbs_ECUGetWeight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetWeight_IOGet
 *
 */

void IoHwAbs_ECUGet_Weight (IoWeightSensorReadingType* weight)
{
	Std_ReturnType status;
	Spi_DataType spiData;
	
	status = Spi_ReadIB(SpiConf_SpiChannel_WeightSensor, &spiData);
	
	if (status == E_OK)
	{
		*weight = (IoWeightSensorReadingType)spiData;
	}
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Height (void)
{
	Dio_WriteChannel(DioConfg_DioChannel_HeightMotorCh, STD_HIGH);
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetInlice_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Incline (void)
{
	Dio_WriteChannel(DioConfg_DioChannel_InclineMotorCh, STD_HIGH);
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Slide (void)
{
	Dio_WriteChannel(DioConfg_DioChannel_SlideMotorCh, STD_HIGH);
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Height (void)
{
	Dio_WriteChannel(DioConfg_DioChannel_HeightMotorCh, STD_LOW);
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetInlice_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Incline (void)
{
	Dio_WriteChannel(DioConfg_DioChannel_InclineMotorCh, STD_LOW);
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Slide (void)
{
	Dio_WriteChannel(DioConfg_DioChannel_SlideMotorCh, STD_LOW);
}


