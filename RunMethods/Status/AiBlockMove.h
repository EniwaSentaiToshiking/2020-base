#include "RunStatus.h"
#include "Course.h"

class AiBlockMove : public RunStatus
{
  private:
    int ana_ansnum = 7;
    int deg_ansnum = 7;

  public:
    AiBlockMove();
    void init();
    void setNextState();
    void aians_Input(int Predict_Ana_Num , int Predict_Deg_Num);
    virtual ~AiBlockMove();
};
