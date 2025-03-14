#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream fi("NUMFINAL.inp");
    ofstream fo("NUMFINAL.out");
    int a,n;
    int s=1;
    fi>>a;
    fi>>n;
    for(int i =1;i<=n;i++){
        s=(s*a)%10;
    }
    fo<<s<<endl;
    return 0;
}
