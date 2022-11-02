/*
    Input: sequence of n numbers
    Output: permutation of above sequence, such that the numbers are in increasing order
    Numbers are "keys"
    Other info attached to keys are "Satellite data"
    Together, they form a "record"
    
    Algo is good for sorting small number of elements. Pick one by one from input array, arrange correctly in second array.
*/

#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& A){
    for(int i = 1; i < A.size(); i++){
        int key = A[i];
        int j = i - 1;      // Previous term
        while(j > -1 && A[j] > key){ //Previous term is valid and is greater than next term, then... [_, 7, 5, 2, _,  _]
            A[j+1] = A[j];  // Replace next term with previous term [_, 7, 5, 5, _, _]
            j = j - 1;  // Go to previous-previous term, check again now with key. 
        }
        A[j + 1] = key;
    }
}

int main() {
    std::vector<int> A = {31, 41, 59, 26, 41, 58};
    insertion_sort(A);
    for(int x : A){
        std::cout << x << '\t';
    }
    std::cout << '\n';
    return 0;
}