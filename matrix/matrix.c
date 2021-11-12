/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#include <stdio.h>
#include "matrix.h"

/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow, int nCol, Matrix *m){
  ROWS(*m) = nRow;
  COLS(*m) = nCol;
}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j){
  return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m){
  return ROWS(m) - 1;
}
/* Mengirimkan Index baris terbesar m */
Index getLastIdxCol(Matrix m){
  return COLS(m) - 1;
}
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, Index i, Index j){
  return(i >= 0 && i < ROWS(m) && j >= 0 && j < COLS(m));
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, Index i){
  return ELMT(m, i, i);
}
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes){
  CreateMatrix(ROWS(mIn), COLS(mIn), mRes);
  for(int i = 0; i < ROWS(mIn); i++){
    for(int j = 0; j < COLS(mIn); j++){
      ELMT(*mRes, i, j) = ELMT(mIn, i, j);
    }
  }
}
/* Melakukan assignment MRes = MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
  CreateMatrix(nRow, nCol, m);
  for(int i = 0; i < nRow; i++){
    for(int j = 0; j < nCol; j++){
      int x;
      scanf("%d", &x);
      ELMT(*m, i, j) = x;
    }
  }
}
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void displayMatrix(Matrix m){
  for(int i = 0; i < ROWS(m); i++){
    for(int j = 0; j < COLS(m); j++){
      printf("%d", ELMT(m, i, j));
      if(j != COLS(m) - 1){
        printf(" ");
      }
    }
    if(i != ROWS(m) - 1){
      printf("\n");
    }
  }
}

boolean isLocationConnected(Matrix m, Index loc1, Index loc2){
    return ELMT(m,loc1,loc2)==1 || ELMT(m,loc2,loc1);
}

void printMap(Matrix m, Index x , Index y){
    for(int j=0;j<COLS(m)+2;j++){
        printf("*");
    }
    printf("\n");
    for(int i=0;i<ROWS(m);i++){
        printf("*");
        for(int j=0;j<COLS(m);j++){
            //jika connected dengan posisi nobita saat ini
            // kamu harus cek di koordinat i,j itu ada bangunan apa melalui arrdin
            if(true){

            }
        }
        printf("*\n");
    }
}