//Runtime: 12 ms, faster than 98.15% of C++ online submissions for Remove Duplicates from Sorted Array.
//Memory Usage: 14.2 MB, less than 99.99% of C++ online submissions for Remove Duplicates from Sorted Array.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if (nums.size() == 0){
            return 0;
        }
        
        int i;
        int last_value = nums[0];
        int size = nums.size();
        vector<int> nums1;

        
        nums1.push_back(nums[0]);
        
        for (i = 0; i < size; ++i){
            if (nums[i] == last_value){
                
            } else{
                last_value = nums[i];
                nums1.push_back(last_value);
            }
        }
        
        nums = nums1;
        
        return nums.size();;
        
    }
};
