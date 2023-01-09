class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
       unordered_map <int, int> m;
        int res = 1e9; bool f=false;

        for(int i= 0; i<cards.size(); i++){

            if(m.count(cards[i])){
                res = min(res, i-m[cards[i]]+1 );
                f =true;
            }
            m[cards[i]] = i; 
        }

        return (!f) ? -1 :res;  
    }
};
