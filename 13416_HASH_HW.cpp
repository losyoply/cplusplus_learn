#include <iostream>
#include <math.h> 
//#include "13416_HASH.h"
#include "function.h"
using namespace std;
int b = 13331 % 41;
void Implement::Add(const string &str)
{
    int value = 0;
    for (int i = 0; i < str.length();i++)
    {
        value =  (value * b + int(str[i])) % 41;
    }
    for(string s: this->table[value])
    {
        if(s == str) return;
    }
    table[value].push_back(str);
    return;
}

void Implement::Delete(const string &str)
{
    int value = 0;
    for (int i = 0; i < str.length();i++)
    {
        value =  (value * b + int(str[i])) % 41;
    }
    for(auto it = this->table[value].begin() ; it != this->table[value].end() ; it++)
    {
        if(*it==str)
        {
            this->table[value].erase(it);
            return;
        }
    }
    return;
}

bool Implement::Exist(const string &str)
{
    int value = 0;
    for (int i = 0; i < str.length();i++)
    {
        value =  (value * b + int(str[i])) % 41;
    }
    for(string s: this->table[value])
    {
        if(s == str) return true;
    }
    return false;
}