// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Drive.h"
#include "PORTS.h"
#include "ControlBoard.h"

Drive::Drive(Drivetrain* drivetrain, ControlBoard* humanControl) {
    drivetrain_ = drivetrain;
    humanControl_ = humanControl;
    
    
}

void Drive::Initialize() {

}

void Drive::Execute() {
    double leftJoyX = humanControl_->GetJoystickValue(ControlBoard::Joysticks::kLeftJoy, ControlBoard::Axes::kX);
    double rightJoyX = humanControl_->GetJoystickValue(ControlBoard::Joysticks::kRightJoy, ControlBoard::Axes::kX);
    double leftJoyY = humanControl_->GetJoystickValue(ControlBoard::Joysticks::kLeftJoy, ControlBoard::Axes::kY);
    double rightJoyY = humanControl_->GetJoystickValue(ControlBoard::Joysticks::kRightJoy, ControlBoard::Axes::kY);
    
	drivetrain_->TankDrive(leftJoyY, rightJoyY);
}

bool Drive::IsFinished() {
	return false;
}

// void Drive::End() {

// }

// void Drive::Interrupted() {
	
// }

