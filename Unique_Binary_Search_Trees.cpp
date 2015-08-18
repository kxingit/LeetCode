/*
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 */
class Solution {
  public:
    int numTrees(int n) {
      vector<int> f(n + 1, 0); // should include ""

      f[0] = 1;
      f[1] = 1;
      for (int i = 2; i <= n; i++) {
	for (int k = 0; k < i; k++){
	  f[i] += f[k] * f[i - 1 - k];  // split to a tree with 0 to k - 1, and a tree with k + 1 to i - 1
	}
      }
      return f[n];
    }
};
