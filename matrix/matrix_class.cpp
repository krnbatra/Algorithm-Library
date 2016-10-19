#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long MOD2 = static_cast<long long>(MOD) * MOD;
const int MAX_K = 50;

struct Matrix{
    vector< vector<int> > mat; // the contents of matrix as a 2D-vector
    int n_rows, n_cols; // number of rows and columns

    Matrix(vector< vector<int> > values): mat(values), n_rows(values.size()),
        n_cols(values[0].size()) {}

    static Matrix identity_matrix(int n){
        // Return I_n - the identity matrix of size n.
        // This function is static, because it creates a new Matrix instance
        vector< vector<int> > values(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const {
        int n = n_rows, m = other.n_cols;
        vector< vector<int> > result(n_rows, vector<int>(n_cols, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < n_cols; k++) {
                    result[i][j] = (result[i][j] + mat[i][k] * 1ll * other.mat[k][j]) % MOD;
                }
            }
        // Multiply matrices as usual, then return the result as the new Matrix
        return Matrix(result);
    }

    inline bool is_square() const{
        return n_rows == n_cols;
    }
};

Matrix fast_exponentiation(Matrix m, int power){
    assert(m.is_square());
    Matrix result = Matrix::identity_matrix(m.n_rows);

    while(power) {
        if(power & 1)
            result = result * m;
        m = m * m;
        power >>= 1;
    }

    return result;
}

int main(){
  int t;
  Matrix M1({ 
      {1, 1}, 
      {1, 1}});
  Matrix M2({ 
      {1, 1}, 
      {1, 0}});
  // Matrix result = M1*M2;
  // for(int i =0 ;i < 2; i++){
  //   for(int j = 0;j < 2; j++){
  //     cout << result.mat[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  vector<vector<int> > values(3, vector<int>(2, 0));
  Matrix M3(values);
  for(int i = 0;i < 3; i++){
    for(int j = 0;j < 2; j++){
      cin >> M3.mat[i][j];
    }
  }
  for(int i = 0; i < 3; i++){
    for(int j = 0;j < 2; j++){
      cout << M3.mat[i][j] << ' ';
    }
    cout << endl;
  }
}