// Basic movement functions

// left motor plugged in to port 0, right motor plugged in to port 2
int LEFT_MOTOR = 0;
int RIGHT_MOTOR = 2;

// go forward
void forward() {
	fd(LEFT_MOTOR);
	fd(RIGHT_MOTOR);
}

// go backward
void backward() {
	bk(LEFT_MOTOR);
	bk(RIGHT_MOTOR);
}


// turn left
void left() {
	bk(LEFT_MOTOR);
	fd(RIGHT_MOTOR);
}

// turn right
void right() {
	fd(LEFT_MOTOR);
    bk(RIGHT_MOTOR);
}