#include "boolean.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 50
#define COL_SIZE 50

typedef char ElType;
typedef struct {
    ElType contents[ROW_SIZE][COL_SIZE];
    int rowEff;
    int colEff;
} Matrix;

#define ROW(M) (M).rowEff
#define COL(M) (M).colEff
#define ELMT(M, i, j) (M).contents[(i)][(j)]

typedef struct {
    ElType contents[50][50];
    int neff;
} List;

#define NEFF(L) (L).neff
#define ELMTL(L, i) (L).contents[(i)]

Matrix map;
Matrix result;
List words;
char fileName[50];
int count = 0;

void file_config(){
    printf("Input nama file: ");
    scanf("%s", &fileName);

    FILE* fp = fopen(fileName, "r");

    char c = fgetc(fp);
    char currc = c;
    ROW(map) = 0;
    COL(map) = 0;
    int brs = 0;
    int kol = 0;
    while (c!='\n' || currc!='\n'){
        if ((c!=' ') && (c!='\n')){
            ELMT(map, brs, kol) = c;
            kol++;
        }
        if (c=='\n'){
            ROW(map)++;
            brs++;
            COL(map) = kol;
            kol = 0; 
        }
        currc = c;
        c = fgetc(fp);
    }

    ROW(result) = ROW(map);
    COL(result) = COL(map);

    NEFF(words) = 0;
    char line[50];
    while (fgets(line, sizeof(line), fp)){
        strcpy(ELMTL(words, NEFF(words)), line);
        NEFF(words)++;
    }

    for (int i = 0; i < NEFF(words)-1; i++){
        ELMTL(words, i)[strlen(ELMTL(words, i))-1] = '\0';
    }
    fclose(fp);
}

boolean search_east(int n){
    int currLen = strlen(ELMTL(words,n));
    for (int i = 0; i < ROW(map); i ++){
        for (int j = 0; j< COL(map); j++){
            int m = 0;
            count++;
            while ((m<currLen)&&(ELMT(map,i,j+m)==ELMTL(words,n)[m])){
                m++;
                count++;
            }
            if (m==currLen){
                for (int a = 0; a <ROW(result); a++){
                    for (int b = 0; b<COL(result); b++){
                        ELMT(result, a, b) = '-';
                    }
                }
                while (m != 0){
                    ELMT(result, i, j)=ELMT(map, i, j);
                    j++;
                    m--;
                }
                for (int i = 0; i <ROW(map); i++){
                    for (int j = 0; j<COL(map); j++){
                        printf("%c ",(ELMT(result, i, j)));
                    }
                    printf("\n");
                }
                printf("\n");
                return true;
            }
        }
    }
    return false;
}

boolean search_southeast(int n){
    int currLen = strlen(ELMTL(words,n));
    for (int i = 0; i < ROW(map); i ++){
        for (int j = 0; j< COL(map); j++){
            int m = 0;
            count++;
            while ((m<currLen)&&(ELMT(map,i+m,j+m)==ELMTL(words,n)[m])){
                m++;
                count++;
            }
            if (m==currLen){
                for (int a = 0; a <ROW(result); a++){
                    for (int b = 0; b<COL(result); b++){
                        ELMT(result, a, b) = '-';
                    }
                }
                while (m != 0){
                    ELMT(result, i, j)=ELMT(map, i, j);
                    i++;
                    j++;
                    m--;
                }
                for (int i = 0; i <ROW(map); i++){
                    for (int j = 0; j<COL(map); j++){
                        printf("%c ",(ELMT(result, i, j)));
                    }
                    printf("\n");
                }
                printf("\n");
                return true;
            }
        }
    }
    return false;
}

boolean search_south(int n){
    int currLen = strlen(ELMTL(words,n));
    for (int i = 0; i < ROW(map); i ++){
        for (int j = 0; j< COL(map); j++){
            int m = 0;
            count++;
            while ((m<currLen)&&(ELMT(map,i+m,j)==ELMTL(words,n)[m])){
                m++;
                count++;
            }
            if (m==currLen){
                for (int a = 0; a <ROW(result); a++){
                    for (int b = 0; b<COL(result); b++){
                        ELMT(result, a, b) = '-';
                    }
                }
                while (m != 0){
                    ELMT(result, i, j)=ELMT(map, i, j);
                    i++;
                    m--;
                }
                for (int i = 0; i <ROW(map); i++){
                    for (int j = 0; j<COL(map); j++){
                        printf("%c ",(ELMT(result, i, j)));
                    }
                    printf("\n");
                }
                printf("\n");
                return true;
            }
        }
    }
    return false;
}

boolean search_southwest(int n){
    int currLen = strlen(ELMTL(words,n));
    for (int i = 0; i < ROW(map); i ++){
        for (int j = 0; j< COL(map); j++){
            int m = 0;
            count++;
            while ((m<currLen)&&(ELMT(map,i+m,j-m)==ELMTL(words,n)[m])){
                count++;
                m++;
            }
            if (m==currLen){
                for (int a = 0; a <ROW(result); a++){
                    for (int b = 0; b<COL(result); b++){
                        ELMT(result, a, b) = '-';
                    }
                }
                while (m != 0){
                    ELMT(result, i, j)=ELMT(map, i, j);
                    i++;
                    j--;
                    m--;
                }
                for (int i = 0; i <ROW(map); i++){
                    for (int j = 0; j<COL(map); j++){
                        printf("%c ",(ELMT(result, i, j)));
                    }
                    printf("\n");
                }
                printf("\n");
                return true;
            }
        }
    }
    return false;
}

