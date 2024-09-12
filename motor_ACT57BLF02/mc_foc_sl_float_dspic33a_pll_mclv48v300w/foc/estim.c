/**********************************************************************
* © 2009 Microchip Technology Inc.
*
* SOFTWARE LICENSE AGREEMENT:
* Microchip Technology Incorporated ("Microchip") retains all ownership and 
* intellectual property rights in the code accompanying this message and in all 
* derivatives hereto.  You may use this code, and any derivatives created by 
* any person or entity by or on your behalf, exclusively with Microchip's
* proprietary products.  Your acceptance and/or use of this code constitutes 
* agreement to the terms and conditions of this notice.
*
* CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  NO 
* WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED 
* TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A 
* PARTICULAR PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH MICROCHIP'S 
* PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
*
* YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE, WHETHER 
* IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF STATUTORY DUTY), 
* STRICT LIABILITY, INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR ANY INDIRECT, SPECIAL, 
* PUNITIVE, EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, FOR COST OR EXPENSE OF 
* ANY KIND WHATSOEVER RELATED TO THE CODE, HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN 
* ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT 
* ALLOWABLE BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO 
* THIS CODE, SHALL NOT EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP SPECIFICALLY TO 
* HAVE THIS CODE DEVELOPED.
*
* You agree that you are solely responsible for testing the code and 
* determining its suitability.  Microchip has no obligation to modify, test, 
* certify, or support the code.
*
*******************************************************************************/

/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                    include files                                           */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
#include "estim.h"

#include "park.h"
#include "userparms.h"
#include "sineTable.h"

#define DECIMATE_NOMINAL_SPEED      ((NOMINAL_SPEED_RPM *(M_PI/30))*NOPOLESPAIRS/10)


struct LPF
	{
		float Y;				// Output
		float Y_prev;			// Previous Value of Output
		float X;				// Output
		float X_prev;			// Previous Value of Input
		float Wc;				// Cutoff Frequency
		float Ts;				// sampling time
	};
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                    typedef definitions                                     */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
tEstimParm 			EstimParm;
tMotorEstimParm 	MotorEstimParm;

