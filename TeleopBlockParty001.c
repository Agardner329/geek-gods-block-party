#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Hubs,  S3, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     INF,            sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     RGB,            sensorCOLORGREEN)
#pragma config(Motor,  mtr_S1_C1_1,     yellow,        tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     red,           tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     blue,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     green,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     arm,           tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C3_2,     whisk,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     lift,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     flag,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S3_C1_1,    autoflipper,          tServoStandard)
#pragma config(Servo,  srvo_S3_C1_2,    wrist,                tServoStandard)
#pragma config(Servo,  srvo_S3_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// teleopblockparty001.c

#include "JoystickDriver.c";
#include "statuslight.c";
string direction = "yellow";
void initializeRobot(){
	nNoMessageCounterLimit = 100;
	servo[autoflipper] = 20;
	motor[arm] = 0;
	return;
}
float DZ(float input){
	if(input > -10 && input < 10){
		return 0;
		}else{
		return input;
	}
}

int whiskeeeee = 0;
task autoflip(){
	int switcha = 0;
	int switchb = 1;
	wait10Msec(500);
	servo[autoflipper] = 0;
	wait10Msec(100);
	servo[autoflipper] = 240;
	while(true){
		if((joy2Btn(1)) && (switcha == 0)){
			switcha = 1;
		}
		if((joy2Btn(1) != true) && (switcha == 1)){
			switcha = 0;
			switchb *= -1;
		}
		if(switchb == 1){
			servo[autoflipper] = 240;
		}
		if(switchb == -1){
			servo[autoflipper] = 0;
		}
	}
}


