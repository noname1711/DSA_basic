#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[20];
    int n=10;   //Số lượng phần tử trong mảng
    int k=7;    // Giá trị k cần tìm
    for(int i=1; i<=10;i++){     //Nhập giá trị cho mảng
        cin>>a[i];
    }
    int d=1;    // biến bắt đầu của phạm vi tìm kiếm
    int c=n;    // biến kết thúc của phạm vi tìm kiếm
    while (d<=c){
        int center =(d+c)/2;
        if (a[center]< k)  d=center +1;  //phần tử ở giữa nhỏ hơn k thì điều chỉnh lại phạm vi tìm kiếm
        else c=center -1;  //ngược lại thì chỉnh phạm vi tìm kiếm sang trái
    }
    cout<< a[d]<<endl;  //a[d] là phần tử đầu tiên t/m
    return 0;
}