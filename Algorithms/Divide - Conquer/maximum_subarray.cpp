//* Find Maximum Subarrays using Devide-Conquer algorithm
/*
Problem: cho mang? A co n phan tu gom cac so tu nhien (ke ca so am)
-> tim mang con co tong lon nhat

=> devide-conquer algorithm:
- chia mang? A thanh 2 phan:
    + A[low.....mid]
    + A[mid + 1 .... high]
    => cac mang? con chia thanh 2 phan tuong tu vay
- De quy:
    + tiep tuc voi mang A[low....mid] -> left_maximum_subarray
    + tuong tu voi A[mid + 1... high] -> right_maximum_subarray
    + cross_maximum_subarray: mang? con lon nhat chua phan tu mid
    => break condition: low == high -> return A[low]
- return:
    return max(left_maximum_subarray, right_maximum_subarray, cross_maximum_subarray)
*/
#include <iostream>
#include <vector>
using namespace std;
//* find maximim crossing subarray
// tim mang? con lon nhat cua mang A[low...high] chua' phan tu a[mid]
int find_maximum_crossing_subarray(int *a, const int &low, const int &high, int &mid, vector<int> &result)
{
    int max_left, max_right; // max_left, max_right is staring and ending index of crossing subarray
    int left_sum, right_sum; // sum of left and right subarray
    int sum, i;

    // find left-maximum-subarray
    left_sum = -1e9;
    sum = 0; // sum = sum of(a[i], a[i + 1], a[i + 2], ..., a[mid])
    for (i = mid; i >= low; --i)
    {
        sum += a[i];
        if (sum > left_sum) // update new record
        {
            left_sum = sum; // update left_sum
            max_left = i;   // update starting indext
        }
    }
    // => left maximum subarray : {a[max_left], a[max_left + 1], ..., a[mid]}
    // => sum of left maximum subarray = left_sum

    // find right maximum subarray
    right_sum = -1e9;
    sum = 0;
    for (i = mid + 1; i <= high; ++i)
    {
        sum += a[i];
        if (sum > right_sum) // update new record
        {
            right_sum = sum; // update left_sum
            max_right = i;   // update ending index
        }
    }

    // return result
    // return subarray
    result.assign(a + max_left, a + max_right + 1);
    return (left_sum + right_sum); // return sum of subarray
}

// Devide-Conquer algorithm to find maximum subarray
int Find_Maximum_Subarray(int *a, const int &low, const int &high, vector<int> &result)
{
    if (low == high)
    {
        result = {a[low]};
        return a[low];
    }
    else
    {
        int mid = (low + high) / 2; // midpoint

        // find left maximum subarray {a[low], ..., a[mid]}
        vector<int> left_subrray;                                        // left maximum subarray
        int left_sum = Find_Maximum_Subarray(a, low, mid, left_subrray); // sum of left_subarray

        // find right maximum subarray (a[mid + 1], ... , a[high])
        vector<int> right_subarray;                                              // right maximum subarray
        int right_sum = Find_Maximum_Subarray(a, mid + 1, high, right_subarray); // sum of right_subarray

        // find maximum crossing subarray
        vector<int> cross_subarray;                                                        // maximum crossing subarray
        int cross_sum = find_maximum_crossing_subarray(a, low, high, mid, cross_subarray); // sum of cross_subarray

        // return result
        if (left_sum >= right_sum && left_sum >= cross_sum)
        {
            result = left_subrray;
            return left_sum;
        }
        else if (right_sum >= left_sum && right_sum > cross_sum)
        {
            result = right_subarray;
            return right_sum;
        }
        else
        {
            result = cross_subarray;
            return cross_sum;
        }
    }
}
// End of algorithm
int main()
{
    int A[] = {-4, -7, -2, -9, -1, -8, -6, -3}; // base array
    vector<int> result;                         // maximum subarray
    cout << "int A[] = {-4, -7, -2, -9, -1, -8, -6, -3}\n";
    cout << "Max sum of subarray: " << Find_Maximum_Subarray(A, 0, 7, result); // sum of maximum subarray
    cout << "\nSubarray : [";
    for (int x : result)
        cout << x << " ";
    cout << "]\n";
    system("pause");
    return 0;
}