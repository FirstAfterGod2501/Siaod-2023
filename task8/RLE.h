//
// Created by first on 24.11.23.
//

#ifndef TASK8_RLE_H
#define TASK8_RLE_H

#include <string>

std::string RLE(const std::string& input) {
    std::string result;
    int count = 1;
    for (int i = 0; i < input.size(); i++) {
        if (i + 1 < input.size() && input[i] == input[i + 1]) {
            count++;
        } else {
            result += std::to_string(count) + input[i];
            count = 1;
        }
    }
    return result;
}

#endif //TASK8_RLE_H
