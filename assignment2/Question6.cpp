//(a) transpose of matrix

#include <iostream>
using namespace std;
void display(int sparsemat[7][3]){
    for(int i = 0;i<7;i++){
       cout<<sparsemat[i][0]<<" ";
        cout<<sparsemat[i][1]<<" ";
         cout<<sparsemat[i][2]<<" "<<endl;
    }
}
void transpose(int sparsemat[7][3]){
    int n = 1;
    for(int i = 1;i<5;i++){
        for(int j = i;j<7;j++){
            if(sparsemat[j][1]==i-1){
                swap(sparsemat[j][0],sparsemat[j][1]);
                 swap(sparsemat[j][0],sparsemat[n][0]);
                  swap(sparsemat[j][1],sparsemat[n][1]);
                   swap(sparsemat[j][2],sparsemat[n][2]);
                   n++;
            }
        }
    }
}
int main(){
    int ogmat[4][4] = {
        {20,0,0,12},
        {0,0,11,0},
        {0,0,0,35},
        {25,10,0,0}};
        int sparsemat[7][3] = {
            {4,4,6},
            {0,0,20},
            {0,3,12},
            {1,2,11},
            {2,3,35},
            {3,0,25},
            {3,1,10}
            
        };
        transpose(sparsemat);
        display(sparsemat);
        return 0;
}



//(b) Addition of two matrices. 

#include <iostream>
using namespace std;

void display(int mat[][3], int terms) {
    cout << "Row Col Val\n";
    for (int i = 0; i <= terms; i++) {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
    }
}

void addSparse(int A[][3], int B[][3], int result[][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Matrices dimensions do not match, cannot add!\n";
        return;
    }

    int termsA = A[0][2], termsB = B[0][2];
    int i = 1, j = 1, k = 1;

    while (i <= termsA && j <= termsB) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            result[k][0] = A[i][0];
            result[k][1] = A[i][1];
            result[k][2] = A[i][2];
            i++; k++;
        }
        else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            result[k][0] = B[j][0];
            result[k][1] = B[j][1];
            result[k][2] = B[j][2];
            j++; k++;
        }
        else { 
            int val = A[i][2] + B[j][2];
            if (val != 0) { // store only non-zeros
                result[k][0] = A[i][0];
                result[k][1] = A[i][1];
                result[k][2] = val;
                k++;
            }
            i++; j++;
        }
    }
    while (i <= termsA) {
        result[k][0] = A[i][0];
        result[k][1] = A[i][1];
        result[k][2] = A[i][2];
        i++; k++;
    }


    while (j <= termsB) {
        result[k][0] = B[j][0];
        result[k][1] = B[j][1];
        result[k][2] = B[j][2];
        j++; k++;
    }

    result[0][0] = A[0][0];   
    result[0][1] = A[0][1];   
    result[0][2] = k - 1;     
}

int main() {
    int sparseA[7][3] = {
        {4,4,6},
        {0,0,20},
        {0,3,12},
        {1,2,11},
        {2,3,35},
        {3,0,25},
        {3,1,10}
    };

    int sparseB[6][3] = {
        {4,4,5},
        {0,3,10},
        {1,1,15},
        {2,0,20},
        {2,3,25},
        {3,3,40}
    };

    int sum[20][3]; 

    addSparse(sparseA, sparseB, sum);

    cout << "Matrix A (Triplet):\n";
    display(sparseA, sparseA[0][2]);

    cout << "\nMatrix B (Triplet):\n";
    display(sparseB, sparseB[0][2]);

    cout << "\nSum of A and B (Triplet):\n";
    display(sum, sum[0][2]);

    return 0;
}


//(c) Multiplication of two matrices.

#include <iostream>
using namespace std;

void display(int mat[][3], int terms) {
    cout << "Row Col Val\n";
    for (int i = 0; i <= terms; i++) {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
    }
}


void multiply(int A[][3], int B[][3], int product[][3]) {
    int rowsA = A[0][0], colsA = A[0][1], termsA = A[0][2];
    int rowsB = B[0][0], colsB = B[0][1], termsB = B[0][2];

    
    int B_T[50][3];
    B_T[0][0] = colsB;
    B_T[0][1] = rowsB;
    B_T[0][2] = termsB;

    int k = 1;
    for (int col = 0; col < colsB; col++) {
        for (int i = 1; i <= termsB; i++) {
            if (B[i][1] == col) {
                B_T[k][0] = B[i][1];
                B_T[k][1] = B[i][0];
                B_T[k][2] = B[i][2];
                k++;
            }
        }
    }

    int idx = 1;
    for (int i = 1; i <= termsA; i++) {
        for (int j = 1; j <= termsB; j++) {
            if (A[i][1] == B[j][0]) {
                product[idx][0] = A[i][0];
                product[idx][1] = B[j][1];
                product[idx][2] = A[i][2] * B[j][2];
                idx++;
            }
        }
    }

    product[0][0] = rowsA;
    product[0][1] = colsB;
    product[0][2] = idx - 1;
}

int main() {
    int sparsemat[7][3] = {
        {4,4,6},
        {0,0,20},
        {0,3,12},
        {1,2,11},
        {2,3,35},
        {3,0,25},
        {3,1,10}
    };

    int sparsemat1[6][3] = {
        {4,4,5},
        {0,3,10},
        {1,1,15},
        {2,0,20},
        {2,3,25},
        {3,3,40}
    };

    int product[50][3]; 

    multiply(sparsemat, sparsemat1, product);

    cout << "Matrix A (triplet form):\n";
    display(sparsemat, sparsemat[0][2]);

    cout << "\nMatrix B (triplet form):\n";
    display(sparsemat1, sparsemat1[0][2]);

    cout << "\nProduct Matrix (triplet form):\n";
    display(product, product[0][2]);

    return 0;
}
