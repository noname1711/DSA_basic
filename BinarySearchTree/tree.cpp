#include<bits/stdc++.h>
using namespace std;

struct Node    //cấu trúc của 1 node
{
    int data;
    Node *left;
    Node *right;
};

typedef Node *Tree;

Node *CreateNode(int init)   //tạo node
{
    Node *p = new Node;
    p->data = init;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void CreateTree(Tree &root)   //hàm tạo cây
{
    root = NULL;
}

void DestroyTree(Tree &root)   //hàm hủy cây
{
    if (root)
    {
        DestroyTree(root->left);
        DestroyTree(root->right);
        delete root;
    }
}

void AddNode(Tree &root, Node *node)  //thêm nốt
{
    if (root)
    {
        if (root->data == node->data) // Nếu bị trùng giá trị thì không thêm
            return;
        if (node->data < root->data) // Thêm vào cây con bên trái (nhỏ hơn nút hiện tại)
            AddNode(root->left, node);
        else
            AddNode(root->right, node); // Thêm vào cây con bên phải (lớn hơn nút hiện tại)
    }
    else
    {
        root = node; // Đã tìm thấy vị trí thích hợp, thêm node vào
    }
}

Node *FindNode(Tree root, int x)  //tìm node
{
    if (root)
    {
        if (root->data == x) // Tìm thấy
            return root;
        if (x < root->data)
            return FindNode(root->left, x); // Tìm cây con bên trái
        return FindNode(root->right, x); // Tìm cây con bên phải
    }
    return NULL; // Không tìm thấy
}

void PrintTreeNLR(Tree root){  //in cây bằng NLR
    if (root==NULL) return;
    cout << root->data << " ";
    PrintTreeNLR(root->left);
    PrintTreeNLR(root->right);
}
void PrintTreeLNR(Tree root){   //in cây bằng LNR
    if (root==NULL) return;
    PrintTreeLNR(root->left);
    cout << root->data << " ";
    PrintTreeLNR(root->right);
}
void PrintTreeLRN(Tree root)// in cây bằng LRN
{
    if (root==NULL) return;
    PrintTreeLRN(root->left);
    PrintTreeLRN(root->right);
    cout << root->data << " ";
}

void duyet(Tree root)    //duyệt tiền tự,trung tự và hậu tự đều giống nhau
{
    if (root)
    {
        // Xử lý nút gốc (root)
        duyet(root->left);
        duyet(root->right);
    }
}


// nút p là nút cần thay thế, tree là cây đang xét (cây bên phải)
void FindAndReplace1(Tree &p, Tree &tree)
{
    if (tree->left) // chưa phải nhỏ nhất (trái nhất)
        FindAndReplace1(p, tree->left); // tiếp tục tìm
    else // tree là nút trái nhất
    {
        p->data = tree->data; // copy data
        p = tree; // trỏ nút p vào nút tree sẽ làm thế mạng bị xóa
        tree = tree->right; // nút trái không còn tuy nhiên nút phải có thể còn nên ta phải nối chúng lại
    }
}

// nút p là nút cần thay thế, tree là cây đang xét (cây bên trái)
void FindAndReplace2(Tree &p, Tree &tree)
{
    if (tree->right) // chưa phải lớn nhất (phải nhất)
        FindAndReplace2(p, tree->right); // tiếp tục tìm
    else // tree là nút trái nhất
    {
        p->data = tree->data; // copy data
        p = tree; // trỏ nút p vào nút tree sẽ làm thế mạng bị xóa
        tree = tree->left; // nút phải không còn tuy nhiên nút trái có thể còn nên ta phải nối chúng lại
    }
}

void DeleteNode(Tree &root, int x)
{
    if (root)
    {
        if (x > root->data)
            DeleteNode(root->right, x);
        else if (x < root->data)
            DeleteNode(root->left, x);
        else // nút hiện tại (root) là nút cần xóa
        {
            Node *p = root; // lưu lại nút cần xóa tránh bị ghi đè
            if (!root->left)
                root = root->right; // trường hợp 1
            else if (!root->right)
                root = root->left; // trường hợp 2
            else
                FindAndReplace1(p, root->right); // cách 1
                // FindAndReplace2(p, root->left); // cách 2
            delete p; // xóa nút
        }
    }
    else
    {
        cout << "Khong tim thay"; // Không tìm thấy phần tử cần xóa
    }
}

int main(){
    Tree root;
    CreateTree(root);
    int choice;
    do {
        cout << "\n--------------------------------------";
        cout << "\nCac thao tac tren binary search tree";
        cout << "\n1. Them Node";
        cout << "\n2. Xoa Node";
        cout << "\n3. Tim Node";
        cout << "\n4. In cay (NLR)";
        cout << "\n5. In cay (LNR)";
        cout << "\n6. In cay (LRN)";
        cout << "\n7. Duyet cay";
        cout << "\n8. Thoat";
        cout << "\n--------------------------------------";
        cout << "\nNhap lua chon: ";
        cin >> choice;
        switch (choice) {
            case 1:
                int value;
                cout << "Nhap gia tri can them: ";
                cin >> value;
                AddNode(root, CreateNode(value));
                break;
            case 2:
                int deleteValue;
                cout << "Nhap gia tri can xoa: ";
                cin >> deleteValue;
                DeleteNode(root, deleteValue);
                break;
            case 3:
                int searchValue;
                cout << "Nhap gia tri can tim: ";
                cin >> searchValue;
                if (FindNode(root, searchValue)) {
                    cout << "Da thay Node!";
                } else {
                    cout << "Khong thay Node!";
                }
                break;
            case 4:
                cout<<"Cay tim kiem nhi phan (NLR): ";
                PrintTreeNLR(root);
                break;
            case 5:
                cout << "Cay tim kiem nhi phan (LNR): ";
                PrintTreeLNR(root);
                break;
            case 6:
                cout<<" Cay tim kiem nhi phan (LRN): ";
                PrintTreeLRN(root);
                break;
            case 7:
                cout << "Duyet cay: ";
                duyet(root);
                break;
            case 8:
                cout << "Dang thoat";
                break;
            default:
                cout << "Khong co lua chon nay.";
                break;
        }

    } while (choice != 8);

    DestroyTree(root); // Giải phóng bộ nhớ đã cấp phát trước khi thoát

    return 0;
}
