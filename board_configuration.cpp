#include "pch.h"
#include "hellen_meta.h"
#include "defaults.h"
#include "board_overrides.h"
//#include "hellen_leds_144.cpp"


static void setInjectorPins() {
	engineConfiguration->injectionPins[0] = Gpio::G7;
	engineConfiguration->injectionPins[1] = Gpio::G8;
	engineConfiguration->injectionPins[2] = Gpio::D11;
	engineConfiguration->injectionPins[3] = Gpio::D10;
	engineConfiguration->injectionPins[4] = Gpio::D9;
	engineConfiguration->injectionPins[5] = Gpio::F12;
}


static void setIgnitionPins() {
	engineConfiguration->ignitionPins[0] = Gpio::B9;
	engineConfiguration->ignitionPins[1] = Gpio::Unassigned;
	engineConfiguration->ignitionPins[2] = Gpio::Unassigned;
	engineConfiguration->ignitionPins[3] = Gpio::Unassigned;
	engineConfiguration->ignitionPins[4] = Gpio::Unassigned;
	engineConfiguration->ignitionPins[5] = Gpio::Unassigned;
}


static void setupDefaultSensorInputs() {
	engineConfiguration->tps1_1AdcChannel = EFI_ADC_4;
 	engineConfiguration->clt.adcChannel = EFI_ADC_12;
	engineConfiguration->iat.adcChannel = EFI_ADC_13;
	engineConfiguration->mafAdcChannel = EFI_ADC_14;
	engineConfiguration->vehicleSpeedSensorInputPin = Gpio::F11;
	engineConfiguration->triggerInputPins[0] = Gpio::B1;
	engineConfiguration->camInputs[0] = Gpio::A6;
	engineConfiguration->clutchDownPin = Gpio::F5;
	engineConfiguration->clutchDownPinMode = PI_PULLDOWN;
	engineConfiguration->vbattAdcChannel = EFI_ADC_0;
 	
  	//engineConfiguration->map.sensor.hwChannel = Gpio::Unassigned;
	//setPPSInputs(Gpio::Unassigned, Gpio::Unassigned);
	
	// 5.6k high side/1k low side = 1.56 ratio divider
	//engineConfiguration->analogInputDividerCoefficient = 1.56f;
	
	// 6.34k high side/ 1k low side
	//engineConfiguration->vbattDividerCoeff = (6.34 + 1) / 1;
	
	//engineConfiguration->adcVcc = 3.3f;
		
}

void customBoardDefaultConfiguration() {
	setInjectorPins();
	setIgnitionPins();
	setupDefaultSensorInputs();
	setHellenMMbaro();
	setCrankOperationMode();
	setCommonNTCSensor(&engineConfiguration->clt, HELLEN_DEFAULT_AT_PULLUP);
	setCommonNTCSensor(&engineConfiguration->iat, HELLEN_DEFAULT_AT_PULLUP);
    setTPS1Calibration(75, 900);
	hellenWbo();
	setHellenVbatt();
	//hellenMegaSdWithAccelerometer();
	setHellenSdCardSpi1Hardware();
	//setAccelerometerSpi();  //maybe this will work?
  	setHellenCan();
	setDefaultHellenAtPullUps();

	engineConfiguration->displayLogicLevelsInEngineSniffer = true;
	engineConfiguration->globalTriggerAngleOffset = 9;
	engineConfiguration->enableSoftwareKnock = true;
	engineConfiguration->cylindersCount = 6;
	engineConfiguration->firingOrder = FO_1_4_2_5_3_6;
	engineConfiguration->ignitionMode = IM_ONE_COIL;
	engineConfiguration->fuelAlgorithm = engine_load_mode_e::LM_REAL_MAF;
	engineConfiguration->canTxPin = Gpio::D1;
	engineConfiguration->canRxPin = Gpio::D0;
	engineConfiguration->mainRelayPin = Gpio::E10;
 	engineConfiguration->fanPin = Gpio::G6;
	engineConfiguration->fuelPumpPin = Gpio::G4;
	engineConfiguration->idle.solenoidPin = Gpio::G3;
	engineConfiguration->tachOutputPin = Gpio::F13;
	engineConfiguration->enableVerboseCanTx = true;
	engineConfiguration->injectorCompensationMode = ICM_FixedRailPressure;
}

void setup_custom_board_overrides() {
	custom_board_DefaultConfiguration = customBoardDefaultConfiguration;
}
