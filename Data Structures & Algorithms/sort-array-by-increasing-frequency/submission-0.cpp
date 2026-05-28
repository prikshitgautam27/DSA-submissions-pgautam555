class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        auto comp=[](pair<int, int>&a, pair<int ,int>&b){
            if(a.first==b.first) return a.second<b.second;
            return a.first>b.first;

        };
         unordered_map<int,int> freq;
        for(int i=0;i<nums.size(); i++){
            freq[nums[i]]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)>minheap(comp);
        
        for(auto item: freq){
            minheap.push({item.second, item.first});
            
        
        }
        vector<int>res;
        while(!minheap.empty()){
            int element=minheap.top().second;
            int times=minheap.top().first;
            minheap.pop();
            for(int i=0;i<times;i++){
                res.push_back(element);
            }
          
        }
    
        return res;
        
    }
};

