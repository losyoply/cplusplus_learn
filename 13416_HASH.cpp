#include <iostream>
#include "13416_HASH.h"
using namespace std;
#include "13416_HASH_HW.cpp"
int main()
{
    Implement ht =  *(new Implement());

    string command , str;

    while(cin>>command){
        if(command == "add"){
            cin>>str;
            ht.Add(str);
        }else if(command == "delete"){
            cin >> str;
            ht.Delete(str);
        }else if(command == "exist"){
            cin >> str;
            bool is_exist = ht.Exist(str);
            if(is_exist)
                cout<<"exist"<<endl;
            else
                cout<<"not exist"<<endl;
        }else if(command == "print"){
            cout<<ht<<endl;
        }

    }

    return 0;
}
