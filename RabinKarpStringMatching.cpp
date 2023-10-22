/*This algorithm Named "Rabin-Karp algo" used for string matching.*/
#include <iostream>

using namespace std;
int power(int a,int n,int q){
   int res=1;
    a=a%q;
   while(n>0){
        if(n&1){
            res=(res*a)%q;
        }
        n=n/2;
          a=(a*a)%q;
    }
    return res;
    
}

void rabin_karp_matcher(string T,string p,int d,int q)
{
    int n = T.length();
    int m = p.length();
    int h = power(d,m-1,q);
    int pt = 0,t=0;
    for(int i=0;i<m;i++)
    {
        pt = (d*pt+p[i]-'0')%q;
        t = (d*t+T[i]-'0')%q;
    }
    for(int s=0;s<n-m;s++)
    {  
       int count=0;
       for(int i=0;i<m;i++)
       {
           if(p[i] == T[s+i])
           {
               count++;
           }
           if(count==m)
           {
               cout<<"Pattern Occurence at Shift:"<<count;
           }
       }
        if(s<n-m)
        {
            t = (d*(t-T[s]-'0')*h) + (T[s+m]-'0')%q;
            if(t<0) {
              t = t+q;
            }
        }
    }
}
int main()
{
   string T = "415789802";
   string p = "789";
   int d = 10,q=13;
   rabin_karp_matcher(T,p,d,q);

    return 0;
}