task directionCont(){
	while(true){
		getJoystickSettings(joystick);
		if(joy1Btn(1)){
			direction = "blue";
			}else if(joy1Btn(2)){
			direction = "yellow";
			}else if(joy1Btn(3)){
			direction = "red";
			}else if(joy1Btn(4)){
			direction = "green";
		}
		abortTimeslice();
	}
}
task drive(){
	int turn;
	while(true){
		if(joystick.joy1_TopHat == 2){
			turn = 100;
			}else if(joystick.joy1_TopHat == 6){
			turn = -100;
			}else{
			turn = 0;
		}

		getJoystickSettings(joystick);
		if(direction == "red"){
			motor[red] = (((DZ(joystick.joy1_y1)+DZ(joystick.joy1_x1))/128.0)*100) - turn;
			motor[green] = (((DZ(joystick.joy1_y1)-DZ(joystick.joy1_x1))/128.0)*100) - turn;
			motor[blue] = -(((DZ(joystick.joy1_y1)+DZ(joystick.joy1_x1))/128.0)*100) - turn;
			motor[yellow] = (((DZ(joystick.joy1_x1)-DZ(joystick.joy1_y1))/128.0)*100) - turn;

			}else if(direction == "green"){
			//default direction
			motor[green] = (((DZ(joystick.joy1_y1)+DZ(joystick.joy1_x1))/128.0)*100) - turn;
			motor[blue] = (((DZ(joystick.joy1_y1)-DZ(joystick.joy1_x1))/128.0)*100) - turn;
			motor[yellow] = -(((DZ(joystick.joy1_y1)+DZ(joystick.joy1_x1))/128.0)*100) - turn;
			motor[red] = (((DZ(joystick.joy1_x1)-DZ(joystick.joy1_y1))/128.0)*100) - turn;

			}else if(direction == "blue"){
			motor[blue] = (((DZ(joystick.joy1_y1)+DZ(joystick.joy1_x1))/128.0)*100) - turn;
			motor[yellow] = (((DZ(joystick.joy1_y1)-DZ(joystick.joy1_x1))/128.0)*100) - turn;
			motor[red] = -(((DZ(joystick.joy1_y1)+DZ(joystick.joy1_x1))/128.0)*100) - turn;
			motor[green] = (((DZ(joystick.joy1_x1)-DZ(joystick.joy1_y1))/128.0)*100) - turn;

			}else if(direction == "yellow"){
			motor[yellow] = (((DZ(joystick.joy1_y1)+DZ(joystick.joy1_x1))/128.0)*100) - turn;
			motor[red] = (((DZ(joystick.joy1_y1)-DZ(joystick.joy1_x1))/128.0)*100) - turn;
			motor[green] = -(((DZ(joystick.joy1_y1)+DZ(joystick.joy1_x1))/128.0)*100) - turn;
			motor[blue] = (((DZ(joystick.joy1_x1)-DZ(joystick.joy1_y1))/128.0)*100) - turn;
		}
	}
}
task lifter(){
	while(true){
		if(joy1Btn(8)){
			motor[lift] = -100;
			}else if(joy1Btn(6)){
			motor[lift] = 100;
			}else if(joy2Btn(8)){
			motor[lift] = -100;
			}else if(joy2Btn(6)){
			motor[lift] = 100;
			}else{
			motor[lift] = 0;
		}
		abortTimeslice();
	}
}
task flagger(){
	while(true){
		if(joy1Btn(5)){
			motor[flag] = 100;
			}else if(joy2Btn(5)){
			motor[flag] = 100;
			}else{
			motor[flag] = 0;
		}
		abortTimeslice();
	}
}
task armer(){
	while(true){
		if(joystick.joy1_TopHat == 4){
			motor[arm] = -60;
			}else if(joystick.joy1_TopHat == 0){
			motor[arm] = 60;
			}else if(joystick.joy2_TopHat == 0){
			motor[arm] = 60;
			}else if(joystick.joy2_TopHat == 4){
			motor[arm] = -60;
			}else{
			motor[arm] = 0;
		}

		if(DZ(joystick.joy1_y2) > 15){
			servo[wrist] -= ((DZ(joystick.joy1_y2))/100);
			}else if(DZ(joystick.joy1_y2) < -15){
			servo[wrist] -= ((DZ(joystick.joy1_y2))/100);
			}else if(DZ(joystick.joy2_y2) > 15){
			servo[wrist] -= ((DZ(joystick.joy2_y2))/100);
			}else if(DZ(joystick.joy2_y2) < -15){
			servo[wrist] -= ((DZ(joystick.joy2_y2))/100);
			}else if(joy2Btn(9)){
			whiskeeeee = 1;
			//even though it says 8
			servo[wrist] = 0;
			wait10Msec(50);
			while(nMotorEncoder[arm] > 10 && joystick.joy2_TopHat == -1){
				motor[arm] = -30;
				motor[whisk] = 20;
			}
			motor[arm] = 0;
			servo[wrist] = 123;
			wait10Msec(100);
			motor[whisk] = 0;
			whiskeeeee = 0;
			}else if(joy2Btn(10)){
			whiskeeeee = 1;
			//enev though it says 9
			servo[wrist] = 0;
			wait10Msec(70);
			while(nMotorEncoder[arm] < 4753 && joystick.joy2_TopHat == -1){
				motor[arm] = 30;
				motor[whisk] = 20;
				if(nMotorEncoder[arm] > 1000){
					servo[wrist] += 1;
					wait1Msec(5);
				}
			}
			motor[arm] = 0;
			servo[wrist] = 177;
			motor[whisk] = 0;
			whiskeeeee = 0;


		}
		abortTimeslice();
	}
}
task whisker(){
	while(true){
		if(whiskeeeee == 0){
			if(joy1Btn(7)){
				motor[whisk] = 100;
				}else if(joy2Btn(7)){
				motor[whisk] = 100;
				}else{
				motor[whisk] = 0;
			}
		}
		abortTimeslice();
	}
}

task lightcolor(){
	color1 = "green";
	color2 = "none";
	while(true){
		if (bDisconnected == true){
			color2 = "red";
			}else{
			color2 = "none";
		}
	}
}

task main(){

	SensorType[RGB] = sensorCOLORGREEN;
	initializeRobot();
	nMotorEncoder[arm] = 0;
	servo[wrist] = 0;
	// make freaking sure the arm is down
	waitForStart();
	StartTask(directionCont);

	StartTask(drive);

	StartTask(lifter);

	StartTask(armer);

	StartTask(flagger);

	StartTask(whisker);

	StartTask(autoflip);

	StartTask(blinker);

	StartTask(lightcolor);
	while(true){
		nxtDisplayTextLine(1,"%f",servo[wrist]);
		nxtDisplayTextLine(2,"%f",nMotorEncoder[arm]);
	}
}
//verticle servo: 177 encoder: 4753
//123 is for scooping [servo] 0 encoder