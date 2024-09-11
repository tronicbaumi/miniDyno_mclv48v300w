#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/mc_mb_sl_fip_dsPIC33CK_mclv48v300w.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/mc_mb_sl_fip_dsPIC33CK_mclv48v300w.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=mcc_generated_files/adc/src/adc1.c mcc_generated_files/motorBench/commutation/pll.c mcc_generated_files/motorBench/hal/mcaf_pin_manager.c mcc_generated_files/motorBench/hal/hardware_access_functions.c mcc_generated_files/motorBench/metadata/data_model_snapshot.c mcc_generated_files/motorBench/parameters/init_params.c mcc_generated_files/motorBench/monitor.c mcc_generated_files/motorBench/mcapi.c mcc_generated_files/motorBench/commutation.c mcc_generated_files/motorBench/math_asm.s mcc_generated_files/motorBench/ui.c mcc_generated_files/motorBench/fault_detect.c mcc_generated_files/motorBench/test_harness.c mcc_generated_files/motorBench/sat_PI.c mcc_generated_files/motorBench/stall_detect.c mcc_generated_files/motorBench/startup.c mcc_generated_files/motorBench/diagnostics.c mcc_generated_files/motorBench/current_measure.c mcc_generated_files/motorBench/test_harness_timestamps.c mcc_generated_files/motorBench/recover.c mcc_generated_files/motorBench/mcaf_traps.c mcc_generated_files/motorBench/isr.c mcc_generated_files/motorBench/foc.c mcc_generated_files/motorBench/system_state.c mcc_generated_files/motorBench/mcaf_main.c mcc_generated_files/motorBench/board_service.c mcc_generated_files/motorBench/adc_compensation.c mcc_generated_files/motorBench/mcaf_sample_application.c mcc_generated_files/motorBench/state_machine.c mcc_generated_files/motorBench/system_init.c mcc_generated_files/opa/src/opa1.c mcc_generated_files/opa/src/opa2.c mcc_generated_files/opa/src/opa3.c mcc_generated_files/pwm_hs/src/pwm.c mcc_generated_files/qei/src/qei1.c mcc_generated_files/system/src/pins.c mcc_generated_files/system/src/system.c mcc_generated_files/system/src/dmt_asm.s mcc_generated_files/system/src/interrupt.c mcc_generated_files/system/src/traps.c mcc_generated_files/system/src/clock.c mcc_generated_files/system/src/dmt.c mcc_generated_files/system/src/config_bits.c mcc_generated_files/system/src/reset.c mcc_generated_files/timer/src/sccp1.c mcc_generated_files/timer/src/tmr1.c mcc_generated_files/uart/src/uart1.c mcc_generated_files/X2Cscope/X2Cscope.c mcc_generated_files/X2Cscope/X2CscopeComm.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o ${OBJECTDIR}/mcc_generated_files/motorBench/commutation/pll.o ${OBJECTDIR}/mcc_generated_files/motorBench/hal/mcaf_pin_manager.o ${OBJECTDIR}/mcc_generated_files/motorBench/hal/hardware_access_functions.o ${OBJECTDIR}/mcc_generated_files/motorBench/metadata/data_model_snapshot.o ${OBJECTDIR}/mcc_generated_files/motorBench/parameters/init_params.o ${OBJECTDIR}/mcc_generated_files/motorBench/monitor.o ${OBJECTDIR}/mcc_generated_files/motorBench/mcapi.o ${OBJECTDIR}/mcc_generated_files/motorBench/commutation.o ${OBJECTDIR}/mcc_generated_files/motorBench/math_asm.o ${OBJECTDIR}/mcc_generated_files/motorBench/ui.o ${OBJECTDIR}/mcc_generated_files/motorBench/fault_detect.o ${OBJECTDIR}/mcc_generated_files/motorBench/test_harness.o ${OBJECTDIR}/mcc_generated_files/motorBench/sat_PI.o ${OBJECTDIR}/mcc_generated_files/motorBench/stall_detect.o ${OBJECTDIR}/mcc_generated_files/motorBench/startup.o ${OBJECTDIR}/mcc_generated_files/motorBench/diagnostics.o ${OBJECTDIR}/mcc_generated_files/motorBench/current_measure.o ${OBJECTDIR}/mcc_generated_files/motorBench/test_harness_timestamps.o ${OBJECTDIR}/mcc_generated_files/motorBench/recover.o ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_traps.o ${OBJECTDIR}/mcc_generated_files/motorBench/isr.o ${OBJECTDIR}/mcc_generated_files/motorBench/foc.o ${OBJECTDIR}/mcc_generated_files/motorBench/system_state.o ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_main.o ${OBJECTDIR}/mcc_generated_files/motorBench/board_service.o ${OBJECTDIR}/mcc_generated_files/motorBench/adc_compensation.o ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_sample_application.o ${OBJECTDIR}/mcc_generated_files/motorBench/state_machine.o ${OBJECTDIR}/mcc_generated_files/motorBench/system_init.o ${OBJECTDIR}/mcc_generated_files/opa/src/opa1.o ${OBJECTDIR}/mcc_generated_files/opa/src/opa2.o ${OBJECTDIR}/mcc_generated_files/opa/src/opa3.o ${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o ${OBJECTDIR}/mcc_generated_files/qei/src/qei1.o ${OBJECTDIR}/mcc_generated_files/system/src/pins.o ${OBJECTDIR}/mcc_generated_files/system/src/system.o ${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o ${OBJECTDIR}/mcc_generated_files/system/src/traps.o ${OBJECTDIR}/mcc_generated_files/system/src/clock.o ${OBJECTDIR}/mcc_generated_files/system/src/dmt.o ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o ${OBJECTDIR}/mcc_generated_files/system/src/reset.o ${OBJECTDIR}/mcc_generated_files/timer/src/sccp1.o ${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o ${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o ${OBJECTDIR}/mcc_generated_files/X2Cscope/X2Cscope.o ${OBJECTDIR}/mcc_generated_files/X2Cscope/X2CscopeComm.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/commutation/pll.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/hal/mcaf_pin_manager.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/hal/hardware_access_functions.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/metadata/data_model_snapshot.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/parameters/init_params.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/monitor.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/mcapi.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/commutation.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/math_asm.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/ui.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/fault_detect.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/test_harness.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/sat_PI.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/stall_detect.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/startup.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/diagnostics.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/current_measure.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/test_harness_timestamps.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/recover.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_traps.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/isr.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/foc.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/system_state.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_main.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/board_service.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/adc_compensation.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_sample_application.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/state_machine.o.d ${OBJECTDIR}/mcc_generated_files/motorBench/system_init.o.d ${OBJECTDIR}/mcc_generated_files/opa/src/opa1.o.d ${OBJECTDIR}/mcc_generated_files/opa/src/opa2.o.d ${OBJECTDIR}/mcc_generated_files/opa/src/opa3.o.d ${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o.d ${OBJECTDIR}/mcc_generated_files/qei/src/qei1.o.d ${OBJECTDIR}/mcc_generated_files/system/src/pins.o.d ${OBJECTDIR}/mcc_generated_files/system/src/system.o.d ${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o.d ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o.d ${OBJECTDIR}/mcc_generated_files/system/src/traps.o.d ${OBJECTDIR}/mcc_generated_files/system/src/clock.o.d ${OBJECTDIR}/mcc_generated_files/system/src/dmt.o.d ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o.d ${OBJECTDIR}/mcc_generated_files/system/src/reset.o.d ${OBJECTDIR}/mcc_generated_files/timer/src/sccp1.o.d ${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o.d ${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o.d ${OBJECTDIR}/mcc_generated_files/X2Cscope/X2Cscope.o.d ${OBJECTDIR}/mcc_generated_files/X2Cscope/X2CscopeComm.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o ${OBJECTDIR}/mcc_generated_files/motorBench/commutation/pll.o ${OBJECTDIR}/mcc_generated_files/motorBench/hal/mcaf_pin_manager.o ${OBJECTDIR}/mcc_generated_files/motorBench/hal/hardware_access_functions.o ${OBJECTDIR}/mcc_generated_files/motorBench/metadata/data_model_snapshot.o ${OBJECTDIR}/mcc_generated_files/motorBench/parameters/init_params.o ${OBJECTDIR}/mcc_generated_files/motorBench/monitor.o ${OBJECTDIR}/mcc_generated_files/motorBench/mcapi.o ${OBJECTDIR}/mcc_generated_files/motorBench/commutation.o ${OBJECTDIR}/mcc_generated_files/motorBench/math_asm.o ${OBJECTDIR}/mcc_generated_files/motorBench/ui.o ${OBJECTDIR}/mcc_generated_files/motorBench/fault_detect.o ${OBJECTDIR}/mcc_generated_files/motorBench/test_harness.o ${OBJECTDIR}/mcc_generated_files/motorBench/sat_PI.o ${OBJECTDIR}/mcc_generated_files/motorBench/stall_detect.o ${OBJECTDIR}/mcc_generated_files/motorBench/startup.o ${OBJECTDIR}/mcc_generated_files/motorBench/diagnostics.o ${OBJECTDIR}/mcc_generated_files/motorBench/current_measure.o ${OBJECTDIR}/mcc_generated_files/motorBench/test_harness_timestamps.o ${OBJECTDIR}/mcc_generated_files/motorBench/recover.o ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_traps.o ${OBJECTDIR}/mcc_generated_files/motorBench/isr.o ${OBJECTDIR}/mcc_generated_files/motorBench/foc.o ${OBJECTDIR}/mcc_generated_files/motorBench/system_state.o ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_main.o ${OBJECTDIR}/mcc_generated_files/motorBench/board_service.o ${OBJECTDIR}/mcc_generated_files/motorBench/adc_compensation.o ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_sample_application.o ${OBJECTDIR}/mcc_generated_files/motorBench/state_machine.o ${OBJECTDIR}/mcc_generated_files/motorBench/system_init.o ${OBJECTDIR}/mcc_generated_files/opa/src/opa1.o ${OBJECTDIR}/mcc_generated_files/opa/src/opa2.o ${OBJECTDIR}/mcc_generated_files/opa/src/opa3.o ${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o ${OBJECTDIR}/mcc_generated_files/qei/src/qei1.o ${OBJECTDIR}/mcc_generated_files/system/src/pins.o ${OBJECTDIR}/mcc_generated_files/system/src/system.o ${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o ${OBJECTDIR}/mcc_generated_files/system/src/traps.o ${OBJECTDIR}/mcc_generated_files/system/src/clock.o ${OBJECTDIR}/mcc_generated_files/system/src/dmt.o ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o ${OBJECTDIR}/mcc_generated_files/system/src/reset.o ${OBJECTDIR}/mcc_generated_files/timer/src/sccp1.o ${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o ${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o ${OBJECTDIR}/mcc_generated_files/X2Cscope/X2Cscope.o ${OBJECTDIR}/mcc_generated_files/X2Cscope/X2CscopeComm.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=mcc_generated_files/adc/src/adc1.c mcc_generated_files/motorBench/commutation/pll.c mcc_generated_files/motorBench/hal/mcaf_pin_manager.c mcc_generated_files/motorBench/hal/hardware_access_functions.c mcc_generated_files/motorBench/metadata/data_model_snapshot.c mcc_generated_files/motorBench/parameters/init_params.c mcc_generated_files/motorBench/monitor.c mcc_generated_files/motorBench/mcapi.c mcc_generated_files/motorBench/commutation.c mcc_generated_files/motorBench/math_asm.s mcc_generated_files/motorBench/ui.c mcc_generated_files/motorBench/fault_detect.c mcc_generated_files/motorBench/test_harness.c mcc_generated_files/motorBench/sat_PI.c mcc_generated_files/motorBench/stall_detect.c mcc_generated_files/motorBench/startup.c mcc_generated_files/motorBench/diagnostics.c mcc_generated_files/motorBench/current_measure.c mcc_generated_files/motorBench/test_harness_timestamps.c mcc_generated_files/motorBench/recover.c mcc_generated_files/motorBench/mcaf_traps.c mcc_generated_files/motorBench/isr.c mcc_generated_files/motorBench/foc.c mcc_generated_files/motorBench/system_state.c mcc_generated_files/motorBench/mcaf_main.c mcc_generated_files/motorBench/board_service.c mcc_generated_files/motorBench/adc_compensation.c mcc_generated_files/motorBench/mcaf_sample_application.c mcc_generated_files/motorBench/state_machine.c mcc_generated_files/motorBench/system_init.c mcc_generated_files/opa/src/opa1.c mcc_generated_files/opa/src/opa2.c mcc_generated_files/opa/src/opa3.c mcc_generated_files/pwm_hs/src/pwm.c mcc_generated_files/qei/src/qei1.c mcc_generated_files/system/src/pins.c mcc_generated_files/system/src/system.c mcc_generated_files/system/src/dmt_asm.s mcc_generated_files/system/src/interrupt.c mcc_generated_files/system/src/traps.c mcc_generated_files/system/src/clock.c mcc_generated_files/system/src/dmt.c mcc_generated_files/system/src/config_bits.c mcc_generated_files/system/src/reset.c mcc_generated_files/timer/src/sccp1.c mcc_generated_files/timer/src/tmr1.c mcc_generated_files/uart/src/uart1.c mcc_generated_files/X2Cscope/X2Cscope.c mcc_generated_files/X2Cscope/X2CscopeComm.c main.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/mc_mb_sl_fip_dsPIC33CK_mclv48v300w.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33CK256MP508
MP_LINKER_FILE_OPTION=,--script=p33CK256MP508.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o: mcc_generated_files/adc/src/adc1.c  .generated_files/flags/default/819285e46b66e64b1426d19c912894f8f96661a5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/adc/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/adc/src/adc1.c  -o ${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/commutation/pll.o: mcc_generated_files/motorBench/commutation/pll.c  .generated_files/flags/default/94bdf2bea17bc7ebdf25b8d21d6187eb68a68432 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench/commutation" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/commutation/pll.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/commutation/pll.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/commutation/pll.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/commutation/pll.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/commutation/pll.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/hal/mcaf_pin_manager.o: mcc_generated_files/motorBench/hal/mcaf_pin_manager.c  .generated_files/flags/default/6a040ba5ad189f9e1d194ccf11e36918e21fd2ec .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench/hal" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/hal/mcaf_pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/hal/mcaf_pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/hal/mcaf_pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/hal/mcaf_pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/hal/mcaf_pin_manager.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/hal/hardware_access_functions.o: mcc_generated_files/motorBench/hal/hardware_access_functions.c  .generated_files/flags/default/40521554ffe834f0907483d6fed70c2ec34dccb9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench/hal" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/hal/hardware_access_functions.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/hal/hardware_access_functions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/hal/hardware_access_functions.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/hal/hardware_access_functions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/hal/hardware_access_functions.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/metadata/data_model_snapshot.o: mcc_generated_files/motorBench/metadata/data_model_snapshot.c  .generated_files/flags/default/788067da8b1c5356644f458cc8d3bd59a1d7fbbd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench/metadata" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/metadata/data_model_snapshot.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/metadata/data_model_snapshot.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/metadata/data_model_snapshot.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/metadata/data_model_snapshot.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/metadata/data_model_snapshot.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/parameters/init_params.o: mcc_generated_files/motorBench/parameters/init_params.c  .generated_files/flags/default/49d68c5db610fa0096ac7ed42dc6c4de8b04ca58 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench/parameters" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/parameters/init_params.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/parameters/init_params.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/parameters/init_params.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/parameters/init_params.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/parameters/init_params.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/monitor.o: mcc_generated_files/motorBench/monitor.c  .generated_files/flags/default/511b5c5811b2049c2558e58c824f721cd233940a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/monitor.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/monitor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/monitor.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/monitor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/monitor.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/mcapi.o: mcc_generated_files/motorBench/mcapi.c  .generated_files/flags/default/76c0f3dd505a8349c5e6170823e370cf2ee0e476 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/mcapi.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/mcapi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/mcapi.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/mcapi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/mcapi.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/commutation.o: mcc_generated_files/motorBench/commutation.c  .generated_files/flags/default/3c7cb0aa9f0c0666bcf5a95376c4e5d0c578a7d2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/commutation.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/commutation.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/commutation.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/commutation.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/commutation.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/ui.o: mcc_generated_files/motorBench/ui.c  .generated_files/flags/default/8c89b0e33dd122e20a81d91cb3af9ef6d5009dd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/ui.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/ui.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/ui.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/ui.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/ui.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/fault_detect.o: mcc_generated_files/motorBench/fault_detect.c  .generated_files/flags/default/7370bb926ee41debc034371392fa3ecf4c06d3d4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/fault_detect.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/fault_detect.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/fault_detect.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/fault_detect.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/fault_detect.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/test_harness.o: mcc_generated_files/motorBench/test_harness.c  .generated_files/flags/default/f4b00bd2e27457ab96dac13b472d2090e3da98d7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/test_harness.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/test_harness.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/test_harness.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/test_harness.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/test_harness.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/sat_PI.o: mcc_generated_files/motorBench/sat_PI.c  .generated_files/flags/default/7c658c60fab469444a21b63e1f18f9c6e5c41b30 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/sat_PI.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/sat_PI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/sat_PI.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/sat_PI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/sat_PI.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/stall_detect.o: mcc_generated_files/motorBench/stall_detect.c  .generated_files/flags/default/a6cfa916284977d3627501a6dbe886d40fbe3ce1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/stall_detect.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/stall_detect.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/stall_detect.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/stall_detect.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/stall_detect.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/startup.o: mcc_generated_files/motorBench/startup.c  .generated_files/flags/default/a8867c29df49b660c10e58dd1c1bce2f81d27322 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/startup.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/startup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/startup.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/startup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/startup.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/diagnostics.o: mcc_generated_files/motorBench/diagnostics.c  .generated_files/flags/default/c275ae3ec9384aa2ae8ab8d2debb3375241c69e8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/diagnostics.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/diagnostics.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/diagnostics.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/diagnostics.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/diagnostics.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/current_measure.o: mcc_generated_files/motorBench/current_measure.c  .generated_files/flags/default/f345a5b4bbc17cecb0ec06d3db0d66c41cc437cf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/current_measure.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/current_measure.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/current_measure.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/current_measure.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/current_measure.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/test_harness_timestamps.o: mcc_generated_files/motorBench/test_harness_timestamps.c  .generated_files/flags/default/e1a371f2f2d1ca18d8957901b8fc1f684211986b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/test_harness_timestamps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/test_harness_timestamps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/test_harness_timestamps.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/test_harness_timestamps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/test_harness_timestamps.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/recover.o: mcc_generated_files/motorBench/recover.c  .generated_files/flags/default/33dc715502a7ae2fa2ba9471602b663b01a9b794 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/recover.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/recover.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/recover.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/recover.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/recover.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_traps.o: mcc_generated_files/motorBench/mcaf_traps.c  .generated_files/flags/default/5fb9ba354a54128e84e49bd0e8437a094379c2e7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/mcaf_traps.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_traps.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/isr.o: mcc_generated_files/motorBench/isr.c  .generated_files/flags/default/c21f4f658807a7f6da4dfbb53f71af81b1454985 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/isr.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/isr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/isr.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/isr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/isr.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/foc.o: mcc_generated_files/motorBench/foc.c  .generated_files/flags/default/c5029ad6bc5f9275bb62c42077a77e8fed7e57be .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/foc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/foc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/foc.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/foc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/foc.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/system_state.o: mcc_generated_files/motorBench/system_state.c  .generated_files/flags/default/3d733b3d6d8bb8cd9e303265a0db46546e22e63b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/system_state.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/system_state.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/system_state.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/system_state.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/system_state.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_main.o: mcc_generated_files/motorBench/mcaf_main.c  .generated_files/flags/default/f8b23a29b5755afba65b91415d682a2b3d685a43 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_main.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/mcaf_main.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/board_service.o: mcc_generated_files/motorBench/board_service.c  .generated_files/flags/default/a5d534f45e329fd34d0cbbbb97a39c86b3a673a5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/board_service.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/board_service.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/board_service.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/board_service.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/board_service.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/adc_compensation.o: mcc_generated_files/motorBench/adc_compensation.c  .generated_files/flags/default/ceb7f7065a365167bd9082eeee5d2c67fbbec51 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/adc_compensation.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/adc_compensation.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/adc_compensation.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/adc_compensation.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/adc_compensation.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_sample_application.o: mcc_generated_files/motorBench/mcaf_sample_application.c  .generated_files/flags/default/9dbc806dc338401aa42b237e6d5fa51ae6e83dc3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_sample_application.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_sample_application.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/mcaf_sample_application.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_sample_application.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_sample_application.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/state_machine.o: mcc_generated_files/motorBench/state_machine.c  .generated_files/flags/default/5a6924ead9db29741fee4a03110a31928699e8e5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/state_machine.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/state_machine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/state_machine.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/state_machine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/state_machine.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/system_init.o: mcc_generated_files/motorBench/system_init.c  .generated_files/flags/default/cc607aabaff7761a48a6739a50eb4e128ff2ae41 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/system_init.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/system_init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/system_init.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/system_init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/system_init.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/opa/src/opa1.o: mcc_generated_files/opa/src/opa1.c  .generated_files/flags/default/4955f14da68546af1fbc8eec8ebef5a21e3bc51c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/opa/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/opa/src/opa1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/opa/src/opa1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/opa/src/opa1.c  -o ${OBJECTDIR}/mcc_generated_files/opa/src/opa1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/opa/src/opa1.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/opa/src/opa2.o: mcc_generated_files/opa/src/opa2.c  .generated_files/flags/default/dafcf845a97325a93dc8976153b383ea1299f6f7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/opa/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/opa/src/opa2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/opa/src/opa2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/opa/src/opa2.c  -o ${OBJECTDIR}/mcc_generated_files/opa/src/opa2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/opa/src/opa2.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/opa/src/opa3.o: mcc_generated_files/opa/src/opa3.c  .generated_files/flags/default/7c2acd7ecf9c1c71c48a6577248e4b4c7b864c26 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/opa/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/opa/src/opa3.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/opa/src/opa3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/opa/src/opa3.c  -o ${OBJECTDIR}/mcc_generated_files/opa/src/opa3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/opa/src/opa3.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o: mcc_generated_files/pwm_hs/src/pwm.c  .generated_files/flags/default/dd893b571ef432520ef80795e96916775792b230 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/pwm_hs/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pwm_hs/src/pwm.c  -o ${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/qei/src/qei1.o: mcc_generated_files/qei/src/qei1.c  .generated_files/flags/default/2ed63ac6ff7c838de4778ecda97804580be9fe7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/qei/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/qei/src/qei1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/qei/src/qei1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/qei/src/qei1.c  -o ${OBJECTDIR}/mcc_generated_files/qei/src/qei1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/qei/src/qei1.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/pins.o: mcc_generated_files/system/src/pins.c  .generated_files/flags/default/b1fb2498ce395f36c5966ceee3a25afe2d74538e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/pins.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/pins.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/pins.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/pins.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/pins.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/system.o: mcc_generated_files/system/src/system.c  .generated_files/flags/default/fdc54f4912cd4a08b4383bda7630c38f1c44cfff .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/system.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/system.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o: mcc_generated_files/system/src/interrupt.c  .generated_files/flags/default/707721b1abd85c4475ca6c0c578df5248eebfee0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/interrupt.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/traps.o: mcc_generated_files/system/src/traps.c  .generated_files/flags/default/15771d21cae679cfcbcc04ec70f7553bf0f256e9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/traps.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/traps.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/clock.o: mcc_generated_files/system/src/clock.c  .generated_files/flags/default/f33f9c224122845dff00aeecce78879e07a5476d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/clock.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/clock.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/dmt.o: mcc_generated_files/system/src/dmt.c  .generated_files/flags/default/e6e5443a430c621c7d00878bce04e56a84306284 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/dmt.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/dmt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/dmt.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/dmt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/dmt.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o: mcc_generated_files/system/src/config_bits.c  .generated_files/flags/default/f25f9ea45a0c90799e5084114e9af08e6ee38b26 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/config_bits.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/reset.o: mcc_generated_files/system/src/reset.c  .generated_files/flags/default/3406c8ef6cfe4d89ffd8c97bb1776736331f7e45 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/reset.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/reset.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/reset.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/timer/src/sccp1.o: mcc_generated_files/timer/src/sccp1.c  .generated_files/flags/default/d563ccf6eb51fa363dc45d053990d79600cd05ff .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/timer/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/sccp1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/sccp1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/timer/src/sccp1.c  -o ${OBJECTDIR}/mcc_generated_files/timer/src/sccp1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/timer/src/sccp1.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o: mcc_generated_files/timer/src/tmr1.c  .generated_files/flags/default/30f5c447854697496f752977314df4495e6372d1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/timer/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/timer/src/tmr1.c  -o ${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o: mcc_generated_files/uart/src/uart1.c  .generated_files/flags/default/a696b47394276ee66e84c48729246d62979351c8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/uart/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/uart/src/uart1.c  -o ${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/X2Cscope/X2Cscope.o: mcc_generated_files/X2Cscope/X2Cscope.c  .generated_files/flags/default/79115d4cc7cf8ca606a7882d73c9f553bd5e9ebd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/X2Cscope" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/X2Cscope/X2Cscope.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/X2Cscope/X2Cscope.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/X2Cscope/X2Cscope.c  -o ${OBJECTDIR}/mcc_generated_files/X2Cscope/X2Cscope.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/X2Cscope/X2Cscope.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/X2Cscope/X2CscopeComm.o: mcc_generated_files/X2Cscope/X2CscopeComm.c  .generated_files/flags/default/63d6ff7998948200cdde681bfa0af3578fe20695 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/X2Cscope" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/X2Cscope/X2CscopeComm.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/X2Cscope/X2CscopeComm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/X2Cscope/X2CscopeComm.c  -o ${OBJECTDIR}/mcc_generated_files/X2Cscope/X2CscopeComm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/X2Cscope/X2CscopeComm.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/c1c626ddf43b24710c0662c64c7830527a1834a0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o: mcc_generated_files/adc/src/adc1.c  .generated_files/flags/default/f2f894bd078d030de529ba85256c942853b5bf8b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/adc/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/adc/src/adc1.c  -o ${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/adc/src/adc1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/commutation/pll.o: mcc_generated_files/motorBench/commutation/pll.c  .generated_files/flags/default/f1589d73476736ddf5e8964889bbe18bdca4219d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench/commutation" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/commutation/pll.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/commutation/pll.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/commutation/pll.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/commutation/pll.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/commutation/pll.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/hal/mcaf_pin_manager.o: mcc_generated_files/motorBench/hal/mcaf_pin_manager.c  .generated_files/flags/default/50b88995d92be3a491ccbd6b30a5c18f2fc6a83d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench/hal" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/hal/mcaf_pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/hal/mcaf_pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/hal/mcaf_pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/hal/mcaf_pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/hal/mcaf_pin_manager.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/hal/hardware_access_functions.o: mcc_generated_files/motorBench/hal/hardware_access_functions.c  .generated_files/flags/default/b564df9d3fa5feab50a94334fb6c25afdba472ef .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench/hal" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/hal/hardware_access_functions.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/hal/hardware_access_functions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/hal/hardware_access_functions.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/hal/hardware_access_functions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/hal/hardware_access_functions.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/metadata/data_model_snapshot.o: mcc_generated_files/motorBench/metadata/data_model_snapshot.c  .generated_files/flags/default/e323a35cf0526d60d8d1405dd4ed4188c69f76fc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench/metadata" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/metadata/data_model_snapshot.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/metadata/data_model_snapshot.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/metadata/data_model_snapshot.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/metadata/data_model_snapshot.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/metadata/data_model_snapshot.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/parameters/init_params.o: mcc_generated_files/motorBench/parameters/init_params.c  .generated_files/flags/default/cd9a8e30cbf7f1337b4a00f70e098b1a414ca65a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench/parameters" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/parameters/init_params.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/parameters/init_params.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/parameters/init_params.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/parameters/init_params.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/parameters/init_params.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/monitor.o: mcc_generated_files/motorBench/monitor.c  .generated_files/flags/default/3beded1fb8816faa4af76955cd7e152fee9d02bd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/monitor.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/monitor.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/monitor.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/monitor.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/monitor.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/mcapi.o: mcc_generated_files/motorBench/mcapi.c  .generated_files/flags/default/fd1c7ce25f100e0c5e13ad895d8599b2b5a4b1a1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/mcapi.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/mcapi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/mcapi.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/mcapi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/mcapi.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/commutation.o: mcc_generated_files/motorBench/commutation.c  .generated_files/flags/default/e850d380901c18bf2371dc16139d5e4e8255c668 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/commutation.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/commutation.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/commutation.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/commutation.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/commutation.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/ui.o: mcc_generated_files/motorBench/ui.c  .generated_files/flags/default/63e96f342617e360107993244001b000af325463 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/ui.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/ui.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/ui.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/ui.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/ui.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/fault_detect.o: mcc_generated_files/motorBench/fault_detect.c  .generated_files/flags/default/6848ae95dc979d272e173ef6f6669491fb38333b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/fault_detect.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/fault_detect.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/fault_detect.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/fault_detect.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/fault_detect.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/test_harness.o: mcc_generated_files/motorBench/test_harness.c  .generated_files/flags/default/719d3592125549cd1dabcd1e36bb4df26acf820c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/test_harness.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/test_harness.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/test_harness.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/test_harness.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/test_harness.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/sat_PI.o: mcc_generated_files/motorBench/sat_PI.c  .generated_files/flags/default/31136ada8389f4c529a757451542786a1cbafc7e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/sat_PI.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/sat_PI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/sat_PI.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/sat_PI.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/sat_PI.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/stall_detect.o: mcc_generated_files/motorBench/stall_detect.c  .generated_files/flags/default/be571c7f65cb3068771b37cc23c40a10e190d907 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/stall_detect.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/stall_detect.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/stall_detect.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/stall_detect.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/stall_detect.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/startup.o: mcc_generated_files/motorBench/startup.c  .generated_files/flags/default/9e11cd24381a47cf3f2a0e521017d7a3b8a838 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/startup.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/startup.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/startup.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/startup.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/startup.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/diagnostics.o: mcc_generated_files/motorBench/diagnostics.c  .generated_files/flags/default/86f934bbf4d3ef37b4f771a25fd38c3096c73bcb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/diagnostics.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/diagnostics.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/diagnostics.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/diagnostics.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/diagnostics.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/current_measure.o: mcc_generated_files/motorBench/current_measure.c  .generated_files/flags/default/5691b217ba25d9750273d34228881fd9472a349d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/current_measure.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/current_measure.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/current_measure.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/current_measure.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/current_measure.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/test_harness_timestamps.o: mcc_generated_files/motorBench/test_harness_timestamps.c  .generated_files/flags/default/e3a40ff37c8e7ce26d308077627b3c3a8c023a1e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/test_harness_timestamps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/test_harness_timestamps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/test_harness_timestamps.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/test_harness_timestamps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/test_harness_timestamps.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/recover.o: mcc_generated_files/motorBench/recover.c  .generated_files/flags/default/7918a84d4185ccb2b7c96050f7cd8d74cc66c429 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/recover.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/recover.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/recover.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/recover.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/recover.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_traps.o: mcc_generated_files/motorBench/mcaf_traps.c  .generated_files/flags/default/6516d489ac395f7a0cf3669a7724fd37a5d54960 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/mcaf_traps.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_traps.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/isr.o: mcc_generated_files/motorBench/isr.c  .generated_files/flags/default/aee36d1270b955a9e5008abe89b5d2fdeae56a49 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/isr.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/isr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/isr.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/isr.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/isr.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/foc.o: mcc_generated_files/motorBench/foc.c  .generated_files/flags/default/3451a68cbb41f44ffa61561cb9a0c2954f5b244f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/foc.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/foc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/foc.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/foc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/foc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/system_state.o: mcc_generated_files/motorBench/system_state.c  .generated_files/flags/default/1dd73c461481dc58d6bebdbe0caf9a9441a8ae70 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/system_state.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/system_state.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/system_state.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/system_state.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/system_state.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_main.o: mcc_generated_files/motorBench/mcaf_main.c  .generated_files/flags/default/10a0034c00cbe3a5b5fabb2efc77d9482d739a42 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_main.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/mcaf_main.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/board_service.o: mcc_generated_files/motorBench/board_service.c  .generated_files/flags/default/a67ba12c34ce343825045b4bff68a754721712f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/board_service.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/board_service.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/board_service.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/board_service.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/board_service.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/adc_compensation.o: mcc_generated_files/motorBench/adc_compensation.c  .generated_files/flags/default/c204bc39847506e554cc19e12922e6c1baebb324 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/adc_compensation.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/adc_compensation.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/adc_compensation.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/adc_compensation.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/adc_compensation.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_sample_application.o: mcc_generated_files/motorBench/mcaf_sample_application.c  .generated_files/flags/default/46fbafcf92cb8d86017295c4f20b0639da09cecf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_sample_application.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_sample_application.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/mcaf_sample_application.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_sample_application.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/mcaf_sample_application.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/state_machine.o: mcc_generated_files/motorBench/state_machine.c  .generated_files/flags/default/22c744810aeb6f000aa571065be32c19dacc897d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/state_machine.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/state_machine.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/state_machine.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/state_machine.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/state_machine.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/motorBench/system_init.o: mcc_generated_files/motorBench/system_init.c  .generated_files/flags/default/fa89f7e0bfba65a6ccd56bce7d5f2bfcd99f0c0c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/system_init.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/system_init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/motorBench/system_init.c  -o ${OBJECTDIR}/mcc_generated_files/motorBench/system_init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/motorBench/system_init.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/opa/src/opa1.o: mcc_generated_files/opa/src/opa1.c  .generated_files/flags/default/b5706541e5a09cd7a64fba96a43fd93349a0f991 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/opa/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/opa/src/opa1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/opa/src/opa1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/opa/src/opa1.c  -o ${OBJECTDIR}/mcc_generated_files/opa/src/opa1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/opa/src/opa1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/opa/src/opa2.o: mcc_generated_files/opa/src/opa2.c  .generated_files/flags/default/cb93c897d67f1418279f59996b0b7ba2e560fa9c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/opa/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/opa/src/opa2.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/opa/src/opa2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/opa/src/opa2.c  -o ${OBJECTDIR}/mcc_generated_files/opa/src/opa2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/opa/src/opa2.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/opa/src/opa3.o: mcc_generated_files/opa/src/opa3.c  .generated_files/flags/default/82dfff6ef0794c6f83c0236f7016967636a16918 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/opa/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/opa/src/opa3.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/opa/src/opa3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/opa/src/opa3.c  -o ${OBJECTDIR}/mcc_generated_files/opa/src/opa3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/opa/src/opa3.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o: mcc_generated_files/pwm_hs/src/pwm.c  .generated_files/flags/default/7df8b9d78dfea6bcc835d70620faf276c9edd15f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/pwm_hs/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pwm_hs/src/pwm.c  -o ${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/pwm_hs/src/pwm.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/qei/src/qei1.o: mcc_generated_files/qei/src/qei1.c  .generated_files/flags/default/2331639779c03831332beed7069a60817df27f5e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/qei/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/qei/src/qei1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/qei/src/qei1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/qei/src/qei1.c  -o ${OBJECTDIR}/mcc_generated_files/qei/src/qei1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/qei/src/qei1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/pins.o: mcc_generated_files/system/src/pins.c  .generated_files/flags/default/7b19407040d4365ecb35aa9b7787845b6663dc13 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/pins.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/pins.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/pins.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/pins.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/pins.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/system.o: mcc_generated_files/system/src/system.c  .generated_files/flags/default/cc663f07e2fbf418da9296260ab31fa1bc923376 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/system.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/system.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/system.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o: mcc_generated_files/system/src/interrupt.c  .generated_files/flags/default/46f1f5a3dc3f8ac86749a5edb0dd13305fd6f476 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/interrupt.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/interrupt.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/traps.o: mcc_generated_files/system/src/traps.c  .generated_files/flags/default/ad6f6ee6a52050f2ee8c95aedf29742aab408491 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/traps.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/traps.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/traps.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/clock.o: mcc_generated_files/system/src/clock.c  .generated_files/flags/default/ec44bf3ca9e0ec4c2c6b0e66a401d414234ea217 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/clock.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/clock.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/clock.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/dmt.o: mcc_generated_files/system/src/dmt.c  .generated_files/flags/default/9cfabff25d8421ba4d2fd8987c201892a0fbba2d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/dmt.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/dmt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/dmt.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/dmt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/dmt.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o: mcc_generated_files/system/src/config_bits.c  .generated_files/flags/default/abc5508c781ce99b0033839dc093a678f2b54302 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/config_bits.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/config_bits.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/reset.o: mcc_generated_files/system/src/reset.c  .generated_files/flags/default/341db60a2047021c10ad6e8ccead0ffb6b555817 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/reset.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/system/src/reset.c  -o ${OBJECTDIR}/mcc_generated_files/system/src/reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/system/src/reset.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/timer/src/sccp1.o: mcc_generated_files/timer/src/sccp1.c  .generated_files/flags/default/b366bae06023cb8c0cab622cfedba8cd2ccc559c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/timer/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/sccp1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/sccp1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/timer/src/sccp1.c  -o ${OBJECTDIR}/mcc_generated_files/timer/src/sccp1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/timer/src/sccp1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o: mcc_generated_files/timer/src/tmr1.c  .generated_files/flags/default/6283b9bac4d466f418b10274cda111ef966b383b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/timer/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/timer/src/tmr1.c  -o ${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/timer/src/tmr1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o: mcc_generated_files/uart/src/uart1.c  .generated_files/flags/default/166b2a78cc0787130375ddf077440cae8e31b8e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/uart/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/uart/src/uart1.c  -o ${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/uart/src/uart1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/X2Cscope/X2Cscope.o: mcc_generated_files/X2Cscope/X2Cscope.c  .generated_files/flags/default/435f1f6a9d9e64b212247d96a3556d8a2084b171 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/X2Cscope" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/X2Cscope/X2Cscope.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/X2Cscope/X2Cscope.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/X2Cscope/X2Cscope.c  -o ${OBJECTDIR}/mcc_generated_files/X2Cscope/X2Cscope.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/X2Cscope/X2Cscope.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/X2Cscope/X2CscopeComm.o: mcc_generated_files/X2Cscope/X2CscopeComm.c  .generated_files/flags/default/e90b10118c1c0afac2c0ab2f736d29adca7d5afa .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/X2Cscope" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/X2Cscope/X2CscopeComm.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/X2Cscope/X2CscopeComm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/X2Cscope/X2CscopeComm.c  -o ${OBJECTDIR}/mcc_generated_files/X2Cscope/X2CscopeComm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/mcc_generated_files/X2Cscope/X2CscopeComm.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/efe1da9ce6571803f0b3cb0a849bf084c4ed0bb6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -mlarge-data -msmall-scalar -O1 -fomit-frame-pointer -msmart-io=1 -Wall -msfr-warn=off -finline   -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/mcc_generated_files/motorBench/math_asm.o: mcc_generated_files/motorBench/math_asm.s  .generated_files/flags/default/4f29d1d96482f2a2a7dd165ad06e03275f871b5a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/math_asm.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/math_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  mcc_generated_files/motorBench/math_asm.s  -o ${OBJECTDIR}/mcc_generated_files/motorBench/math_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -Wa,-MD,"${OBJECTDIR}/mcc_generated_files/motorBench/math_asm.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o: mcc_generated_files/system/src/dmt_asm.s  .generated_files/flags/default/e07719b0ce25549e83b6f6624823357d45e76af3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  mcc_generated_files/system/src/dmt_asm.s  -o ${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -Wa,-MD,"${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/mcc_generated_files/motorBench/math_asm.o: mcc_generated_files/motorBench/math_asm.s  .generated_files/flags/default/86c8de2520423bc356ed9626638e141b63cf32d7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/motorBench" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/math_asm.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/motorBench/math_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  mcc_generated_files/motorBench/math_asm.s  -o ${OBJECTDIR}/mcc_generated_files/motorBench/math_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)    -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -Wa,-MD,"${OBJECTDIR}/mcc_generated_files/motorBench/math_asm.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o: mcc_generated_files/system/src/dmt_asm.s  .generated_files/flags/default/234cc951aeef83bea84f6b88bf8eb10593ce0d41 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files/system/src" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  mcc_generated_files/system/src/dmt_asm.s  -o ${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)    -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -Wa,-MD,"${OBJECTDIR}/mcc_generated_files/system/src/dmt_asm.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)  -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/mc_mb_sl_fip_dsPIC33CK_mclv48v300w.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  mcc_generated_files/motorBench/library/mc-library/libmotor_control_dspic-elf.a mcc_generated_files/X2Cscope/libx2cscope-33ck-elf.a mcc_generated_files/motorBench/library/x2cscope/libx2cscope-dspic-elf.a  
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/mc_mb_sl_fip_dsPIC33CK_mclv48v300w.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    mcc_generated_files\motorBench\library\mc-library\libmotor_control_dspic-elf.a mcc_generated_files\X2Cscope\libx2cscope-33ck-elf.a mcc_generated_files\motorBench\library\x2cscope\libx2cscope-dspic-elf.a  -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope"  -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/mc_mb_sl_fip_dsPIC33CK_mclv48v300w.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  mcc_generated_files/motorBench/library/mc-library/libmotor_control_dspic-elf.a mcc_generated_files/X2Cscope/libx2cscope-33ck-elf.a mcc_generated_files/motorBench/library/x2cscope/libx2cscope-dspic-elf.a 
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/mc_mb_sl_fip_dsPIC33CK_mclv48v300w.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    mcc_generated_files\motorBench\library\mc-library\libmotor_control_dspic-elf.a mcc_generated_files\X2Cscope\libx2cscope-33ck-elf.a mcc_generated_files\motorBench\library\x2cscope\libx2cscope-dspic-elf.a  -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -I"mcc_generated_files" -I"mcc_generated_files/motorBench" -I"mcc_generated_files/motorBench/library/mc-library" -I"mcc_generated_files/motorBench/library/x2cscope" -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/mc_mb_sl_fip_dsPIC33CK_mclv48v300w.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
