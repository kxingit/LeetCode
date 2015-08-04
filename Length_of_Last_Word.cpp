/* 
 * Length of Last Word 
 */
class Solution {
  public:
    int lengthOfLastWord(string s) {
      int count = 0;
      for(int i = s.size() - 1; i >= 0; i--){
	if(s[i] == ' ') s.pop_back();
	else break;
      }
      for(int i = s.size() - 1; i >= 0; i--){
	if(s[i] == ' ') break;
	else count++;
      }
      return count;
    }
};
