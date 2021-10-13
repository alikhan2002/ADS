#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int max_col[m + n];
    int min_row[m + n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        min_row[i] = 1000;
        for(int j = 0; j < m; j++){
            if(a[i][j] < min_row[i]) min_row[i] = a[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        max_col[i] = -1000;
        for(int j = 0; j < n; j++){
            if(max_col[i] < a[j][i]) max_col[i] = a[j][i];
             
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == max_col[j] and a[i][j] == min_row[i]) cnt++;
        }
    }
    cout << cnt << "\n";
}