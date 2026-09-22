#include <iostream>
using namespace std;

int main(){
    int A[] = {10, 2, 66};
    int B[] = {90, 11, 44};

    int n = 3;
    int m = 3;

    int C[6];

    int i = 0;
    int j = 0;
    int k = 0;


    while(i < n && j < m){

        if(A[i] < B[j]){
            C[k] = A[i];
            i++;
        }
        else {
            C[k] = B[j];
            j++;
        }
        k++;
    }

    while(i < n){
        C[k] = A[i];
        i++;
        k++;
    }

    while( j < m){
        C[k] = B[j];
        j++;
        k++;
    }

     for(int x = 0; x < n + m; x++) {
        cout << C[x] << " ";
    }

    return 0;
}