/*
   Happy Number Total Accepted: 22773 Total Submissions: 71916 My Submissions Question Solution 
   Write an algorithm to determine if a number is "happy".

   A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
 */

class Solution {
  public:
    bool isHappy(int n) {
      unordered_map<int, int> map;
      while(n != 1){
	int sum = 0;
	while(n > 0){
	  int digit = n % 10;
	  n /= 10;
	  sum += digit * digit;
	}
	n = sum;
	if (map.find(n) != map.end()) break;
	map[n] = 1;
      }
      return n == 1;
    }
};

// v2
class Solution {
public:
    bool isHappy(int n) {
        // 11:10 - 11:13
        unordered_set<int> set;
        
        while(n != 1) {
            set.insert(n);
            int next = 0;
            while(n) {
                int last = n % 10;
                n = n / 10;
                next += last * last;
            }
            if(set.find(next) != set.end()) {
                return false;
            }
            n = next;
        }
        
        return true;
    }
};
