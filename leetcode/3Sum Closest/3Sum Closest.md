# 3Sum Closest 

本题与3Sum其实做法类似，主要区别在于需要维护一个当前找到的最接近target的值。

依然采用类似与3Sum的方式，首先对nums排序。先固定一个数字nums[i]，然后在nums[i]右侧的部分进行类似于2Sum的操作。每次移动left或right后都将新得到的三数和与之前的最优解作比较，新的结果更接近target，更新保存的最优解。（如果找到了三数和等于target，可以直接返回target，因为不存在更好的解了）

算法的正确性证明也很简单。题干中保证了最优解恰有一组，设最优解的三个数字在nums的下标为(i,j,k)且i<j<k.第一个数字固定为nums[i]之后，我们只需要证明left与right会经过left=j且right=k的状态即可（因为这个状态是最优的，一定会被更新且不会被后续的任何状态更新）

我们不妨设nums[i]+nums[j]+nums[k]不大于target。同3Sum中对2Sum算法正确性证明类似，left和right总是会经历"left=j,right>k"或"left<j,right=k"的状态。

如果经历的是left=j,right>k的状态，此时的nums[left]+nums[right]>nums[j]+nums[k]。又由于(i,j,k)是最优的，因此nums[i]+nums[left]+nums[right]一定大于target（如果这个和小于target，这个和就比最优解更接近target，矛盾），则之后的更新始终会使right左移，直至达到left=j且right=k的状态。

如果经历的是left<j,right=k的状态,此时的nums[i]+nums[left]+nums[right]<nums[i]+nums[j]+nums[k]<target,则之后的更新始终会使left右移，直至达到最优解。

