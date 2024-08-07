
//Implement Lower Bound
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int ind1 = lower_bound(nums , target);
        int ind2 = lower_bound(nums, target+1) - 1;
        if( ind1 < nums.size() && nums[ind1] == target){
            return {ind1 , ind2};
        }
        else{
            return {-1 , -1};
        }
};

int lower_bound(vector<int>& nums , int target){
     int n = nums.size();
      int low = 0 , high = n-1;
      int ans = n; // assume ans to be last of the index +1  
      while( low <= high){
        int mid = (low + high) / 2;
        //maybe it can be my answer
        if( nums[mid] >= target){
            ans = mid;
            // look for more samll index on left to find lowest bound
            high = mid - 1;
        }
        else{
            low = mid + 1; //look for right
        }
      }
      return ans; 
    }
};

/* For a vector nums = [5, 7, 7, 8, 8, 10] and target = 8:

ind1 = lower_bound(nums, 8) will return the index of the first 8.
ind2 = lower_bound(nums, 9) - 1 will return the index of the last 8.
searchRange will return [3, 4] */