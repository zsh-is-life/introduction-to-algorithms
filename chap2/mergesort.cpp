#include <iostream>
#include <cmath>
#include <vector>
void merge(std::vector<int>& A, int p, int q, int r){
	int nl = q - p + 1; // A[p:q]
	int nr = r - q; // A[q+1:r]
	std::vector<int> L;
	std::vector<int> R;
	for(int i = 0; i < nl; i++){
		L.push_back(A[p+i]);
	}
	for(int i = 0; i < nr; i++){
		R.push_back(A[q+1+i]);
	}
	int i = 0;
	int j = 0;
	int k = p;
	while(i < nl && j < nr){
		if (L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
			j++;
		}
		k++;
	}
	//Now, one of the two vectors is empty.
	//But we don't know which one.
	while(i < nl){
		A[k] = L[i];
		i++;
		k++;
	}
	while(j < nr){
		A[k] = R[j];
		j++;
		k++;
	}
	//Now L and R have been completely copied.
}

void merge_sort(std::vector<int>& A, int p, int r){
	if(p >= r)
		return;
	//Find midpoint
	int q = std::floor((p + r)/2);
    merge_sort(A, p, q);
	merge_sort(A, q+1, r);
	merge(A, p, q, r);	
}

int main(){
	std::vector<int> A = {12,3,7,9,14,6,11,2};
	int p = 0;
	int r = 7;
	merge_sort(A, p, r);
	for(int x : A){
		std::cout << x << '\t';
	}	
	return 0;
}
