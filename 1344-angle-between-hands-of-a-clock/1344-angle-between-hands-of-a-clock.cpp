class Solution {
public:
    double angleClock(int hour, int minutes) {
        //minute hand moves 360 / 60 = 6 degrees per minute

        //hour hand moves 360 / 12 = 30 degrees per hour
        //but each hour it moves 30 / 60 (minutes in an hour) = 0.5 degrees per minute
        //so in total the hour hand moves 30 * hour + 0.5 * minutes degrees.

        double minuteAngle = minutes * 6;
        double hourAngle = hour * 30 + minutes * 0.5;

        double diff = abs(hourAngle - minuteAngle);

        if(diff > 180) return 360 - diff;
        else return diff;
    }
};