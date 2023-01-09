class Solution {
public:
    int findMaximizedCapital(int k, int cap, vector<int>& profits, vector<int>& capital) {
        int ans =0;
        vector<pair<int,int>>arr;
        int n = capital.size();
        for(int i =0; i<n ; i++){
            arr.push_back({capital[i],profits[i]});
        }
        sort(arr.begin(),arr.end());

        int i =0; 
        priority_queue<int> pq;
         while(k && i<n){
             if(arr[i].first<=cap)pq.push(arr[i++].second);
             else{
                  if(pq.empty()) return cap;
                  cap+=pq.top();pq.pop();k--;
             }
         }

         while(!pq.empty() && k){
             k--;
             cap+=pq.top();pq.pop();
         }   
         return cap;
    }
};
