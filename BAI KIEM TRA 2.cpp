    #include <stdio.h>
    #include <string.h>
    #define MAX_THI_SINH 100

typedef struct {
    int ma; 						
    char ten[50]; 
    char ngay_sinh[11]; 
    float diem[3]; 
    float tong_diem; 
} ThiSinh;

void nhap_thi_sinh(ThiSinh *ts, int ma) {
    ts->ma = ma;
    printf("Nhap ten thi sinh: ");
    fgets(ts->ten, sizeof(ts->ten), stdin);
    ts->ten[strcspn(ts->ten, "\n")] = 0; 

    printf("Nhap ngay sinh (dd/mm/yyyy): ");
    fgets(ts->ngay_sinh, sizeof(ts->ngay_sinh), stdin);
    ts->ngay_sinh[strcspn(ts->ngay_sinh, "\n")] = 0; 
    // nhap cac diem 
    printf("Nhap diem mon 1: ");
    scanf("%f", &ts->diem[0]);
    printf("Nhap diem mon 2: ");
    scanf("%f", &ts->diem[1]);
    printf("Nhap diem mon 3: ");
    scanf("%f", &ts->diem[2]);
    ts->tong_diem = ts->diem[0] + ts->diem[1] + ts->diem[2]; 
    getchar(); 
}

void tim_thu_khoa(ThiSinh ds[], int n) {
    float diem_cao_nhat = -1;
    int i;

    
    for (i = 0; i < n; i++) {
        if (ds[i].tong_diem > diem_cao_nhat) {
            diem_cao_nhat = ds[i].tong_diem;
        }
    }

    
    printf("Thu khoa:\n");
    for (i = 0; i < n; i++) {
        if (ds[i].tong_diem == diem_cao_nhat) {
            printf("%d %s %s %.1f\n", ds[i].ma, ds[i].ten, ds[i].ngay_sinh, ds[i].tong_diem);
        }
    }
}

int main() {
    int n;
    ThiSinh ds[MAX_THI_SINH];
    // nhap so thi sinh 
    
    printf("Nhap so thi sinh: ");
    scanf("%d", &n);
    getchar(); 

    
    for (int i = 0; i < n; i++) {
        nhap_thi_sinh(&ds[i], i + 1);
    }

    
    tim_thu_khoa(ds, n);

    return 0;
}
