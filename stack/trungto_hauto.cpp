#include<bits/stdc++.h>
using namespace std;
char stack1[101];   //là mảng A
string stack2="";   //là mảng B
bool isnull=true;
int is_top=-1;  
int sl=0;
int push (int peak)  //trả về vị trí của đỉnh stack
{
    if(isnull)
    {
        is_top++;
        sl=1;
        stack1[is_top]=peak;
        isnull=false;
    }else{
        is_top++;
        stack1[is_top]=peak;
        sl=is_top+1;
    }
    return is_top;
}
char pop (){    //trả về giá trị được lấy ra từ stack1
    if(isnull)  return '.';   //trả về 1 giá trị bất kì miễn là ko nằm trong bảng chữ cái và dấu + - * /  ^ ở đây là dấu . 
    //lưu ý đặt trong ' '(cho kí tự) chứ không phải " "(cho xâu) (với tất cả các dấu)
    else{
        char bien_pop=stack1[is_top];
        is_top--;
        sl--;
        if(is_top==-1)  isnull=true;
        return bien_pop;
    }
}
int main(){
    string xau;
    cin>>xau;
    int len_stack2=0;
    for(int i=0;i<xau.length();i++){
        if (xau[i] >= 'A'  &&  xau[i]<='Z'){  //xau[i] là chữ cái
           stack2=stack2+xau[i]+" ";
        }
        else{
            if (isnull)  push(xau[i]);
            else{
                if(xau[i]=='+'|| xau[i]=='-'){
                    while( isnull==false && (stack1[is_top]=='*'|| stack1[is_top]=='/'|| stack1[is_top]=='+'|| stack1[is_top]=='-'|| stack1[is_top]=='^'))
                    {
                        char xx=pop();
                        if( xx!='.'){   //dấu chấm thì ko lấy vì khi đó stack rỗng, tương tự với các biến bên dưới
                            stack2=stack2+xx+" ";
                        } 
                    }
                    is_top++;
                    sl++;
                    stack1[is_top]=xau[i];
                    if(isnull)  isnull=false;
                }
                if (xau[i]=='*'|| xau[i]=='/')
                {
                    while(isnull==false && (stack1[is_top]=='*'|| stack1[is_top]=='/'|| stack1[is_top]=='^'))
                    {
                        char yy=pop();
                        if (yy!='.'){
                            stack2=stack2+yy+" ";
                        }
                    }
                    is_top++;
                    sl++;
                    stack1[is_top]=xau[i];
                    if(isnull)  isnull=false;
                }
                if (xau[i]=='('){
                    is_top++;
                    stack1[is_top]=xau[i];
                    if (isnull)  isnull=false;
                }
                if (xau[i]==')'){
                    while(isnull==false && stack1[is_top]!='('){
                        char zz=pop();
                        if ( zz !='.'){
                           stack2=stack2+zz+" ";
                        }
                    }
                    is_top--;
                    sl--;
                    if (is_top==-1)  isnull=true;
                }
                if(xau[i]=='^'){
                    is_top++;
                    stack1[is_top]=xau[i];
                    sl++;
                    if (isnull)  isnull=false;
                }
            }
        }  
    }
    while(isnull==false){
        stack2=stack2+stack1[is_top]+" ";
        pop();
    }
    cout<<stack2<<endl;
    return 0;
}

