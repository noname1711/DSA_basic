#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n;
    int a[100005];
    for (int i=1;i<=n;i++)    cin>>a[i];
    cin>>k;
    int b[10005];
    for (int i=1;i<=k;i++)   cin>>b[i];
    a[0]=0;
    for(int i=1; i<=n;i++)   a[i]=a[i-1]+a[i];  //tổng cộng dồn, là mảng b đã phân tích trên
    for(int i=1;i<=k;i++){
        int x=b[i];
        int d=1;
        int c=n;
        while(d<=c){   //tìm số đầu tiên >=x
            int center =(d+c)/2;
            if(a[center]<x)     d=center+1;
            else  c=center-1;
        }
        cout<<d<<" ";
    }
    return 0;
}