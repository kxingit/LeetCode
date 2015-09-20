/*
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 */
class Solution {
  public:
    int maxPoints(vector<Point>& points) {
      if(points.size() <= 2) return points.size();
      int res = 0;
      double slope = 0;
      for(int i = 0; i < points.size() - 1; i++) {
	map<double, int> count;
	int inf = 0;
	int same = 1;
	for(int j = i + 1; j < points.size(); j++) {
	  if(points[j].x - points[i].x == 0 && points[j].y - points[i].y == 0) {
	    same++;
	  }
	  else if(points[j].x - points[i].x == 0) {
	    slope = INT_MAX;
	    count[slope]++;
	  }
	  else {
	    slope = ((double)points[j].y - points[i].y) / (points[j].x - points[i].x);
	    count[slope]++;
	  }
	}
	for(auto c : count) {
	  res = max(res, c.second + same);
	}
	res = max(res, same); // if empty map
      }
      return res;
    }
};

