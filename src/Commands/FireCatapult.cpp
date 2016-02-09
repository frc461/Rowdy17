// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "FireCatapult.h"
#include "../OI.h"
#include "../XBoxJoystickMap.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

FireCatapult::FireCatapult(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::catapultPneumatics.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void FireCatapult::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void FireCatapult::Execute() {
	std::shared_ptr<Joystick> xbox = Robot::oi->getXbox();
	if(xbox->GetRawButton(XboxJoystickButton::XboxButtonY)){
		RobotMap::catapultPneumaticsCatapult1->Set(true);
		RobotMap::catapultPneumaticsCatapult2->Set(true);
		RobotMap::catapultPneumaticsCatapult3->Set(true);
		RobotMap::catapultPneumaticsCatapult4->Set(true);
	}else{
		RobotMap::catapultPneumaticsCatapult1->Set(false);
		RobotMap::catapultPneumaticsCatapult2->Set(false);
		RobotMap::catapultPneumaticsCatapult3->Set(false);
		RobotMap::catapultPneumaticsCatapult4->Set(false);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool FireCatapult::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void FireCatapult::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FireCatapult::Interrupted() {

}
