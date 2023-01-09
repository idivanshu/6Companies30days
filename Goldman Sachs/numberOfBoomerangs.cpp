class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
         int ans = 0;
   
    for (int i = 0; i < points.size(); ++i) {
        
        unordered_map<long, int> m(points.size());
        
      
        for (int j = 0; j < points.size(); ++j) {
            
            if (j == i) continue;
            
            int dy=points[i][1]-points[j][1], dx=points[i][0]-points[j][0];
            int dis = (dy * dy) + (dx * dx);
            m[dis]++;
        }
        
        for (auto it : m) {
            if (it.second > 1) {
                ans += it.second * (it.second - 1);
            }
        }
    }
    
    return ans;
    }
};
