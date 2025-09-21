#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    bool static comp(pair<int,int> a, pair<int,int> b) {
         double r1 = (double) a.first / (double) a.second;
         double r2 = (double) b.first / (double) b.second;
         return r1 > r2;
    }
    
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
      vector<pair<int,int>> arr;
      for(int i=0;i<val.size();i++){
          arr.push_back({val[i],wt[i]});
      }
      int n = val.size();
      sort(arr.begin(), arr.end(), comp);

      int curWeight = 0;
      double finalvalue = 0.0;

      for (int i = 0; i < n; i++) {
         if (curWeight + arr[i].second <= capacity) {
            curWeight += arr[i].second;
            finalvalue += arr[i].first;
         } else {
            int remain = capacity - curWeight;
            finalvalue += (arr[i].first / (double) arr[i].second) * (double) remain;
            break;
         }
      }

      return finalvalue;
        
    }
};
