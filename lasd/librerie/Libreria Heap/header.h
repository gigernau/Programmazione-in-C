#define MAX 32


/*===========================================================
Libreria per alberi Heap e relative funzioni di utilizzo

Autori: Gianluca De Lucia (N86001826)
        Carlo Mennella    (N86001552)
        
A.A  2016/2017
=============================================================*/


int left(int i);
int right(int i);
int p(int i);
void swap(int A[], int i, int j);
void Heapify(int A[], int i,int);
void BuildHeap(int A[],int);
void HeapSort(int A[],int);
int Min (int A[],int);
int Max (int A[], int);
int IsEmpty(int);
void Insert (int A[],int * );
void Delete (int A[],int indelement,int *);
void size (int );

