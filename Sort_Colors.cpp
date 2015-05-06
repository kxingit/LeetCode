class Solution {
  public:
    void sortColors(int A[], int n) {
      int is = 0, ie = n -1, i = 0;
      while(i < ie + 1){
	if(A[i] == 0){
	  std::swap(A[i], A[is]);
	  is++;
	}
	else if(A[i] == 2){
	  std::swap(A[i], A[ie]);
	  ie--;
	  continue;
	}
	i++;
      }
    }
};
