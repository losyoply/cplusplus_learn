#include<bits/stdc++.h>
using namespace std;

typedef struct players
{
    unsigned long long indice;
    struct players* next;
    players(unsigned long long i)
    {
        indice = i;
        next = NULL;
    };
    
} players;

int main()
{
    int N;
    int indices;
    //
    cin >> N;
    cin >> indices;
    players *head = new players(indices);
    players *curr = head;
    for(int ii = 0 ; ii < N-1; ii++)
    {
        cin>>indices;
        curr->next = new players(indices);
        curr = curr->next;
    }
    //players *end = curr;
    curr->next = head;

    int i;
    //int j;
    unsigned long long j;
    players *bombkeeper = head;
    players *tmp, *newplay;
    unsigned long long num = N;
    
    while(cin>>i)
    {
        //j = J % N;
        if(bombkeeper->next == bombkeeper) break;
        if(i==-1) break;

        if(i==1)
        {
            cin >> j;
            j = j % num;
            if(j!=0)
            {
                for (int p = 0; p < (int)j- 1;p++)
                {
                    bombkeeper = bombkeeper->next;
                }
            }
            else
            {
               for (int p = 0; p < num-1;p++)
                {
                    bombkeeper = bombkeeper->next;
                } 
            }
            tmp = bombkeeper->next;
            bombkeeper->next = bombkeeper->next->next;
            delete tmp;
            num=num-1;
            bombkeeper = bombkeeper->next;
         }
        else if(i==2)
        {
            cin >> j;
            newplay = new players(j);
            newplay->next = bombkeeper->next;
            bombkeeper->next = newplay;
            num=num+1;
        }

        //////////////
        /*head = bombkeeper;
        while(head->next != bombkeeper)
        {
            cout << head->indice<< " ";
            head = head->next;
        }
        cout << head->indice << "\n";*/

    }
    head = bombkeeper;
    while(head->next != bombkeeper)
    {
        cout << head->indice<< " ";
        head = head->next;
    }
    cout << head->indice << "\n";
}