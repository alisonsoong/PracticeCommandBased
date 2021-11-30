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

  /**
   * Constructor
   * @param leftJoy a Joystick
   * @param rightJoy a Joystick
   */
  ControlBoard(frc::Joystick *leftJoy, frc::Joystick *rightJoy);

  /**
   * Read controls (joysticks for now)
   */
  void ReadControls();

  /**
   * Gets a value of a joystick
   * @param j (kLeftJoy or kRightJoy)
   * @param a (kX, kY, kZ, kLT)
   */
  double GetJoystickValue(Joysticks j, Axes a); 

  ~ControlBoard();

 private:
  void ReadAllButtons();
  frc::Joystick *leftJoy_, *rightJoy_;
  double leftJoyX_, leftJoyY_, rightJoyX_, rightJoyY_;
};
