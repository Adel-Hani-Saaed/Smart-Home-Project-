/********************************************************/
/********************************************************/
/*************** Author: Adel Hani	  *******************/
/*************** Layer: MCAL		  *******************/
/*************** SWC: DIO			  *******************/
/*************** Date: 28/1/2023 	  *******************/
/*************** Version: 2.00		  *******************/
/********************************************************/
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_Math.h"


#include "DIO_interface.h"
#include "DIO_register.h"


DIO_ErrorStatus	DIO_enumSetPinDirection(u8 Copy_u8Port ,u8 Copy_u8Pin , u8 Copy_u8Direction )
{
	DIO_ErrorStatus Local_enumErrorState = DIO_OK;

	/* Make sure that the Port ID and Pin ID are in the valid range */
	if (Copy_u8Port <= DIO_PORTD && Copy_u8Pin <= DIO_PIN7 )
	{
		if (Copy_u8Direction == DIO_OUTPUT)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8Port)
			{
			case DIO_PORTA: SET_BIT(DDRA_REG,Copy_u8Pin); break ;
			case DIO_PORTB: SET_BIT(DDRB_REG,Copy_u8Pin); break ;
			case DIO_PORTC: SET_BIT(DDRC_REG,Copy_u8Pin); break ;
			case DIO_PORTD: SET_BIT(DDRD_REG,Copy_u8Pin); break ;
			}
		}

		else if (Copy_u8Direction == DIO_INPUT)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8Port)
			{
			case DIO_PORTA: CLR_BIT(DDRA_REG,Copy_u8Pin); break ;
			case DIO_PORTB: CLR_BIT(DDRB_REG,Copy_u8Pin); break ;
			case DIO_PORTC: CLR_BIT(DDRC_REG,Copy_u8Pin); break ;
			case DIO_PORTD: CLR_BIT(DDRD_REG,Copy_u8Pin); break ;
			}
		}
		else
		{
			Local_enumErrorState = DIO_NOK;
		}
	}

	else
	{
		Local_enumErrorState = DIO_NOK;
	}

	return Local_enumErrorState;
}




DIO_ErrorStatus DIO_enumSetPinValue(u8  Copy_u8Port ,u8 Copy_u8Pin , u8 Copy_u8Value)
{
	DIO_ErrorStatus Local_enumErrorState = DIO_OK;

	/* Make sure that the Port in the valid range */
	if (Copy_u8Port <= DIO_PORTD && Copy_u8Pin <= DIO_PIN7 )
	{
		if (Copy_u8Value == DIO_HIGH)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8Port)
			{
			case DIO_PORTA: SET_BIT(PORTA_REG,Copy_u8Pin); break ;
			case DIO_PORTB: SET_BIT(PORTB_REG,Copy_u8Pin); break ;
			case DIO_PORTC: SET_BIT(PORTC_REG,Copy_u8Pin); break ;
			case DIO_PORTD: SET_BIT(PORTD_REG,Copy_u8Pin); break ;
			}
		}

		else if (Copy_u8Value == DIO_LOW)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8Port)
			{
			case DIO_PORTA: CLR_BIT(PORTA_REG,Copy_u8Pin); break ;
			case DIO_PORTB: CLR_BIT(PORTB_REG,Copy_u8Pin); break ;
			case DIO_PORTC: CLR_BIT(PORTC_REG,Copy_u8Pin); break ;
			case DIO_PORTD: CLR_BIT(PORTD_REG,Copy_u8Pin); break ;
			}
		}
		else
		{
			Local_enumErrorState = DIO_NOK;

		}
	}

	else
	{
		Local_enumErrorState = DIO_NOK;
	}

	return Local_enumErrorState;

}

DIO_ErrorStatus DIO_enumGetPinValue(u8  Copy_u8Port ,u8 Copy_u8Pin , u8* Copy_pu8Value)
{
	DIO_ErrorStatus Local_enumErrorState = DIO_OK;

	/* Make sure that the Port ID and Pin ID are in the valid range */
	if (Copy_u8Port <= DIO_PORTD && Copy_u8Pin <= DIO_PIN7 )
	{
		/* Check on the Required PORT Number */
		switch (Copy_u8Port)
		{
		case DIO_PORTA:  *Copy_pu8Value = GET_BIT(PINA_REG,Copy_u8Pin); break ;
		case DIO_PORTB:  *Copy_pu8Value = GET_BIT(PINB_REG,Copy_u8Pin); break ;
		case DIO_PORTC:  *Copy_pu8Value = GET_BIT(PINC_REG,Copy_u8Pin); break ;
		case DIO_PORTD:  *Copy_pu8Value = GET_BIT(PIND_REG,Copy_u8Pin); break ;
		}
	}
	else
	{
		/* in case of error in the Pin ID or PORT ID */
		Local_enumErrorState = DIO_NOK ;
	}
	return Local_enumErrorState;
}



