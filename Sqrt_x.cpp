class Solution {
  public:
    int mySqrt(int x) {
      long long i = 0, j = x / 2 + 1; // use long long from the beginning
      while(i <= j){
	long long k = (i + j) / 2; 
	long long sq = k * k; // use long long for int*int
	if(sq == x){
	  return k;
	}
	else if(sq > x){
	  j = k - 1;
	}
	else if(sq < x){
	  i = k + 1;
	}
      }
      return i - 1; // !!! need to return j or i - 1
    }
};
