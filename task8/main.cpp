#include "iostream"
#include "RLE.h"
#include "shannonFano.h"
#include "LZ77.h"


int main(){
    std::string input = "kukukukurekurekun";

    shenonWarmup("Ana, Deus, Ricky, Paki,\n"
                 "Dorms poop\n"
                 "constuntaki,\n"
                 "Deus deus canadaeus –\n"
                 "bam!");
    std::string compressed = compressLZ77(input);
    double ratio = double(input.length()) / double(compressed.length());
    std::cout<<"ratio: " <<ratio<<std::endl;
    std::cout << "Compressed: " << compressed << std::endl;
    return 0;
}