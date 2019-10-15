#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "define.hpp"

using namespace std;

int findmax(vector<node*>& tree, int& second)//返回最大值和最小值的下标；
{
    int min, smin, first;
    if(tree[0]->count<=tree[1]->count)
    {
        min = tree[0]->count;
        first = 0;
        smin = tree[1]->count;
        second = 1;
    }
    else
    {
        min = tree[1]->count;
        first = 1;
        smin = tree[0]->count;
        second = 0;
    }
    for(int i=2; i<tree.size(); i++)
    {
        if(tree[i]->count<smin)
        {
            if(tree[i]->count<min)
            {
                int temp = min;
                int temp1 = first;
                first = i;
                min = tree[i]->count;
                smin = temp;
                second = temp1;
            }
            else
            {
                second = i;
                smin = tree[i]->count;
            }
        }
    }
    return first;
}

node* formtree(int* count)
{
    vector<node*> tree;
    for(int i=0; i<MYCHAR_NUM; i++)
    {
        if(count[i]!=0)
        {
            node* temp = new node(i-MYCHAR_MIN, count[i]);
            tree.push_back(temp);
        }
    }
    /*vector<node*>::iterator b = tree.begin();
    while(b!=tree.end())
    {
        cout<<(*b)->mychar<<" "<<(*b)->count<<endl;
        b++;
    }*/
    while(tree.size()!=1)
    {
        int first,second;
        first = findmax(tree, second);
        int temp1 = tree[first]->count + tree[second]->count;
        node* temp = new node(temp1, tree[first], tree[second]);
        if(first>second)
        {
            tree.erase(tree.begin()+first);
            tree.erase(tree.begin()+second);
        }
        else
        {
            tree.erase(tree.begin()+first);
            tree.erase(tree.begin()+second-1);
        }
        tree.push_back(temp);
    }
    return tree[0];
}

void trantree(string* tree, node* head, string temp)
{
    if(head->left!=nullptr)
    {
        temp.push_back(0);
        trantree(tree, head->left, temp);
        temp.pop_back();
    }
    if(head->right!=nullptr)
    {
        temp.push_back(1);
        trantree(tree, head->right, temp);
        temp.pop_back();
    }
    if(head->left==nullptr)
    {
        if(head->count!=0)
        tree[head->mychar - MYCHAR_MIN] = temp;
    }
}


void freenode(node* head)
{
    if(head->left!=nullptr)
    {
        freenode(head->left);
    }
    if(head->right!=nullptr)
    {
        freenode(head->right);
    }
    delete head;
}