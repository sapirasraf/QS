//
// Created by Sapir on 07/05/2020.
//

#ifndef QS_SERIES_H
#define QS_SERIES_H
#include<cmath>

class Series {
public:
    void setArray(int *array);

public:
    int size;
    int *array = new int[size];


    Series(int size);

    Series(int size, int *array);

    void randomArray();

    void printArray();

    void setSize(int size);

    int getSize() const;

    int *getArray() const;

    void randomHaar();

    void randomCGAMA();

    void randomArray2();

    void randomBetween(int min, int max);
};


#endif //QS_SERIES_H
