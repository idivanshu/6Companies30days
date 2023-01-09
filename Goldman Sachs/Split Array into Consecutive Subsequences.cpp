class Solution {
public:
// detailed explaination
//https://leetcode.com/problems/split-array-into-consecutive-subsequences/solutions/2449167/C++-O(1)-memory-O(n)-time/
    bool isPossible(vector<int>& nums) {
        int ind =0;
        int a = 0;//
        int b = 0;// 
        int c=0;
        for(int i =-1001; i<=1001; i++){
            int cnt=0;
            while(ind<nums.size() && nums[ind]==i){
                ind++;cnt++;
            }

            if(cnt<a+b)return false;
            int a_p= a;
            a = max(0,(cnt-(a+b+c)));
            b = a_p;
            c = cnt - (a+b);

        }
        return true;

    }
};
