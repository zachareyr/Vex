#include "main.h"

pros::Controller master( CONTROLLER_MASTER );
bool push_is_active = true;
// true for forward driving, false otherwise
bool driving_mode = true;

bool push_is_forward = false;

bool drive_reverse_held = false;
bool push_reverse_held = false;

