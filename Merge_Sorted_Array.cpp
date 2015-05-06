class Solution {
  public:
    void merge(int A[], int m, int B[], int n) {
      int i = m - 1, j = n - 1, ie = m + n - 1;
      while(i >= 0 && j >= 0){
	if(A[i] > B[j]) A[ie] = A[i--];
	else A[ie] = B[j--];
	ie--;
      }
      while(j >= 0) A[ie--] = B[j--];
    }
};
