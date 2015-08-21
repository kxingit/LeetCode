/*
 * Given two binary strings, return their sum (also a binary string).
 */
class Solution {
  public:
    string addBinary(string a, string b) {
      int i = a.size(), j = b.size();
      int digit = 0, carry = 0;
      string result;
      while(i > 0 || j > 0) {
	i--; j--;
	if(i >= 0 && j >= 0) digit = a[i] - '0' + b[j] - '0';
	else if(i >=0) digit = a[i] - '0';
	else digit = b[j] - '0';
	digit += carry;
	carry = digit / 2;
	digit = digit % 2;
	result.insert(result.begin(), digit + '0');
      }
      if(carry) result.insert(result.begin(), carry + '0');
      return result;
    }
};
