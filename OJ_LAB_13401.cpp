#include<iostream>
#include <deque>
using namespace std;
std::deque<pair<int,int>> SE;
int M, N;
long long ans=0;
pair<int, int> needsort[5000000];
pair<int, int> temp;
void swap(pair<int,int> *a, pair<int,int> *b){
    pair<int,int> temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(pair<int, int> *arr, int front, int end){
    pair<int,int> pivot = arr[end];
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (arr[j].second < pivot.second) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}
void QuickSort(pair<int,int> *arr, int front, int end){
    if (front < end) {
        int pivot = Partition(arr, front, end);
        QuickSort(arr, front, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
    cin >> N >> M;
    int s, e;
    for (int i = 0; i < N;i++)
    {
        cin >> s >> e;
        needsort[i] = {s, e};

    }

    QuickSort(needsort, 0, N-1);

    ans += M;
    for (int i = 0; i < N-1;i++)
    {
        ans+=2* abs(needsort[i].first - needsort[i].second);
    }

        cout << ans << endl;
}

