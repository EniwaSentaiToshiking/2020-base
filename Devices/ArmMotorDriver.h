#include "Motor.h"
using namespace ev3api;

class ArmMotorDriver {

private:
    Motor *motor;
    const int DEFAULT_ANGLE = 25;

    const int KP = 2.5F;
    const int PWM_ABS_MAX = 60;

public:
    ArmMotorDriver();

    /**
     * reset - モータリセット モータ停止および角位置の0リセット、オフセット初期化を行う  
     *
     * @param  {void}
     * @return {void}
     */
    void reset();

    /**
     * getCount - オフセット付き角位置取得 
     *
     * @param  {void}
     * @return {int32_t} モータ角位置 [deg] 
     */
    int32_t getCount();

    /**
     * rotate - 腕を動かす
     *
     * @param  {int32_t}     angle	角度 [deg] 
     * @return {void} 
     */
    void rotate(int32_t angle);

    /**
     * rotateDefault - デフォルトの位置まで動かす
     *
     * @param  {void}
     * @return {void} 
     */
    void rotateDefault();


    virtual ~ArmMotorDriver();

};