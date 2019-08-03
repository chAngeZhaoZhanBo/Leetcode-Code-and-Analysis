class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size && nums[i] <= 0; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = size - 1, target = -nums[i];
            while (left < right) {
                if (nums[left] + nums[right] > target) {
                    right--;
                } else if (nums[left] + nums[right] < target) {
                    left++;
                } else {
                    if ((left == i + 1 || nums[left] != nums[left - 1]) &&
                        (right == size - 1 || nums[right] != nums[right + 1]))
                        res.push_back(
                            vector<int>({nums[i], nums[left], nums[right]}));
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};
