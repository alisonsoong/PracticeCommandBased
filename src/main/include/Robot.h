// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>

#include <frc/WPILib.h>

#include "RobotContainer.h"

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.

  frc2::Command* curAutoCommand_ = nullptr;

  // subsystems
  Drivetrain* drivetrain_;

  // commands
  Drive* drive_;

  // motors
  WPI_TalonFX *leftPrimary_, *rightPrimary_, *leftSecondary_, *rightSecondary_;

  // control board
  ControlBoard* humanControl_;
  frc::Joystick *leftJoy_, *rightJoy_;


  RobotContainer container_;
};
