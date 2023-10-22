//Naive Approach for String Matching Algorithm.
#include <iostream>

using namespace std;
void Naive(string t,string p)
{
     int n = t.length();
     int m = p.length();
     
     for(int s=0;s<n-m;s++)
     {
         int i=0,j=0;
         while(j<=m && t[s+i]==p[j])
         {
             i++;
             j++;
         }
         if(j==m)
         {
             cout<<"Pattern occurs with Shift:"<<s;
         }
     }
}
int main()
{
    string text="jim saw me in a book shop";
    string pattern="book";
    
    Naive(text,pattern);

    return 0;
}