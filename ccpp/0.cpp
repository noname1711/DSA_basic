#include <iostream>
#include <string>

using namespace std;

// Định nghĩa cấu trúc Node
struct Node {
    string bienSoXe;   // Biển số xe
    string thoiGianVao; // Thời gian vào bãi
    Node* trai;    // Con bên trái
    Node* phai;    // Con bên phải

    Node(const string& bienSo, const string& thoiGian)
        : bienSoXe(bienSo), thoiGianVao(thoiGian), trai(nullptr), phai(nullptr) {}
};

// Hàm tìm Node có giá trị trái nhất
Node* timGiaTriNhoNhat(Node* goc) {
    while (goc->trai != nullptr) {
        goc = goc->trai;
    }
    return goc;
}

// Hàm xóa một Node khỏi cây
Node* xoaNode(Node* goc, const string& bienSoXe) {
    if (goc == nullptr) {
        return goc;
    }

    if (bienSoXe < goc->bienSoXe) {
        goc->trai = xoaNode(goc->trai, bienSoXe);
    } else if (bienSoXe > goc->bienSoXe) {
        goc->phai = xoaNode(goc->phai, bienSoXe);
    } else {
        // Tìm thấy Node cần xóa
        if (goc->trai == nullptr) {
            Node* tam = goc->phai;
            delete goc;
            return tam;
        } else if (goc->phai == nullptr) {
            Node* tam = goc->trai;
            delete goc;
            return tam;
        }

        // Node có hai con
        Node* tam = timGiaTriNhoNhat(goc->phai);
        goc->bienSoXe = tam->bienSoXe;
        goc->thoiGianVao = tam->thoiGianVao;
        goc->phai = xoaNode(goc->phai, tam->bienSoXe);
    }
    return goc;
}

// Hàm tìm kiếm một Node trong cây
Node* timKiem(Node* goc, const string& bienSoXe) {
    if (goc == nullptr || goc->bienSoXe == bienSoXe) {
        return goc;
    }

    if (bienSoXe < goc->bienSoXe) {
        return timKiem(goc->trai, bienSoXe);
    } else {
        return timKiem(goc->phai, bienSoXe);
    }
}

// Hàm thêm một Node mới vào cây
Node* themNode(Node* goc, const string& bienSoXe, const string& thoiGianVao) {
    if (goc == nullptr) {
        return new Node(bienSoXe, thoiGianVao);
    }

    if (bienSoXe < goc->bienSoXe) {
        goc->trai = themNode(goc->trai, bienSoXe, thoiGianVao);
    } else if (bienSoXe > goc->bienSoXe) {
        goc->phai = themNode(goc->phai, bienSoXe, thoiGianVao);
    }

    return goc;
}

// Ví dụ sử dụng các hàm trên
int main() {
    Node* goc = nullptr;

    // Thêm các xe vào bãi
    goc = themNode(goc, "29A-12345", "2024-05-15 08:00");
    goc = themNode(goc, "30B-67890", "2024-05-15 09:00");
    goc = themNode(goc, "31C-54321", "2024-05-15 10:00");

    // Tìm kiếm xe
    Node* timThay = timKiem(goc, "30B-67890");
    if (timThay != nullptr) {
        cout << "Xe " << timThay->bienSoXe << " vào lúc " << timThay->thoiGianVao << "\n";
    } else {
        cout << "Không tìm thấy xe với biển số 30B-67890\n";
    }

    // Xóa xe
    goc = xoaNode(goc, "30B-67890");

    // Tìm kiếm lại xe sau khi xóa
    timThay = timKiem(goc, "30B-67890");
    if (timThay != nullptr) {
        cout << "Xe " << timThay->bienSoXe << " vào lúc " << timThay->thoiGianVao << "\n";
    } else {
        cout << "Không tìm thấy xe với biển số 30B-67890\n";
    }

    return 0;
}
