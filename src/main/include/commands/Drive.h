// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <subsystems/Drivetrain.h>
#include "ControlBoard.h"
#include <frc/WPILib.h>
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

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class Drive
    : public frc2::CommandHelper<frc2::CommandBase, Drive> {
 public:

  /**
   * Creates a new Drive command.
   *
   * @param drivetrain Subsystem for drivetrain
   */
  explicit Drive(Drivetrain* drivetrain, ControlBoard* humanControl);
  void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End();
	void Interrupted();

 private:
  Drivetrain* drivetrain_;
  ControlBoard* humanControl_;
  
};
