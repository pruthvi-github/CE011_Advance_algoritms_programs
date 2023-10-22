//Horsepool's Algorithm for string Matching.
#include <iostream>
#include<bits/stdc++.h>


using namespace std;

int Horsepool(string t,string p){
    int n=t.length();
    int m=p.length();
    
    int shift[26]={m};
    
    for(int i=0;i<26;i++){
        shift[i]=m;
    }
    
    // create shift table.
    for(int i=0;i<m-1;i++){
        shift[p[i]-'a']=m-1-i;
    }

    /* if you want to print Shift table value.*/
     for(int i=0;i<26;i++){
         cout<<sigma[i]<<" ";
     }


    /*For Shift the pattern according to shift value in the table and print shift value by which pattern is match.*/
    int j=0;
    while(j+m<=n){
        if(p[m-1]==t[j+m-1]){
            int i=m-2;
            while(i>=0 && p[i]==t[j+i]){
                i=i-1;
                
            }
            if(i==-1)
                return j;
        }
        if(t[j+m-1] == ' ')
           j=j+m;
        else{
            
            j=j+shift[t[j+m-1]-'a'];
        }
    }
    return j;
}

int main()
{
    
    string t="jim saw me in a book shop";
    string p="book";
    

    cout<<Horsepool(t,p);

    return 0;
}