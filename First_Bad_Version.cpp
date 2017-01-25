/*
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
 */
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
  public:
    int firstBadVersion(int n) {
      int start = 1, end = n;
      while(start < end) {
	int mid = start + (end - start) / 2; // overflow
	if(isBadVersion(mid)) {
	  end = mid;
	}
	else {
	  start = mid + 1;
	}
      }
      return start;
    }
};
// template
class Solution {
  public:
    int firstBadVersion(int n) {
      int start = 1, end = n;
      while(start + 1 < end) {
	int mid = start + (end - start) / 2; // overflow
	if(isBadVersion(mid)) {
	  end = mid;
	}
	else {
	  start = mid;
	}
      }
	  if(isBadVersion(start)) return start;
	  else return end;
	}
};

// v3
class Solution {
  public:
	int firstBadVersion(int n) {
	  int start = 1, end = n;
	  while (start + 1 < end) {
		int mid = start + (end - start) / 2;
		if(isBadVersion(mid)) {
		  end = mid;
		} else {
		  start = mid;
		}
	  }
	  return isBadVersion(start) ? start : end;
	}
};
