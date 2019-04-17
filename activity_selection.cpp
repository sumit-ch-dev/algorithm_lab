#include <iostream>
#include<algorithm>

using namespace std;

struct activity
{
    int start,finish;
};

bool activityCompare(activity i,activity j)
{
    return (i.finish<j.finish);
}

void printmaxActivity(activity arra_1[],int n)
{
    sort(arra_1,arra_1+n,activityCompare);
    int i = 0;
    cout<<arra_1[i].start<<"  "<<arra_1[i].finish<<endl;
    for(int j=1; j<n; j++)
    {
        if(arra_1[j].start>=arra_1[i].finish)
        {
            cout<<arra_1[j].start<<"  "<<arra_1[j].finish<<endl;
            i=j;
        }
    }
}
int main()
{
    activity arra[] = {{5,9},{7,10},{10,15},{14,17},{17,23}};
    int n = sizeof(arra)/sizeof(arra[0]);
    printmaxActivity(arra, n);
    return 0;
}
