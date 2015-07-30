class Solution {
  public:
    bool isPalindrome(int x) {
      if (x < 0) return false;
      int end = 1;
      int x2 = x;
      while(x2 / 10 != 0) {
	x2 = x2 / 10;
	end *= 10;
      }
      while(x > 0) {
	if(x / end != x % 10) return false;
	x = x % end;
	x = x / 10;
	end /= 100;
      }
      return true;
    }
};
