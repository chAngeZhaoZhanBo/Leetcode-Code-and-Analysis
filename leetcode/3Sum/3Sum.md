# 3Sum

对于3Sum问题，我们先对数组进行排序。

排序的目的在于：3Sum问题可以先固定一个值，然后转化为2Sum问题。而对于排序的数组，2Sum问题存在一种one-pass的、空间复杂度为O(1)的算法。



我们先来讨论在排序数组上2Sum问题的解法

```cpp
vector<int> 2Sum(vector<int>& nums, int target) {
    vector<int> res;
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        if (nums[left] + nums[right] > target) {
            right--;
        } else if (nums[left] + nums[right] < target) {
            left++;
        } else {
            if ((left == i + 1 || nums[left] != nums[left - 1]) &&
                (right == size - 1 || nums[right] != nums[right + 1]))
                res.push_back(vector<int>({nums[left], nums[right]}));
            left++;
            right--;
        }
    }
    return res;
}
```

算法很容易理解，下面证明其正确性。

1. 算法找到的所有解均是正确的：算法只会在else分支将nums[left]和nums[right]加入res，此时的nums[left]+nums[right]一定恰为target
2. 所有的正确解均会被算法找到：对于任意的正确解，设其对应的两个数字在nums的下标分别为$ i,j(i<j)$ 。由于算法在left=right时中止，则算法中止时，“left在i的右侧”与“right在j的左侧”至少有一个成立（两者均成立时总有出现的次序先后），不妨设“算法终止时left在i的右侧”先于"right在j的左侧"达成。由于left和right每次循环均只移动一步，则算法必然经过left=i,right>j的状态。由于nums有序，此时我们有nums[left]+nums[right]>nums[i]+nums[j]=target，因此算法会不断地让right向左移动，直至right=j时，将(i,j)加入res。

上文的2Sum算法中else分支中的第10行的判断保证了算法不会把重复的解加入res。如nums=[1,1,2,2]，target=3时，得到的解为[[1,2]]而不是[[1,2],[1,2]]，这是符合我们将要解决的3Sum问题的要求的。该2Sum问题的时间复杂度为O(n)，空间复杂度为O(1)



有了2Sum问题的解法，3Sum问题也就迎刃而解了。先将nums排序，然后从左到右遍历nums，选定到达的数字nums[i]作为第一个数字。然后在第一个数字右面的区间进行2Sum算法，target设为-num[i]。

值得注意的是，为了保证3Sum问题不会得到重复的解。除了上述2Sum算法中第10行的判断外，还要保证遍历的第一个数字nums[i]不等于nums[i-1]。此外，可以增加判断提前中断循环，由于3Sum算法的目标和为0 。因此，排序后的nums在第一个数字大于0时就可以中止循环了（后面的数字全部大于0，3数和也一定大于0）

由于2Sum是O(n)的，则3Sum是O(n^2)的。排序算法通常为O(n^2)的，因此不会拖累算法的时间复杂度。

