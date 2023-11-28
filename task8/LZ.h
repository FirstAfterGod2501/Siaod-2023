//
// Created by first on 24.11.23.
//

#ifndef TASK8_LZ_H
#define TASK8_LZ_H

#include <string>
#include <map>
#include <vector>


/*
 * ACAGAATAGAGA.
Словарь 	            Содержимое считываемой строчки 	      Код
	A 	                                                    <0, A>
A = 1 	                                   C 	            <0, C>
A = 1
C = 2 	                                 AG                 <1, G>
A = 1, C = 2
AG = 3 	                                AA                  <1, A>
A = 1, C = 2
AG = 3, AA = 4 	                        T 	                <0, T>
A = 1, C = 2, AG = 3
AA = 4, T = 5 	                       AGA 	                <3, A>
A = 1, C = 2, AG = 3
AA = 4, T = 5, AGA = 6              	G 	                 <0, G>
A = 1, C = 2, AG = 3, AA = 4
T = 5, AGA = 6, G = 7       	        A 	                <1, EOF>
 */
struct DictionaryEntry {
    int prefixIndex;
    char nextChar;
};

std::string compressLZ(const std::string& input) {
    std::map<std::string, int> dictionary;
    std::vector<DictionaryEntry> result;

    int nextIndex = 0;
    std::string currentString;

    for (char c : input) {
        currentString += c;
        if (dictionary.find(currentString) == dictionary.end()) {
            dictionary[currentString] = nextIndex++;
            result.push_back({dictionary[currentString.substr(0, currentString.length() - 1)], c});
            currentString = "";
        }
    }

    if (!currentString.empty()) {
        result.push_back({dictionary[currentString], '0'});
    }

    std::string answ;

    for (auto token : result) {
        answ += token.nextChar;
    }

    return answ;
}
#endif //TASK8_LZ_H
