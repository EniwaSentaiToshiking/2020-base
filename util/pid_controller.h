#ifndef PIDController_H
#define PIDController_H

#define DELTA_T 0.001 /* TRACER_TASKのハンドラ周期<sec>と同じ */

class PIDController
{
private:
	int previous_error;
  	int current_error;
	float integral; /* 積分 */
	const float absMax = 100;

public:
	PIDController();
	int calc_pid_control_pwm_value(float k_p, float k_i, float k_d, unsigned int sensor_val, unsigned int target_val);
	int pwm_controller_limit(int pid_value);

	virtual ~PIDController();
};
#endif