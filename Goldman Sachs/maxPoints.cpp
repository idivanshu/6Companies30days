class Solution {
public:
        double maxi = 1e9;

    double slope(double x1, double y1,double x2,double y2){
        if(x1==x2)return maxi;
        double ans = (y2-y1) / (x2-x1);
        return ans;
    }

    int maxPoints(vector<vector<int>>& points) {
        int ans=1;
        int n = points.size();
        if(points.size()<3)return points.size();
       for(int i =0; i<n; i++){
           double sl = 0.0;
            map<double, int >m;
           for(int j = i+1; j<n; j++){
               auto it= points[i];
               auto it2 = points[j];
            //    if(it == it2)continue;
               double x1= double(it[0]),y1=double(it[1]),x2=double(it2[0]),                y2= double(it2[1]);
                sl = slope(x1,y1,x2,y2);
                // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"--  "<<sl<<endl;
                if(m[sl]==0)m[sl]++;
                
              m[sl]++;
               ans = max(m[sl],ans);
           }
       
        // m[sl]=0;
       }
    //    int ans =0;
    //    for( auto it:m){
    //        cout<<it.first<<" "<<it.second<<endl;
    //        ans = max(it.second,ans);
    //    }
        return ans;
    }
};
