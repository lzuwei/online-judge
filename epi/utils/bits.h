//
// Created by Li Zuwei on 10/10/16.
//

#ifndef EPI_BITS_H
#define EPI_BITS_H
int count_bits(unsigned int x) {
    int num_bits = 0;
    while(x) {
        num_bits += x & 0x1;
        x >>= 1;
    }
    return num_bits;
}
#endif //EPI_BITS_H
