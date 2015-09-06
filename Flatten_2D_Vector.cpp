/*
 * Implement an iterator to flatten a 2d vector.
 */
class Vector2D {
  public:
    vector<int> vec;
    Vector2D(vector<vector<int>>& vec2d) {
      for(int i = 0; i < vec2d.size(); i++){
	for(int j = 0; j < vec2d[i].size(); j++){
	  vec.push_back(vec2d[i][j]);
	}
      }
    }

    int next() {
      int temp = vec[0];
      vec.erase(vec.begin());
      return temp;
    }

    bool hasNext() {
      if(vec.size()) return true;
    }
};
