/*
 * SettablePIDOut.cpp
 *
 *  Created on: Feb 20, 2016
 *      Author: 461
 */
#include "WPILib.h"

class SettablePIDOut : public PIDOutput {

private:
	//SpeedController *m_fr;
	//SpeedController *m_fl;
	//SpeedController *m_br;
	//SpeedController *m_bl;
	float m_output;

public:

	//void setSpeedControllers(SpeedController *fr, SpeedController *fl, SpeedController *br, SpeedController *bl) {
	//	m_fr = fr;
	//	m_fl = fl;
	//	m_br = br;
	//	m_bl = bl;
	//}

	void PIDWrite (float output) {
		m_output = output;
	}
	
	SettablePIDOut() : m_output(0) { }
	
	float getOutput() { return m_output; }
};

