#include "iostream"
#include "vector"
#include "chrono"
#include "Headers/FirstTask.h"
#include "Headers/MergeSort.h"

#include <iostream>
#include <vector>
#include <chrono>


int main(){
    auto firstTask = new FirstTask();

    int num;

    std::vector<int> vector;

    for(int i = 10000000; i> 0;i--) {
        vector.push_back(i);
    }

    int startClock = clock();

    int start(number_of_allocs);

    mergesort(vector.begin(), vector.end());

    int end(number_of_allocs);

    std::cout<<"amount allocations: " << end-start;

    int endClock = clock();

    auto elapsed = (startClock - endClock)/ CLOCKS_PER_SEC;


    std::cout << "\nelapsed: "<<elapsed << "\n";


    std::cout<<"1)enter num: \n";
    std::cin>>num;
    std::cout<<"after calling: " << firstTask->SetBit(num);

    std::cout<<"\n2)enter num: \n";
    std::cin>>num;
    std::cout<<"after calling: " << firstTask->ResetBit(num);

    std::cout<<"\n3)enter num: \n";
    std::cin>>num;
    std::cout<<"after calling: " << firstTask->BinaryMultiplex(num);

    std::cout<<"\n4)enter num: \n";
    std::cin>>num;
    std::cout<<"after calling: " << firstTask->BinaryDivision(num);

    std::cout<<"\n5)enter num: \n";
    std::cin>>num;
    std::cout<<"enter offset:\n";
    int offset;
    std::cin>>offset;
    std::cout<<"after calling: " << firstTask->MaskChange(num,offset);


    int n;
    std::cout << "Enter size of array: ";
    std::cin >> n;
    std::vector<int> input(n);

    std::cout << "Enter array elements: ";

    for (int i = 0; i < n; i++) {
        std::cin >> input[i];
    }

    unsigned char* arr = firstTask->MakeArray(10000000);
    firstTask->SetBits(arr, input);
    firstTask->SaveResult(arr, input);

    for (int i = 0; i < n; i++) {
        std::cout << input[i];
    }

    delete[] arr;
    delete firstTask;
}