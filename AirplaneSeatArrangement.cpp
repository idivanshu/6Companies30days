class Solution
{
public:
    double nthPersonGetsNthSeat(int n)
    {
        if (n == 1) // when one person with one seat
            return 1.0;
        return 0.50;
        // for n=2,
        //     there will be two person with two seats so the probability of getting the correct position is 50%
        //     for n=3,
        //     3 person A B C with 3 seats.
        //    Probability of C will get his seat= (A sits his correct position)+(exchange seats between A and B)
        //                                      =1/3+1/6 = 1/2
        //     for n=4,5,6...
        //     the probability will be 50%
    }
};