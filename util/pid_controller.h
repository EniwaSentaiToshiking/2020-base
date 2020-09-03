#ifndef PIDController_H
#define PIDController_H

class PIDController
{
private:
	int previous_error;
	int current_error;
	float integral;
	float differential;

public:
	PIDController();
	int calc_pid_control_pwm_value(float k_p, float k_i, float k_d, unsigned int sensor_val, unsigned int target_val);
	int pwm_controller_limit(int pid_value);

	virtual ~PIDController();
};
#endif