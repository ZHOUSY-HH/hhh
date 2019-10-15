#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "define.hpp"

using namespace std;

char* input(int* count, char** argv, long long int& countfile)
{
    ifstream in(argv[1],ios::in|ios::binary);//有空判断是否成功打开文件；
    if(!in)
    {
        cout<<"error"<<endl;
        char* temp = nullptr;
        return temp;
    }
    in.seekg(0, ios::end);
    countfile = in.tellg();
    in.seekg(0, ios::beg);
    char* toreturn = new char[countfile];
    in.read(toreturn, countfile);
    for(int i=0; i<countfile; i++)
    {
        ++count[toreturn[i]-MYCHAR_MIN];
    }
    in.close();
    return toreturn;
}
