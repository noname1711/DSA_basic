#include<bits/stdc++.h>
using namespace std;
int a[10000];

void qsort (int d,int c){
    int l=d;
    int r=c;
    int moc=a[(d+c)/2]; //dùng đc mảng a vì đã được khai báo toàn cục bên trên, mốc là phần tử ở giữa
    do {
        while(a[l] < moc) l++;  //trái < mốc thì dịch lên để tìm được phần tử đầu tiên trái > mốc
        while(a[r]> moc) r--;   //phải > mốc thì dịch về để tìm được phần tử đầu tiên phải < mốc
        if(l<=r){               //nếu bên trái <= phải thì đổi chỗ trái phải và thu hẹp khoảng cách trái phải
            int x= a[l];
            a[l]= a[r];
            a[r]=x;
            l++;r--;

        }
    } while (l<=r); //đk để lệnh trong do chạy
    if (l<c) qsort(l,c); //nếu bên trái còn phần tử < phần tử cuối mảng ban đầu(c) thì tiếp tục quick sort lại từ phần tử đó đến c
    if (d<r) qsort(d,r); //nếu bên phải còn phần tử > phần tử đầu mảng ban đầu(d) thì tiếp tục quick sort lại từ d đến phần tử đó
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    qsort(0,n-1);  //duyệt từ a[0] và phần tử cuối cùng
    for(int i=0; i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}