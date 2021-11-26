// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/WPILib.h>
#include <ControlBoard.h>
#include <AHRS.h>
#include "ctre/Phoenix.h"
#include <rev/CANSparkMax.h>
#include <frc/DriverStation.h>
#include <networktables/NetworkTableEntry.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <networktables/NetworkTableEntry.h>
#include <math.h>
#define PI 3.141592

static const double DEADBAND_MAX = 0.1;

class Drivetrain : public frc2::SubsystemBase { // subclassing the abstract class, SubsystemBase
 public: 
  
  /**
   * Constructor
   * @param leftPrimary a pointer to a WPI_TalonFX
   * @param rightPrimary a pointer to a WPI_TalonFX
   * @param leftSecondary a pointer to a WPI_TalonFX
   * @param rightSecondary a pointer to a WPI_TalonFX
   */
  Drivetrain(WPI_TalonFX *leftPrimary, WPI_TalonFX *rightPrimary, WPI_TalonFX *leftSecondary, WPI_TalonFX *rightSecondary);

  /**
   * Moves by tank drive
   */
  void TankDrive(double left, double right);

  /**
   * Cubic adjustment for smoother driving
   */
  double GetCubicAdjustment(double value, double adjustmentConstant);
  /**
   * Deadband adjustment
   */
  double GetDeadbandAdjustment(double value);

  /**
   * Adjusts power output values for motors
   */
  void MaxSpeedAdjustment(double &leftvalue, double &rightvalue);

  /**
   * Deadband adjustment
   */
  void SetDriveValues(double left, double right);



 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  WPI_TalonFX *leftPrimary_, *rightPrimary_, *leftSecondary_, *rightSecondary_;
  double thrustSensitivity_;
  double rotateSensitivity_;

};
