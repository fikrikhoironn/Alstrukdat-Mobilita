/* File: matrix.h */
/* File to store ADT Matrix */

#ifndef MATRIX_H
#define MATRIX_H

#include<stdlib.h>
#include<stdio.h>
#include"boolean.h"
#include "../arraydin/arraydin.h"
#include "../time/time.h"
#include "../pcolor/pcolor.h"
#include "../linkedlist/linkedlist.h"
#include "../stack/stack.h"

#define CAPACITY1 100
#define COL_CAP 100
#define ROW_CAP 100
#define ROWS(M) (M).rowEff
#define COLS(M) (M).colEff
#define ELMT(M,i,j) (M).buffer[i][j]

typedef int ElType;
typedef int Index;
typedef struct Matrix{
  ElType buffer[ROW_CAP+1][COL_CAP+1];
  int rowEff;
  int colEff;
}Matrix;


/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void CreateMatrix(int nRow,int nCol, Matrix *m);
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */


/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j);

/** Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
Index getLastIdxRow(Matrix m);

/* Mengirimkan Index baris terbesar m */
Index getLastIdxCol(Matrix m);

/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, Index i, Index j);

/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, Index i);

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes);

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol);

/* Check and Debugging Stuff*/
/*isplayin Matrix*/
void displayMatrix(Matrix m);

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isLocationConnected(Matrix m, Index loc1, Index loc2);

/* mencetak peta berdasrkan kooridnat saat itu */
void printMap(linkedList toDoList ,Matrix m, ArrayBuild arrBuild ,int x , int y,time t, stack bag);


#endif