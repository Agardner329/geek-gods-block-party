#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Hubs,  S3, HTServo,  none,     none,     none)
#pragma config(Hubs,  S4, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     INF,            sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     red,           tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     yellow,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     green,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     blue,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_1,     arm,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_2,     whisk,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C2_1,     lift,           tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C2_2,     flag,         tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S3_C1_1,    autoflipper,          tServoStandard)
#pragma config(Servo,  srvo_S3_C1_2,    wrist,                tServoStandard)
#pragma config(Servo,  srvo_S3_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_6,    servo6,               tServoNone)
//Lift Adjuster.c
task main(){
	nxtDisplayCenteredTextLine(1, "Lift Adjuster");
	while(true){
		if (nNxtButtonPressed == 2){
			motor[lift] = -60;
			nxtDisplayCenteredBigTextLine(4, "Lowering");
			}else if(nNxtButtonPressed == 1){
			motor[lift] = 60;
			nxtDisplayCenteredBigTextLine(4, "Raising");
			}else{
			motor[lift] = 0;
			nxtDisplayCenteredBigTextLine(4, "Still");
		}
		wait10Msec(1);
	}
}