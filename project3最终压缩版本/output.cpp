#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include "define.hpp"

using namespace std;

char convert(string& byte, long long int& begin)
{
    char temp = 0;
    for(long long int i= begin; i<begin+8; i++)
    {
        temp = temp<<1;
        /*if(byte[i]=='1')
        {
            temp = temp|1;
        }*/
        temp = temp|byte[i];
    }
    return temp;
}


void output(string* tree, char* data, char** argv, const long long int& countfile)
{
    int inttemp = 0;
    string stringtemp;
    ofstream out(argv[2], ios::out|ios::binary);
    if(!out)
    {
        cout<<"error"<<endl;
        return;
    }
    char chartemp=0;
    int countree = 0;
    for(int i=0; i<MYCHAR_NUM; i++)
    {
        if(tree[i].size()!=0)
        {
            ++countree;
        }
    }
    chartemp = countree-128-1;//实际上是减128；
    //cout<<(int)chartemp<<endl;
    out.put(chartemp);//树的大小；
    for(int i=0; i<MYCHAR_NUM; i++)
    {
        if(tree[i].size()!=0)
        {
            chartemp = i+MYCHAR_MIN;
            out.put(chartemp);//字符；
            chartemp = tree[i].size()-128;//字符数量,字符数量减了128；
            out.put(chartemp);
            out.write(tree[i].c_str(), tree[i].size());
        }
    }
    out.write((char*)&countfile, sizeof(long long int));//写入原有字节个数；*/


    string tooutput;
    for(int i=0; i<countfile; i++)
    {
        stringtemp += tree[data[i]-MYCHAR_MIN];
        if(stringtemp.size()%8)
        {
            continue;
        }
        for(long long int j=0; j<stringtemp.size();j=j+8)
        {
            tooutput.push_back(convert(stringtemp, j));
        }
        stringtemp.clear();
    }
    delete []data;
    inttemp = stringtemp.size()%8;
    if(inttemp)
    {
        for(int i= inttemp; i<8; i++)
        {
            stringtemp.push_back(0);
        }
    }
    for(long long int j=0; j<stringtemp.size();j=j+8)
    {
        tooutput.push_back(convert(stringtemp, j));
    }
    /*for(long long int i=0; i<stringtemp.size(); i=i+8)
    {
        tooutput.push_back(convert(stringtemp, i));
    }*/
    out.write(tooutput.c_str(), tooutput.size());
    out.close();
}
