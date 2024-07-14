#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin>>n;
    int a[n];
    for(int i=0;i< n;i++){
        cin >> a[i];
    }
    int i, key, j;
    for (i = 1; i < n; i++)
   {
       key = a[i]; // i chạy đến đâu gán key bằng a[i]
       j = i-1;  // chọn phần tử liền trước a[i]
 
       /* Di chuyển các phần tử có giá trị lớn hơn giá trị 
       key về sau một vị trí so với vị trí ban đầu
       của nó */
       while (j >= 0 && a[j] > key)   // miễn là j ko âm và phần tử thứ j > key
       {
           a[j+1] = a[j];  //di chuyển ptu lớn hơn key về sau làm chỗ trống cho key
           j = j-1;  //giảm giá trị của j để kiểm tra phần tử trước đó của mảng
       }
       a[j+1] = key;  //key( giá trị cần chèn) được gán vào sau a[j]
   }
 
    
    for(int i=0;i<n; i++){
        cout << a[i]<<" ";
    }
 
    return 0;
}