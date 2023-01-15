class StockPrice
{
public:
    unordered_map<int, int> mp;
    multiset<int> s; // we will store the price here
    int maxTime = 0;
    void update(int timestamp, int price)
    {
        if (mp.count(timestamp))
        {
            auto it = s.find(mp[timestamp])
                          s.erase(it);
                }
        maxTime = max(maxTime, timestamp);
        mp[timestamp] = price;
        s.insert(price);
    }
    int current()
    {
        return mp[maxTime];
    }
    int maximum()
    {
        return *s.rbegin();
    }
    int minimum()
    {
        return *s.begin();
    }
}