//Problem: https://leetcode.com/problems/find-peak-element/

//Aim: Given an array consisting of multiple peaks, return the index of any peak (0-based indexing)

//Firstly, let's handle the edge cases.
//1) If, the number of elements in the array is equal to 1, then that is the peak.
//2) Since, we are going to be checking the adjacent elements for each mid element, we need to make sure that we don't go out of bounds.
//   So, we handle the first and last elements separately. We just check whether they are peaks or not.

//Now, once we've handled the edge cases, we maintain the following invaraints:
//l -> always points to a rising part or a peak
//r -> always points to a falling part

//we check whether mid belongs to rising/peak part or falling part and adjust the l and r pointers.
//In the end, the answer will be contained in the l pointer.

//Code:

class Solution {
public:
    bool Rising(vector<int> &nums, int n, int mid){
        if(nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]) return true; //check whether mid is in rising part
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return true; //check whether mid is a peak or not
        return false;
    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        int l = 0, r = n-1;
        while(r > l+1){
            int mid = l + (r-l)/2;
            if(Rising(nums, n, mid)) l = mid;
            else r = mid;
        }
        return l;
    }
};
