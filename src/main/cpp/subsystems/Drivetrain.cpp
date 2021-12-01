// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"
#include "PORTS.h"

Drivetrain::Drivetrain(WPI_TalonFX *leftPrimary, WPI_TalonFX *rightPrimary, WPI_TalonFX *leftSecondary, WPI_TalonFX *rightSecondary) {
  // Implementation of subsystem constructor goes here.

  // Motors
  leftPrimary_ = leftPrimary;
  rightPrimary_ = rightPrimary;
  leftSecondary_ = leftSecondary;
  rightSecondary_ = rightSecondary;

  // Sets motors to accept outputs in percent
  leftPrimary_->Set(ControlMode::PercentOutput, 0.0);
  rightPrimary_->Set(ControlMode::PercentOutput, 0.0);

  // left secondary and right secondary motors follow primary motors
  leftSecondary_->Follow(*leftPrimary_); // remember that the motors are pointers, so need to dereference them
  rightSecondary_->Follow(*rightPrimary_);

  rightJoystickXLastValue_ = 0.0;
  rightJoystickXCurrValue_ = 0.0;

  thrustSensitivity_ = 0;
  rotateSensitivity_ = 0;
}

void Drivetrain::TankDrive(double left, double right){
  // adjusting sensitivity
  left = GetDeadbandAdjustment(left);
  // left = GetCubicAdjustment(left, thrustSensitivity_);
  right = GetDeadbandAdjustment(right);
  // right = GetCubicAdjustment(right, rotateSensitivity_);

  MaxSpeedAdjustment(left, right);

  SetDriveValues(left, right);
}

void Drivetrain::ArcadeDrive(double thrust, double rotate){
    // adjusting sensitivity for turn
    thrust = GetDeadbandAdjustment(thrust);
    // thrust = GetCubicAdjustment(thrust, thrustSensitivity_);
    rotate = GetDeadbandAdjustment(rotate);
    // rotate = GetCubicAdjustment(rotate, rotateSensitivity_);
    
    double rotationValueAdjustment = GetRotateVelocityAdjustment(rotate);

    double leftOutput, rightOutput;

		leftOutput = thrust + rotate;		
		rightOutput = thrust - rotate*(1+rotationValueAdjustment);
    
    MaxSpeedAdjustment(leftOutput, rightOutput);
    
    SetDriveValues(leftOutput, rightOutput);
}

void Drivetrain::MaxSpeedAdjustment(double &leftvalue, double &rightvalue){
  if (leftvalue > 1.0){
    rightvalue /= leftvalue;
    leftvalue = 1.0;
  } else if (leftvalue < -1.0){
    rightvalue /= -leftvalue;
    leftvalue = -1.0;
  } if (rightvalue > 1.0){
    leftvalue /= rightvalue;
    rightvalue = 1.0;
  } else if (rightvalue < -1.0){
    leftvalue /= -rightvalue;
    rightvalue = -1.0;
  }
}

// adjusts joystick sensitivity using a cubic for smoother driving
double Drivetrain::GetCubicAdjustment(double value, double adjustmentConstant){
  return adjustmentConstant * std::pow(value, 3.0) + (1.0 - adjustmentConstant) * value;
}

// returns how much the thrust value should be adjusted
double Drivetrain::GetDeadbandAdjustment(double value){
  // if it's lower than the deadband, the robot should not move
  if (fabs(value) < DEADBAND_MAX){
    return 0.0;
  } else if (value > DEADBAND_MAX){ // robot power is 0.0-1.0
    return (1/(1-DEADBAND_MAX))*(value - DEADBAND_MAX); // fits any deadband value
  } else{
    return (1/(1-DEADBAND_MAX))*(value + DEADBAND_MAX);
  }
}

// adjusts rotation for turns in arcade drive
double Drivetrain::GetRotateVelocityAdjustment(double value){
    rightJoystickXLastValue_ = rightJoystickXCurrValue_;
    rightJoystickXCurrValue_ = value;
    double time = 60.0/50; // time between last iteration and current
    return abs(rightJoystickXCurrValue_-rightJoystickXLastValue_)/time;
}


// sets drive outputs
void Drivetrain::SetDriveValues(double left, double right){
    leftPrimary_->Set(-left);
    rightPrimary_->Set(right);
}

