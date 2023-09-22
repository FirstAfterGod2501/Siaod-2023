//
// Created by first on 15.09.23.
//

#include <iostream>
#include "FileManager/Filemanager.h"
#include "UI/UI.h"

int main() {
    int menu = -1;

    auto ui = new UI();
    while (menu != 0) {
        std::cout << "Choose the task:\n0 - Exit\n1 - Managing usual text file\n2 - Managing binary file\n> ";
        std::cin >> menu;
        if (menu == 1) {
            ui->FirstTaskHandler();
        }
        else if (menu == 2) {
            ui->SecondTaskHandler();
        }
    }
    delete ui;
}

