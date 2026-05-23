class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];
        return max(lin_search(nums, 0, n-2), lin_search(nums , 1 , n-1));


    }

    int lin_search(vector<int>& nums , int left , int right ){
        int prev2= 0;
        int prev1 =0;

        for(int i=left;i<=right ; i++){
            int curr= max(prev2+ nums[i], prev1);
            prev2= prev1;
            prev1= curr;

        }
        return prev1;
    }
};
