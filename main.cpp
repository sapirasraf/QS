#include <iostream>
#include "Series.h"
#include "Encode.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include<cmath>
using namespace std;


int main() {

    /*Series s(8);
    s.randomArray();
    s.printArray();

    Encode e(s, 8,0, "UNARY");
    e.calcHaarNoDiv(1);
*/




   /* std::cout << "Example from the article:" << std::endl;
    std::string mys = "31642 | 31633 | 31624 | 31615 | 31606 | 31597 | 31588 | 31580 | 31572 | 31564 | 31556 | 31548 | 31541 | 31534 | 31527 | 31520 | 31513 | 31506 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500 | 31500";
    std::replace(mys.begin(), mys.end(), '|', ',');
    std::cout << mys <<endl;



    Series s(64);
    Encode e(s, 64, floor(log2(31642/64)), "UNARY");
    int array[] = {31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 ,
                   31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 ,
                   31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 ,
                   31500 , 31500 , 31500 , 31500 , 31506 , 31513 , 31520 , 31527 , 31534 , 31541 , 31548 , 31548 , 31556 , 31564 , 31572 ,
                   31580 , 31588 , 31597 , 31606 , 31615 , 31624 , 31633 , 31642 };
    s.setArray(array);
    s.printArray();
    e.calcAll(1);
    std::cout << "Total: " << e.totalBits() << " ell: " << floor(log2(1840/8)) << std::endl << std::endl;

    Series s1(64);
    Encode e1(s1, 64, 0, "C_GAMA");
    int array1[] = {31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 ,
                    31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 ,
                    31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 , 31500 ,
                    31500 , 31500 , 31500 , 31500 , 31506 , 31513 , 31520 , 31527 , 31534 , 31541 , 31548 , 31548 , 31556 , 31564 , 31572 ,
                    31580 , 31588 , 31597 , 31606 , 31615 , 31624 , 31633 , 31642 };
    s1.setArray(array1);
    s1.printArray();
    e1.calcAll(1);
    std::cout << e1.totalBits() << std::endl;
    for (int i = 0; i <= 30; i++) {

        Encode e1(s1, 64, i, "C_GAMA");
        e1.calcAll(0);
        std::cout << "Total C Gama:" << e1.totalBits() << " ell_Cgama: " << i << std::endl;
    }


    Series s_haar(8);
    Encode e_haar(s_haar, 8, 3, "UNARY");
    int array_haar[] = {1840, 1680, 1632, 1504, 1536, 1472, 1360, 1328};
    s_haar.setArray(array_haar);
    std::cout << "Haar:" << std::endl;
    e_haar.calcHaar2(1);

*/

    Series s(8);
    Encode e(s, 8, floor(log2(84/8)), "UNARY");
    int array[] = {84,60,52,51,34,18,13,3};
    s.setArray(array);
    s.printArray();
    e.calcAll(1);
    std::cout << e.totalBits()  << std::endl<<  std::endl;

    Series s1(8);
    Encode e1(s1, 8, 2, "C_GAMA");
    int array1[] = {84,60,52,51,34,18,13,3};
    s1.setArray(array1);
    s1.printArray();
    e1.calcAll(1);
    std::cout << e1.totalBits()  << std::endl;
    for (int i=1; i<=30; i++){

        Encode e1(s1, 8, i, "C_GAMA");
        e1.calcAll(0);
        std::cout << "Total C Gama:" << e1.totalBits() << " ell_Cgama: " << i  << std::endl;

    }


   /* for (int j = 0; j <= 0; j++) {
        srand(time(NULL));
        int size = pow(2, 8);
        int ell_Unary, ell_Cgama, min_series, max_series, ms_ell;
        Series s_2_8(size);
        s_2_8.randomArray2();
        s_2_8.printArray();
        min_series = s_2_8.getArray()[0];
        max_series = s_2_8.getArray()[size - 1];
        ms_ell = std::to_string(min_series).length();

        ell_Unary = log(max_series / size) / log(2);
        Encode e_unary(s_2_8, size, ell_Unary, "UNARY");
        e_unary.calcAll(0);
        std::cout << "Total Unary:" << e_unary.totalBits() << " ell_Unary: " << ell_Unary << std::endl;

        int min = INT_MAX, ell_min = INT_MAX;
        for (int i = 1; i <= 30; i++) {
            ell_Cgama = i;
            Encode e_c_gama(s_2_8, size, ell_Cgama, "C_GAMA");
            e_c_gama.calcAll(0);
            std::cout << "Total C Gama:" << e_c_gama.totalBits() << " ell_Cgama: " << ell_Cgama << std::endl;
            if (e_c_gama.totalBits() < min) {
                min = e_c_gama.totalBits();
                ell_min = ell_Cgama;
            }
        }
        std::cout << "Total MIN C Gama:" << min << " MIN ell_Cgama: " << ell_min << std::endl;



        int i;
        int num = 256;
        float data[num];

        std::cout << "Enter " << num << " elements: ";
        for (i = 0; i < num; ++i){
            std::cin >> data[i];
            }

        std::cout << std::endl << "Standard Deviation = " << e_unary.calculateSD(data, num);


        std::string s = "938 | 943 | 950 | 974 | 980 | 1009 | 1017 | 1034 | 1057 | 1082 | 1102 | 1104 | 1126 | 1141 | 1169 | 1180 | 1205 | 1210 | 1222 | 1240 | 1243 | 1243 | 1272 | 1297 | 1307 | 1315 | 1337 | 1353 | 1358 | 1361 | 1364 | 1367 | 1372 | 1395 | 1402 | 1424 | 1444 | 1454 | 1456 | 1463 | 1484 | 1512 | 1527 | 1528 | 1552 | 1574 | 1584 | 1588 | 1609 | 1637 | 1655 | 1678 | 1696 | 1711 | 1727 | 1738 | 1758 | 1770 | 1771 | 1781 | 1784 | 1813 | 1817 | 1819 | 1823 | 1849 | 1865 | 1881 | 1904 | 1932 | 1947 | 1975 | 1984 | 2003 | 2006 | 2007 | 2017 | 2037 | 2048 | 2068 | 2095 | 2121 | 2128 | 2151 | 2163 | 2182 | 2193 | 2199 | 2211 | 2239 | 2244 | 2244 | 2261 | 2270 | 2290 | 2291 | 2319 | 2322 | 2335 | 2341 | 2359 | 2361 | 2368 | 2392 | 2394 | 2418 | 2421 | 2449 | 2474 | 2496 | 2524 | 2546 | 2570 | 2596 | 2598 | 2606 | 2609 | 2618 | 2640 | 2666 | 2667 | 2677 | 2677 | 2703 | 2722 | 2724 | 2743 | 2766 | 2790 | 2803 | 2831 | 2842 | 2871 | 2891 | 2892 | 2902 | 2904 | 2909 | 2920 | 2948 | 2948 | 2977 | 2992 | 3001 | 3008 | 3035 | 3047 | 3048 | 3049 | 3063 | 3076 | 3104 | 3121 | 3139 | 3168 | 3183 | 3190 | 3204 | 3215 | 3217 | 3230 | 3253 | 3279 | 3296 | 3320 | 3329 | 3337 | 3366 | 3377 | 3400 | 3415 | 3439 | 3468 | 3494 | 3509 | 3536 | 3548 | 3567 | 3580 | 3604 | 3613 | 3614 | 3624 | 3646 | 3662 | 3687 | 3696 | 3713 | 3727 | 3747 | 3748 | 3774 | 3788 | 3812 | 3840 | 3843 | 3855 | 3883 | 3909 | 3930 | 3946 | 3948 | 3966 | 3990 | 4012 | 4018 | 4034 | 4054 | 4067 | 4082 | 4103 | 4125 | 4137 | 4153 | 4176 | 4191 | 4212 | 4221 | 4234 | 4236 | 4241 | 4260 | 4286 | 4297| 4297 | 4326 | 4328 | 4349 | 4359 | 4385 | 4390 | 4401 | 4402 | 4410 | 4439 | 4459 | 4465 | 4479 | 4495 | 4512 | 4529 | 4551 | 4571 | 4595 | 4604 | 4614 | 4623 | 4646 | 4646 | 4669 | 4670 | 4693 | 4693 | 4703 | 4725 | 1073745891";
        std::replace( s.begin(), s.end(), '|', '\n');
        std::cout << s ;


    }
    */


/*//8
   for(int i = 0; i < 3000; ++i) {
        int size = 8;


        Series s_h(size);
       int  a[8] = {700, 540, 441, 462, 955, 745, 431, 492,};
       s_h.setArray(a);

        /*int firstNum = (rand() % (10000) + 1);
        s_h.getArray()[0] = firstNum;


        for (int i = 1; i < size; i++) {
                int x =   (rand() % (10) + 1);
                while((s_h.getArray()[i - 1]) - x>=0) {

                    if ((s_h.getArray()[i - 1]) - x >= 0) {
                        s_h.getArray()[i] = (s_h.getArray()[i - 1]) - x;
                        break;
                    }
                }
        }


        Encode e_h(s_h, size, 3, "UNARY");
        //std::cout << "!!" << std::endl;
        s_h.printArray();
        e_h.calcHaar(1);
        //std::cout << "!!" << std::endl;


        for (int i = 0; i < size; ++i) {

            if (e_h.haar[i] >= e_h.haar[i + 1])
                int l;
            if (e_h.haar[i] <= e_h.haar[i + 1]) {

                break;
            }
            if (i==size-2) {
               int count = 0;
                for(int j = 0; j<e_h.size; j++){
                    if( floor(e_h.haar[j]) == e_h.haar[j]) {
                        count++;
                    }

                }
                if(count==size){
                    std::cout << "!!!!whole!!!!!!!!!!!"<<  std::endl;}

                if(count==size){
                    std::cout << "!!!!whole!!!!!!!!!!!"<<  std::endl;}
                s_h.printArray();
                e_h.calcHaar(1);
                std::cout << count << "    " << "ttttttttttttttttttrrrrrrrrrrrrrrrruuuuuuuuuuuuuuuueeeeeeeeeee" << std::endl;
            }
        }

    }*/



    //256
    //Series good_256(256);

   /* for (int i = 0; i < 1; ++i) {

        int size = 8;
        Series s_256(size);

        s_256.randomHaar();
        s_256.printArray();
        Encode e_h(s_256, size, 3, "UNARY");

        e_h.calcHaar(1);


        for (int i = 0; i < size; ++i) {
            if (e_h.haar[i] >= e_h.haar[i + 1]) {
                int l;
            }
            if (e_h.haar[i] <= e_h.haar[i + 1]) {
                break;
            }

        }

        int count = 0;
        for (int j = 0; j < e_h.size; j++) {
            if (floor(e_h.haar[j]) == e_h.haar[j]) {
                count++;
            }
        }

        if (count == size) {
            std::cout << "!!!!whole!!!!!!!!!!!"<< std::endl;
        }

            s_256.printArray();
            e_h.calcHaar(1);

            std::cout << count << "    " << "ttttttttttttttttttrrrrrrrrrrrrrrrruuuuuuuuuuuuuuuueeeeeeeeeee"
                      << std::endl;



    }*/


   /* std::cout <<  "my: " << std::endl;
    good_256.printArray();
    Encode good_e_256(good_256, 256, 3, "UNARY");
     good_e_256.calcHaar(1);*/



/*for(int i = 0; i < 300; ++i) {
        int size = 8;


        Series s_h(size);

        int firstNum = (rand() % (10000) + 1);
        s_h.getArray()[0] = firstNum;


        for (int i = 1; i < size; i++) {
                int x =   (rand() % (10) + 1);
                while((s_h.getArray()[i - 1]) - x>=0) {

                    if ((s_h.getArray()[i - 1]) - x >= 0) {
                        s_h.getArray()[i] = (s_h.getArray()[i - 1]) - x;
                        break;
                    }
                }
        }


        Encode e_h(s_h, size, 3, "UNARY");
        //std::cout << "!!" << std::endl;
        //s_h.printArray();
        e_h.calcHaar(0);
        //std::cout << "!!" << std::endl;


        for (int i = 0; i < size; ++i) {

            if (e_h.haar[i] >= e_h.haar[i + 1])
                int l;
            if (e_h.haar[i] <= e_h.haar[i + 1]) {

                break;
            }
            if (i==size-2) {
               int count = 0;
                for(int j = 0; j<e_h.size; j++){
                    if( floor(e_h.haar[j]) == e_h.haar[j]) {
                        count++;
                    }

                }
                if(count==size){
                    std::cout << "!!!!whole!!!!!!!!!!!"<<  std::endl;}
                s_h.printArray();
                e_h.calcHaar(1);
                std::cout << count << "    " << "ttttttttttttttttttrrrrrrrrrrrrrrrruuuuuuuuuuuuuuuueeeeeeeeeee" << std::endl;
            }
        }

    }
*/

/*
// new HAAR2

    float avg_sd=0, total_unary=0, total_cgama=0, avg_sd_haar=0, total_unary_haar=0, total_cgama_haar=0;
    for(int i =0; i<1; i++) {
        for(int i =0; i<10000000; i++) {
            int x=1;
            x+i;
        }
        std::cout << std::endl << "New Series : " << endl;
        srand(time(NULL));
        srand(time(NULL));
        int size = 64;
        int ell_Unary, ell_Cgama, min_series, max_series, ms_ell;
        Series s_haar2(size);
        Encode e_haar(s_haar2, size, 0, "UNARY");
        s_haar2.randomBetween(0, 32000);
        s_haar2.printArray();
        avg_sd= avg_sd + e_haar.calculateSD(s_haar2.getArray(), size);
        std::cout << std::endl << "Standard Deviation of Series= " << e_haar.calculateSD(s_haar2.getArray(), size)  << endl;

        std::cout << endl << "======================================================" << endl;

        min_series = s_haar2.getArray()[0];
        max_series = s_haar2.getArray()[size - 1];
        ms_ell = std::to_string(min_series).length();

        ell_Unary = log(max_series / size) / log(2);
        Encode e_unary(s_haar2, size, ell_Unary, "UNARY");
        e_unary.calcAll(1);
        std::cout << "Total Unary:" << e_unary.totalBits() << ", ell_Unary: " << ell_Unary << std::endl;
        total_unary =  total_unary + e_unary.totalBits();

        int min = INT_MAX, ell_min = INT_MAX;
        for (int i = 0; i <= 30; i++) {
            ell_Cgama = i;
            Encode e_c_gama(s_haar2, size, ell_Cgama, "C_GAMA");
            e_c_gama.calcAll(1);
           // std::cout << "Total C Gama:" << e_c_gama.totalBits() << " ell_Cgama: " << ell_Cgama << std::endl;
            if (e_c_gama.totalBits() < min) {
                min = e_c_gama.totalBits();
                ell_min = ell_Cgama;
            }
        }
        std::cout << "Total MIN C Gama:" << min << ", MIN ell_Cgama: " << ell_min << std::endl;
        total_cgama += min;
        std::cout << endl << "======================================================" << endl;

        Series new_series(size, s_haar2.getArray());
        std::cout << endl << "Haar:" << endl;
        new_series.printArray();
        e_haar.calcHaar2(1);


        int max = e_haar.haar[1];
        for (int i = 1; i < size; i++) {
            if (e_haar.haar[i] > max)
                max = e_haar.haar[i];
        }
        int ell = floor(log2(max)) + 1;


        Encode e_haar_unary(new_series, size, ell, "UNARY");
        std::cout << std::endl << "Standard Deviation of Haar= " << e_haar_unary.calculateSD(new_series.getArray(), size)  << endl;
        avg_sd_haar += e_haar_unary.calculateSD(new_series.getArray(), size);

        std::cout << endl << "m=" << max << ", ell=" << ell << std::endl;



        e_haar_unary.calcAllHaar(1);
        std::cout << endl << "Total Unary Haar=" << e_haar_unary.totalBits() << ", ell=" << ell << std::endl;
        total_unary_haar += e_haar_unary.totalBits();
        std::cout << endl << "======================================================" << endl;
        Encode e_haar_cgama(new_series, size, ell, "C_GAMA");
        e_haar_cgama.calcAllHaar(1);
        std::cout << endl << "Total C GAMA Haar=" << e_haar_cgama.totalBits() << ", ell=" << ell << std::endl;
        total_cgama_haar += e_haar_cgama.totalBits();

        std::cout << i << ": " << "Unary= " << e_unary.totalBits() << " C_gamma= " << min << " Haar-2-Unary= " << e_haar_unary.totalBits() << " Haar-2-C_gamma= " << e_haar_cgama.totalBits() << endl;

    }
    std::cout << endl << "avg_sd=" << avg_sd/100 << std::endl;
    std::cout << endl << "total_unary=" << total_unary/100 << std::endl;
    std::cout << endl << "total_cgama=" << total_cgama/100 << std::endl;
    std::cout << endl << "avg_sd_haar=" << avg_sd_haar/100 << std::endl;
    std::cout << endl << "total_unary_haar=" << total_unary_haar/100 << std::endl;
    std::cout << endl << "total_cgama_haar=" << total_cgama_haar/100 << std::endl;


*/
    return 0;
}




