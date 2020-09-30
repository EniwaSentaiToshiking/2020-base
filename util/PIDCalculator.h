#pragma once

class PIDCalculator
{
public:
	PIDCalculator();
	void init();
	int calc_pid_control_pwm_value(float k_p, float k_i, float k_d, int sensor_val, int target_val);
	int pwm_controller_limit(int pidValue);
	void terminate();

private:
	int previous_error;
	int current_error;
	float integral;
	float differential;
	const int absMax = 100;
	const float dt = 0.001; /* TRACER_TASKのハンドラ周期<sec>と同じ */
};