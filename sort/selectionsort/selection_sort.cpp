#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int a[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            if (a[j]<a[i])
                swap(a[i],a[j]);
        }
    }
    for (int i=1;i<=n;i++) cout<< a[i]<<endl;
}