DIO_ErrorStatus DIO_enumTogglePinValue( u8 Copy_u8Port, u8 Copy_u8Pin )
{
	DIO_ErrorStatus Local_enumErrorState = DIO_OK;

	/* Make sure that the Port ID and Pin ID are in the valid range */
	if (Copy_u8Port <= DIO_PORTD && Copy_u8Pin <= DIO_PIN7 )
	{
		/* Check on the Required PORT Number */
		switch (Copy_u8Port)
		{
		case DIO_PORTA: TOGGLE_BIT(PORTA_REG,Copy_u8Pin); break ;
		case DIO_PORTB: TOGGLE_BIT(PORTB_REG,Copy_u8Pin); break ;
		case DIO_PORTC: TOGGLE_BIT(PORTC_REG,Copy_u8Pin); break ;
		case DIO_PORTD: TOGGLE_BIT(PORTD_REG,Copy_u8Pin); break ;
		}
	}
	else
	{
		/* in case of error in the Pin ID or PORT ID */
		Local_enumErrorState = DIO_NOK ;
	}
	return Local_enumErrorState;

}


DIO_ErrorStatus DIO_enumSetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction)
{
	DIO_ErrorStatus Local_enumErrorState = DIO_OK;

	/* Make sure that the Port ID  in the valid range */
	if (Copy_u8Port <= DIO_PORTD)
	{
		if (Copy_u8Direction == DIO_PORT_OUTPUT)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8Port)
			{
			case DIO_PORTA: SET_REG(DDRA_REG); break ;
			case DIO_PORTB: SET_REG(DDRB_REG); break ;
			case DIO_PORTC: SET_REG(DDRC_REG); break ;
			case DIO_PORTD: SET_REG(DDRD_REG); break ;
			}
		}

		else if (Copy_u8Direction == DIO_PORT_INPUT)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8Port)
			{
			case DIO_PORTA: CLR_REG(DDRA_REG); break ;
			case DIO_PORTB: CLR_REG(DDRB_REG); break ;
			case DIO_PORTC: CLR_REG(DDRC_REG); break ;
			case DIO_PORTD: CLR_REG(DDRD_REG); break ;

			}
		}

		else
		{
			Local_enumErrorState = DIO_NOK;
		}

	}
	else
	{
		Local_enumErrorState = DIO_NOK;
	}

	return Local_enumErrorState;
}


DIO_ErrorStatus DIO_enumSetPortValue(u8  Copy_u8Port , u8 Copy_u8Value)
{
	DIO_ErrorStatus Local_enumErrorState = DIO_OK;

	if ((Copy_u8Port <= DIO_PORTD))
	{

		switch(Copy_u8Port)
		{
		case DIO_PORTA: PORTA_REG=Copy_u8Value; break;
		case DIO_PORTB: PORTB_REG=Copy_u8Value; break;
		case DIO_PORTC: PORTC_REG=Copy_u8Value; break;
		case DIO_PORTD: PORTD_REG=Copy_u8Value; break;
		}
	}
	else
	{
		Local_enumErrorState= DIO_NOK;
	}


	return Local_enumErrorState;
}


DIO_ErrorStatus DIO_enumTogglePortValue( u8 Copy_u8Port )
{
	DIO_ErrorStatus Local_enumErrorState = DIO_OK;

	if (Copy_u8Port <= DIO_PORTD)
	{
		switch(Copy_u8Port)
		{
		case DIO_PORTA: TOGGLE_REG(PORTA_REG); break;
		case DIO_PORTB: TOGGLE_REG(PORTB_REG); break;
		case DIO_PORTC: TOGGLE_REG(PORTC_REG); break;
		case DIO_PORTD: TOGGLE_REG(PORTD_REG); break;
		}
	}

	else
	{
		Local_enumErrorState= DIO_NOK;
	}

	return Local_enumErrorState;

}

DIO_ErrorStatus DIO_enumSetHighNibbleDirection(u8 Copy_u8Port , u8 Copy_u8Direction)
{
	DIO_ErrorStatus Local_enumErrorState = DIO_OK;

	if (Copy_u8Port <= DIO_PORTD)
	{
		if (Copy_u8Direction == DIO_PORT_OUTPUT)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8Port)
			{
			case DIO_PORTA: SET_HIGH_NIB(DDRA_REG); break ;
			case DIO_PORTB: SET_HIGH_NIB(DDRB_REG); break ;
			case DIO_PORTC: SET_HIGH_NIB(DDRC_REG); break ;
			case DIO_PORTD: SET_HIGH_NIB(DDRD_REG); break ;
			}


		}
		else if (Copy_u8Direction == DIO_PORT_INPUT)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8Port)
			{
			case DIO_PORTA: CLR_HIGH_NIB(DDRA_REG); break ;
			case DIO_PORTB: CLR_HIGH_NIB(DDRB_REG); break ;
			case DIO_PORTC: CLR_HIGH_NIB(DDRC_REG); break ;
			case DIO_PORTD: CLR_HIGH_NIB(DDRD_REG); break ;
			}
		}
		else
		{
			Local_enumErrorState= DIO_NOK;
		}

	}

	else
	{
		Local_enumErrorState= DIO_NOK;
	}

	return Local_enumErrorState;
}



