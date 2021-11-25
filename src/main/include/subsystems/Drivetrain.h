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

class Drivetrain : public frc2::SubsystemBase {
 public: 
  Drivetrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void Reset();
  void TankDrive(double left, double right);
  double GetCubicAdjustment(double value, double adjustmentConstant);
  double GetDeadbandAdjustment(double value);
  void MaxSpeedAdjustment(double &leftvalue, double &rightvalue);
  void SetDriveValues(double left, double right);

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  WPI_TalonFX *leftPrimary_, *rightPrimary_, *leftSecondary_, *rightSecondary_;
  double thrustSensitivity_;
  double rotateSensitivity_;
  double leftDrivePower_, rightDrivePower_;

};
