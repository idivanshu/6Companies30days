/* Recognize that if there is an even amount of negative numbers, you can eliminate all the negatives signs in the following fashion:

If there is a pair of adjacent negative numbers, just remove both negative signs
If the remaining negative numbers are separated from each other, just swap their negative signs with the adjacent positive number until they are adjacent to each other, and then you can remove 2 negative signs at a time
If there is an odd amount of negative sign, there will be a negative sign in the end, and we can move that negative sign to the smallest number in the matrix (by swapping as above)

So, if the number of negative signs is even, the answer is the sum of the absolute value of all elements. If it is odd, we will have to minus 2 times the number with smallest absolute value (for we have to change + sign to -) to get the answer:*/

// Traverse each element.
// Find count of negative numbers.
// Find minimum positive value element in the matrix.
// Sum absolute value of each cell.
// If negative count is even return Total Sum.
// Else we will subtract twice of Min Element.

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &a)
    {
        long long neg_cnt = 0, ans = 0, size = a.size(), minn = 1000000;
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
            {
                ans += abs(a[i][j]);
                if (a[i][j] < 0)
                    neg_cnt++;
                minn = minn < abs(a[i][j]) ? minn : abs(a[i][j]);
            }
        if (neg_cnt % 2 == 0)
            return ans;
        else
            return ans - 2 * minn;
    }
};