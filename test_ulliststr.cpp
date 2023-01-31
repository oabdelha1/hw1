#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite
using namespace std;


int main(int argc, char* argv[])
{
    ULListStr dat;


    cout << 1 << endl;
    dat.push_back("1");
    cout << 2 << endl;
    dat.push_back("123");
    cout << dat.get(0) << dat.get(1) <<dat.get(2) << endl;
    dat.push_back("0123456");
    dat.push_back("abc");
    //cout << dat.get(3) <<endl;
    //cout << dat.get(4) <<endl;
    //cout << dat.get(5) <<endl;
    //cout << dat.get(10) << dat.get(11) << dat.get(12)<< endl;
    cout << dat.get(0) << dat.get(1) <<dat.get(2) <<dat.get(3) <<dat.get(4)<<dat.get(5);
    cout <<dat.get(6)<<dat.get(7)<<dat.get(8)<<dat.get(9)<<dat.get(10)<<dat.get(11)<<dat.get(12);
    cout <<dat.get(13)<<dat.get(14)<<endl;
    cout << dat.size() << endl;

    size_t test = 0;
    cout << test << endl;
    test--;
    cout << test << endl;

    ULListStr fat;

    cout << "A" << endl;
    fat.push_front("1");
    fat.push_front("abc");

    cout << fat.get(0) << fat.get(1) << fat.get(2) << fat.get(3) << endl;
    cout << fat.size() << endl;
    /*
    cout << 1 << endl;
    dat.push_front("7");
    cout << 2 << endl;
    dat.push_back("8");
    cout << 3 << endl;
    dat.push_front("8");
    cout << 4 << endl;
    cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
    // prints: 8 7 9
    cout << dat.size() << endl;  // prints 3 since there are 3 strings stored
   
    */
}
