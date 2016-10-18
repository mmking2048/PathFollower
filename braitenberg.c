void main() {
    // left sensor port 2, right sensor port 6
    int LEFT_EYE = 2;
    int RIGHT_EYE = 6;
    
    // threshold for determining whether 
    int threshold_left = 190;
    int threshold_right = 190;

    // time for robot to turn 135 degrees to the left
    float sleeptime = 0.9;
    
    while (1) {
        // left and right sensor readings
        int left = analog(LEFT_EYE);
        int right = analog(RIGHT_EYE);
        
        if (left > threshold_left && right > threshold_right) {
            // left off, right off
            float time = seconds();
            
            // turn left up to 135 degrees
            while (seconds() - time < sleeptime) {
                if (analog(LEFT_EYE) < threshold_left || analog(RIGHT_EYE) < threshold_right) break;
                left();
            }
            
            // turn right up to 135 * 2 degrees
            while (seconds() - time < sleeptime * 3.0) {
                if (analog(LEFT_EYE) < threshold_left || analog(RIGHT_EYE) < threshold_right) break;
                right();
            }
            
        } else if (left > threshold_left && right <= threshold_right) {
            // left off, right on
            // turn right
            right();
        } else if (left <= threshold_left && right > threshold_right) {
            // left on, right off
            // turn left
            left();
        } else if (left <= threshold_left && right <= threshold_right) {
            // left on, right on
            // go forward
            forward();
        }
    }
}