uint16_t theta_d1=0,i_theta_d1=0;
float sin_d1=0,cos_d1=0;
/******************************************************************************/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/******************************************************************************/
void SinCos(void);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/******************************************************************************/
/* Function name: Estim                                                       */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Estimation of the speed of the motor and field angle based on */
/* inverter voltages and motor currents.                                      */
/******************************************************************************/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void Estim(void)
{
    float tempqVelEstim;
    
    if(EstimParm.qVelEstim < 0)
    {
        tempqVelEstim = EstimParm.qVelEstim * (-1);
    }
    else
    {
        tempqVelEstim = EstimParm.qVelEstim;
    }
//    
//    //*******************************
//    // dIalpha = Ialpha-oldIalpha,  dIbeta  = Ibeta-oldIbeta
//    // for lower speed the granularity of differnce is higher - the 
//    // difference is made between 2 sampled values @ 8 ADC ISR cycles
//    if (tempqVelEstim<NOMINAL_SPEED_RPM*NOPOLESPAIRS)
//    {
    
    	EstimParm.qDIalpha	=	(ParkParm.Ialpha-EstimParm.qLastIalpha);//(ParkParm.Ialpha-EstimParm.qLastIalphaHS[(EstimParm.qDiCounter-7)&0x0007]);
    	/* the current difference can exceed the maximum value per 8 ADC ISR cycle */
    	/* the following limitation assures a limitation per low speed - up to the nominal speed */
//    	if (EstimParm.qDIalpha>EstimParm.qDIlimitLS) EstimParm.qDIalpha=EstimParm.qDIlimitLS;
//    	if (EstimParm.qDIalpha<-EstimParm.qDIlimitLS) EstimParm.qDIalpha=-EstimParm.qDIlimitLS;
    	EstimParm.qVIndalpha = (MotorEstimParm.qLsDt * EstimParm.qDIalpha);
     
    	EstimParm.qDIbeta	=	(ParkParm.Ibeta-EstimParm.qLastIbeta);//(ParkParm.Ibeta-EstimParm.qLastIbetaHS[(EstimParm.qDiCounter-7)&0x0007]);
    	/* the current difference can exceed the maximum value per 8 ADC ISR cycle */
    	/* the following limitation assures a limitation per low speed - up to the nominal speed */
//    	if (EstimParm.qDIbeta>EstimParm.qDIlimitLS) EstimParm.qDIbeta=EstimParm.qDIlimitLS;
//    	if (EstimParm.qDIbeta<-EstimParm.qDIlimitLS) EstimParm.qDIbeta=-EstimParm.qDIlimitLS;
    	EstimParm.qVIndbeta= (MotorEstimParm.qLsDt * EstimParm.qDIbeta);
    
//    }
    
    //*******************************
    // update  LastIalpha and LastIbeta
    //EstimParm.qDiCounter=(EstimParm.qDiCounter+1) & 0x0007;
    EstimParm.qLastIalpha	=	ParkParm.Ialpha;
    EstimParm.qLastIbeta 	=	ParkParm.Ibeta;
    
    //*******************************
    // Stator voltage eqations
    // Ualpha = Rs * Ialpha + Ls dIalpha/dt + BEMF
    // BEMF = Ualpha - Rs Ialpha - Ls dIalpha/dt   
    
	EstimParm.qEsa		= 	(ParkParm.Valpha * DC_BUS_VOLTAGE_DUE_TO_SVM) -
							((MotorEstimParm.qRs  * ParkParm.Ialpha))
							-EstimParm.qVIndalpha;
    /* the multiplication between the Rs and Ialpha was shifted by 14 instead of 15 */
    /* because the Rs value normalized exceeded Q15 range, so it was divided by 2 */
    /* immediatelky after the normalization - in userparms.h */

    // Ubeta = Rs * Ibeta + Ls dIbeta/dt + BEMF
    // BEMF = Ubeta - Rs Ibeta - Ls dIbeta/dt   
	EstimParm.qEsb		= 	(ParkParm.Vbeta * DC_BUS_VOLTAGE_DUE_TO_SVM) -
							((MotorEstimParm.qRs  * ParkParm.Ibeta ))
							- EstimParm.qVIndbeta;
							
    /* the multiplication between the Rs and Ibeta was shifted by 14 instead of 15 */
    /* because the Rs value normalized exceeded Q15 range, so it was divided by 2 */
    /* immediatelky after the normalization - in userparms.h */
    
    //*******************************
    // Calculate Sin(Rho) and Cos(Rho)
//    if(SincosParm.Angle >= SINGLE_ELEC_ROT_RADS_PER_SEC)
//        SincosParm.Angle = SincosParm.Angle - SINGLE_ELEC_ROT_RADS_PER_SEC;  
     SincosParm.Angle 	=	EstimParm.qRho + EstimParm.RhoOffset; 
	
    if(SincosParm.Angle >= SINGLE_ELEC_ROT_RADS_PER_SEC)
        SincosParm.Angle = SincosParm.Angle - SINGLE_ELEC_ROT_RADS_PER_SEC;  
//    if(SincosParm.Angle > SINGLE_ELEC_ROT_RADS_PER_SEC)
//        SincosParm.Angle = 0;//SincosParm.Angle - SINGLE_ELEC_ROT_RADS_PER_SEC;  //SincosParm.Angle - SINGLE_ELEC_ROT_RADS_PER_SEC;  
//    
//    SincosParm.Angle = ParkParm.Angle;
    
	SinCos();

    //*******************************
    //    Esd =  Esa*cos(Angle) + Esb*sin(Rho)
	EstimParm.qEsd		=	((EstimParm.qEsa * SincosParm.Cos))
							+
							((EstimParm.qEsb * SincosParm.Sin));
    //*******************************
    //   Esq = -Esa*sin(Angle) + Esb*cos(Rho)
	EstimParm.qEsq		=	(( EstimParm.qEsb * SincosParm.Cos))
							-
							((EstimParm.qEsa * SincosParm.Sin));

    //*******************************
    //*******************************
    // Filter first order for Esd and Esq
    // EsdFilter = 1/TFilterd * Intergal{ (Esd-EsdFilter).dt }
 
	EstimParm.qEsdf			= EstimParm.qEsdf+
								( (EstimParm.qEsd - EstimParm.qEsdf) * EstimParm.qKfilterEsdq) ;

	EstimParm.qEsqf			= EstimParm.qEsqf+
								( (EstimParm.qEsq - EstimParm.qEsqf) * EstimParm.qKfilterEsdq) ;
    

    if (tempqVelEstim>DECIMATE_NOMINAL_SPEED)
    {
    	if(EstimParm.qEsqf>0)
    	{
    		EstimParm.qOmegaMr	=	((MotorEstimParm.qInvKFi*(EstimParm.qEsqf- EstimParm.qEsdf))) ;
    	} else
    	{
    		EstimParm.qOmegaMr	=	((MotorEstimParm.qInvKFi*(EstimParm.qEsqf + EstimParm.qEsdf)));
    	}
    } else // if est speed<10% => condition VelRef<>0
    {
    	if(EstimParm.qVelEstim>0)
    	{
    		EstimParm.qOmegaMr	=	((MotorEstimParm.qInvKFi*(EstimParm.qEsqf- EstimParm.qEsdf))) ;
    	} else
    	{
    		EstimParm.qOmegaMr	=	((MotorEstimParm.qInvKFi*(EstimParm.qEsqf+ EstimParm.qEsdf))) ;
    	}
    }
    
//    if(EstimParm.qRho >= SINGLE_ELEC_ROT_RADS_PER_SEC)
//        EstimParm.qRho = EstimParm.qRho - SINGLE_ELEC_ROT_RADS_PER_SEC;   
//    	
    /* the integral of the angle is the estimated angle */
     EstimParm.qRho	= 	EstimParm.qRho+
							(EstimParm.qOmegaMr)*(EstimParm.qDeltaT);
    
    if(EstimParm.qRho >= SINGLE_ELEC_ROT_RADS_PER_SEC)
        EstimParm.qRho = EstimParm.qRho - SINGLE_ELEC_ROT_RADS_PER_SEC; 
    
    /* the estiamted speed is a filter value of the above calculated OmegaMr. The filter implementation */
    /* is the same as for BEMF d-q components filtering */
	EstimParm.qVelEstim = EstimParm.qVelEstim+
						( (EstimParm.qOmegaMr-EstimParm.qVelEstim)*EstimParm.qVelEstimFilterK );
  
}	// End of Estim()

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/******************************************************************************/
/* Function name: InitEstimParm                                               */
/* Function parameters: None                                                  */
/* Function return: None                                                      */
/* Description: Initialisation of the parameters of the estimator.            */
/******************************************************************************/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void	InitEstimParm(void)  
{
    // Constants are defined in usreparms.h

	//MotorEstimParm.qLsDtBase = NORM_LSDTBASE;
	MotorEstimParm.qLsDt = (float)(MOTOR_PER_PHASE_INDUCTANCE/LOOPTIME_SEC);
	MotorEstimParm.qRs = MOTOR_PER_PHASE_RESISTANCE;

	//MotorEstimParm.qInvKFiBase = NORM_INVKFIBASE;
	MotorEstimParm.qInvKFi = (float)(1/MOTOR_BACK_EMF_CONSTANT_Vpeak_PHASE_RAD_PER_SEC_ELEC);

   	EstimParm.qRhoStateVar=0;
	EstimParm.qOmegaMr=0;
    EstimParm.qVelEstim = 0;
	//EstimParm.qDiCounter=0;
//	EstimParm.qEsdStateVar=0;
//	EstimParm.qEsqStateVar=0;
		
//	EstimParm.qDIlimitHS = D_ILIMIT_HS;
//    EstimParm.qDIlimitLS = D_ILIMIT_LS;
        
    EstimParm.qKfilterEsdq = KFILTER_ESDQ;
    EstimParm.qVelEstimFilterK = KFILTER_VELESTIM;

    EstimParm.qDeltaT = LOOPTIME_SEC;
    EstimParm.RhoOffset = (45 * (M_PI/180));
}
