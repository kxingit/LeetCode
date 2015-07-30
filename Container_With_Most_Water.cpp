class Solution {
  public:
    int maxArea(vector<int> &height) {
      // if moving the shorter bar inside and refresh the max
      int istart = 0, iend = height.size() - 1;
      int result = 0;
      while(istart < iend){
	result = max(result, min(height[istart], height[iend])*(iend-istart));
	if(height[istart] < height[iend]) istart++;
	else iend--;
      }
      return result;
    }
};
