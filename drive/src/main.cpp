#include "main.h"


void power_drive();
void power_flywheel();
void power_intake();
void power_push();
void print_data();
bool move_to(double target, pros::Motor m, int rpm, double maximum_distance_from_target);

double push_starting_pos;

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
	push_starting_pos = m_push.get_position();
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

	bool push_is_moving = false;
	while (1) {
		update_inertial();

		power_drive();
		power_intake();
		if (master.get_digital(PUSH_BUTTON) && !push_is_moving) {
			push_is_moving = true;
		}
		if (push_is_moving) {
			push_is_moving = !move_to(push_starting_pos, m_push, 60, 10);
		}
		// power_push();
		power_flywheel();

		print_data();
		pros::delay(10);
	}
}

// returns: true if the cycle is over, false otherwise
// target: the position of the target
// m: the motor to be moved
// rpm: the maximum rpm of the movement
// over: [bool] whether or not the initial position is greater than the target
// returntype: [bool] true if the motion is complete, false otherwise
bool move_to(double target, pros::Motor m, int rpm, double maximum_distance_from_target) {
	double pos = m.get_position();
	if (pos > target - maximum_distance_from_target || pos < target + maximum_distance_from_target) {
		m = 0;
		return true;
	}
	if (pos > target) m = rpm;
	else m = -rpm;
	return false;
}

void print_data() {
	// master.print(0, 0, m_push.get_position().to_string().c_str());
	std::cout << "pos: " << m_push.get_position() << std::endl;
}

void power_flywheel() {
	int power;
	if (FLYWHEEL_CONTROL_SCHEME == 0) { 
		power = master.get_digital(FLYWHEEL_BUTTON) * 127;
	} else {
		power = master.get_analog(FLYWHEEL_STICK);
	}

	m_fly1 = power;
	m_fly2 = power;
}

void power_push() {
	if (master.get_digital(REVERSE_PUSH_BTN)) {
		if (!push_reverse_held) {
			push_reverse_held = true;
			push_is_forward = !push_is_forward;
		}
	} else {
		push_reverse_held = false;
	}

	m_push = master.get_digital(PUSH_BUTTON) * 127 * bool_to_multiplier(push_is_forward);
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
	if (master.get_digital(REVERSE_DRIVE_BTN)) {
		if (!drive_reverse_held) {
			driving_mode = !driving_mode;
			drive_reverse_held = true;
		}
	} else {
		drive_reverse_held = false;
	}

	int power   = capint(master.get_analog(DRIVE_FWD) + (master.get_analog(DRIVE_FWD_FINE) * 0.25), -127, 127);
	int turning = capint(master.get_analog(DRIVE_TRN) + (master.get_analog(DRIVE_TRN_FINE) * 0.25), -127, 127);


	int left_power  = (power * bool_to_multiplier(driving_mode)) + turning;
	int right_power = (power * bool_to_multiplier(driving_mode)) - turning;

	m_topleft     = left_power;
	m_bottomleft  = left_power;
	m_topright    = right_power;
	m_bottomright = right_power;
}