#pragma once


// typedef struct
// {
// 	float kP; // 比例制御のゲイン
// 	float kI; // 積分制御のゲイン
// 	float kD; // 微分制御のゲイン
// 	int targetVal; // 目標値
// } PIDParam ;

class PIDCalculator
{
public:
	PIDCalculator();
	void init();
	int calcPID(float kP, float kI, float kD, int targetVal, int sensorVal);
	int pwmLimit(int pwm); 
	void terminate();

private:
	int previous_error;
	int current_error;
	float integral;
	float differential;
	static const int absMax = 100;
	float dt = 10 / 1000.0f; /* TRACER_TASKのハンドラ周期<msec>と同じ */
};