DIO_ErrorStatus DIO_enumSetHighNibbleValue(u8  Copy_u8Port  , u8 Copy_u8Value)
{
	DIO_ErrorStatus Local_enumErrorState = DIO_OK;

	if (Copy_u8Port <= DIO_PORTD)
	{

		if (Copy_u8Value == DIO_PORT_HIGH)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8Port)
			{
			case DIO_PORTA: ASSIGN_HIGH_NIB(PORTA_REG,Copy_u8Value); break ;
			case DIO_PORTB: ASSIGN_HIGH_NIB(PORTB_REG,Copy_u8Value); break ;
			case DIO_PORTC: ASSIGN_HIGH_NIB(PORTC_REG,Copy_u8Value); break ;
			case DIO_PORTD: ASSIGN_HIGH_NIB(PORTD_REG,Copy_u8Value); break ;
			}
		}

		else if (Copy_u8Value == DIO_PORT_LOW)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8Port)
			{
			case DIO_PORTA: ASSIGN_HIGH_NIB(PORTA_REG,Copy_u8Value); break ;
			case DIO_PORTB: ASSIGN_HIGH_NIB(PORTB_REG,Copy_u8Value); break ;
			case DIO_PORTC: ASSIGN_HIGH_NIB(PORTC_REG,Copy_u8Value); break ;
			case DIO_PORTD: ASSIGN_HIGH_NIB(PORTD_REG,Copy_u8Value); break ;
			}
		}
		else
		{
			Local_enumErrorState = DIO_NOK;

		}
	}


	else
	{
		Local_enumErrorState= DIO_NOK;
	}

	return Local_enumErrorState;
}



DIO_ErrorStatus DIO_enumSetLowNibbleDirection(u8 Copy_u8Port , u8 Copy_u8Direction)
{

	DIO_ErrorStatus Local_enumErrorState = DIO_OK;

	if (Copy_u8Port <= DIO_PORTD)
	{
		if (Copy_u8Direction == DIO_PORT_OUTPUT)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8Port)
			{
			case DIO_PORTA: SET_LOW_NIB(DDRA_REG); break ;
			case DIO_PORTB: SET_LOW_NIB(DDRB_REG); break ;
			case DIO_PORTC: SET_LOW_NIB(DDRC_REG); break ;
			case DIO_PORTD: SET_LOW_NIB(DDRD_REG); break ;
			}


		}
		else if (Copy_u8Direction == DIO_PORT_INPUT)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8Port)
			{
			case DIO_PORTA: CLR_LOW_NIB(DDRA_REG); break ;
			case DIO_PORTB: CLR_LOW_NIB(DDRB_REG); break ;
			case DIO_PORTC: CLR_LOW_NIB(DDRC_REG); break ;
			case DIO_PORTD: CLR_LOW_NIB(DDRD_REG); break ;
			}
		}
		else
		{
			Local_enumErrorState= DIO_NOK;
		}

	}

	else
	{
		Local_enumErrorState= DIO_NOK;
	}

	return Local_enumErrorState;

}


DIO_ErrorStatus DIO_enumSetLowNibbleValue(u8  Copy_u8Port , u8 Copy_u8Value)
{
	DIO_ErrorStatus Local_enumErrorState = DIO_OK;

	if (Copy_u8Port <= DIO_PORTD)
	{

		if (Copy_u8Value == DIO_PORT_HIGH)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8Port)
			{
			case DIO_PORTA: ASSIGN_LOW_NIB(PORTA_REG,Copy_u8Value); break ;
			case DIO_PORTB: ASSIGN_LOW_NIB(PORTB_REG,Copy_u8Value); break ;
			case DIO_PORTC: ASSIGN_LOW_NIB(PORTC_REG,Copy_u8Value); break ;
			case DIO_PORTD: ASSIGN_LOW_NIB(PORTD_REG,Copy_u8Value); break ;
			}
		}

		else if (Copy_u8Value == DIO_PORT_LOW)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8Port)
			{
			case DIO_PORTA: ASSIGN_LOW_NIB(PORTA_REG,Copy_u8Value); break ;
			case DIO_PORTB: ASSIGN_LOW_NIB(PORTB_REG,Copy_u8Value); break ;
			case DIO_PORTC: ASSIGN_LOW_NIB(PORTC_REG,Copy_u8Value); break ;
			case DIO_PORTD: ASSIGN_LOW_NIB(PORTD_REG,Copy_u8Value); break ;
			}
		}
		else
		{
			Local_enumErrorState = DIO_NOK;

		}
	}


	else
	{
		Local_enumErrorState= DIO_NOK;
	}

	return Local_enumErrorState;
}
