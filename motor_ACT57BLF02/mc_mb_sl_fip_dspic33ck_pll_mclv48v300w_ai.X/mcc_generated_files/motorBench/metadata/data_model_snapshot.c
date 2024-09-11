/*
 * data_model_snapshot.c
 * 
 * Snapshot of code generation data model.
 * This information is included in the executable file
 * and does not affect any memory content in the embedded device.
 */
 
__attribute__((section("diagnostics_cinfo, info"), keep)) char MCAF_data_model_snapshot[] =
  "{\"motor\": {\"Tfr\": 0.0143238350133,\"B\": 3.9961462067e-05,\"Lq\": 0.00015477"
  "2698027,\"poleCount\": 8,\"rated_current\": 7.0,\"J\": 2.84285514219e-05,\"veloc"
  "ity\": {\"nominal\": 314.159265359,\"maximum\": 471.238898038,\"units\": \"rad\\"
  "/s\"},\"L\": 0.000143504976152,\"R\": 0.2403143394,\"current\": {\"maximum\": {"
  "\"continuous\": 7.0,\"peak\": 21.0},\"units\": \"A\"},\"Ld\": 0.000132237254278,"
  "\"Ke\": 0.0372743524276,\"id\": \"act Motor\"},\"controller\": {\"encoder\": {\""
  "tracking_loop\": {\"zeta\": 1.5}},\"foc\": {\"feedback\": {\"voltage_delay\": 0}"
  "},\"pll\": {\"delay_match\": true,\"properties\": {\"reference\": false},\"keInv"
  "erseScaling\": 1.0},\"operation\": {\"min_deceleration_time\": null},\"dyn_curre"
  "nt\": {\"maxgain\": 1.1},\"zsmt\": {\"errorLimit\": 0.99997,\"properties\": {\"i"
  "ndependent\": true,\"reference\": false},\"duration\": {\"lockDelay\": 0.05},\"p"
  "robe\": {\"accumGain\": 1.0}},\"fault_detect\": {\"recovery\": {\"attempts\": 3}"
  "}},\"metadata\": {\"MCC\": {\"architecture\": \"melody\",\"peripherals\": {\"ins"
  "tances\": [{\"name\": \"ADC1\",\"type\": \"adc\"},{\"name\": \"PWM\",\"type\": "
  "\"pwm_hs\"},{\"name\": \"QEI1\",\"type\": \"qei\"},{\"name\": \"TMR1\",\"type\":"
  " \"timer\"},{\"name\": \"SCCP1\",\"type\": \"timer\"},{\"name\": \"UART1\",\"typ"
  "e\": \"uart\"},{\"name\": \"OPA1\",\"type\": \"opa\"},{\"name\": \"OPA2\",\"type"
  "\": \"opa\"},{\"name\": \"OPA3\",\"type\": \"opa\"}]},\"version\": \"5.7.0\",\"p"
  "eripheral_library\": {\"name\": \"melody\",\"version\": \"NA\"}},\"data_model\":"
  " {\"schema_version\": 5},\"motorBench\": {\"commit_id\": \"6062ee969f17e173cb850"
  "2638f1e3c8ee7bea3fb\",\"version\": \"2.45.0\"},\"MCAF\": {\"build\": {\"commit_i"
  "d\": \"116330\",\"date_str\": \"2023 Feb 09\",\"hostname\": \"motor-control-mcaf"
  "-tags-builder-r7-2frc37-1-0ws3m-smcgr-kthrw\",\"time\": 1675959683.33,\"time_iso"
  "\": \"2023-02-09T16:21:23.327489\",\"time_str\": \"2023 Feb 09 16:21\",\"type\":"
  " \"release\",\"username\": \"jenkins\",\"version\": \"R7\\/RC37\"},\"build_time"
  "\": 1675959683.33,\"build_time_iso\": \"2023-02-09T16:21:23.327489\",\"build_tim"
  "e_str\": \"2023 Feb 09 16:21\",\"commit_id\": \"116330\",\"version\": \"R7\\/RC3"
  "7\"}},\"scdata\": {\"setup\": {\"communications\": {\"baudrate\": 625000},\"anal"
  "ysis\": {\"spindown_time\": {\"units\": \"s\",\"value\": 1.0},\"max_motor_speed"
  "\": {\"units\": \"rad\\/s mechanical\",\"value\": 2094.4}},\"calibration\": {\"v"
  "dc\": {\"units\": \"V\",\"value\": 24.0},\"resistor\": {\"units\": \"ohms\",\"va"
  "lue\": 12.0}}}},\"autotune_result\": {\"current\": {\"Kp\": 0.257851726953,\"pha"
  "se_margin\": 80.0,\"wc\": 2148.81735503,\"Ki\": 554.076265902,\"pi_phase_lag\": "
  "45.0},\"velocity\": {\"Kp\": 0.051185954598,\"phase_margin\": 65.0,\"wc\": 89.05"
  "50787553,\"Ki\": 0.803763481145,\"pi_phase_lag\": 10.0}},\"code_generation_tag_m"
  "ap\": {\"application\": \"sample\",\"diagnostics\": \"x2cscope\"},\"operating_ra"
  "nge\": {\"velocity\": {\"units_qualifier\": \"mechanical\",\"units\": \"rad\\/s"
  "\",\"minimum\": 130.89975}},\"build\": {\"hardware_spec\": \"mclv2:33ck256mp508_"
  "extopamp_pim\",\"normfactor_associations\": [{\"context\": null,\"annotations\":"
  " [{\"typerefs\": [\"MCAF_U_CURRENT_ABC\",\"MCAF_U_CURRENT_ALPHABETA\",\"MCAF_U_C"
  "URRENT_DQ\",\"MCAF_U_CURRENT\",\"MCAF_MOTOR_DATA.omegaCtrl.outMin\",\"MCAF_MOTOR"
  "_DATA.omegaCtrl.outMax\"],\"unit\": \"I\",\"q\": 15},{\"typerefs\": [\"MCAF_MOTO"
  "R_DATA.omegaCtrl.integrator\"],\"unit\": \"I\",\"q\": 15},{\"typerefs\": [\"MCAF"
  "_U_VOLTAGE_ABC\",\"MCAF_U_VOLTAGE_ALPHABETA\",\"MCAF_U_VOLTAGE_DQ\",\"MCAF_U_VOL"
  "TAGE\",\"MCAF_MOTOR_DATA.idCtrl.outMin\",\"MCAF_MOTOR_DATA.idCtrl.outMax\",\"MCA"
  "F_MOTOR_DATA.iqCtrl.outMin\",\"MCAF_MOTOR_DATA.iqCtrl.outMax\"],\"unit\": \"V\","
  "\"q\": 15},{\"typerefs\": [\"MCAF_MOTOR_DATA.idCtrl.integrator\",\"MCAF_MOTOR_DA"
  "TA.iqCtrl.integrator\"],\"unit\": \"V\",\"q\": 31},{\"typerefs\": [\"MCAF_U_DUTY"
  "CYCLE_ABC\"],\"unit\": 1,\"q\": 15},{\"typerefs\": [\"MCAF_U_ANGLE_ELEC\"],\"uni"
  "t\": \"theta_e\",\"q\": 15},{\"typerefs\": [\"MCAF_U_ANGLE_MECH\"],\"unit\": \"t"
  "heta_m\",\"q\": 15},{\"typerefs\": [\"MCAF_U_VELOCITY_MECH\"],\"unit\": \"omega_"
  "m\",\"q\": 15},{\"typerefs\": [\"MCAF_U_VELOCITY_ELEC\"],\"unit\": \"omega_e\","
  "\"q\": 15},{\"typerefs\": [\"MCAF_U_VELOCITY_DTHETA_ELEC_DT\"],\"unit\": \"dthet"
  "a_elec_dt\",\"q\": 15},{\"typerefs\": [\"MCAF_U_TEMPERATURE\"],\"unit\": \"Tempe"
  "rature\",\"q\": 15},{\"typerefs\": [\"MCAF_U_DIMENSIONLESS\",\"MCAF_U_DIMENSIONL"
  "ESS_SINCOS\"],\"unit\": 1,\"q\": 15},{\"typerefs\": [\"MCAF_U_NORMALIZED_GAIN\"]"
  ",\"unit\": 1,\"q\": 14}]}]},\"drive\": {\"iout\": {\"measurement\": {\"compensat"
  "ion\": {\"channels\": [\"a\",\"b\"],\"values\": {\"a\": [1.0,0.0],\"b\": [0.0,1."
  "0]},\"offset\": {\"range\": 0.03125,\"samples\": 128,\"filterGain\": 0.25}}},\"t"
  "ime_constant\": 5.971e-07,\"fullscale\": 22.044,\"maximum\": {\"continuous\": 16"
  ".79},\"units\": \"A\"},\"estimator\": {\"type\": \"pll\",\"runtimeSelect\": fals"
  "e,\"atpll\": {\"tau1\": 0.0001,\"tau2\": 0.00219,\"kpfactor\": 1.9,\"kifactor\":"
  " 30},\"omega1\": 732.0,\"tau\": 0.00219},\"flux_control\": {\"emag_tau\": 0.0016"
  "38,\"idref_tau\": 0.006552},\"temperature\": {\"fullscale\": 327.68,\"units\": "
  "\"C\"},\"pwm\": {\"adc_sampling_delay\": 0,\"period\": 5e-05,\"duty_cycle\": {\""
  "maximum\": 0.945,\"minimum\": 0.014},\"deadtime\": 5.9e-07},\"mcaf\": {\"adc\": "
  "{\"triggerSettings\": {\"noTrigger\": \"NO_TRIGGER\",\"trigger1\": \"PWM1_TRIGGE"
  "R1\",\"trigger2\": \"PWM1_TRIGGER2\"},\"channels\": {\"prefix\": \"MCAF_ADC_\","
  "\"critical\": [\"PHASEA_CURRENT\",\"PHASEB_CURRENT\",\"PHASEC_CURRENT\",\"DCLINK"
  "_CURRENT\",\"DCLINK_VOLTAGE\"],\"required\": {\"single_channel\": [\"DCLINK_CURR"
  "ENT\",\"DCLINK_VOLTAGE\",\"POTENTIOMETER\"],\"dual_channel\": [\"PHASEA_CURRENT"
  "\",\"PHASEB_CURRENT\",\"DCLINK_VOLTAGE\",\"POTENTIOMETER\"],\"triple_channel\": "
  "[\"PHASEA_CURRENT\",\"PHASEB_CURRENT\",\"PHASEC_CURRENT\",\"DCLINK_VOLTAGE\",\"P"
  "OTENTIOMETER\"]},\"optional\": [\"PHASEA_VOLTAGE\",\"PHASEB_VOLTAGE\",\"PHASEC_V"
  "OLTAGE\",\"BRIDGE_TEMPERATURE\",\"ABSREF_VOLTAGE\"],\"fullList\": [{\"name\": \""
  "PHASEA_CURRENT\",\"c_fragment\": \"IphaseA\",\"description\": \"phase A current"
  "\"},{\"name\": \"PHASEB_CURRENT\",\"c_fragment\": \"IphaseB\",\"description\": "
  "\"phase B current\"},{\"name\": \"PHASEC_CURRENT\",\"c_fragment\": \"IphaseC\","
  "\"description\": \"phase C current\"},{\"name\": \"PHASEA_VOLTAGE\",\"c_fragment"
  "\": \"VphaseA\",\"description\": \"phase A voltage\"},{\"name\": \"PHASEB_VOLTAG"
  "E\",\"c_fragment\": \"VphaseB\",\"description\": \"phase B voltage\"},{\"name\":"
  " \"PHASEC_VOLTAGE\",\"c_fragment\": \"VphaseC\",\"description\": \"phase C volta"
  "ge\"},{\"name\": \"DCLINK_CURRENT\",\"c_fragment\": \"Ibus\",\"description\": \""
  "DC link current\"},{\"name\": \"DCLINK_VOLTAGE\",\"c_fragment\": \"Dclink\",\"de"
  "scription\": \"DC link voltage\"},{\"name\": \"POTENTIOMETER\",\"c_fragment\": "
  "\"Potentiometer\",\"description\": \"potentiometer voltage\"},{\"name\": \"BRIDG"
  "E_TEMPERATURE\",\"c_fragment\": \"BridgeTemperature\",\"description\": \"bridge "
  "temperature voltage\"},{\"name\": \"ABSREF_VOLTAGE\",\"c_fragment\": \"AbsoluteR"
  "eferenceVoltage\",\"description\": \"absolute reference voltage\"}]}}},\"metadat"
  "a\": {\"name\": \"MCLV-48V-300W Development Board\",\"id\": \"mclv-48v-300w\"},"
  "\"vdc\": {\"nominal\": 24.0,\"time_constant\": 2.87e-05,\"fullscale\": 75.9,\"ma"
  "ximum\": 48.0,\"units\": \"V\",\"minimum\": 12.0},\"configuration\": {\"metadata"
  "\": {\"capability\": {\"adc\": {\"channel\": {\"ABSREF_VOLTAGE\": \"AN6\",\"PHAS"
  "EB_VOLTAGE\": \"AN11\",\"PHASEB_CURRENT\": \"AN4\",\"PHASEA_VOLTAGE\": \"AN10\","
  "\"PHASEC_CURRENT\": \"AN16\",\"POTENTIOMETER\": \"AN17\",\"BRIDGE_TEMPERATURE\":"
  " \"AN18\",\"DCLINK_VOLTAGE\": \"AN15\",\"PHASEA_CURRENT\": \"AN1\",\"PHASEC_VOLT"
  "AGE\": \"AN12\",\"DCLINK_CURRENT\": \"AN0\"}},\"opamp\": \"internal\",\"buttonCo"
  "unt\": 2.0,\"current_measure\": {\"a\": true,\"b\": true,\"c\": true,\"dc\": tru"
  "e}},\"scaling\": {\"temperature\": {\"bridge\": {\"offset\": 5000.0,\"gain\": 0."
  "50354}}},\"peripherals\": {\"adc\": {\"core\": {\"names\": [\"Core0\",\"Core1\","
  "\"SharedCore\"]}}},\"pim\": {\"algorithm\": {\"single_channel\": {\"supported\":"
  " true}},\"device\": \"33ck256mp508\",\"displayName\": \"dsPIC33CK256MP508\",\"id"
  "\": \"33ck256mp508_dim\",\"opamp\": \"internal\",\"peripherals\": {\"adc\": {\"c"
  "ore\": {\"names\": [\"Core0\",\"Core1\",\"SharedCore\"]}}}},\"device\": \"33ck25"
  "6mp508\",\"board\": {\"id\": \"mclv-48v-300w\"}},\"peripherals\": {\"adc\": {\"r"
  "equestedDedCoreSamplingTimeData\": [{\"core\": \"Core0\",\"requestedSamplingTime"
  "_us\": 0.3},{\"core\": \"Core1\",\"requestedSamplingTime_us\": 0.3}],\"dataOutpu"
  "tFormat\": \"Fractional\",\"channelConfig\": [{\"channel\": \"AN1\",\"sign\": \""
  "signed\",\"core\": \"Core1\",\"customName\": \"MCAF_ADC_PHASEA_CURRENT\",\"inver"
  "ted\": true},{\"channel\": \"AN4\",\"sign\": \"signed\",\"core\": \"Shared\",\"c"
  "ustomName\": \"MCAF_ADC_PHASEB_CURRENT\",\"inverted\": true},{\"channel\": \"AN1"
  "6\",\"sign\": \"signed\",\"core\": \"Shared\",\"customName\": \"MCAF_ADC_PHASEC_"
  "CURRENT\",\"inverted\": true},{\"channel\": \"AN0\",\"sign\": \"signed\",\"core"
  "\": \"Core0\",\"customName\": \"MCAF_ADC_DCLINK_CURRENT\",\"inverted\": false},{"
  "\"channel\": \"AN15\",\"sign\": \"signed\",\"core\": \"Shared\",\"customName\": "
  "\"MCAF_ADC_DCLINK_VOLTAGE\"},{\"channel\": \"AN6\",\"sign\": \"unsigned\",\"core"
  "\": \"Shared\",\"customName\": \"MCAF_ADC_ABSREF_VOLTAGE\"},{\"channel\": \"AN17"
  "\",\"sign\": \"signed\",\"core\": \"Shared\",\"customName\": \"MCAF_ADC_POTENTIO"
  "METER\"},{\"channel\": \"AN18\",\"sign\": \"unsigned\",\"core\": \"Shared\",\"cu"
  "stomName\": \"MCAF_ADC_BRIDGE_TEMPERATURE\"},{\"channel\": \"AN10\",\"sign\": \""
  "unsigned\",\"core\": \"Shared\",\"customName\": \"MCAF_ADC_PHASEA_VOLTAGE\"},{\""
  "channel\": \"AN11\",\"sign\": \"unsigned\",\"core\": \"Shared\",\"customName\": "
  "\"MCAF_ADC_PHASEB_VOLTAGE\"},{\"channel\": \"AN12\",\"sign\": \"unsigned\",\"cor"
  "e\": \"Shared\",\"customName\": \"MCAF_ADC_PHASEC_VOLTAGE\"}],\"customName\": \""
  "MCC_ADC\",\"interruptDriven\": false,\"requestedSharedSamplingTime_us\": 0.3,\"r"
  "esolution\": 12.0},\"timer\": [{\"requestedTimerPeriod_ms\": 1.0,\"customName\":"
  " \"MCC_TMR_TICK\",\"interruptDriven\": true},{\"clkSrc\": \"FCY\",\"customName\""
  ": \"MCC_TMR_PROFILE\",\"interruptDriven\": false,\"clkPrescaler\": 1.0,\"periodC"
  "ount\": 65535.0}],\"oscillator\": {\"clockSource\": \"External Oscillator with P"
  "LL\",\"requestedSystemFrequency_Hz\": 0.0,\"defaultValue\": \"max-frequency\",\""
  "setMaximumSystemFrequency\": true,\"clockSourceFrequency\": 8000000.0},\"opamp\""
  ": [{\"customName\": \"MCC_OPA_IDC\",\"enable\": true,\"instance\": 1.0},{\"custo"
  "mName\": \"MCC_OPA_IA\",\"enable\": true,\"instance\": 2.0},{\"customName\": \"M"
  "CC_OPA_IB\",\"enable\": true,\"instance\": 3.0}],\"qei\": [{\"noiseFilterEnable"
  "\": false,\"pinMapping\": [{\"pin\": \"RC4\",\"functionName\": \"A\",\"direction"
  "\": \"input\"},{\"pin\": \"RC5\",\"functionName\": \"B\",\"direction\": \"input"
  "\"},{\"pin\": \"RD2\",\"functionName\": \"INDX\",\"direction\": \"input\"}],\"qe"
  "iOperationMode\": \"Modulo Count mode\",\"indexPulseCaptureEnable\": false,\"hom"
  "ePulseCaptureEnable\": false,\"homePulsePolarity\": false,\"customName\": \"MCC_"
  "QEI\",\"indexPulsePolarity\": false}],\"wdt\": {\"wdtEnable\": true,\"requestedW"
  "dtPeriod_ms\": 1.0,\"wdtMode\": \"Non-Window mode\",\"wdtEnableType\": \"Softwar"
  "e\"},\"pwm\": {\"synchronousUpdate\": true,\"duty_cycle\": {\"maximum\": 0.945,"
  "\"minimum\": 0.014},\"requestedDeadTime_us\": {\"defaultValue\": 0.59,\"maximum"
  "\": 6.0,\"minimum\": 0.385},\"customName\": \"MCC_PWM\",\"generatorMapping\": [{"
  "\"name\": \"MOTOR1_PHASE_A\",\"generator\": 1.0},{\"name\": \"MOTOR1_PHASE_B\","
  "\"generator\": 2.0},{\"name\": \"MOTOR1_PHASE_C\",\"generator\": 3.0}],\"interru"
  "ptDriven\": false,\"faultInputPolarity\": \"Active-low\",\"frequency\": {\"defau"
  "ltValue\": 20000.0,\"maximum\": 50000.0,\"minimum\": 1000.0},\"faultInputSource"
  "\": \"Device pin, PCI20\",\"polarity\": {\"lower\": \"Active-high\",\"upper\": "
  "\"Active-high\"}},\"uart\": {\"baudRate\": 115200.0,\"pinMapping\": [{\"name\": "
  "\"TX\",\"pinSelected\": \"RD14\"},{\"name\": \"RX\",\"pinSelected\": \"RD13\"}],"
  "\"stopBits\": 1.0,\"parity\": \"None\",\"dataSize\": 8.0,\"customName\": \"MCC_U"
  "ART\",\"interruptDriven\": false},\"gpio\": [{\"isWeakPullUp\": false,\"pinSelec"
  "ted\": \"RE12\",\"interruptOnChange\": \"none\",\"isWeakPullDown\": false,\"cust"
  "omName\": \"MCAF_LED1\",\"isAnalogPin\": false,\"direction\": \"output\",\"isOpe"
  "nDrain\": false},{\"isWeakPullUp\": false,\"pinSelected\": \"RE13\",\"interruptO"
  "nChange\": \"none\",\"isWeakPullDown\": false,\"customName\": \"MCAF_LED2\",\"is"
  "AnalogPin\": false,\"direction\": \"output\",\"isOpenDrain\": false},{\"isWeakPu"
  "llUp\": false,\"pinSelected\": \"RE10\",\"interruptOnChange\": \"none\",\"isWeak"
  "PullDown\": false,\"customName\": \"MCAF_BUTTON1\",\"isAnalogPin\": false,\"dire"
  "ction\": \"input\",\"isOpenDrain\": false},{\"isWeakPullUp\": false,\"pinSelecte"
  "d\": \"RE11\",\"interruptOnChange\": \"none\",\"isWeakPullDown\": false,\"custom"
  "Name\": \"MCAF_BUTTON2\",\"isAnalogPin\": false,\"direction\": \"input\",\"isOpe"
  "nDrain\": false},{\"isWeakPullUp\": false,\"pinSelected\": \"RE8\",\"interruptOn"
  "Change\": \"none\",\"isWeakPullDown\": false,\"customName\": \"MCAF_TESTPOINT1\""
  ",\"isAnalogPin\": false,\"direction\": \"output\",\"isOpenDrain\": false}]},\"di"
  "splayName\": \"MCLV-48V-300W\",\"name\": \"MCLV-48V-300W Inverter Board\",\"part"
  "Number\": \"EV18H47A\",\"id\": \"mclv-48v-300w\",\"supportedPim\": [\"33ck256mp5"
  "08_dim\",\"33ck64mc105_dim\"]},\"idc\": {\"maximum\": 2.9,\"units\": \"A\"},\"sa"
  "mpling_time\": {\"current\": 5e-05,\"velocity\": 0.001},\"processor\": {\"clock_"
  "frequency\": 100000000.0,\"pim\": \"dsPIC33CK256MP508\",\"familyName\": \"dsPIC3"
  "3CK256MP508\",\"device\": \"dsPIC33CK256MP508\"},\"vbus\": 24.0},\"config\": {\""
  "ui\": {\"content\": {\"current_measure-method\": \"dual_channel\",\"current_meas"
  "ure-single_channel-minimumTime\": 2.0,\"current_measure-single_channel-sampleDel"
  "ay\": 0.0,\"current_measure-opamp-full_input_range\": true,\"estimator-type\": "
  "\"pll\",\"estimator-active-pll\": false,\"estimator-active-qei\": false,\"estima"
  "tor-active-atpll\": false,\"estimator-active-zsmt\": false,\"estimator-active-id"
  "eal\": false,\"operation-min_velocity_ratio\": 0.25,\"operation-startup_velocity"
  "_ratio\": 0.2744,\"operation-max_velocity_ratio\": 1.25,\"operation-fullscale_ba"
  "se_ratio\": 1.5,\"operation-outer_loop_type\": \"velocity\",\"operation-saliency"
  "-threshold\": 1.25,\"operation-slewrate-accel\": 0.5,\"operation-slewrate-decel"
  "\": 1.0,\"operation-dyn_current_type\": \"none\",\"operation-stopping-type\": \""
  "minimal_impact\",\"operation-stopping-closed_loop_parameters-speed\": 0.05,\"ope"
  "ration-stopping-closed_loop_parameters-time\": 0.5,\"operation-coastdown-end_vel"
  "ocity\": 0.05,\"operation-coastdown-time\": 1.2,\"fault_inject-get_tf-div0\": fa"
  "lse,\"fault_inject-get_tf-missing_data\": false,\"fault_inject-get_tf-raise_valu"
  "e_error\": false,\"fault_inject-get_tf-raise_custom_error\": false,\"fault_injec"
  "t-tf-tf_null\": false,\"fault_inject-tf-tf_jy\": false,\"fault_inject-tf-tf_jyex"
  "\": false,\"fault_inject-tf-div0\": false,\"fault_inject-tf-tau\": 0.0,\"flux_co"
  "ntrol-method\": \"none\",\"flux_control-eqn_based-ilimit-region_type\": \"quadra"
  "tic\",\"flux_control-eqn_based-ilimit-id_limit\": 0.7,\"flux_control-eqn_based-i"
  "limit-iq_limit\": 0.95,\"flux_control-eqn_based-fluxweak_enable\": false,\"flux_"
  "control-eqn_based-fw-vdq_limit\": 0.95,\"flux_control-eqn_based-mtpa_enable\": f"
  "alse,\"deadtimecomp-method\": \"none\",\"deadtimecomp-perphase-current_sign_band"
  "\": 0.02,\"deadtimecomp-perphase-forward_gain\": 0.0,\"deadtimecomp-perphase-fee"
  "dback_gain\": 0.0,\"fault_detect-margin_uv\": 2.0,\"fault_detect-margin_ov\": 2."
  "0,\"fault_detect-stall_detect_enable\": true,\"startup-Istartup\": 0.2,\"startup"
  "-t_rampup\": 25.0,\"startup-t_align\": 0.0,\"startup-min_total_accel_time\": 250"
  ".0,\"startup-torque_scale_accel\": 0.15,\"startup-torque_scale_slow_accel\": 0.2"
  ",\"startup-t_hold\": 0.0,\"startup-omega0\": 0.2,\"startup-theta_converge_rate\""
  ": 1.0,\"startup-method\": \"classic\",\"startup-damping-Imax\": 0.1,\"startup-da"
  "mping-gainmax\": 40.0,\"startup-damping-omega_min\": 0.4,\"overmodulation-vd_lim"
  "it\": 1.0,\"overmodulation-vq_limit\": 1.15,\"overmodulation-include_duty_clippi"
  "ng\": true,\"pll-tau\": 2.19,\"pll-omega1\": 116.5,\"pll-velocity_filter_thresho"
  "ld\": 1.0,\"encoder-lines\": 250.0,\"encoder-index_present\": false,\"encoder-tr"
  "acking_loop-tau\": 1.5,\"encoder-qei_sync-method\": \"align\",\"encoder-qei_sync"
  "-align-t_align\": 0.5,\"encoder-qei_sync-align-angle_shift\": 30.0,\"encoder-qei"
  "_sync-align-angle_init\": -30.0,\"encoder-qei_sync-align_sweep-sweep_rate_pow\":"
  " 1.0,\"encoder-qei_sync-align_sweep-setup_angle\": 45.0,\"encoder-qei_sync-pullo"
  "ut-pullout_slip\": 0.117,\"zsmt-excitation-kV\": 0.12,\"zsmt-excitation-kI\": 0."
  "1,\"zsmt-pll-zeta\": 1.5,\"zsmt-pll-tau\": 10.0,\"zsmt-pll-tau_lpf\": 0.0,\"zsmt"
  "-pll-execution_divider\": 2.0,\"zsmt-startup-align_delay\": 1.0,\"zsmt-startup-p"
  "ll_lock_time\": 1.0,\"zsmt-startup-speed_limit\": 0.015,\"zsmt-startup-current_l"
  "imit\": 0.3,\"zsmt-startup-probe_duration\": 10.0,\"zsmt-startup-probe_slew_time"
  "\": 1.5,\"zsmt-startup-probe_blanking_time\": 4.0,\"zsmt-hybrid-type\": \"minota"
  "ur\",\"zsmt-minotaur-voltage_limit-vd\": 0.45,\"zsmt-minotaur-voltage_limit-vq\""
  ": 0.78,\"zsmt-minotaur-converge-angle\": 10.0,\"zsmt-minotaur-converge-duration"
  "\": 2.0,\"zsmt-minotaur-velocity_threshold-slow\": 0.15,\"zsmt-minotaur-velocity"
  "_threshold-transition\": 0.2,\"zsmt-minotaur-velocity_threshold-fast\": 0.25,\"z"
  "smt-angle_correction-current_gain\": 0.0,\"dyn_current1-peak_factor\": 1.0,\"dyn"
  "_current1-horizon_factor\": 1.05,\"dyn_current1-tau\": 5.0,\"dyn_current1-nsampl"
  "es\": 128.0,\"voltage_outerloop-tau_lpf\": 2.0,\"voltage_outerloop-Kp\": 0.1,\"v"
  "oltage_outerloop-tau\": 100.0,\"mcapi-isSquaredTau\": 1.0,\"mcapi-iqTau\": 1.0,"
  "\"mcapi-adcIsrUserFunctions_enable\": false,\"board_service-uiServiceTiming\": 1"
  ".0,\"board_service-uiButtonDebounceTime\": 7.0,\"board_service-uiButtonLongPress"
  "Time\": 2.5,\"test_harness-perturbation_asymmetric\": false,\"adc-vtempbridge\":"
  " false,\"adc-temp_bridge_params-threshold\": 50.0,\"adc-temp_bridge_params-tau_l"
  "pf\": 10.0,\"adc-temp_bridge_params-slewrate\": 4.0,\"adc-vabsref\": false,\"adc"
  "-vphasea\": false,\"adc-vphaseb\": false,\"adc-vphasec\": false},\"version\": {"
  "\"schema\": 4.0,\"motorBench\": \"2.45.0\",\"MCAF\": \"R7\"},\"status\": {\"vali"
  "d\": true}}}}";