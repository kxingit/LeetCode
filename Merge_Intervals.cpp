/*
 * Given a collection of intervals, merge all overlapping intervals.
 */
class Solution {
  public:
    vector<Interval> merge(vector<Interval>& intervals) {
      vector<Interval> result;
      if(intervals.size() == 0) return result;
      result.push_back(intervals[0]);
      for(int i = 1; i < intervals.size(); i++) {
	result = insert(result, intervals[i]);
      }
      return result;
    }
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
