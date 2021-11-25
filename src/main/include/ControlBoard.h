/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "PORTS.h"
#include <frc/WPILib.h>
#include <unordered_map>

class ControlBoard {
 public:
  enum Joysticks{kLeftJoy, kRightJoy};
	enum Axes{kX, kY, kZ, kLT};
  enum Buttons{kAlignButton, kGearShiftButton, 
              kIntakeSeriesButton, kIndexSeriesButton, 
              kShootClosePrepButton, kShootFarPrepButton, kShootingButton, 
              kClimbRightElevatorUpButton, kClimbRightElevatorDownButton, 
              kClimbLeftElevatorUpButton, kClimbLeftElevatorDownButton, 
              kUndoElevatorButton,
              kWristUpButton, kWristDownButton, kRunRollersButton, kReverseRollersButton,
              kControlPanelButton, kTestFarShootButton};

  ControlBoard();
  void ReadControls();
  double GetJoystickValue(Joysticks j, Axes a); 
  bool GetDesired(Buttons button);
  bool JustPressed(Buttons button);

  ~ControlBoard();

 private:
  void ReadAllButtons();
  frc::Joystick *leftJoy_, *rightJoy_;
  double leftJoyX_, leftJoyY_, rightJoyX_, rightJoyY_;
};
