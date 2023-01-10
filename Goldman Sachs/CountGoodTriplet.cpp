class solution
{
    /*firstly we reorder num1 to make it as 0,1,2... Then num2 is reordered.
For example:
original: nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
new : nums1 = [0,1,2,3,4], nums2 = [0,2,1,4,3]
As a result, we can only focus on num2 because any three number in num1 satisfying the condition (pos_x<pos_y<pos_z) is equivalent to (x<y<z). Then the problem turns out to be finding triplet in num2 with index i<j<k, where nums2[i]<nums2[j]<nums2[k]. To achieve this goal, we need to know(1. numbers smaller than nums[i] when index<i; 2. numbers larger than nums[i] when index>i).

We merge-sort num2. During the merge sort process, x[i] record numbers of value smaller than x[i] for index<i. y[i] stores numbers of value larger than x[i] for index>i;
The rule is simple:
During the merge sort, we have two sorted sub array [l,mid] and [mid+1,r]. Whenever we have decided the position of the number in [l,mid] in new position, say i, we can calculate the numbers larger than nums2[i] in [mid+1,r]. For example:
[l,mid] is [1,3,6,10]
[mid+1,r] is [2,4,5,8,9]
the merged array should be [1,2,3 ... ]. Here when we choose 3 in [l,mid] in the merged array, we have already chosen 1 number in [mid+1,r], i.e. "2". The rest number in [mid+1,r] will be greater than chosen "3" and in total we have 5 numbers in [mid+1,r]. So we have (5-1)=4.
Similiarily, when we have the merged array [1,2,3,4,...]. We have "4" in [mid+1,r], then we look for the number in [l,mid] smaller than "4". Since we already choose 2 numbers(1,3) and [l,mid] has 4 numbers. The number in [l,mid] smaller than "4" is 4-2=2;
At the same time, when we reorder the number, we need to keep the index of the array for the old array. That is the reason to introduce vector record. For example, with:
nums2 : 1,7,5,6,3,9
record: 0,1,2,3,4,5

during the merge sort, the number in nums2 is changing:
nums2 [1,5,7] [3,6,9]
record [0,2,1] [4,3,5]
record maintain the index of each number in nums2, which help us calculate the number smaller or larger than each number in nums2.

For each number in num2, we count how many pairs satisfy our condition with x[i]* y[i].*/
public:
    vector<long long> x, y;
    vector<int> record;
    void merge(vector<int> &total, int l, int r, )
    {
        if (l >= r)
            return;
        int mid = l + (r - l) / 2;
        merge(total, l, mid);
        merge(total, mid + 1, r);
        vector<int> tempValue(r - l + 1);
        vector<int> tempRecord(r - l + 1);
        int i = l, j = mid + 1;
        int t = 0;
        while (i <= mid && j <= r)
        {
            if (total[i] <= total[j])
            {
                tempValue[t] = total[i];
                tempRecord[t] = record[i];
                y[record[i]] += (r - j + 1);
                t++;
                i++;
            }
            else
            {
                tempValue[t] = total[j];
                tempRecord[t] = record[j];
                x[record[j]] += i - l;
                t++;
                j++;
            }
        }
        while (i <= mid)
        {
            tempValue[t] = total[i];
            tempRecord[t] = record[i];
            t++;
            i++;
        }
        while (j <= r)
        {
            tempValue[t] = total[j];
            tempRecord[t] = record[j];
            x[record[j]] += (mid - l + 1);
            t++;
            j++;
        }
        for (int i = l; i <= r; i++)
        {
            total[i] = tempValue[i - l];
            record[i] = tempRecord[i - l];
        }
    }
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> ind(n);
        x.resize(n);
        y.resize(n);
        for (int i = 0; i < n; i++)
        {
            ind[nums1[i]] = i;
        }
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = ind[nums2[i]];
            record.push_back(i);
        }
        merge(, 0, n - 1);
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            res += x[i] * y[i];
        }
        return res;
    }
};
