#include "mbed.h"
 
Serial pc(USBTX, USBRX); // tx, rx
PwmOut forward(p26);
PwmOut back(p25);
PwmOut left(p23);
PwmOut right(p21);

int main() {
    pc.baud(115200);
    char buffer[6]; 
    back.period(0.02);
    forward.period(0.02);
    right.period(0.02);
    left.period(0.02);
    while(1) {
        pc.gets(buffer, 7);
        //convert ascii char to int. 
        // "if u receive 0 over serial, in fact u receive the ascii code of 0 which is 48 or '0', u have to substract 48 or '0'"
        int yaxis = (buffer[0]-'0')*100 +(buffer[1]-'0')*10 + (buffer[2]-'0');
        int xaxis = (buffer[3]-'0')*100 +(buffer[4]-'0')*10 + (buffer[5]-'0');
        //pc.printf("YAXIS %d   XAXIS %d", yaxis, xaxis);
        //DOWN 255, UP 0, LEFT 0, RIGHT 255
        if (yaxis > 120 and yaxis < 135){
            forward=0;
            back=0;
        }else if (yaxis > 130){
            back = (float(yaxis-128)/128);
        }else{
            forward = float(abs(1-float(yaxis)/128));
        }
        if (xaxis > 120 and xaxis < 135){
            left=0;
            right=0;
        }else if (xaxis > 130){
            right = (float(xaxis-128)/128);
        }else{
            left = float(abs(1-float(xaxis)/128));
        }
        
    }
}