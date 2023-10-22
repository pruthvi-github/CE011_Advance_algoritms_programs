#include <stdio.h>
#include<time.h>
int count=0;
void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}
void Randomized_QuickSort(int arr[],int p,int r)
{
    if(p<r)
    {
        int q = Randomized_Partition(arr,p,r);
        Randomized_QuickSort(arr,p,q-1);
        Randomized_QuickSort(arr,q+1,r);
    }
}

int Partition(int arr[],int p,int r)
{
    int x = arr[r];
    int i=p-1;
    int j;
    for(j=p;j<=r-1;j++)
    {
        count++;
        if(arr[j]<=x)
        {
            i=i+1;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return i+1;
}
int Randomized_Partition(int arr[],int p,int r)
{
    int i =  p+rand()%(r-p+1);
    swap(&arr[i],&arr[r]);
    return(Partition(arr,p,r));
}
int main()
{
    srand(time(NULL));
    int n;
    int arr[1002];
    for(int i=1;i<=1000;i++)
    {
        arr[i] = i;
    }
    Randomized_QuickSort(arr,1,1000);
    printf("No of Comparison:%d",count);
    return 0;
}