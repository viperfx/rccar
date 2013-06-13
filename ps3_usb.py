import usb
import serial
"""
Links
https://code.google.com/p/openaxis/
http://blog.davidsingleton.org/nnrccar/

"""
ps3 = usb.core.find(find_all=True,idVendor=0x054C, idProduct=0x0268)[0]
ps3.set_configuration()
ser = serial.Serial('/dev/tty.usbmodem1412', 115200, timeout=0.1)
if __name__ == "__main__":
	while True:
		data = ps3.ctrl_transfer(0xa1, 0x1, 0x0101, 0, 0x31)
		print "LeftY %03d RightX %03d" % (data[7], data[8])
		ser.write("%03d%03d" % (data[7], data[8]))
		line = ser.readline()
		print line
