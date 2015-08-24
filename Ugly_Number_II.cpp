/*
 * Write a program to find the n-th ugly number.
 * Hint: The key is how to maintain the order of the ugly numbers. 
 * Try a similar approach of merging from three sorted lists: L1, L2, and L3.
 * Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
 */
class Solution {
  public:
    int nthUglyNumber(int n) {
      int pos2 = 0, pos3 = 0, pos5 = 0;
      vector<int> res(n, 1);

      for (int i = 1; i < n; i++) {
	res[i] = min(res[pos2] * 2, min(res[pos3] * 3, res[pos5] * 5));
	if (res[i] == res[pos2] * 2) {
	  pos2++;
	}
	if (res[i] == res[pos3] * 3) {
	  pos3++;
	}
	if (res[i] == res[pos5] * 5) {
	  pos5++;
	}
      }

      return res[n-1];
    }
};
