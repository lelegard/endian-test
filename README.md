## Testing the endianness of a platform

This project contains a simple test program to display the endianness of the CPU.

### Test on Apple M3 CPU

This CPU is based on the Arm64 architecture. Although the Arm architecture is supposed to
support mixed endianness, all known operating systems configures it in little endian mode.

~~~
$ uname -a
Darwin mac 24.0.0 Darwin Kernel Version 24.0.0: Mon Aug 12 20:52:18 PDT 2024; root:xnu-11215.1.10~2/RELEASE_ARM64_T8122 arm64
$ make
cc     endian.c   -o endian
./endian
0x01020304 stored as 04 03 02 01 => little endian
~~~

### Test on RISC-V architecture (64-bit)

Tested using Qemu version 9.1.0.

~~~
$ uname -a
Linux vmriscv 6.8.0-44-generic #44.1-Ubuntu SMP PREEMPT_DYNAMIC Wed Aug 21 09:27:53 UTC 2024 riscv64 riscv64 riscv64 GNU/Linux
$ make
cc     endian.c   -o endian
./endian
0x01020304 stored as 04 03 02 01 => little endian
~~~

### Test on IBM s390x architecture

This platform is the last major architecture using big endian.

Tested using Qemu version 9.1.0.

~~~
$ uname -a
Linux vms390x 6.8.0-45-generic #45-Ubuntu SMP Fri Aug 30 11:09:37 UTC 2024 s390x s390x s390x GNU/Linux
$ make
cc     endian.c   -o endian
./endian
0x01020304 stored as 01 02 03 04 => big endian
~~~

### Test on PowerPC architecture (64-bit)

This architecture supports mixed endianness. Originally, Apple and IBM used it in big
endian mode. Nowadays, it is mostly used in little endian mode. In this case the
architecture is usually named `ppc64el`. Here, we test a Debian version which
configures the chip in big endian mode.

Tested using Qemu version 9.1.0.

~~~
$ uname -a
Linux vmppc 6.10.3-powerpc64 #1 SMP Debian 6.10.3-1 (2024-08-04) ppc64 GNU/Linux
$ make
cc     endian.c   -o endian
./endian
0x01020304 stored as 01 02 03 04 => big endian
$ 
~~~
