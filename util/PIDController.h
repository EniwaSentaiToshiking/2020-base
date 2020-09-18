#pragma once

class PIDController
{
private:
	int previous_error = 0;
	int current_error = 0;
	double integral;
	double differential;
	const float absMax = 100;
	const float dt = 0.001; /* TRACER_TASKのハンドラ周期<sec>と同じ */

public:
	PIDController();
	int calc_pid_control_pwm_value(float k_p, float k_i, float k_d, unsigned int sensor_val, unsigned int target_val);
	int pwm_controller_limit(int pid_value);

	virtual ~PIDController();
};