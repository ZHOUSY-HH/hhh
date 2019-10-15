#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include "input.cpp"
#include "tree.cpp"
#include "output.cpp"
#include <ctime>
#include "define.hpp"

using namespace std;

int main(int argc, char**argv)
{
    double start, stop;
    start = clock();
    int count[MYCHAR_NUM]{0};
    long long int countfile(0);
    string tree[MYCHAR_NUM];
    char* data = input(count, argv, countfile);
    if(data==nullptr)
    {
        return 1;
    }
    node* head = formtree(count);
    string temp;
    trantree(tree, head, temp);
    freenode(head);
    output(tree, data, argv, countfile);
    data = nullptr;
    stop = clock();
    stop = (stop-start)/CLOCKS_PER_SEC;
    cout<<stop<<endl;
}