class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0; //

        int c_min=nums[0];// current max
        int c_max= nums[0];// current min
        int g_max=nums[0];// global max

        for(int i=1;i<nums.size();i++){
         int num=nums[i];

            if(num<0){
                swap(c_max,c_min);

            }

            c_max=max(num, c_max* num);
            c_min=min(num, c_min* num);

            g_max=max(g_max, c_max);
        }
        return g_max;
    }

};