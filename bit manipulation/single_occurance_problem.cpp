//Classic Find the single occurance in a array which has a bunch of repeated elements type of question.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<32; i++){
            int set_count = 0;
            for(int j = 0; j<n; j++){
                if(nums[j] & (1LL << i)) set_count++;
            }
            if((set_count%3!=0)){
                ans += (1LL << i);
            }
        }
        return ans;
    }
};
