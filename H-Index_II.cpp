/*
 * Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
 * Expected runtime complexity is in O(log n) and the input is sorted.
 */
// O(n^2) 
class Solution {
  public:
    int hIndex(vector<int>& citations) {
      int result = 0;
      for(int h = 0; h <= citations.size(); h++){
	int nHpapers = 0;
	for(int i = 0; i < citations.size(); i++){
	  if(citations[i] >= h) nHpapers++;
	}
	if(nHpapers >= h) result = max(result, h);
      }
      return result;
    }
};
// O(nlogn)
class Solution {
  public:
    int hIndex(vector<int>& citations) {
      sort(citations.begin(), citations.end(), greater<int>());
      for (int i = 0; i < citations.size(); ++i) {
	if (i >= citations[i]) return i;
      }
      return citations.size();
    }
};
// O(logn)
class Solution {
  public:
    int hIndex(vector<int>& citations) {
      int len = citations.size(), left = 0, right = len - 1;
      while (left <= right) {
	int mid = 0.5 * (left + right);
	if (citations[mid] == len - mid) return len - mid;
	else if (citations[mid] > len - mid) right = mid - 1;
	else left = mid + 1;
      }
      return len - left;
    }
};
