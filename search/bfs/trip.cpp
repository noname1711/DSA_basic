#include <bits/stdc++.h>
#define oo 1000000000
using namespace std;
typedef pair<int, int> II;  //II thay cho pair<int,int>

int n, u, v, k, c[17][17], cl[1 << 17][17], kc[1 << 17][17];
II q[1 << 17];
/*int n, u, v, k: Các biến nguyên, được sử dụng để lưu trữ các giá trị liên quan đến số đỉnh, các đỉnh trong quá trình duyệt BFS.
int c[17][17]: Mảng 2 chiều lưu trữ trọng số của các cạnh giữa các đỉnh. Trong trường hợp này, mảng c có kích thước 17x17, giả sử có tối đa 16 đỉnh (đánh số từ 1 đến 16).
int cl[1 << 17][17]: Mảng 2 chiều dùng để đánh dấu các đỉnh đã được thăm trong quá trình duyệt BFS. Sử dụng một kỹ thuật bitmasking để lưu trạng thái của các đỉnh (có hay không đỉnh i trong tập đã thăm).
int kc[1 << 17][17]: Mảng 2 chiều lưu trữ chi phí nhỏ nhất từ đỉnh xuất phát đến các đỉnh khác nhau trong quá trình duyệt BFS.
II q[1 << 17]: Mảng q lưu trữ các cặp (u, k) trong quá trình thực hiện BFS. Cặp (u, k) biểu diễn trạng thái của đỉnh u và đỉnh k tương ứng.
Chú ý:
1 << 17 là một cách viết ngắn gọn cho 2^17, tương đương với số lượng trạng thái có thể có khi sử dụng bitmasking để đánh dấu các đỉnh trong quá trình duyệt BFS.
*/
void bfs() {
    for (int i = 1; i < (1 << n); i++)
        for (int j = 0; j <= n; j++) {
            kc[i][j] = oo;  // Gán giá trị oo (vô cùng) cho tất cả các đỉnh
            cl[i][j] = 0;   // Gán giá trị 0 cho mảng đánh dấu
        }
    int l = 1, r = 0;
    q[++r] = II(0, 0);     // Thêm đỉnh xuất phát vào hàng đợi
    cl[0][0] = 1;          // Đánh dấu đỉnh xuất phát đã được thăm
    kc[0][0] = 0;          // Chi phí để đi từ đỉnh xuất phát đến chính nó là 0
    while (l <= r) {
        II t = q[l++];
        u = t.first, k = t.second;
        /*Dòng mã II t = q[l++]; u = t.first, k = t.second; thực hiện hai công việc:
II t = q[l++];: Lấy phần tử từ hàng đợi q và gán cho biến t. Đồng thời, tăng giá trị của l sau khi lấy phần tử. Điều này giúp chuyển sang phần tử tiếp theo trong hàng đợi.
u = t.first, k = t.second;: Gán giá trị phần tử vừa lấy từ hàng đợi cho các biến u và k. Đây là cách rút gọn để trích xuất giá trị từ một đối tượng pair. 
t.first là giá trị của phần tử đầu tiên trong pair và t.second là giá trị của phần tử thứ hai trong pair. */
        for (int i = 1; i <= n; i++) {
            // Nếu chưa thăm đỉnh i và có thể di chuyển từ đỉnh k đến đỉnh i
            if ((u & (1 << (i - 1))) == 0) {
                v = u | (1 << (i - 1));  // Đánh dấu đỉnh i đã được thăm
                kc[v][i] = min(kc[v][i], kc[u][k] + c[k][i]);  // Cập nhật chi phí
                if (cl[v][i] == 0) {
                    cl[v][i] = 1;  // Đánh dấu đỉnh i đã được thăm
                    q[++r] = II(v, i);  // Thêm đỉnh i vào hàng đợi
                }
            }
        }
    }
    int ds = oo;
    for (int i = 1; i <= n; i++)
        ds = min(ds, kc[(1 << n) - 1][i]);  // Lấy chi phí bé nhất từ đỉnh xuất phát đến các đỉnh kết thúc
    cout << ds;  // Xuất kết quả
}
int main() {
    ios::sync_with_stdio(false);  //tối ưu tốc độ đọc ghi(có thể thêm hoặc không)
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];  // Nhập ma trận trọng số
    bfs();  // Gọi hàm để thực hiện BFS
    return 0;
}