#include <iostream>
#include"NetUdp/NetUdp.h"

int main(int, char**argv) {
    NetUdp u;
    u.CreateU(argv[1],7838);   
}
