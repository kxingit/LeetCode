/*
 * Implement pow(x, n).
 */
class Solution {
  public:
    double myPow(double x, int n) {
      // if(n < 0) return 1. / myPow(x, -n); // Runtime Error?? 
      // if n = – 2147483648, -n is still – 2147483648
      if(n == 0) return 1.0;
      double half = myPow(x, n / 2);
      if(n % 2 == 0) return half * half; // % not /
      else if(n > 0) return half * half * x;
      else return half * half / x;
    }
};
