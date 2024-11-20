    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>

void chuan_hoa_xau(char *ho_ten) {
    int i, len = strlen(ho_ten);
    char ket_qua[81]; 
    int j = 0; 

    
    while (ho_ten[0] == ' ') {
        for (i = 0; i < len; i++) {
            ho_ten[i] = ho_ten[i + 1];
        }
        len--;
    }

    
    for (i = 0; i < len; i++) {
        
        if (i == 0 || ho_ten[i - 1] == ' ') {
            ket_qua[j++] = toupper(ho_ten[i]); // Vi?t hoa
        } else if (ho_ten[i] == ' ' && ho_ten[i + 1] == ' ') {
            continue; 
        } else {
            ket_qua[j++] = tolower(ho_ten[i]); 
        }
    }

    
    if (j > 0 && ket_qua[j - 1] == ' ') {
        j--;
    }

    ket_qua[j] = '\0'; 
    printf("%s\n", ket_qua); 
}

int main() {
    int n;
    char ho_ten[81];

    
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        fgets(ho_ten, sizeof(ho_ten), stdin);
        ho_ten[strcspn(ho_ten, "\n")] = 0; 
        chuan_hoa_xau(ho_ten);
    }

    return 0;
}
