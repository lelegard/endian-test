#include <stdio.h>
#include <inttypes.h>

int main(int argc, char* argv[])
{
    uint32_t i = 0x01020304;
    char* c = (char*)(&i);
    const char* end = "weird";
    if (c[0] == 4 && c[1] == 3 && c[2] == 2 && c[3] == 1) {
        end = "little";
    }
    else if (c[0] == 1 && c[1] == 2 && c[2] == 3 && c[3] == 4) {
        end = "big";
    }
    printf("0x%08X stored as %02X %02X %02X %02X => %s endian\n", (unsigned int)i, c[0], c[1], c[2], c[3], end);
}
