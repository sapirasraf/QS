//
// Created by Sapir on 07/05/2020.
//
#include <string>
#ifndef QS_ENCODE_H
#define QS_ENCODE_H
#include "Series.h"

class Encode {
public:
    Encode(const Series &series, int size, int ell, const std::string &type);

    Series series;
    int size;
    int ell;
    std::string type;

    std::string *dec2bin = new std::string[size];
    std::string *lowerBits = new std::string[size];
    std::string *binaryLessEllBits = new std::string[size];
    int *bin2dec = new int[size];
    int *subtraction = new int[size];
    std::string *upperBits = new std::string[size];

    int *haar = new int[size];

    std::string *getDec2Bin() const;

    void setDec2Bin(std::string *dec2Bin);

    Encode();



    const Series &getSeries() const;

    const std::string &getType() const;

    void setType(const std::string &type);

    void setSeries(const Series &series);

    void setEll(int ell);

    int getEll() const;

    static int BinToDec(std::string number);

    static  std::string DecToBin(int number);





    std::string *LowerBits(std::string *s);


    std::string *Dec2BinSeries(Series s);



    void calcDec2Bin(int print);

    void calcLowerBits(int print);

    void calcBinaryLessEllBits(int print);

    void calcBin2Dec(int print);

    void calcSubtraction(int print);

    void calcUpperBits(int print);

    std::string Unary(int number);

    std::string C_Gama(int number);

    int totalBits();

    void calcAll(int print);

    static float calculateSD(float *data, int num);

    void calcHaar(int print);
    void calcHaar2(int print);
    void calcHaarNoDiv(int print);

    void calcAllHaar(int print);

    float calculateSD(int *data, int num);
};


#endif //QS_ENCODE_H
