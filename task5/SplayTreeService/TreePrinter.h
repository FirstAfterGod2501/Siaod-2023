//
// Created by first on 15.11.23.
//

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "../SplayTree/Node.h"

class TreePrinter {

private:

    std::string horizontalLine = "-", verticalLine = "|", leftDropDownLine = "/", rightDropDownLine = "\\";

    static std::vector <std::string> VSCat(std::vector <std::string> const &a, std::vector <std::string> const &b) {
        auto r = a;
        r.insert(r.end(), b.begin(), b.end());
        return r;
    }

    typedef std::vector <std::string> vectorOfStrings;

public:
     void printExpressionTree(Node *node,
                             bool high = true,
                             vectorOfStrings const &leftPrefixReference = vectorOfStrings(),
                             vectorOfStrings const &nextPrefixReference = vectorOfStrings(),
                             vectorOfStrings const &rightPrefixReference = vectorOfStrings(),
                             bool root = true,
                             bool left = true,
                             std::shared_ptr <std::vector<vectorOfStrings>> lines = nullptr) {


        auto leftNodeRecursiveChain = [&]() {  // NOLINT(*-no-recursion)
            printExpressionTree(node->left,
                                high,
                                VSCat(leftPrefixReference, high ? vectorOfStrings({" ", " "}) : vectorOfStrings({" "})),
                                VSCat(leftPrefixReference,
                                      high ? vectorOfStrings({leftDropDownLine, horizontalLine}) : vectorOfStrings{
                                              leftDropDownLine}),
                                VSCat(leftPrefixReference,
                                      high ? vectorOfStrings({horizontalLine, " "}) : vectorOfStrings(
                                              {horizontalLine})), false,
                                true,
                                lines);
        };

        auto rightNodeRecursiveChain = [&]() {  // NOLINT(*-no-recursion)
            printExpressionTree(node->right, high,
                                VSCat(rightPrefixReference,
                                      high ? vectorOfStrings({horizontalLine, " "}) : vectorOfStrings(
                                              {horizontalLine})),
                                VSCat(rightPrefixReference,
                                      high ? vectorOfStrings({rightDropDownLine, verticalLine}) : vectorOfStrings(
                                              {rightDropDownLine})),
                                VSCat(rightPrefixReference,
                                      high ? vectorOfStrings({" ", " "}) : vectorOfStrings({" "})), false, false,
                                lines);
        };

        auto formOutput = [&]() {  // NOLINT(*-no-recursion)
            vectorOfStrings out;
            for (size_t l = 0;; ++l) {
                bool last = true;
                std::string line;
                for (size_t i = 0; i < lines->size(); ++i)
                    if (l < (*lines).at(i).size()) {
                        line += lines->at(i)[l];
                        last = false;
                    } else line += " ";
                if (last) break;
                out.push_back(line);
            }
            return out;
        };

        if (!node) {
            return;
        }

        if (root) {
            lines = std::make_shared < std::vector < vectorOfStrings >> ();
        }

        if (node->left) {
            leftNodeRecursiveChain();
        }

        auto data = std::to_string(node->data);

        size_t sm = left || data.empty() ? data.size() / 2 : ((data.size() + 1) / 2 - 1);

        for (size_t i = 0; i < data.size(); ++i) {
            lines->push_back(VSCat(i < sm ? leftPrefixReference : i == sm ? nextPrefixReference : rightPrefixReference,
                                   {std::string(1, data[i])}));
        }

        if (node->right) {
            rightNodeRecursiveChain();
        }

        if (root) {
            for (const auto &i: formOutput()) {
                std::cout << i << std::endl;
            }
        }
    }
};