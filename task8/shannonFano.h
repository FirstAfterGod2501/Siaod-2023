#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"

//
// Created by first on 24.11.23.
//

#ifndef TASK8_SHANNONFANO_H
#define TASK8_SHANNONFANO_H

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

struct Node {
    char symbol{};
    int frequency{};
    std::string code;
    Node* left{};
    Node* right{};
};

bool compareNodes(const Node* a, const Node* b) {
    return a->frequency > b->frequency;
}

void shannonFano(std::vector<Node*>& nodes, int start, int end) {
    if (start >= end) {
        return;
    }

    int totalFrequency = 0;
    for (int i = start; i < end; ++i) {
        totalFrequency += nodes[i]->frequency;
    }

    int mid = start;
    int currentFrequency = 0;
    while (currentFrequency * 2 <= totalFrequency) {
        currentFrequency += nodes[mid]->frequency;
        ++mid;
    }

    for (int i = start; i < mid; ++i) {
        nodes[i]->code += "0";
    }
    for (int i = mid; i <= end; ++i) {
        nodes[i]->code += "1";
    }

    shannonFano(nodes, start, mid - 1);
    shannonFano(nodes, mid, end);
}

void shenonWarmup(const std::string& input){
    std::map<char, int> frequencyMap;
    for (char c : input) {
        frequencyMap[c]++;
    }

    std::vector<Node*> nodes;
    for (const auto& pair : frequencyMap) {
        Node* node = new Node();
        node->symbol = pair.first;
        node->frequency = pair.second;
        nodes.push_back(node);
    }

    std::sort(nodes.begin(), nodes.end(), compareNodes);
    shannonFano(nodes, 0, nodes.size() - 1);

    for (Node* node : nodes) {
        std::cout << node->symbol << ": " << node->code << std::endl;
    }

    for (Node* node : nodes) {
        delete node;
    }
}

#endif //TASK8_SHANNONFANO_H

#pragma clang diagnostic pop