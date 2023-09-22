//
// Created by first on 21.09.23.
//

#ifndef TASK2_UI_H
#define TASK2_UI_H


class UI {
public:

    void FirstTaskHandler();

    void SecondTaskHandler();

private:
//first task UI
    int FirstTaskUI();

    int CreateTextFileHandler();

    int OutputTextFileHandler();

    int AppendNewLineHandler();

    int PrintValueByIndexHandler();

    int PrintNumberOfIntegersHandler();

    int MakeFileHandler();

//second task UI
    int SecondTaskUI();

    void textToBinaryHandler();

    void BinaryToTextHandler();

    void PrintBinary();

    void accessByIndex();

    void deleteRecord();

    void formGroupList();

    void transferStudents();


    std::vector<int> split(std::string s, const std::string &delimiter);
};

#endif //TASK2_UI_H
