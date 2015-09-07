/*
 * tag
 * Given an array of citations (each citation is a non-negative integer) of a researcher, 
 * write a function to compute the researcher's h-index.
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
      for (int i = 0; i < citations.size(); i++) {
	if (i >= citations[i]) return i;
      }
      return citations.size();
    }
};
