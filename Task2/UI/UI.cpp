//
// Created by first on 21.09.23.
//

#include <iostream>
#include "../FileManager/Filemanager.h"
#include "UI.h"
#include "../BinaryFileManager/BinaryFileManager.h"

int UI::FirstTaskUI() {
    while (true) {
        std::cout << "Operation:\n";
        std::cout << "0 - Back;\n";
        std::cout << "1 - Create a text file containing lines with integer numbers;\n";
        std::cout << "2 - Output a text file;\n";
        std::cout << "3 - Append a new line to the end of a text file;\n";
        std::cout << "4 - Print value by index in a file;\n";
        std::cout << "5 - Print number of integer values in a file\n";
        std::cout << "6 - Make a new file of an old one by multiplying each element by the number of strings in the old file\n> ";

        auto choice = 0;
        std::cin >> choice;
        return choice;
    }
}
int UI::CreateTextFileHandler() {
    std::string filename{};
    std::cout << "Type the name of the new file:\n> ";
    std::cin >> filename;

    auto fm = new FileManager();

    fm->createTextFile(filename);
}

int UI::OutputTextFileHandler() {
    std::string filename{};
    auto fm = new FileManager();

    std::cout << "Type the name of the file to output:\n> ";
    std::cin >> filename;

    std::cout << fm->readFromFile(filename);
}

int UI::AppendNewLineHandler() {
    std::string filename{};
    std::string stringWithNumbers;
    auto fm = new FileManager();

    std::cout << "Type the name of the file to edit:\n> ";
    std::cin >> filename;
    std::cout << "Type the new string of integers\n> ";
    std::cin.get();
    getline(std::cin, stringWithNumbers);

    auto numbers = split(stringWithNumbers, " ");
    fm->appendTextFile(filename, numbers);
}

int UI::PrintValueByIndexHandler() {
    std::string filename{};
    std::string index{};
    auto fm = new FileManager();

    std::cout << "Type the name of the file:\n> ";
    std::cin >> filename;
    std::cout << "Type the index:\n> ";
    std::cin >> index;

    auto result = fm->readNumberFromFile(filename, stoi(index));

    if (result == -1) {
        std::cout << "Out of bounds of file" << std::endl;
    }
    else {
        std::cout << result << std::endl;
    }
}

int UI::PrintNumberOfIntegersHandler() {
    std::string filename{};
    auto fm = new FileManager();

    std::cout << "Type the name of the file:\n> ";
    std::cin >> filename;

    std::cout << fm->countNumbersInFile(filename) << std::endl;
}

int UI::MakeFileHandler() {
    std::string oldFilename{}, newFilename{};
    auto fm = new FileManager();

    std::cout << "Type the name of the existing file:\n> ";
    std::cin >> oldFilename;
    std::cout << "Type the name of the new file:\n> ";
    std::cin >> newFilename;

    fm->createNewFileWithDividedValues(oldFilename, newFilename);
}

std::vector<int> UI::split(std::string s, const std::string &delimiter) {
    std::vector<int> nums;
    size_t pos;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        nums.push_back(stoi(token));
        s.erase(0, pos + delimiter.length());
    }

    return nums;
}

void UI::FirstTaskHandler() {
    auto choice = -1;
    auto ui = new UI();

    while (choice != 0) {

        choice = ui->FirstTaskUI();

        switch (choice) {
            case 1:
                ui->CreateTextFileHandler();
                break;
            case 2:
                ui->OutputTextFileHandler();
                break;
            case 3:
                ui->AppendNewLineHandler();
                break;
            case 4:
                ui->PrintValueByIndexHandler();
                break;
            case 5:
                ui->PrintNumberOfIntegersHandler();
                break;
            case 6:
                ui->MakeFileHandler();
                break;
            default:
                std::cout<<"wrong input";
        }
    }
}

