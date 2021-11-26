// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"
#include "PORTS.h"

Drivetrain::Drivetrain(WPI_TalonFX *leftPrimary, WPI_TalonFX *rightPrimary, WPI_TalonFX *leftSecondary, WPI_TalonFX *rightSecondary) {
  // Implementation of subsystem constructor goes here.
  leftPrimary_  = leftPrimary;
	rightPrimary_  = rightPrimary;
	leftSecondary_ = leftSecondary;
	rightSecondary_ = rightSecondary;
  leftPrimary_->Set(ControlMode::PercentOutput, 0.0);
  rightPrimary_->Set(ControlMode::PercentOutput, 0.0);
  leftSecondary_->Follow(*leftPrimary_);
  rightSecondary_->Follow(*rightPrimary_);

  thrustSensitivity_ = 0.5;
  rotateSensitivity_ = 0.7;
}

void Drivetrain::TankDrive(double left, double right){
    // adjusting sensitivity
    left = GetDeadbandAdjustment(left);
    left = GetCubicAdjustment(left, thrustSensitivity_);
    right = GetDeadbandAdjustment(right);
    right = GetCubicAdjustment(right, rotateSensitivity_);

    MaxSpeedAdjustment(left, right);

    SetDriveValues(left, right);
}

void Drivetrain::MaxSpeedAdjustment(double &leftvalue, double &rightvalue){
    if(leftvalue>1.0){
        rightvalue /= leftvalue;
        leftvalue = 1.0;
    } else if(leftvalue<-1.0){
        rightvalue /= -leftvalue;
        leftvalue = -1.0;
    }
    if(rightvalue>1.0){
        leftvalue /= rightvalue;
        rightvalue = 1.0;
    } else if(rightvalue<-1.0){
        leftvalue /= -rightvalue;
        rightvalue = -1.0;
    }
}

// adjusts joystick sensitivity using a cubic for smoother driving
double Drivetrain::GetCubicAdjustment(double value, double adjustmentConstant){
    return adjustmentConstant * std::pow(value, 3.0) + (1.0 - adjustmentConstant) * value;
}

// returns how much the thrust value should be adjusted, if it's lower than the deadband, the robot should not move
double Drivetrain::GetDeadbandAdjustment(double value){
    if(fabs(value)<DEADBAND_MAX){
        return 0.0;
    }
    else if (value > DEADBAND_MAX){ // robot power is 0.0-1.0
        return (1/(1-DEADBAND_MAX))*(value - DEADBAND_MAX); // fits any deadband value
    }
    else{
        return (1/(1-DEADBAND_MAX))*(value + DEADBAND_MAX);
    }
}

void Drivetrain::SetDriveValues(double left, double right){
    leftPrimary_->Set(-left);
    rightPrimary_->Set(right);
}

