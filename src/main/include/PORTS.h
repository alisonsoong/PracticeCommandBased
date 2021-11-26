// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */


// Drive Encoders
static const int LEFT_DRIVE_ENCODER_YELLOW_PWM_PORT      = 6;
static const int RIGHT_DRIVE_ENCODER_YELLOW_PWM_PORT     = 8;
static const int LEFT_DRIVE_ENCODER_RED_PWM_PORT         = 7;
static const int RIGHT_DRIVE_ENCODER_RED_PWM_PORT        = 9;

// Drive Motors
static const int RIGHT_DRIVE_MOTOR_ID                   = 0;
static const int RIGHT_DRIVE_MOTOR_2_ID                  = 1;
static const int LEFT_DRIVE_MOTOR_ID                    = 2;
static const int LEFT_DRIVE_MOTOR_2_ID                   = 3;

// Joysticks
static const int LEFT_JOY_USB_PORT                       = 0;
static const int RIGHT_JOY_USB_PORT                      = 1;