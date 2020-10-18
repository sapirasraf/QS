//
// Created by Sapir on 07/05/2020.
//
#include <string>
#include<cmath>
#include <iostream>
#include "Encode.h"

Encode::Encode(const Series &series,int size, int ell, const std::string &type) : series(series), size(size), ell(ell), type(type){}



const std::string &Encode::getType() const {
    return type;
}

void Encode::setType(const std::string &type) {
    Encode::type = type;
}

void Encode::setSeries(const Series &series) {
    Encode::series = series;
}

void Encode::setEll(int ell) {
    Encode::ell = ell;
}

int Encode::getEll() const {
    return ell;
}

const Series &Encode::getSeries() const {
    return series;
}


std::string Encode::DecToBin(int number)
{
    if ( number == 0 ) return "0";
    if ( number == 1 ) return "1";

    if ( number % 2 == 0 )
        return DecToBin(number / 2) + "0";
    else
        return DecToBin(number / 2) + "1";
}

int Encode::BinToDec(std::string number)
{
    int result = 0, pow = 1;
    for ( int i = number.length() - 1; i >= 0; --i, pow <<= 1 )
        result += (number[i] - '0') * pow;

    return result;
}


std::string *Encode::getDec2Bin() const {
    return dec2bin;
}

void Encode::setDec2Bin(std::string *dec2Bin) {
    dec2bin = dec2Bin;
}

void Encode::calcDec2Bin(int print) {
        for (int i = 0 ; i < size; i++) {
        Encode::dec2bin[i] = DecToBin(series.getArray()[i]);
    }
    if(print==1) {
        std::cout << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << dec2bin[i];
            std::cout << " | ";
        }
        std::cout << " (0) Dec2Bin" << std::endl;
    }
}

void Encode::calcLowerBits(int print) {
     for (int i = 0; i < size; i++) {
        try {
            Encode::lowerBits[i] =  dec2bin[i].substr(dec2bin[i].length() - ell, ell);
        } catch (std::out_of_range outofrange) {
            Encode::lowerBits[i] = dec2bin[i];
        }
    }
    for (int i = 0; i < size; i++) {
        if (lowerBits[i].length()<ell){
            lowerBits[i] = std::string( ell - lowerBits[i].length(), '0').append( lowerBits[i]);
        }

    }

    if(print==1) {
        std::cout << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << lowerBits[i];
            std::cout << " | ";
        }

        std::cout << " (*) Lower Bits " << type << std::endl;
    }
}

void Encode::calcBinaryLessEllBits(int print) {

    for (int i = 0; i < size; i++) {
        int del = dec2bin[i].length() - ell;
        if (del <= 0) {
            Encode::binaryLessEllBits[i] = "0";
        } else {
            Encode::binaryLessEllBits[i] = dec2bin[i].substr(0, del);
        }
    }
    if(print==1) {
        std::cout << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << binaryLessEllBits[i];
            std::cout << " | ";
        }

        std::cout << " (1) Binary Less " << ell << " Bits" << std::endl;
    }
}

void Encode::calcBin2Dec(int print) {

    for (int i = 0 ; i < size; i++) {
        Encode::bin2dec[i] = BinToDec(binaryLessEllBits[i]);
    }
    if(print==1) {
        std::cout << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << bin2dec[i];
            std::cout << " | ";
        }
        std::cout << " (2) Bin2Dec" << std::endl;
    }
}

void Encode::calcSubtraction(int print) {

    for (int i = 0 ; i < size; i++) {
        if(i==size-1){
            Encode::subtraction[i] = bin2dec[i]-0;
        }
        else {
            Encode::subtraction[i] = bin2dec[i] - bin2dec[i+1];
        }
    }
    if(print==1) {
        std::cout << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << subtraction[i];
            std::cout << " | ";
        }
        std::cout << " (3) Subtraction" << std::endl;
    }
}

void Encode::calcUpperBits(int print) {

    if (type == "UNARY") {
        for (int i = 0; i < size; i++) {
            if(subtraction[i]>=0) {
                upperBits[i] = Unary(subtraction[i]);
            }
            else{
                upperBits[i] = "1";
            }
        }
    }
    else if (type == "C_GAMA") {
        for (int i = 0; i < size; i++) {
            if(subtraction[i]>=0) {
                upperBits[i] = C_Gama(subtraction[i]);
            }
            else{
                upperBits[i] = "1";
            }
        }
    }
    else{
        std::cout << " ERROR TYPE!!! ";
    }
    if(print==1) {
        std::cout << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << upperBits[i];
            std::cout << " | ";
        }

        std::cout << " (*) Upper Bits " << type << std::endl;
    }
}

std::string Encode::Unary(int number)
{
    std::string unary;
    std::string s1 = "0";

    for (int i=0; i<number;i++)
        unary += s1;

    return  unary + "1";
}

