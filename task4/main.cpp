#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <tuple>
#include <stdexcept>
#include <memory>

struct Node {
    std::string data;
    Node* left;
    Node* right;
};

Node* createNode(char data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

static std::string horizontalLine = "-", verticalLine = "|", leftDropDownLine = "/", rightDropDownLine = "\\";

bool isOperator(char& op){
    return op == '/' ||
           op == '+' ||
           op == '-' ||
           op == '*';
}

Node* buildExpressionTree(std::string postfix) {
    std::stack<Node*> st;
    Node* t, * t1, * t2;

    for (auto & i : postfix) {
        if (!isOperator(i)) {
            t = createNode(i);
            st.push(t);
        }
        else {
            t = createNode(i);

            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();

            t->right = t1;
            t->left = t2;

            st.push(t);
        }
    }

    t = st.top();
    st.pop();

    return t;
}


std::string GetData(char data){
    if(isdigit(data)){

    }
}

std::vector<std::string> VSCat(std::vector<std::string> const &a, std::vector<std::string> const &b) {
    auto r = a;
    r.insert(r.end(), b.begin(), b.end());
    return r;
}

typedef std::vector<std::string> vectorOfStrings;

void printExpressionTree(Node const * node,
           bool high = true,
           vectorOfStrings const & leftPrefixReference = vectorOfStrings(),
           vectorOfStrings const & nextPrefixReference = vectorOfStrings(),
           vectorOfStrings const & rightPrefixReference = vectorOfStrings(),
           bool root = true, 
           bool left = true, 
           std::shared_ptr<std::vector<vectorOfStrings>> lines = nullptr) {


    auto leftNodeRecursiveChain = [&]() {  // NOLINT(*-no-recursion)
        printExpressionTree(node->left,
              high,
              VSCat(leftPrefixReference, high ? vectorOfStrings({" ", " "}) : vectorOfStrings({" "})),
              VSCat(leftPrefixReference,
                    high ? vectorOfStrings({leftDropDownLine, horizontalLine}) : vectorOfStrings{leftDropDownLine}),
              VSCat(leftPrefixReference, high ? vectorOfStrings({horizontalLine, " "}) : vectorOfStrings({horizontalLine})), false,
              true,
              lines);
    };

    auto rightNodeRecursiveChain = [&]() {  // NOLINT(*-no-recursion)
        printExpressionTree(node->right, high,
              VSCat(rightPrefixReference, high ? vectorOfStrings({horizontalLine, " "}) : vectorOfStrings({horizontalLine})),
              VSCat(rightPrefixReference,
                    high ? vectorOfStrings({rightDropDownLine, verticalLine}) : vectorOfStrings({rightDropDownLine})),
              VSCat(rightPrefixReference, high ? vectorOfStrings({" ", " "}) : vectorOfStrings({" "})), false, false, lines);
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
        lines = std::make_shared<std::vector<vectorOfStrings>>();
    }

    if (node->left) {
        leftNodeRecursiveChain();
    }

    auto data = (node->data);

    size_t sm = left || data.empty() ? data.size() / 2 : ((data.size() + 1) / 2 - 1);

    for (size_t i = 0; i < data.size(); ++i) {
        lines->push_back(VSCat(i < sm ? leftPrefixReference : i == sm ? nextPrefixReference : rightPrefixReference, {std::string(1, data[i])}));
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

void expressionTreeToPrefix(Node* root, std::string& prefix) { // NOLINT(*-no-recursion)
    if (root == nullptr)
        return;

    prefix += root->data;

    expressionTreeToPrefix(root->left, prefix);
    expressionTreeToPrefix(root->right, prefix);
}

int evaluateExpressionTree(Node* root) { // NOLINT(*-no-recursion)
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return root->data[0] - '0';

    int leftVal = evaluateExpressionTree(root->left);
    int rightVal = evaluateExpressionTree(root->right);

    if (root->data[0] == '+')
        return leftVal + rightVal;
    if (root->data[0] == '-')
        return leftVal - rightVal;
    if (root->data[0] == '*')
        return leftVal * rightVal;
}

int evaluatePrefixExpression(std::string prefix) {
    std::stack<int> st;

    for (int i = prefix.length() - 1; i >= 0; i--) { // NOLINT(*-narrowing-conversions)
        if (isdigit(prefix[i]))
            st.push(prefix[i] - '0');
        else {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (prefix[i]) {
                case '+':
                    st.push(op1 + op2);
                    break;
                case '-':
                    st.push(op1 - op2);
                    break;
                case '*':
                    st.push(op1 * op2);
                    break;
            }
        }
    }

    return st.top();
}

int main() {
    std::string postfix = "23*4+";
    //std::cin>>postfix;
    Node* root = buildExpressionTree(postfix);

    std::cout << "Дерево выражения:" << std::endl;
    printExpressionTree(root, true);

    std::string prefix;
    expressionTreeToPrefix(root, prefix);
    std::cout << "Префиксная форма выражения: " << prefix << std::endl;

    int result = evaluateExpressionTree(root);
    std::cout << "Значение выражения по дереву: " << result << std::endl;

    int prefixResult = evaluatePrefixExpression(prefix);
    std::cout << "Значение выражения по префиксной форме: " << prefixResult << std::endl;

    return 0;
}