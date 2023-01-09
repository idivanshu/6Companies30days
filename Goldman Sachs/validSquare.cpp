class Solution {
public:
   int get_dis(vector<int> p1,vector<int> p2)
    {
        int x1 = p1[0];
        int y1 = p1[1];
        int x2 = p2[0];
        int y2 = p2[1];
        return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2); 
    }
    bool check(int a,int b,int c)
    {
        if(a==c)
            return false;
        return c == a+b and a==b;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) 
    {
        vector<int> v = {get_dis(p1,p2),get_dis(p1,p3),get_dis(p1,p4)};
        sort(v.begin(),v.end());
        vector<int> v1 = {get_dis(p2,p1),get_dis(p2,p3),get_dis(p2,p4)};
        sort(v1.begin(),v1.end());
        vector<int> v2 = {get_dis(p3,p1),get_dis(p3,p2),get_dis(p3,p4)};
        sort(v2.begin(),v2.end());
        vector<int> v3 = {get_dis(p4,p1),get_dis(p4,p2),get_dis(p4,p3)};
        sort(v3.begin(),v3.end());
        return check(v[0],v[1],v[2]) && check(v1[0],v1[1],v1[2]) && check(v2[0],v2[1],v2[2]) && check(v3[0],v3[1],v3[2]);
    }
};
