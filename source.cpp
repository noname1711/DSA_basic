#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
template<class T>
class Matrix
{
private:
    int rows, cols;
    T** data;

    void create_data(int m, int n) {
        rows = m;
        cols = n == 0 ? m : n;
        data = new T * [rows];
        for (int i = 0; i < rows; i++)
            data[i] = new T[cols];
    }
public:
    Matrix(int m, int n = 0) {
        create_data(m, n);
    }

    Matrix& operator=(const T* values) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                data[i][j] = *values++;
        }
        return *this;
    }
    Matrix& operator=(T value) {
        for (auto& a : *this) {
            a = value;
        }
        return *this;
    }

    int Rows() const { return rows; }
    int Columns() const { return cols; }

    T& ElementAt(int a, int b) {
        return data[a][b];
    }
    class iterator {
        Matrix& mat;
        int iRow, iCol;
    public:
        iterator(Matrix& mat, int r = 0, int c = 0) : mat(mat), iRow(r), iCol(c) {}

        iterator& operator++() {
            if (++iCol == mat.cols) {
                ++iRow;
                iCol = 0;
            }
            return *this;
        }

        bool operator!=(const iterator& other) const {
            return iCol != other.iCol || iRow != other.iRow;
        }

        T& operator*() {
            return mat.ElementAt(iRow, iCol);
        }
    };
    friend iterator begin(Matrix& a) { return iterator(a); }
    friend iterator end(Matrix& a) { return iterator(a, a.rows); }

};

template<class T>
ostream& operator<<(ostream& out, Matrix<T>& M) {
    //for (int i = 0; i < M.Rows(); i++) {
    //    for (int j = 0; j < M.Columns(); j++) {
    //        out << M.ElementAt(i, j) << '\t';
    //    }
    //    out << endl;
    //}
    int k = 0;
    for (auto a : M) {
        out << a << '\t';
        if (++k == M.Columns()) {
            out << endl;
            k = 0;
        }
    }
    return out;
}
int main() {

    int v[] = {
        1, 2, 3,
        4, 5, 6
    };
    Matrix<int> A(2);
    cout << (A = 100);
}
