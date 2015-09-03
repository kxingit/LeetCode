/*
 * Given n non-negative integers representing the histogram's 
 * bar height where the width of each bar is 1, 
 * find the area of largest rectangle in the histogram.
 *
 */
class Solution {
  public:
    int largestRectangleArea(vector<int>& height) {
      stack<int> S;
      height.push_back(0);
      int sum = 0;
      for (int i = 0; i < height.size(); i++) {
	if (S.empty() || height[i] > height[S.top()]) S.push(i);
	else {
	  int tmp = S.top();
	  S.pop();
	  sum = max(sum, height[tmp]*(S.empty()? i : i-S.top()-1));
	  i--;
	}
      }
      return sum;
    }
};
// brutal force O(n^2)
class Solution {
  public:
    int largestRectangleArea(vector<int>& height) {
      int result = 0;
      for(int i = 0; i < height.size(); i++){
	int h = INT_MAX; // current height
	for(int j = i; j >= 0; j--){
	  h = min(h, height[j]);
	  result = max(result, h * (i - j + 1));
	}
      }
      return result;
    }
};
// pruning O(n^2)
class Solution {
  public:
    int largestRectangleArea(vector<int>& height) {
      int result = 0;
      for(int i = 0; i < height.size(); i++){
	if(i < height.size() - 1 && height[i] <= height[i + 1]){
	  continue;
	}
	int h = INT_MAX; // current height
	for(int j = i; j >= 0; j--){
	  h = min(h, height[j]);
	  result = max(result, h * (i - j + 1));
	}
      }
      return result;
    }
};
// v4
class Solution {
  public:
    int largestRectangleArea(vector<int>& height) {
      stack<int> s;
      height.push_back(0);
      int result = 0;
      for(int i = 0; i < height.size(); i++){
	if(s.empty() || height[i] > height[s.top()]) s.push(i);
	else{
	  int tmp = s.top();
	  s.pop();
	  int width = s.empty() ? i : i - s.top() - 1;
	  int area = height[tmp] * width;
	  result = max(result, area);
	  i--;
	}
      }
      return result;
    }
};
// v5
class Solution {
  public:
    int largestRectangleArea(vector<int>& height) {
      height.push_back(0);
      stack<int> s; // save increasing indeces
      int result = 0;
      for(int i = 0; i < height.size(); i++){
	if(s.empty() || height[i] > height[s.top()]) s.push(i);
	else{
	  int tmpi = s.top();
	  s.pop();
	  int width = s.empty() ? i : i - s.top() - 1;
	  int h = height[tmpi];
	  result = max(result, h * width);
	  i--;
	}
      }
      return result;
    }
};
// v6
ass Solution {
  public:
    int largestRectangleArea(vector<int>& height) {
      stack<int> s; // save increasing indeces
      int result = 0;
      height.push_back(0);
      for(int i = 0; i < height.size(); i++){
	if(s.empty() || height[i] > height[s.top()]) s.push(i);
	else{
	  int tmpi = s.top(); // top index
	  s.pop();
	  int h = height[tmpi];
	  int width = s.empty() ? i : i - s.top() - 1;
	  result = max(result, h * width);
	  i--; // try the previous stack top
	}
      }
      return result;
    }
};
