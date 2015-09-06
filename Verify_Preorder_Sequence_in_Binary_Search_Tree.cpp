/*
 * tag
 * Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
 */
// Time Limit Exceeded
class Solution {
  public:
    bool verifyPreorder(vector<int>& preorder) {
      return isPreorder(0, preorder.size() - 1, preorder);
    }
    bool isPreorder(int start, int end, vector<int> &preorder){
      if(start >= end) return true;
      int pivot = -1;
      for(int i = start; i <= end; i++) {
	if(preorder[i] > preorder[start]) { // i is root
	  pivot = i;
	  break;
	}
      }
      if(pivot = -1) {
	if(isPreorder(start + 1, end, preorder)) return true;
	else return false;
      }
      if(isPreorder(start + 1, pivot - 1, preorder) && isPreorder(pivot + 1, end, preorder)) {
	return true;
      }
      else {
	return false;
      }
    }
};
// v2
class Solution {
  public:
    bool verifyPreorder(vector<int>& preorder) {
      int low = INT_MIN, i = -1;
      for (int p : preorder) {
	if (p < low)
	  return false;
	while (i >= 0 && p > preorder[i])
	  low = preorder[i--];
	preorder[++i] = p;
      }
      return true;
    }
};
// v3
class Solution {
  public:
    bool verifyPreorder(vector<int>& preorder) {
      int low = INT_MIN;
      stack<int> path;
      for (int p : preorder) {
	if (p < low)
	  return false;
	while (!path.empty() && p > path.top()){
	  low = path.top();
	  path.pop();
	}
	path.push(p);
      }
      return true;
    }
};

