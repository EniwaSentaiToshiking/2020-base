#ifndef PID_H
#define PID_H
/* *_Hは*_headerだな */

class PID
{
public:
  float k_p, k_i, k_d;

  PID(float k_p, float k_i, float k_d);
  virtual ~PID();
};

#endif