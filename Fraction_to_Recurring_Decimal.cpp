/*
 * Given two integers representing the numerator and denominator of a fraction, 
 * return the fraction in string format.
 * If the fractional part is repeating, enclose the repeating part in parentheses.
 */
class Solution {
  public:
    string fractionToDecimal(int numerator, int denominator) {
      if(numerator == 0) return "0";
      long long n = numerator, d = denominator;
      string result;
      if(n < 0 ^ d < 0) result += "-";
      n = abs(n);
      d = abs(d);
      result += to_string(n / d);
      long long mod = n % d;
      if(mod == 0) return result;
      else result += ".";
      unordered_map<int, int> map;
      while(mod) {
	if(map.find(mod) != map.end()) {
	  result.insert(map[mod], "(");
	  result += ")";
	  return result;
	}
	map[mod] = result.size();
	mod *= 10;
	result += to_string(mod / d);
	mod = mod % d;
      }
      return result;
    }
};
// v2
class Solution {
  public:
    string fractionToDecimal(int numerator, int denominator) {
      if(!numerator) return "0";
      string result;
      long long n = numerator, d = denominator;
      if(double(n) / d < 0) result += "-";
      n = abs(n);
      d = abs(d);
      long long num = n / d;
      result += to_string(num);
      long long mod = n % d;
      if(!mod) return result;
      result += ".";
      unordered_map<int, int> map;
      while(mod) {
	if(map.find(mod) != map.end()) {
	  result.insert(map[mod], "(");
	  result += ")";
	  return result;
	}
	map[mod] = result.size();
	mod = mod * 10;
	result += to_string(mod / d);
	mod = mod % d;
      }
      return result;
    }
};
