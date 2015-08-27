/*
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 */
// time limit exceeded. many string copys
class Solution {
  public:
    int compareVersion(string version1, string version2) {
      while(version1.size() || version2.size()){
	int v1 = getHighest(version1);
	int v2 = getHighest(version2);
	if(v1 > v2) return 1;
	if(v1 < v2) return -1;
      }
      return 0;
    }
    int getHighest(string& version){ // return highest level version #, and chop version #
      int n = version.size();
      int v1 = 0, n1 = 0; // highest version # and its length
      int i = 0;
      while(i < n){
	if(version[i] != '.') {
	  v1 = v1 * 10 + version[i] - '0';
	  n1++;
	}
	else{
	  break;
	}
	i++;
      }
      version.erase(version.begin(), version.begin() + n1 - 1);
      if(i < n - 1) version.erase(version.begin(), version.begin()); // remove '.'
      return v1;
    }
};
// O(n)
class Solution {
  public:
    int compareVersion(string version1, string version2) {
      int i = 0, j = 0;
      while(i < version1.size() || j < version2.size()){
	int v1 = 0, v2 = 0; // highest version #
	while(version1[i] != '.' && i < version1.size()){
	  v1 = v1 * 10 + version1[i] - '0';
	  i++;
	} 
	i++;
	while(version2[j] != '.' && j < version2.size()){
	  v2 = v2 * 10 + version2[j] - '0';
	  j++;
	}
	j++;
	if(v1 > v2) return 1;
	if(v1 < v2) return -1;
      }
      return 0;
    }
};
