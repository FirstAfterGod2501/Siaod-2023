//
// Created by first on 07.09.23.
//

#ifndef TASK1_FIRSTTASK_H
#define TASK1_FIRSTTASK_H

#include "bitset"

class FirstTask {
private:

    int mask = 0x2A0;

    int SecondMask = 0x5555;

    template<typename data,typename Format>
    int output(data n, Format format){
        std::cout<<format<<n;
    }

public:

    int SetBit(int num){
        std::cout<<"bit mask: ";
        output(std::bitset<16>(mask), std::dec);
        std::cout<<" answer: ";
        return num | mask;
    }

    int ResetBit(int num){
        output(std::bitset<16>(SecondMask), std::dec);
        std::cout<<" answer: ";
        return num & SecondMask;
    }

    int BinaryMultiplex(int num){
        return num << 7;
    }

    int BinaryDivision(int num){
        return num >> 7;
    }

    int MaskChange(int num, int n){
        long mask = 0x8000;
        return num | (mask >> (15-n));
    }

    unsigned char* MakeArray(int size) {
        auto* arr = new unsigned char[(size >> 3) + 1];
        for (int i = 0; i <= (size >> 3); i++) {
            arr[i] = 0;
        }
        return arr;
    }

    void SetBits(unsigned char*& arr, const std::vector<int>& input) {
        for (int i : input) {
            arr[i >> 3] = arr[i >> 3] | (1 << (i & 0x7));
        }
    }

    void SaveResult(unsigned char* arr, std::vector<int>& input) {
        input.clear();

        mask= 0x1;

        int cnt;

        for (int i = 0; i <= 10000000 >> 3; i++) {
            cnt = 0;
            while (arr[i] != 0) {
                if ((arr[i] & mask) != 0) {
                    input.push_back((i << 3) + cnt);
                }
                arr[i] >>= 1;
                cnt++;
            }
        }
    }

};


#endif
