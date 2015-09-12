/*
 * tag
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 */
class Solution {
  public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
      vector<Interval> res;
      vector<Interval>::iterator it;  
      for (it = intervals.begin();it!=intervals.end();it++){
	if (newInterval.start<(*it).start){
	  intervals.insert(it,newInterval);
	  break;
	}
      }    
      if (it==intervals.end()){intervals.insert(it,newInterval);}
      if (intervals.empty()) {return res;}
      res.push_back(*intervals.begin());
      for (it = intervals.begin()+1;it!=intervals.end();it++){
	if ((*it).start>res.back().end){res.push_back(*it);}
	else{ res.back().end = max(res.back().end,(*it).end);}
      }
      return res;
    }
};
