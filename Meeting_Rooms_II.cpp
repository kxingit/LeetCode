/*
 * tag
 * find the minimum number of conference rooms required.
 */
class Solution {
  public:
    int minMeetingRooms(vector<Interval>& intervals) {
      map<int, int> changes;//sorted by keys.
      for(auto i:intervals){
	changes[i.start]++;
	changes[i.end]--;
      }
      int rooms = 0, min_rooms = 0;
      for(auto c:changes){
	rooms += c.second;
	min_rooms = max(min_rooms, rooms);
      }
      return min_rooms;
    }
};
// v2
class Solution {
  public:
    int minMeetingRooms(vector<Interval>& intervals) {
      sort(intervals.begin(), intervals.end(), comp);
      vector<Interval> rooms; // save the last meeting interval of each room
      for(auto meeting : intervals){
	int iroom = findRoom(meeting, rooms);
	if(iroom == - 1){
	  rooms.push_back(meeting);
	}
	else{
	  rooms[iroom] = meeting;
	}
      }
      return rooms.size();
    }
    static bool comp(Interval &a, Interval &b){
      return a.start < b.start;
    }
    int findRoom(Interval &meeting, vector<Interval> &rooms){
      for(int i = 0; i < rooms.size(); i++){
	if(meeting.start >= rooms[i].end) return i;
      }
      return -1;
    }
};
