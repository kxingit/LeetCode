/*
 * tag
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 * Find all strobogrammatic numbers that are of length = n.
 */
class Solution {
  public:
    vector<string> findStrobogrammatic(int n) {
      vector<string> strobos;
      if (n & 1) strobos = {"0", "1", "8"};
      else strobos = {""};
      vector<string> bases = {"00", "11", "88", "69", "96"};
      int m = bases.size(); 
      while (n > 1) {
	n -= 2;
	vector<string> temp;
	for (string strobo : strobos){
	  for (int i = (n < 2 ? 1 : 0); i < m; i++)
	    temp.push_back(bases[i].substr(0, 1) + strobo + bases[i].substr(1));
	  swap(temp, strobos);
	}
      }
      return strobos;
    }
};
// recursion
class Solution {
  public:
    vector<string> findStrobogrammatic(int n) {
      return helper(n, n);
    }
    vector<string> helper(int n, int target) {
      vector<string> result;
      vector<pair<string, string>> pairStrobo = 
      {{"0", "0"}, {"1", "1"}, {"6", "9"}, {"8", "8"}, {"9", "6"}};
      vector<string> strobo = {"0", "1", "8"};
      if(n == 0){
	return result;  
      } 
      if(n == 1) {
	for(auto p : strobo){
	  result.push_back(p);
	}
	return result;
      }
      if(n == 2) {
	for(auto ps : pairStrobo){
	  if(target == n && ps.first == "0") continue;
	  result.push_back(ps.first + ps.second);
	}
	return result;
      }
      vector<string> temp = helper(n - 2, target);
      for(auto p : temp) {
	for(auto ps : pairStrobo) {
	  if(target == n && ps.first == "0") continue;
	  result.push_back(ps.first + p + ps.second);
	}
      }
      return result;
    }

};
