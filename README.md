rccar
=====

This project allows a remote control car to be controlled via a ps3 controller. 

The remote's cover was removed and appropriate pin were connected to an mbed microcontroller so that the car could be driven by digtal signals output from the mbed (controlled by main.cpp). The ps3 controller axis values input are taken (using pyusb) and converted to pwm signal values. 

###[Read more here](http://tharshan.me/blog/2013/06/21/ps3-controller-plus-rc-car/)


![alt text](http://i.imgur.com/PmnwTjr.jpg "Workspace screenshot")

##Talk
I gave a talk about this at Django Weekend 2014 in Cardiff. You can find the presenation slides [here](https://slid.es/tharshan09/baby-you-can-drive-my-car-with-a-bit-of-python/)
