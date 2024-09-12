#ifndef ESTIM_H
#define ESTIM_H


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


typedef struct {
    float   			  qDeltaT;      // Integration constant
    float   			  qRho;    	    // angle of estimation
    float  			  qRhoStateVar; // internal variable for angle
    float   			  qOmegaMr;     // primary speed estimation
    float   			  qLastIalpha;  // last value for Ialpha
    float   			  qLastIbeta;   // last value for Ibeta
    float   			  qDIalpha;     // difference Ialpha
    float   			  qDIbeta;      // difference Ibeta
	float				  qEsa;			// BEMF alpha
	float				  qEsb;			// BEMF beta
	float				  qEsd;			// BEMF d
	float				  qEsq;			// BEMF q
//	short				  qDiCounter;	// counter in Last DI tables
	float				  qVIndalpha;   // dI*Ls/dt alpha
	float				  qVIndbeta;    // dI*Ls/dt beta
	float				  qEsdf;        // BEMF d filtered
	//float                 qEsdStateVar; // state var for BEMF d Filtered
	float				  qEsqf;        // BEMF q filtered
	//float                 qEsqStateVar; // state var for BEMF q Filtered
	float				  qKfilterEsdq; // filter constant for d-q BEMF
	float   			  qVelEstim; 			// Estimated speed 
	float   			  qVelEstimFilterK; 	// Filter Konstant for Estimated speed 
	//float   			  qVelEstimStateVar; 	// State Variable for Estimated speed 
    float   			  qLastValpha;  // Value from last control step Ialpha 
    float   			  qLastVbeta;   // Value from last control step Ibeta
//	float				  qDIlimitLS;			// dIalphabeta/dt
//	float				  qDIlimitHS;			// dIalphabeta/dt
//	float				  qLastIalphaHS[8];		//  last  value for Ialpha
//	float				  qLastIbetaHS[8];			// last  value for Ibeta
	float               RhoOffset;            // estima angle init offset

    } tEstimParm;


typedef struct {
	float				   qRs;			// Rs value - stator resistance
	float				   qLsDt;		// Ls/dt value - stator inductand / dt - variable with speed
    //float				   qLsDtBase;	// Ls/dt value - stator inductand / dt for base speed (nominal)
	float				   qInvKFi;	    // InvKfi constant value ( InvKfi = Omega/BEMF )
	//float				   qInvKFiBase; // InvKfi constant - base speed (nominal) value
    } tMotorEstimParm;

	

extern tEstimParm 	EstimParm;
extern tMotorEstimParm 	MotorEstimParm;

//------------------  C API for Control routine ---------------------

void	Estim(void);
void	InitEstimParm(void);

#endif
