#include<bits/stdc++.h>
using namespace std;

typedef struct Card
{
    int ID;
    struct Card* next;
    Card(int id)
    {
        ID = id;
        next = NULL;
    };
} Card;

int main()
{
    int N, M, K;
    cin>>N>>M>> K;
    int joker[109] = {0};
    int idx;
    for(int i = 0;i<K;i++)
    {
        cin>>idx;
        joker[idx] = 1;
    }
    Card* players[109];
    for(int i = 1;i<= N;i++)
    {
        players[i] = new Card(0);
        Card* curr = players[i];
        if(joker[i] == 1)
        {
            curr->next = new Card(-1);
            curr = curr->next;
            for(int j = 2;j<=M;j++)
            {
                curr->next = new Card(j);
                curr = curr->next;
            }
        }
        else
        {

            for(int j = 1;j<=M;j++)
            {
                curr->next = new Card(j);
                curr = curr->next;
            }
        }

    }
    int firstplayer = 1;
    int nextplayer;
    int draw, place;
    Card* temp, *drawed;
    Card* placetmp;
    while(cin>>draw>>place)
    {
        if(draw==place&&place == -1) break;

        nextplayer = (firstplayer==N) ? 1: firstplayer+1;

        //draw
        temp = players[nextplayer];
        for(int i = 0;i<draw-1;i++)
        {
            if(temp->next->next==NULL) break;
            temp = temp->next;
        }
        drawed = temp->next;
        temp->next = temp->next->next;
        //check joker
        if(drawed->ID == -1)
        {
            joker[nextplayer]--;
            joker[firstplayer]++;
        }

        //insert
        placetmp = players[firstplayer];
        for(int i = 0;i<place-1;i++)
        {
            if(placetmp->next==NULL) break;
            placetmp = placetmp->next;
        }
        drawed->next = placetmp->next;
        placetmp->next = drawed;

        firstplayer = nextplayer;

    }
    for (int i = 1; i <= N; i++)
    {
       if (!joker[i])
        {
            Card* print = players[i]->next;
            if(print) cout << print->ID;
            else
            {
                cout << endl;
                return 0;
            }
            while (print->next)
            {
                print = print-> next;
                cout << " " << print-> ID;
            }
            cout << endl;
            return 0;
        }
    }

}