std::string Encode::C_Gama(int number)
{
    std::string part1;
    std::string part2;

    part1 = Unary(DecToBin(number+1).length()).substr(1);
    if(number==0){
        part2 ="";
    }
    else {
        part2 = DecToBin(number+1).substr(1);
    }

    return  part1 + part2;
}

int Encode::totalBits(){
    int total = 0;

    for (int i=0; i<size;i++){
        total += lowerBits[i].length();
        total += upperBits[i].length();
    }
    return total;
}

void Encode::calcAll(int print) {
    calcDec2Bin(print);
    calcLowerBits(print);
    calcBinaryLessEllBits(print);
    calcBin2Dec(print);
    calcSubtraction(print);
    calcUpperBits(print);
}

float Encode::calculateSD(float data[], int num)
{
    float sum = 0.0, mean, standardDeviation = 0.0;

    int i;

    for(i = 0; i < num; ++i)
    {
        sum += data[i];
    }

    mean = sum/num;

    for(i = 0; i < num; ++i)
        standardDeviation += pow(data[i] - mean, 2);

    return sqrt(standardDeviation / num);
}

float Encode::calculateSD(int data[], int num)
{
    float sum = 0.0, mean, standardDeviation = 0.0;

    int i;

    for(i = 0; i < num; ++i)
    {
        sum += data[i];
    }

    mean = sum/num;

    for(i = 0; i < num; ++i)
        standardDeviation += pow(data[i] - mean, 2);

    return sqrt(standardDeviation / num);
}

void Encode::calcHaar(int print) {

    double *series_temp = new double[size];
    for (int i = 0; i < size; i++) {
        series_temp[i] = series.getArray()[i];
    }

    int flag=size;
    double x,y;

    while(flag>0) {
        flag = flag / 2;
        for (int i = 0; i < flag; i++) {
            x = series_temp[i * 2];
            y = series_temp[i * 2 + 1];

            haar[i] = (x + y)/ 2.0;
            std::cout << "i:" << i << "  " << x << "+" << y << "=" << (x + y)/2.0 << std::endl;

            haar[flag + i] = (x - y) / 2.0;
            std::cout << "i:" << flag + i << " " << x << "-" << y << "=" << (x - y)/2.0<< std::endl;

        }
        for (int i = 0; i < size; i++) {
            series_temp[i] = haar[i];
        }
    }


    if(print==1) {
        std::cout << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << haar[i];
            std::cout << " | ";
        }
        std::cout << " (*) Haar" << std::endl;

    }
}

void Encode::calcHaar2(int print) {

    double *series_temp = new double[size];
    for (int i = 0; i < size; i++) {
        series_temp[i] = series.getArray()[i];
    }

    int flag=size;
    double x,y;

    while(flag>0) {
        flag = flag / 2;
        for (int i = 0; i < flag; i++) {
            x = series_temp[i * 2];
            y = series_temp[i * 2 + 1];

            haar[i] = floor((x + y)/ 2.0);
            //std::cout << "i:" << i << "  " << x << "+" << y << "=" << (x + y)/2.0 << std::endl;

            haar[flag + i] = floor((x - y) / 2.0);
            // std::cout << "i:" << flag + i << " " << x << "-" << y << "=" << (x - y)/2.0<< std::endl;

        }
        for (int i = 0; i < size; i++) {
            series_temp[i] = haar[i];
        }
    }


    if(print==1) {
        std::cout << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << haar[i];
            std::cout << " | ";
        }
        std::cout << " (*) Haar" << std::endl;
    }
}

void Encode::calcAllHaar(int print) {
    calcDec2Bin(print);
    calcLowerBits(print);
    calcBinaryLessEllBits(print);
    calcBin2Dec(print);
    calcSubtraction(print);
    calcUpperBits(print);
}


void Encode::calcHaarNoDiv(int print) {

    double *series_temp = new double[size];
    for (int i = 0; i < size; i++) {
        series_temp[i] = series.getArray()[i];
    }

    int flag=size;
    double x,y;

    while(flag>0) {
        flag = flag / 2;
        for (int i = 0; i < flag; i++) {
            x = series_temp[i * 2];
            y = series_temp[i * 2 + 1];

            haar[i] = (x + y);
            std::cout << "i:" << i << "  " << x << "+" << y << "=" << (x + y)<< std::endl;

            haar[flag + i] = (x - y) ;
            std::cout << "i:" << flag + i << " " << x << "-" << y << "=" << (x - y)<< std::endl;

        }
        for (int i = 0; i < size; i++) {
            series_temp[i] = haar[i];
        }
    }


    if(print==1) {
        std::cout << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << haar[i];
            std::cout << " | ";
        }
        std::cout << " (*) Haar" << std::endl;

    }
}








