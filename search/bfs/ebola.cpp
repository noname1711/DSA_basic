#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;int a[15][15];
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int m;    //số đầu tiên, chỉ số người tiếp xúc với người thứ i
        cin>>m;
        int z=1;   //phần tử đếm, để dếm xem đã nhập đủ m người hay chưa
        while(z<=m){
            int m1;  //m1 là số hiệu người tiếp xúc với i(m1 t/x vs i)
            cin>>m1;
            a[i][m1]=1;
            a[m1][i]=1;
            z++;
        }
    }
    int que[15];
    bool checking[15];
    for(int i=1;i<=15;i++)   checking[i]=false;  //chưa đc set
    int d=1;
    int c=1;
    que[1]=k;
    checking[k] = true;
    int sl=1;   //biến số lượng
    while(d<=c){
        int u=que[d];
        d++;
        for(int i=1;i<=n;i++)   if (a[u][i]==1)
        {
            if (checking[i]==false){
                checking[i]=true;
                c++;
                que[c]=i;
                sl++;
            }
        }  
    }
    sort(que+1,que+1+sl);
    cout<<sl<<endl;
    for(int i=1;i<=sl;i++)    cout<<que[i]<<" ";
    return 0;
}