/*
   There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

   You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

   Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
 */
class Solution {
  public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int n = gas.size();

      int T = 0; // fuel in tank
      int sum = 0; // total gas-cost
      int istart = 0; // start position
      for(int i = 0; i < n; i++){
	T = T + gas[i] - cost[i];
	sum = sum + gas[i] - cost[i];
	if(T < 0){
	  T = 0;
	  istart = i + 1;
	}
      }

      if(sum < 0) return -1;
      else return istart; // if sum > 0, there must exist istart
    }
};
