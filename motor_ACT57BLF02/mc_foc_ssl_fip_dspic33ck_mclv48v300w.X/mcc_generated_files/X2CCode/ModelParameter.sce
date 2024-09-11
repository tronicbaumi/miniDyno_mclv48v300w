// Scilab script file to store Model parameters
// This file is automatically executed by initProject.sce
// initScript.sce and this script is executed automatically, if model is opened from MPLAB X MCC X2C library.

//*********************************
//  MCLV-48V-300W ACT 57BLF02
//*********************************

// Simulation settings
//endTime     = 5;
//stepSize    = 1.0E-2; 
X2C_sampleTime =100E-6;//10kHz control loop


sim_step = 0.0001;
sim_buffer = 250000;


// POWERSTAGE DATA
U_DCLINK = 24;
Vbus = U_DCLINK;

// MCLV-48V-300W 
Rshunt = 0.003;
Igain = -25;
I_MAX = 22;

// MOTOR parameters for PLL
// ACT 57BLF02
MotorLs = 0.34; // line to line
MotorRs = 0.40; //line to line
BEMF_VRPM = 6.3; //V/kRPM
n_p = 4;        // number of polepairs
N_motorNominal = 4000;//free run

BEMFVPP = BEMF_VRPM*2;
N_MAX = 5000; //Higher than motor max speed to avoid FIP saturations
BEMF_D_UDC = (BEMFVPP/Vbus)*(N_MAX/N_motorNominal);//BEM/UDC scaled FiP


PLL_INT = 5500;


// Speed PI
SpeedKp = 0.5;
SpeedKi = 0.4;
SpeedDemandRate = 0.2;

// Current PI
PIFluxKp =  1;
PIFluxKi = 100;

PITorqueKp = PIFluxKp;
PITorqueKi = PIFluxKi;


// MOTORDATA for MOTOR SIMULATION MODEL
Nm_ozin = 7.061552e-3;
KRPM_rads = 0.060/2/%pi;

Rs = MotorRs;
Ld = MotorLs;
Lq = MotorLs;
Kell = BEMF_VRPM;     //7.24;


J = 0.000628 * Nm_ozin;   // inertia
cf = 0;
chy = 0;
d = 0;
ced = 0;
ded = 0;

alphaCU = 0;
alphaPM = 0;
Temp_nom = 25;
omega_m0 = 0;
theta_m0 = 0;
psi_pm = Kell/sqrt(3)*60/(2*%pi*1000)/n_p;
theta_r0 = theta_m0*2*%pi*n_p;
omega_r0 = omega_m0/60*2*%pi*n_p;



Ld = Ld/2;
Lq = Lq/2;
Rs = Rs/2;


// initalize input for simulation
//exec("./gen_inputs.sci");
//exec("./qei_sim.sce");
//exec("./qei_sim2.sce");

