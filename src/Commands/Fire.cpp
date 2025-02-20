// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Fire.h"
#include "../OI.h"
#define FIRETIME 0.25

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

Fire::Fire(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::firing.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

	fireTimer = std::shared_ptr<Timer>(new Timer);
	didFire = false;
	Robot::firing->StopFiring();
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void Fire::Initialize() {
	fireTimer->Start();
	didFire = false;
}

// Called repeatedly when this Command is scheduled to run
void Fire::Execute() {
	if (Robot::oi->getXboxController()->GetRawAxis(XboxAxisRightTrigger) > 0.5 && Robot::oi->getXboxController()->GetRawAxis(XboxAxisLeftTrigger) > 0.5) {
		fireTimer->Reset();
		didFire = true;
	}

	if (fireTimer->Get() < FIRETIME && didFire) {
		Robot::firing->FireSolenoids();
	}
	else {
		Robot::firing->StopFiring();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool Fire::IsFinished() {
    return fireTimer->Get() > FIRETIME;
}

// Called once after isFinished returns true
void Fire::End() {
	Robot::firing->StopFiring();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Fire::Interrupted() {
	Robot::firing->StopFiring();
}
