/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ControlBoard.h"

ControlBoard::ControlBoard(frc::Joystick *leftJoy, frc::Joystick *rightJoy) {
	// reset joystick coordinates
    leftJoyX_ = 0.0;
    leftJoyY_ = 0.0;
    rightJoyX_ = 0.0;
    rightJoyY_ = 0.0;

	// assign joysticks to ports
    leftJoy_ = leftJoy;
    rightJoy_ = rightJoy; 

    ReadControls();
	printf("end of control board constructor\ns");
}

// update joystick coordinates
double ControlBoard::GetJoystickValue(Joysticks j, Axes a) {
	switch (j) {
	  case (kLeftJoy):
		switch(a) {
			case(kX):
				return leftJoyX_;
			case(kY):
				return leftJoyY_;
            default:
                printf("WARNING: left joystick value not received");
		}
	  	break;
	  case (kRightJoy):
		switch(a){
	  	    case(kX):
			    return rightJoyX_;
	  	    case(kY):
			    return rightJoyY_;
            default:
                printf("WARNING: right joystick value not received");
		}
		break;
	  default:
      printf("WARNING: Joystick value not received in ControlBoard::GetJoystickValue\n");
	}
	return 0;
}

// update control variables
void ControlBoard::ReadControls(){
    leftJoyX_ = leftJoy_->GetX();
	leftJoyY_ = -leftJoy_->GetY();
    rightJoyX_ = rightJoy_->GetX();
	rightJoyY_ = -rightJoy_->GetY();
}

ControlBoard::~ControlBoard(){
	delete leftJoy_;
	delete rightJoy_;
}