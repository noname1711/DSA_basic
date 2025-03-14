#include<bits/stdc++.h>
using namespace std;

class sv{       //quản lý mỗi sinh viên(thẻ sinh viên)
    public:
    int mssv;
    string name;
    sv *next;
    sv(int mssv1,string name1){  //hàm khởi tạo
        this->mssv=mssv1;
        this->name=name1;
        this->next=NULL;   //NULL chỉ dùng cho con trỏ
    }
    ~sv(){};   //hàm hủy
};

typedef sv* node;  //node là 1 con trỏ của struct sv

class list_sv{     //danh sách sinh viên
    public:
    node root=NULL;  //quản lý số node trong link_list
    int size_=0;
    list_sv(){};     //hàm ktao mặc định
    ~list_sv(){};    //hàm hủy mặc định
    private:
    bool check(){  //list rỗng thì trả về true, ko thì false
        if (size_==0)   return true;
        return false;
    }
    public:
    node addsv(int mssv, string name){
        node node_sv=new sv(mssv,name);   //toán tử new chỉ dùng khi là con trỏ
        if (this->check()){  //this bắt buộc cần có vì hàm check ở vùng private
            this->root=node_sv;    //ko nhất thiết phải this vì root ở vùng public
            size_++;
            return this->root;
        }
        if (this->root->mssv>=node_sv->mssv){
            node_sv->next=this->root;
            this->root=node_sv;
            return this->root;
        }
        node xx= this->root;
        while((xx->next != NULL)&&(xx->next->mssv <= node_sv->mssv)){
            xx=xx->next;
        }   //sau khi kết thúc vòng lặp thì có 2 trường hợp
             //1. xx ở điểm kết thúc
             //2. xx->next->mssv > node_sv>mssv,  xx->mssv<node_sv->mssv
        if(xx->next==NULL){
            xx->next=node_sv;
            size_++;
            return this->root;
        }
        node_sv->next=xx->next;
        xx->next=node_sv;
        size_++;
        return this->root;
    }
    void print_list(){
        node xx=this->root;
        while (xx!=NULL){
            cout<<xx->mssv<<" "<<xx->name<<endl;
            xx=xx->next;
        }
    }
};  

typedef list_sv *list_;
int main() {
    list_ ds=new list_sv();  //khai báo ds dạng list_sv*
    ds->addsv(20213942,"Le Viet Hung");
    ds->addsv(20203942,"Nguyen Viet Hung");
    ds->addsv(20181734,"Pham Viet Lam");
    ds->addsv(20193943,"Le Viet Hoang");
    ds->print_list();
    return 0;
}
