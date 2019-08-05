class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int minDist=INT_MAX;
        int left,right,sum;
        for(int minIndex=0;minIndex<nums.size()-2;++minIndex){
            left=minIndex+1;
            right=nums.size()-1;
            while(left<right){
                sum=nums[minIndex]+nums[left]+nums[right];
                if(abs(sum-target)<abs(minDist))
                    minDist=sum-target;
                if(sum<target)
                    left++;
                else if(sum>target)
                    right--;
                else
                    return target;
            }
        }
        return target+minDist;
    }
};
