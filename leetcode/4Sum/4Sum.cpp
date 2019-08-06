class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums, int begin, int end,
                                 int target) {
        vector<vector<int>> res;
        for (int i = begin; i < end; ++i) {
            if (i > begin && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = end - 1;
            while (left < right) {
                if (nums[left] + nums[right] + nums[i] > target) {
                    right--;
                } else if (nums[left] + nums[right] + nums[i] < target) {
                    left++;
                } else {
                    if ((left == i + 1 || nums[left] != nums[left - 1]) &&
                        (right == end - 1 || nums[right] != nums[right + 1]))
                        res.push_back(
                            vector<int>({nums[i], nums[left], nums[right]}));
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = size - 1; i >= 0 ; --i) {
            if (i < size - 1 && nums[i] == nums[i + 1]) continue;
            vector<vector<int>> tmpRes =
                threeSum(nums, 0, i, target - nums[i]);
            for (int j = 0; j < tmpRes.size(); ++j) {
                tmpRes[j].push_back(nums[i]);
                res.push_back(tmpRes[j]);
            }
        }
        return res;
    }
};
