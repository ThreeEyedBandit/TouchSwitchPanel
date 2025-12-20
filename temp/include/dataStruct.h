#include <Arduino.h>

#ifndef MY_STRUCT_H
#define MY_STRUCT_H

struct dataValues{
    byte outsideTemp;
    byte airPressure;
    boolean Button1;
    boolean Button2;
    boolean Button3;
    boolean Button4;
    boolean Button5;
    boolean Button6;
    boolean Button7;
    boolean Button8;
};

extern struct dataValues TXdData;
extern struct dataValues RXdData;
extern struct dataValues CurrentData;

#endif