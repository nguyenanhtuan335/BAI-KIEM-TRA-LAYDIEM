   #include <stdio.h>
 // MOI BAN NHAP MA TRAn
    void nhap_ma_tran(int a[100][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

    void tinh_tich_ma_tran(int a[100][100], int b[100][100], int c[100][100], int n, int m) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0; 
            for (int k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void in_ma_tran(int c[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", c[i][j]);
            if (j < n - 1) printf(" "); 
        }
        printf("\n"); 
    }
}

int main() {
    int t; // S? b? test
    scanf("%d", &t);
    
    for (int test = 1; test <= t; test++) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        int a[100][100];
        int b[100][100]; 
        int c[100][100]; 
        
        // nhap ma tran 
        nhap_ma_tran(a, n, m);
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[j][i] = a[i][j];
            }
        }
        
       
        tinh_tich_ma_tran(a, b, c, n, m);
        
        
        printf("Test %d:\n", test);
        in_ma_tran(c, n);
    }

    return 0;
}
