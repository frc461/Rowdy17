// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "SwitchGears.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

SwitchGears::SwitchGears(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::transmission.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

	isFirstGear = true;
	buttonPressed = false;
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void SwitchGears::Initialize() {
//	printf("Switch initialized\n");
}

// Called repeatedly when this Command is scheduled to run
void SwitchGears::Execute() {
//	printf("Switch execute\n");
	if (Robot::oi->getRightJoystick()->GetRawButton(1) && !buttonPressed) {
		Robot::transmission->ChangeGears(isFirstGear);
		isFirstGear = !isFirstGear;
		buttonPressed = true;
	}

	else {
		buttonPressed = false;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool SwitchGears::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void SwitchGears::End() {
	printf("Switch ended\n");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SwitchGears::Interrupted() {
	printf("Switch interrupted\n");
}
