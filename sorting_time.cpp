#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include <chrono>

#define MAX 1000000
#define MIN 10

using namespace std;
using namespace std::chrono;

void ran_gen()
{
    ofstream f1;
    int i,x;
    srand(time(NULL));

    f1.open("random input.txt");
    if(!f1)
    {
        exit(1);
    }
    for(i=0; i<MAX; i++)
    {
        x=rand();
        f1<<x<<endl;
    }
    f1.close();
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    ofstream f4;
    ifstream f2;
    int array_1[MAX];
    int n = sizeof(array_1)/sizeof(array_1[0]);
    ran_gen();

    f2.open("random input.txt");
    while(f2)
    {
        for(int j=0; j<MAX; j++)
        {
            f2>>array_1[j];
        }


    }
    f2.close();

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    quickSort(array_1,0,n-1);

    high_resolution_clock::time_point t2= high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>( t2 - t1).count();

    cout <<"for quicksort sort-" <<duration1<<" microseconds"<<endl;
    cout<<"\a";
    f4.open("quicksort_output_sorted.txt");
    if(!f4)
    {
        exit(1);
    }
    for(int l=0; l<MAX; l++)
    {
        f4<<array_1[l]<<endl;
    }
    f4.close();
}
