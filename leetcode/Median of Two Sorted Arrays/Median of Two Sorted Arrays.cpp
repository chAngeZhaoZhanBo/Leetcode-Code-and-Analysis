class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size(),len2=nums2.size();
        if(len1>len2)
            return findMedianSortedArrays(nums2,nums1);
        int left=0,right=len1;
        const int halfLen=(len1+len2+1)/2;
        while(left<=right){
            int i=(left+right)/2;
            int j=halfLen-i;
            if(i<right&&nums2[j-1]>nums1[i]){
                left=i+1;
            }
            else if(i>left&&nums1[i-1]>nums2[j]){
                right=i-1;
            }
            else{
                int maxLeft=0;
                if(i==0)
                    maxLeft=nums2[j-1];
                else if(j==0)
                    maxLeft=nums1[i-1];
                else
                    maxLeft=max(nums1[i-1],nums2[j-1]);
                if((len1+len2)&1)
                    return maxLeft;
                int minRight=0;
                if(i==len1)
                    minRight=nums2[j];
                else if(j==len2)
                    minRight=nums1[i];
                else
                    minRight=min(nums1[i],nums2[j]);
                return (maxLeft+minRight)/2.0;
            }
        }
        return 0.0;
    }
};
