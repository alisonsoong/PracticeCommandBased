// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Drive.h"
#include "PORTS.h"

Drive::Drive(Drivetrain* drivetrain)
    : drivetrain_{drivetrain} {
    leftPrimary_  = new WPI_TalonFX(LEFT_DRIVE_MOTOR_ID);
	rightPrimary_  = new WPI_TalonFX(LEFT_DRIVE_MOTOR_2_ID);
	leftSecondary_ = new WPI_TalonFX(RIGHT_DRIVE_MOTOR_ID);
	rightSecondary_ = new WPI_TalonFX(RIGHT_DRIVE_MOTOR_2_ID);
    leftPrimary_->Set(ControlMode::PercentOutput, 0.0);
    rightPrimary_->Set(ControlMode::PercentOutput, 0.0);
    leftSecondary_->Follow(*leftPrimary_);
    rightSecondary_->Follow(*rightPrimary_);
    
}

// void Drive::Initialize() {

// }

// void Drive::Execute() {
	
// }

// bool Drive::IsFinished() {
// 	return false;
// }

// void Drive::End() {

// }

// void Drive::Interrupted() {
	
// }

