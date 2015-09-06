/*
 * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
 * determine if a person could attend all meetings.
 */
// brutal force. Time Limit Exceeded
class Solution {
  public:
    bool canAttendMeetings(vector<Interval>& intervals) {
      for(int i = 0; i < intervals.size(); i++){
	for(int j = 0; j < intervals.size(); j++){
	  if(intervals[i].start > intervals[j].start && intervals[i].start < intervals[j].end)
	    return false;
	}
      }
      return true;
    }
};
// v2, sort first
class Solution {
  public:
    bool canAttendMeetings(vector<Interval>& intervals) {
      if(intervals.size() == 0) return true;
      sort(intervals.begin(), intervals.end(), sortStart);
      for(int i = 0; i < intervals.size() - 1; i++){
	if(intervals[i].end > intervals[i + 1].start) return false;
      }
      return true;
    }
    static bool sortStart(Interval &i1, Interval &i2){
      return i1.start < i2.start;
    }
};
