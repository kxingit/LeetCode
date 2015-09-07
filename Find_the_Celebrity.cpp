/*
 * Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity. 
 * The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.
 */
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
  public:
    int findCelebrity(int n) {
      int i = 0, j = n - 1;
      while(i < j){
	if(knows(i, j)) i++;
	else j--;
      }
      for(int k = 0; k < n; k++){
	if(k == i) continue;
	if(knows(i, k)) return -1;
	if(!knows(k, i)) return -1;
      }
      return i;
    }
};
