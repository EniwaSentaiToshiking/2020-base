#pragma once
/* インクルードガード(https://kaworu.jpn.org/cpp/%E3%82%A4%E3%83%B3%E3%82%AF%E3%83%AB%E3%83%BC%E3%83%89%E3%82%AC%E3%83%BC%E3%83%89)*/
/*(従来)
#ifndef HOGE_H
#define HOGE_H
class Hoge {
};
#endif // HOGE_H
*/
#include "Motor.h"
using namespace ev3api;

class WheelInfo {

private:

public:
    Motor *left;
    Motor *right;
    int32_t currentCount[2] = {0, 0};
    int32_t initCount[2] = {0, 0};

    WheelInfo();

    /**
     * reset - モータリセット モータ停止および角位置の0リセット、オフセット初期化を行う  
     *
     * @param  {void}
     * @return {void}
     */
    void reset();

    int32_t *getInitCount();

    /**
     * getCount - オフセット付き角位置取得 
     *
     * @param  {void}
     * @return {int32_t} モータ角位置 [deg] 
     */
    int32_t *getCount();

    virtual ~WheelInfo();

};