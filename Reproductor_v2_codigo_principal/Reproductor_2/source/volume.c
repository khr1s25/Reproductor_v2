#include "volume.h"
#include "fsl_tpm.h"
#include "pin_mux.h"
#include "fsl_port.h"

#define VOLUME_LED 0u
#define VOLUME_READ 13u
#define PORCENTAJE_CICLOS 10u

void volume_init(){
	PORT_SetPinMux(PORTA, VOLUME_READ, kPORT_MuxAlt3);
	CLOCK_EnableClock(kCLOCK_PortA);

	CLOCK_SetTpmClock(1u);

	tpm_config_t tpmConf;

	TPM_GetDefaultConfig(&tpmConf);
	TPM_Init(TPM1, &tpmConf);

	tpm_chnl_pwm_signal_param_t tpmParam;
	tpm_pwm_level_select_t pwmLevel = kTPM_LowTrue;

	tpmParam.chnlNumber = (tpm_chnl_t)1u;
	tpmParam.level = pwmLevel;
	tpmParam.dutyCyclePercent = PORCENTAJE_CICLOS;

	TPM_SetupPwm(TPM1, &tpmParam, 1u, kTPM_CenterAlignedPwm, 20000u, CLOCK_GetFreq(kCLOCK_PllFllSelClk));

	TPM_StartTimer(TPM1, kTPM_SystemClock);
}

