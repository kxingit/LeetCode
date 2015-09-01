/*
 * The API: int read4(char *buf) reads 4 characters at a time from a file.
 * The return value is the actual number of characters read. 
 * For example, it returns 3 if there is only 3 characters left in the file.
 */
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
  public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
      int curlen;
      int len = 0;
      while(len <= n - 4){
	curlen = read4(buf + len);
	len += curlen;
	if(curlen < 4) return len;
      }
      char* remain = new char[4];
      int remainlen = read4(remain);
      remainlen = min(remainlen, n - len);
      for(int i = 0; i < remainlen; i++){
	buf[len] = remain[i];
	len++;
      }
      return len;
    }
};
