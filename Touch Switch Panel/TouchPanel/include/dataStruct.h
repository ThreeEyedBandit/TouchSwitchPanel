#include <Arduino.h>

#ifndef MY_STRUCT_H
#define MY_STRUCT_H

struct dataValues{
    byte outsideTemp;
    byte airPressure;
    byte batt2Voltage;
    boolean Button1State;
    boolean Button2State;
    boolean Button3State;
    boolean Button4State;
    boolean Button5State;
    boolean Button6State;
    boolean Button7State;
    boolean Button8State;
    boolean Button1Indicator;
    boolean Button2Indicator;
    boolean Button3Indicator;
    boolean Button4Indicator;
    boolean Button5Indicator;
    boolean Button6Indicator;
};

extern struct dataValues storedData;
extern struct dataValues currentData;

#endif