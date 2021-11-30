// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/WPILib.h>
#include <frc2/command/CommandScheduler.h>

void Robot::RobotInit() {

  // drivetrain motors
  leftPrimary_  = new WPI_TalonFX(LEFT_DRIVE_MOTOR_ID);
  rightPrimary_  = new WPI_TalonFX(RIGHT_DRIVE_MOTOR_ID);
  leftSecondary_ = new WPI_TalonFX(LEFT_DRIVE_MOTOR_2_ID);
  rightSecondary_ = new WPI_TalonFX(RIGHT_DRIVE_MOTOR_2_ID);

  // joysticks
  leftJoy_ = new frc::Joystick(LEFT_JOY_USB_PORT);
  rightJoy_ = new frc::Joystick(RIGHT_JOY_USB_PORT);

  // human control (control board)
  humanControl_ = new ControlBoard(leftJoy_, rightJoy_);

  // subsystems
  drivetrain_ = new Drivetrain(leftPrimary_, rightPrimary_, leftSecondary_, rightSecondary_);

  // commands
  drive_ = new Drive(drivetrain_, humanControl_);
  
  
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  // frc2::CommandScheduler::getInstanxce().run();
  
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  curAutoCommand_ = container_.GetAutonomousCommand();

  if (curAutoCommand_ != nullptr) {
    curAutoCommand_->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (curAutoCommand_ != nullptr) {
    curAutoCommand_->Cancel();
    curAutoCommand_ = nullptr;
  }

}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {
  humanControl_->ReadControls();

  // get joystick controls, drive (directly using subsystem for now...)
  double leftJoyX = humanControl_->GetJoystickValue(ControlBoard::Joysticks::kLeftJoy, ControlBoard::Axes::kX);
  double rightJoyX = humanControl_->GetJoystickValue(ControlBoard::Joysticks::kRightJoy, ControlBoard::Axes::kX);
  double leftJoyY = humanControl_->GetJoystickValue(ControlBoard::Joysticks::kLeftJoy, ControlBoard::Axes::kY);
  double rightJoyY = humanControl_->GetJoystickValue(ControlBoard::Joysticks::kRightJoy, ControlBoard::Axes::kY);

  drivetrain_->TankDrive(leftJoyY, rightJoyY);
  // drivetrain_->ArcadeDrive(leftJoyY, rightJoyX);

}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
