// Given that we have to find i , j such that 0 <= i < j <= n - 1 and
// nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff
// Step 1::
// Rewriting the inequality--
// (nums1[i] - nums2[i]) <= (nums1[j] - nums2[j]) + diff

// Step 2::
// Make a new array/vector c which stores nums1[i]-nums2[i].
// or c[i] = nums1[i]-nums2[i] for 0 <= i <= n - 1.

// Step 3::
// Problem reduces to find i , j such that 0 <= i < j <= n - 1 and
// c[i] <= c[j] + diff
class Solution
{
public:
    long long int count;
    void checkCount(vector<int> &nums, int start, int mid, int end, int d)
    {
        int l = start, r = mid + 1;
        while (l <= mid && r <= end)
        {
            if (nums[l] <= nums[r] + d)
            {
                count = count + (end - r + 1);
                l++;
            }
            r++;
        }
    }
    sort(nums.begin(), nums.end());
    return;
} void mergeSort(vector<int> &nums, int start, int end, int d)
{
    if (start == end)
        return;
    int mid = (start + end) / 2;
    mergeSort(nums, start, mid, d);
    mergeSort(nums, mid + 1, end, d);
    checkCount(nums, start, mid, end, d);
    return;
}
long long numberOfPairs(vector<int> &a, vector<int> &b, int d)
{
    count = 0;
    int n = a.size();
    vector<int> c;
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i] - b[i];
        mergeSort(c, 0, n - 1, d);
        return count;
    }
}