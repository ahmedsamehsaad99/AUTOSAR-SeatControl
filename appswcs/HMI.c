/**
 *
 * \file SWC_HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4-28-2023 08:41 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HMI.h"


/**
 *
 * Runnable HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_HMI_MainFunction_100ms
 *
 */

void HMI_MainFunction (void)
{
	uint8 Height;
	uint8 Incline;
	uint8 Slide;

	MultiStateBtnType HeightBtnState;
	MultiStateBtnType InclineBtnState;
	MultiStateBtnType SlideBtnState;
	
	MultiStateBtnType BtnState[3] = {MULTI_STATE_BTN_INIT, MULTI_STATE_BTN_MINUS, MULTI_STATE_BTN_PLUS};

	/* Data Receive Points */
	boolean HeightUpdated = Rte_IsUpdated_rpSeatCtrlData_Height();
	boolean InclineUpdated = Rte_IsUpdated_rpSeatCtrlData_Incline();
	boolean SlideUpdated = Rte_IsUpdated_rpSeatCtrlData_Slide();

	Std_ReturnType HeightStatus = Rte_Read_rpSeatCtrlData_Height(&Height);
	Std_ReturnType InclineStatus = Rte_Read_rpSeatCtrlData_Incline(&Incline);
	Std_ReturnType SlideStatus = Rte_Read_rpSeatCtrlData_Slide(&Slide);
	
	/* For the Height button */
	if (HeightStatus != RTE_E_OK || !HeightUpdated) /* If not updated or timeout occured */
		HeightBtnState = BtnState[0];	/* Set the state to MULTI_STATE_BTN_INIT */
	else	
		HeightBtnState = BtnState[Height]; /* Set the state to its corresponding from the array */
	
	/* For the Incline button */
	if (InclineStatus != RTE_E_OK || !InclineUpdated)
		InclineBtnState = BtnState[0];
	else
		InclineBtnState = BtnState[Incline];

	/* For the Incline button */
	if (SlideStatus != RTE_E_OK || !SlideUpdated)
		SlideBtnState = BtnState[0];
	else
		SlideBtnState = BtnState[Slide];


	/* Data Send Points */
	Rte_Write_ppSeatCtrlBtns_HeightBtnState(HeightBtnState);
	Rte_Write_ppSeatCtrlBtns_InclineBtnState(InclineBtnState);
	Rte_Write_ppSeatCtrlBtns_SlideBtnState(SlideBtnState);
}


/**
 *
 * Runnable HMI_SeatModeChanged
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatModeBtn_SeatModeBtn
 *
 */

void HMI_SeatModeChanged (void)
{
	SeatModeBtnType SeatModeBtn;
	uint8 SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;

	/* Data Receive Points */
	Rte_Read_rpSeatModeBtn_SeatModeBtn(&SeatModeBtn);
	
	switch (SeatModeBtn)
	{
		case SEAT_MODE_BTN_MANUAL:
			SeatCtrlMode = RTE_MODE_SeatCtrlMode_MANUAL;
			break;
		case SEAT_MODE_BTN_AUTO:
			SeatCtrlMode = RTE_MODE_SeatCtrlMode_AUTO;
			break;			
	}
	
	Rte_Switch_ppSeatCtrlMode_SeatCtrlMode(SeatCtrlMode);

}

