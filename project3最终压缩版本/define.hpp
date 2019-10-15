#ifndef DEFINE_H
#define DEFINE_H

#define MYCHAR_NUM 256
#define MYCHAR_MIN -128
#define MYCHAR_MAX 127


struct node//树节点结构；
{
    char mychar;
    node* left;
    node* right;
    int count;
    node(char temp, int count1):mychar(temp),count(count1),left(nullptr), right(nullptr){}
    node(int count2, node*left1, node*right1):count(count2), left(left1), right(right1){}
};

#endif