#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    long long a[100005];
    for(int i=1;i<=n;i++)   cin>>a[i];
    int res =0;
    sort(a+1,a+n+1);
    for(int i=1;i<=n-1;i++){
        int x=a[i];
        int d=i+1;
        int c=n;
        while(d<=c){
            int center =(d+c)/2;
            if( a[center]<x+k)   d=center+1;
            else  c=center-1;
        }
        if (a[d]-x==k)  res ++;
    }
    cout<<res<<endl;
    return 0;
}