#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m;
    cin>>n>>m;
    long long a[100005];
    for(int i=1;i<=n;i++)   cin>>a[i];
    sort(a+1,a+n+1);
    bool checking= true;   //có đáp án thì là false, true thì ko có đáp án
    for(int i=1; i<=n-1;i++){
        int x=a[i];
        int d=i+1;
        int c=n;
        while(d<=c){
            int center =(d+c)/2;
            if(a[center]<x+m)   d=center+1;
            else c=center-1;
        }
        if (a[d]==x+m){   //lúc này đã có ít nhất 1 đáp án
            checking=false;
            cout<<x<<" "<<a[d];
            break;
        }
    }
    if (checking==true)  cout<<-1<<endl;
    return 0;
}