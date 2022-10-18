#include "main.h"

void power_drive();
void power_flywheel();
void power_intake();
void power_push();
void print_data();

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::print(0, "Drive v0.11");
	// pros::lcd::print(1)

	inertial_sensor.reset();
	pros::lcd::register_btn1_cb(on_center_button);
}



/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */



void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field	 Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

	/*
	 * pros::controller master
	    * master controller
	 * pros::motor m_(top/bottom)(left/right) 
	    * drive motors
	 * pros::motor m_fly(1/2) 
	 	* flywheel motors 
	 * pros::Imu interial_sensor 
	    * interial sensor
	 * std::vector<pros::c::imu_gyro_s_t> rotation_list
	    * a list of the rotations of the robot at different timestamps
	 * std::vector<pros::c::imu_accel_s_t> acceleration_list
	 	* a list of the accelerations of the robot at different timestamps
	 * std::vector<double> timestamps
	 	* a list of doubles representing the times that different rotations and accelerations were taken in ms since robot run
		* timestamps[i] == time that acclerations[i] and rotations[i] was recorded
	*/


	while (1) {
		update_inertial();

		power_drive();
		power_intake();
		power_push();
		power_flywheel();

		print_data();
		pros::delay(10);
	}
}

void print_data() {
	// TODO
}

void power_flywheel() {
	int power;
	if (INTAKE_CONTROL_SCHEME == 0) { 
		power = master.get_digital(FLYWHEEL_BUTTON) * 127;
	} else {
		power = master.get_analog(FLYWHEEL_STICK);
	}

	m_fly1 = power;
	m_fly2 = power;
}

void power_push() {
	m_push = master.get_digital(PUSH_BUTTON) * 127;
}

void power_intake() {
	int power = 0;
	if (INTAKE_CONTROL_SCHEME == 0) {
		if (master.get_digital(INTAKE_FWD_BUTTON)) {
			power = 127;
		} else if (master.get_digital(INTAKE_REV_BUTTON)) {
			power = -127;
		}
	} else {
		power = master.get_analog(INTAKE_STICK);
	}
	m_intake = power;
}

void power_drive() {
	int power = master.get_analog(DRIVE_FWD);
	int turning;
	if (DRIVE_CONTROL_SCHEME == 0) {
		turning = master.get_analog(DRIVE_TRN);
	} else {
		turning = master.get_analog(DRIVE_TRN_ALT);
	}
	
	int left_power = power + turning;
	int right_power = power - turning;

	m_topleft = left_power;
	m_bottomleft = left_power;
	m_topright = right_power;
	m_bottomright = right_power;
}