void UI::SecondTaskHandler() {
    auto choice = -1;
    auto ui = new UI();

    while (choice != 0) {

        choice = ui->SecondTaskUI();

        switch (choice) {
            case 1:
                ui->textToBinaryHandler();
                break;
            case 2:
                ui->BinaryToTextHandler();
                break;
            case 3:
                ui->PrintBinary();
                break;
            case 4:
                ui->accessByIndex();
                break;
            case 5:
                ui->deleteRecord();
                break;
            case 6:
                ui->formGroupList();
                break;
            case 7:
                ui->transferStudents();
                break;
            default:
                std::cout<<"wrong input";
        }
    }
}

int UI::SecondTaskUI() {
    std::cout << "Operation:\n";
    std::cout << "0 - Back;\n";
    std::cout << "1 - Text to binary\n";
    std::cout << "2 - Binary to text;\n";
    std::cout << "3 - Print from binary;\n";
    std::cout << "4 - Note access by the position;\n";
    std::cout << "5 - Remove note by key;\n";
    std::cout << "6 - Make up the list of universities including such speciality;\n";
    std::cout << "7 - Change the code by the speciality name.\n> ";
    int choice{};
    std::cin >> choice;
    return choice;
}

void UI::textToBinaryHandler() {
    std::string InputFilename{};
    std::string OutputFilename{};

    auto BFM = new BinaryFileManager();
    std::cout << "Type the name of the .txt file\n> ";
    std::cin >> InputFilename;
    std::cout << "Type the name of the .bin file\n> ";
    std::cin >> OutputFilename;
    BFM->textToBinary(InputFilename,OutputFilename);
}

void UI::BinaryToTextHandler() {
    std::string InputFilename{};
    std::string OutputFilename{};

    auto BFM = new BinaryFileManager();
    std::cout << "Type the name of the .bin file\n> ";
    std::cin >> InputFilename;
    std::cout << "Type the name of the .txt file\n> ";
    std::cin >> OutputFilename;
    BFM->binaryToText(InputFilename,OutputFilename);
}

void UI::PrintBinary() {
    std::string InputFilename{};

    auto BFM = new BinaryFileManager();
    std::cout << "Type the name of the .bin file\n> ";
    std::cin >> InputFilename;
    BFM->printBinaryFile(InputFilename);
}

void UI::accessByIndex() {
    std::string InputFilename{};
    int index;

    auto BFM = new BinaryFileManager();
    std::cout << "Type the name of the .bin file\n> ";
    std::cin >> InputFilename;
    std::cout << "Enter index\n> ";
    std::cin >> index;
    BFM->accessByIndex(InputFilename,index);
}

void UI::deleteRecord() {
    std::string InputFilename{};
    int IDToDelete;

    auto BFM = new BinaryFileManager();
    std::cout << "Type the name of the .bin file\n> ";
    std::cin >> InputFilename;
    std::cout << "Id to delete\n> ";
    std::cin >> IDToDelete;
    BFM->deleteRecord(InputFilename,IDToDelete);
}

void UI::formGroupList() {
    std::string InputFilename{};
    std::string OutputFilename{};
    int groupID{};

    auto BFM = new BinaryFileManager();
    std::cout << "Type the name of the .bin file\n> ";
    std::cin >> InputFilename;
    std::cout << "Type the name of the .txt file\n> ";
    std::cin >> OutputFilename;
    std::cout << "Type the GroupID\n> ";
    std::cin >> groupID;

    BFM->formGroupList(InputFilename,groupID ,OutputFilename);
}

void UI::transferStudents() {
    std::string InputFilename{};
    std::string StudentsFilename{};
    int groupID{};

    auto BFM = new BinaryFileManager();
    std::cout << "Type the name of the .bin file\n> ";
    std::cin >> InputFilename;
    std::cout << "Type the name of the .txt file\n> ";
    std::cin >> StudentsFilename;
    std::cout << "Type the GroupID\n> ";
    std::cin >> groupID;

    BFM->transferStudents(InputFilename,StudentsFilename, groupID);
}
