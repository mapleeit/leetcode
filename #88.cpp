#include <iostream>

using namespace std;

void merge(int A[], int m, int B[], int n){
	while(n >= 1 || m >= 1){
        A[n + m - 1] = n < 1 || (m >= 1 && A[m - 1] > B[n - 1]) ? A[--m] : B[--n];
    }
}

int main(){

}