boolean search_west(int n){
    int currLen = strlen(ELMTL(words,n));
    for (int i = 0; i < ROW(map); i ++){
        for (int j = 0; j< COL(map); j++){
            int m = 0;
            count++;
            while ((m<currLen)&&(ELMT(map,i,j-m)==ELMTL(words,n)[m])){
                count++;
                m++;
            }
            if (m==currLen){
                for (int a = 0; a <ROW(result); a++){
                    for (int b = 0; b<COL(result); b++){
                        ELMT(result, a, b) = '-';
                    }
                }
                while (m != 0){
                    ELMT(result, i, j)=ELMT(map, i, j);
                    j--;
                    m--;
                }
                for (int i = 0; i <ROW(map); i++){
                    for (int j = 0; j<COL(map); j++){
                        printf("%c ",(ELMT(result, i, j)));
                    }
                    printf("\n");
                }
                printf("\n");
                return true;
            }
        }
    }
    return false;
}

boolean search_northwest(int n){
    int currLen = strlen(ELMTL(words,n));
    for (int i = 0; i < ROW(map); i ++){
        for (int j = 0; j< COL(map); j++){
            int m = 0;
            count++;
            while ((m<currLen)&&(ELMT(map,i-m,j-m)==ELMTL(words,n)[m])){
                count++;
                m++;
            }
            if (m==currLen){
                for (int a = 0; a <ROW(result); a++){
                    for (int b = 0; b<COL(result); b++){
                        ELMT(result, a, b) = '-';
                    }
                }
                while (m != 0){
                    ELMT(result, i, j)=ELMT(map, i, j);
                    i--;
                    j--;
                    m--;
                }
                for (int i = 0; i <ROW(map); i++){
                    for (int j = 0; j<COL(map); j++){
                        printf("%c ",(ELMT(result, i, j)));
                    }
                    printf("\n");
                }
                printf("\n");
                return true;
            }
        }
    }
    return false;
}

boolean search_north(int n){
    int currLen = strlen(ELMTL(words,n));
    for (int i = 0; i < ROW(map); i ++){
        for (int j = 0; j< COL(map); j++){
            int m = 0;
            count++;
            while ((m<currLen)&&(ELMT(map,i-m,j)==ELMTL(words,n)[m])){
                count++;
                m++;
            }
            if (m==currLen){
                for (int a = 0; a <ROW(result); a++){
                    for (int b = 0; b<COL(result); b++){
                        ELMT(result, a, b) = '-';
                    }
                }
                while (m != 0){
                    ELMT(result, i, j)=ELMT(map, i, j);
                    i--;
                    m--;
                }
                for (int i = 0; i <ROW(map); i++){
                    for (int j = 0; j<COL(map); j++){
                        printf("%c ",(ELMT(result, i, j)));
                    }
                    printf("\n");
                }
                printf("\n");
                return true;
            }
        }
    }
    return false;
}

boolean search_northeast(int n){
    int currLen = strlen(ELMTL(words,n));
    for (int i = 0; i < ROW(map); i ++){
        for (int j = 0; j< COL(map); j++){
            int m = 0;
            count++;
            while ((m<currLen)&&(ELMT(map,i-m,j+m)==ELMTL(words,n)[m])){
                count++;
                m++;
            }
            if (m==currLen){
                for (int a = 0; a <ROW(result); a++){
                    for (int b = 0; b<COL(result); b++){
                        ELMT(result, a, b) = '-';
                    }
                }
                while (m != 0){
                    ELMT(result, i, j)=ELMT(map, i, j);
                    i--;
                    j++;
                    m--;
                }
                for (int i = 0; i <ROW(map); i++){
                    for (int j = 0; j<COL(map); j++){
                        printf("%c ",(ELMT(result, i, j)));
                    }
                    printf("\n");
                }
                printf("\n");
                return true;
            }
        }
    }
    return false;
}

int main(){
    file_config();
    printf("\n");
    printf("berikut adalah puzzle yang akan diselesaikan: \n");
    for (int i = 0; i <ROW(map); i++){
        for (int j = 0; j<COL(map); j++){
            printf("%c ",(ELMT(map, i, j)));
        }
        printf("\n");
    }
    printf("\n");
    printf("\nberikut adalah kata yang akan dicari: \n");
    for (int i = 0; i <= NEFF(words); i++){
        printf("%s\n", ELMTL(words, i));
    }
    clock_t start_time = clock();
    for (int n = 0; n < NEFF(words); n++){
        search_east(n);
        search_north(n);
        search_northeast(n);
        search_northwest(n);
        search_south(n);
        search_southeast(n);
        search_southwest(n);
        search_west(n);
    }
    clock_t end_time = clock();
    printf("Jumlah perbandingan kata yang dicari: %d", count);
    printf("\n");
    double total = end_time-start_time;
    printf("Waktu running algoritma: %f detik", total/1000);
}