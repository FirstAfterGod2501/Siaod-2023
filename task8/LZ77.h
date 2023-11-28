//
// Created by first on 24.11.23.
//

#ifndef TASK8_LZ77_H
#define TASK8_LZ77_H

#include <string>
#include <vector>

/*
              Поз.  Длина    Симв.
 abracadabra    0      0      a
a bracadabra    0      0      b
ab racadabra    0      0      r
abr acadabra    3      1      ac
abrac adabra    2      1      ad
abracad abra    7      4      abra
 */

struct Token {
    int offset;
    int length;
    char nextChar;
};

std::string compressLZ77(const std::string& input) {
    std::vector<Token> compressed;
    int bufferSize = 255;
    int maxBufferIndex = 0;
    int currentIndex = 0;
    while (currentIndex < input.size()) {
        int bestMatchLength = 0;
        int bestMatchOffset = 0;
        for (int i = 1; i <= bufferSize && i <= currentIndex; ++i) {
            int matchLength = 0;
            while (currentIndex - i + matchLength < currentIndex && input[currentIndex - i + matchLength] == input[currentIndex + matchLength]) {
                matchLength++;
            }
            if (matchLength > bestMatchLength) {
                bestMatchLength = matchLength;
                bestMatchOffset = i;
            }
        }
        Token token{};
        token.offset = bestMatchOffset;
        token.length = bestMatchLength;
        token.nextChar = input[currentIndex + bestMatchLength];
        compressed.push_back(token);
        currentIndex += bestMatchLength + 1;
        maxBufferIndex = std::max(maxBufferIndex, currentIndex);
    }
    std::string compressedStr;

    for (auto token : compressed) {
        if(token.nextChar == '\000'){
            break;
        }
        compressedStr += token.nextChar;
    }

    return compressedStr;
}
#endif //TASK8_LZ77_H
