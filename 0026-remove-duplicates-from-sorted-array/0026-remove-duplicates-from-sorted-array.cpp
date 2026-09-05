class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> answer;
         answer.push_back(nums[0]);

         for( int i=1;i<nums.size();i++)
         {
            if(nums[i]!=nums[i-1])
            answer.push_back(nums[i]);
         }        
         for(int i=0;i<answer.size();i++)
         {
            nums[i]=answer[i];
         }
         return answer.size();
    }
};