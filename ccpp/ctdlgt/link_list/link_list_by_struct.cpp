#include<bits/stdc++.h>
using namespace std;

struct Node{  //đã viết struct r thì khi khai báo sẽ như bthg
    int data;
    // khai báo con trỏ next của struct node
    Node *next;
};
typedef struct Node* node;  //de do phai dung con tro

node makeNode(int x){   //cap phat dong mot node moi voi du lieu la so x
    node tmp= new Node();
    tmp->data =x;
    tmp->next=NULL;  //null thay cho con tro null
    return tmp;
}

bool empty (node a){   //kiem tra rong
    return a == NULL;
}

int Size(node a){
    int cnt =0;
    while(a != NULL){  //node dau tien( head) chay den null thi se ket thuc so node
        ++cnt;   //dem so node
        a = a-> next;  //gan dia chi node dang sau cho a, khi do a se nhay sang node tiep theo
    // khi a tro den null thi se ket thuc vong lap
    }
    return cnt;
}

void insertFirst( node &a, int x){   //them 1 phan tu vao dau linked list
    // &a(truyen tham chieu) de thay doi a la gia tri dau tien sau khi them phan tu vao dau danh sach
    node tmp =makeNode(x); //cap phat con tro ms la tmp va no se tro vao null,phan data la x
    if(a== NULL){  //list dang rong nen chi can de node dau tien quan ly luon node vua them
        a=tmp;
    }else{   //neu list ko rong thi phai cho next cua temp tro vao a
        tmp ->next=a;  //tmp luu dia chi dau tien cua bien hien tai,giu lai ket noi dang sau
        a= tmp;         //khi nay a lai la phan tu dau tien trong list, chinh la phan tu vua them vao dau
    }
}

void insertLast(node &a, int x){  //them 1 phan tu vao cuoi linked list
    //node cuoi dang tro vao null, h phai lam cho next cua no tro vao temp, khi do temp thanh phan tu cuoi list
    node tmp= makeNode(x);
    if(a ==NULL){
        a= tmp;
    }
    else{
        node p =a;  //khai bao p de a ko thay doi, tranh mat cac node dau
        while(p->next != NULL){  //tim den node cuoi cung
            p=p->next;
        }
        p->next=tmp;  // de phan next cua p tro den node ms, nhu vay node ms se thanh node cuoi
    }
}

void insertMiddle (node &a, int x, int pos){  //them 1 phu tu vao giua
//chen x vao vi tri cua pos(vi tri can chen)
    int n=Size(a);
    if(pos <= 0 || pos > pos +1){
        cout<<"vi tri khong hop le"<<endl;
    }
    if(n==1){  //them vao vi tri dau
        insertFirst(a,x);
        return;
    }
    if(n== pos +1){  //them vao vi tri cuoi
        insertLast(a,x);
        return;
    }
    //neu them o giua thi de next cua tmp tro vao node pos, next cua pos-1 tro vao tmp
    node p=a;
    for(int i=1;i<pos-1;i++){
        p=p-> next;
    }
    node tmp= makeNode(x);
    tmp-> next= p-> next;
    p->next= tmp;
}

void deleteFirst(node &a){  //xoa phan tu dau danh sach
    if(a==NULL) return; //rong thi khong xoa gi ca
    //neu list ko rong thi chi can cho a(node dau) chuyen sang node sau la se tu mat node dau cu
    a= a->next;
}

void deleteLast(node &a){  //xoa phan tu cuoi danh sach
    if(a==NULL) return;  //rong thi ko xoa gi ca
    //cho next cua phan tu sat cuoi tro vao null la tu mat
    node truoc=NULL, sau =a;
    while(sau->next!= NULL){
        truoc=sau;
        sau=sau->next;
    }
    if(truoc=NULL){  //neu list chi co 1 phan tu
        a=NULL;
    }else{  //neu co tu hai phan tu tro len
        truoc->next=NULL;
    }
}

void deleteMiddle(node &a,int pos){   //xoa phan tu o giua
    if(pos<=0|| pos >Size(a))   return;
    node truoc = NULL, sau =a;
    for(int i=1;i< pos; i++){
        //de xoa phan tu o vi tri pos,node o vi tri pos-1(truoc) tro vao node o vi tri pos+1(voi pos la sau)
        truoc= sau;
        sau= sau->next;
    }
    if(truoc==NULL){
        a=a->next;
    }
    else{
        truoc ->next= sau->next;
    }
}

void in(node a){   //in ra danh sach
    cout<<"----------------------"<<endl;
    while(a != NULL){    // duyet qua tat ca cac node
        cout<< a-> data <<" ";
        a=a->next;
    } 
    cout<<endl;
}

void sapxep(node &a){    //luu y la chi hoan vi gia tri cua node chu ko thay doi tham chieu
    for(node p=a; p-> next != NULL; p=p->next){
        node min = p;
        for( node q= p->next; q !=NULL; q= q->next){
            if(q->data < min-> data){
                min = q;
            }
        }
        int tmp =min-> data;
        min->data =tmp;
    }
}

int main(){
    node head = NULL;   //khai bao node dau tien de quan ly
    while(1){
        cout<<"-------------MENU-----------------\n";
        cout<<"1.Chen phan tu vao dau danh sach\n";
        cout<<"2.Chen phan tu vao cuoi danh sach \n";
        cout<<"3.Chen phan tu vao giua danh sach\n";
        cout<<"4.Xoa phan tu dau danh sach\n";
        cout<<"5.Xoa phan tu cuoi danh sach\n";
        cout<<"6.Xoa phan tu o giua danh sach\n";
        cout<<"7.Duyet danh sach lien ket\n";
        cout<<"8.Sap xep cac phan tu trong list\n";
        cout<<"0.Thoat\n";
        cout<<"----------------------------------\n";
        cout<<"Nhap lua chon : ";
        int lc; cin>>lc;
        if(lc==1){
            int x; 
            cout<<"Nhap gia tri can chen: ";
            cin>>x;
            insertFirst(head,x);
        }
        if(lc==2){
            int x; 
            cout<<"Nhap gia tri can chen: ";
            cin>>x;
            insertLast(head,x);
        }
        if(lc==3){
            int x; 
            cout<<"Nhap gia tri can chen: ";
            cin>>x;
            int pos; cout<<"Nhap vi tri can chen: ";
            cin>>pos;
            insertMiddle(head, x, pos);
        }
        if( lc==4){
            deleteFirst(head);
        }
        if( lc==5){
            deleteLast(head);
        }
        if( lc==6){
            int pos; cout<<"Nhap vi tri can xoa: ";
            cin >>pos;
            deleteMiddle(head, pos);
        }
        if( lc==7){
            in(head);
        }
        if(lc==8){
            sapxep(head);
        }
        if(lc==0){
            break;
        }
    }
    return 0;
}