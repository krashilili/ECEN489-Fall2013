#include "performance_metric.h"

double scorePercentageVertical(const double tilt_angle, const vector<double>& acceleration, vector<double>& velocity, double ts)
{
    double acc_mag = sqrt(acceleration[0]*acceleration[0] + acceleration[1]*acceleration[1] + acceleration[2]*acceleration[2]);

    vector<double> acc_mod = acceleration;

    double angle_rad = tilt_angle;
    angle_rad *= (pi/180);

    for (int i = 0; i < 3; i++){
        acc_mod[i] = acceleration[i]/acc_mag;
    }

    double acc_angle = acos(abs(acc_mod[2]));

    double vel_percent = 0.01;
    double tilt_percent = 0.1;


    if (acceleration[0] < 5.0 && acceleration[1]< 5.0 && acceleration[2] < 5.0)
            vel_percent = 0.0;
    else if (abs(acc_angle) < pi/18)
        vel_percent = 1.0;
    else if (abs(acc_angle) < pi/9)
        vel_percent = 0.75;
    else if (abs(acc_angle) < pi/4)
        vel_percent = 0.5;
    else if (abs(acc_angle) < pi/3)
        vel_percent = 0.25;
    else if (abs(acc_angle) < 85*pi/180)
        vel_percent = 0.1;


    if (angle_rad < pi/18)
        tilt_percent = 1.0;
    else if (angle_rad < pi/9)
        tilt_percent = 0.75;
    else if (angle_rad < pi/4)
        tilt_percent = 0.5;
    else if (angle_rad < pi/3)
        tilt_percent = 0.25;


    cout<<"Acc percent: "<<vel_percent<<endl;
    cout<<"Tilt percent: "<<tilt_percent<<endl;
    double total_percent = vel_percent*tilt_percent;
    //velocity = current_velocity;

    return total_percent;
}
/*
double scorePercentage(const double tilt_angle, AccelerationVector acceleration)
{
	double acc_mag = sqrt(acceleration.x*acceleration.x + acceleration.y*acceleration.y + acceleration.z*acceleration.z);
	AccelerationVector acc_mod = acceleration;

	
		acc_mod.x = acceleration.x/acc_mag;
		acc_mod.y = acceleration.y/acc_mag;
		acc_mod.z = acceleration.z/acc_mag;
	

	double acc_angle = acos(acc_mod.z);

	double acc_percent = 0.0;
	double tilt_percent = 0.0;

	if (acc_angle < pi/18)
		acc_percent = 1.0;
	else if (acc_angle < pi/9)
		acc_percent = 0.75;
	else if (acc_angle < pi/4)
		acc_percent = 0.5;
	else if (acc_angle < pi/3)
		acc_percent = 0.25;

	if (tilt_angle < pi/18)
		tilt_percent = 1.0;
	else if (tilt_angle < pi/9)
		tilt_percent = 0.75;
	else if (tilt_angle < pi/4)
		tilt_percent = 0.5;
	else if (tilt_angle < pi/3)
		tilt_percent = 0.25;

	double total_percent = acc_percent*tilt_percent;

	return total_percent;
}

		
		*/
