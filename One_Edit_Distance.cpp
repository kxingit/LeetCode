class Solution {
  public:
    bool isOneEditDistance(string s, string t) {
      if(s.size() == 0 && t.size() == 0) return 0;
      int count = 0;
      int i, j;
      if(s.size() == t.size()){
	i = 0; j = 0;
	while(i < s.size() && j < t.size()){
	  if(s[i] != t[i]) count ++;
	  i++;
	  j++;
	}
	if(count == 1) return 1;
      }
      else if(abs(int(s.size()) - int(t.size())) == 1){ // extra attention!! unsign_int
	if(s.size() < t.size()){
	  return isOneEditDistance(t, s);
	}
	count = 0;
	i = 0; j = 0;
	while(i < s.size()){
	  if(s[i] != t[j]){
	    i++;
	    count++;
	  }
	  else{
	    i++;
	    j++;
	  }
	}
	if(count == 1) return 1;
      }
      return 0;
    }
};
