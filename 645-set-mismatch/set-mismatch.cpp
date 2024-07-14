class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        // int hash[n+1] = {0};
        //Vector Initialization: vector<int> hash(n + 1, 0);
        // initializes a vector of size n + 1 with all elements set to 0.
        vector<int> hash(n + 1, 0);
        for (int i = 0 ; i<n ; i++){
            hash[nums[i]]++;
        }
        int repeating = -1, missing = -1;
        for(int i = 1; i<=n ; i++){
            if(hash[i] ==2 )  repeating = i;
            else if(hash[i] ==0) missing = i;
            if(repeating != -1 &&  missing != -1){
                break;
            }
        }
        return {repeating , missing};
    }
};