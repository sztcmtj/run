#include <cstdio>

union endian_struct {
    int a;
    char b;
};

int main(int argc, char** argv) {
    union endian_struct u1;
    u1.a = 0x12345678;
    if (0x78 == u1.b) {
        printf("大端\n");
    } else if (0x12 == u1.b) {
        printf("小端\n");
    }

    return 0; 
}