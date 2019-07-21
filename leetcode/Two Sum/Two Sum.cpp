/**
 *这道题目最大的意义可能就是让萌新产生使用Hash的意识（大雾）
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> myMap;
        for(int i=0;i<nums.size();++i){
            int toFind=target-nums[i];
            if(myMap.find(toFind)!=myMap.end()){
                return vector<int>{myMap[toFind],i};
            }
            myMap.insert({nums[i],i});
        }
        return vector<int>{-1,-1};
    }
};
