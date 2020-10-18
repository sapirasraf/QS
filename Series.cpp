//
// Created by Sapir on 07/05/2020.
//
#include <iostream>
#include "Series.h"
#include <random>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<cmath>

Series::Series(int size) : size(size)
{}

Series::Series(int size, int *array) : size(size), array(array) {
    std::sort(Series::array, Series::array+size,std::greater<int>());

}

void Series::setArray(int *array) {
    for (int i = 0; i < size; i++) {
        Series::array[i] = array[i];
    }
}
void Series::randomArray() {
    std::cout << std::endl;
    srand(time(NULL));
    int firstNum = rand()%(1000) + 0;
    Series::array[0]=firstNum;
    for (int i = 1 ; i < size; i++){
        Series::array[i]=rand()%(INT_MAX) +Series::array[i-1];
    }
    /*Series::array[size-1]=INT_MAX;*/
}
void Series::randomArray2() {
    std::cout << std::endl;
    srand(time(NULL));
    int *diff = new int[size];
    for (int i = 0 ; i < size; i++) {        diff[i] = rand()%(100) +0;
    }
    std::sort(diff, diff+size, std::greater<int>());
    int firstNum = rand()%(INT_MAX) + 0;
    Series::array[0]=firstNum;
    for (int i = 1 ; i < size; i++){
        Series::array[i]=Series::array[i-1]-diff[i];
    }
}

void Series::randomCGAMA() {
    std::cout << std::endl;
    srand(time(NULL));
    int firstNum = rand()%(9000) + 0;
    Series::array[0]=firstNum;
    for (int i = 1 ; i < size; i++){
        Series::array[i]=rand()%(10) +Series::array[i-1];
    }
    Series::array[size-1]=rand()%(INT_MAX) + INT_MAX/2;
    /*Series::array[size-1]=INT_MAX;*/
}

void Series::randomHaar() {
    //std::cout << std::endl;
    srand(time(NULL));
    int num = rand() % 500 + 31500;
    std::cout << num << std::endl;
    Series::array[0] = (num) + 0;
    Series s_diff(size);

    for (int i=0; i<size; i++){

        int diff = (rand()%32+0);
        s_diff.getArray()[i] = diff;
    }
    std::sort(s_diff.getArray(), s_diff.getArray()+size,std::greater<int>());
    std::cout << "diff :";
    for (int i=0; i<size; i++){
        std::cout << s_diff.getArray()[i] << "," ;
    }
    std::cout << std::endl;


    for (int i=1; i<size; i++){
        Series::array[i] = Series::array[i-1] - s_diff.getArray()[i];
        if(Series::array[i]<=0){
            Series::array[i] = 0;
        }
    }
}


void Series::randomBetween(int min, int max) {
    //std::cout << std::endl;
    int x = max-min;
    srand(time(NULL));
    Series::array[0] = rand() % x + min;
     for (int i=1; i<size; i++){

        Series::array[i] = rand() % x + min;

        if(Series::array[i]<=min){
            Series::array[i] = min;
        }
    }
    std::sort(Series::array, Series::array+size);//,std::greater<int>());
}


void Series::setSize(int size) {
    Series::size = size;
}

int Series::getSize() const {
    return size;
}

void Series::printArray() {

    for (int i = 0 ; i < size; i++) {
        std::cout << array[i];
        std::cout << " | ";
    }
    std::cout << " (*) Series" <<std::endl;
}

int *Series::getArray() const {
    return array;
}




