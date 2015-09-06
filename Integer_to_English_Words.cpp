/*
 * tag
 * Convert a non-negative integer to its english words representation. 
 * Given input is guaranteed to be less than 2^31 - 1.
 */
class Solution {
  public:
    string getWord(int num, string *digit, string *digit1) {
      if (num == 0) return "Zero";
      string res;
      int h = num / 100;
      num %= 100;
      if (h > 0) res += digit[h] + " Hundred";
      if (num == 0) return res;
      else if (h > 0) res += " ";
      if (num < 20) {
	res += digit[num];
      } else {
	h = num / 10;
	num %= 10;
	res += digit1[h];
	if (num != 0) res += " " + digit[num];
      }
      return res;
    }
    string numberToWords(int num) {
      if (num == 0) return "Zero";
      string digit[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
	"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
      };
      string digit1[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
      string digit2[10] = {"", "Thousand", "Million", "Billion"};
      vector<string> words;
      string str;
      int num2, cnt = 0;
      while (num != 0) {
	num2 = num % 1000;
	str = getWord(num2, digit, digit1);
	if (str != "Zero") {
	  if (cnt > 0) words.push_back(str + " " + digit2[cnt]);
	  else words.push_back(str);
	}
	num /= 1000;
	++cnt;
      }
      string res;
      for (int i = (int)words.size() - 1; i > 0; --i) {
	res += words[i] + " ";
      }
      res += words.front();
      return res;
    }
};
