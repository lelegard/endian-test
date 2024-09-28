## Testing the endianness of a platform

This project contains a simple test program to display the endianness of the CPU.

### Test on Apple M3 CPU

This CPU is based on the Arm64 architecture. Although the Arm architecture is supposed
to support mixed endianness, all known operating systems configures it in little
endian mode.

~~~
$ make
cc     endian.c   -o endian
./endian
0x01020304 stored as 04 03 02 01 => little endian
~~~


