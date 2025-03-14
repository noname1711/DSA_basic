#include <bits/stdc++.h>
using namespace std;
int main(){
    int value=5;
    int *a=&value;
    cout<<"a = "<<a<<endl;
    cout<<"value = "<<value<<endl;
    cout<<"tham chieu value: "<<&value<<endl;
    return 0;
}