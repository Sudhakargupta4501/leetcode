class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums1.size();
        int m= nums2.size();

        for(int i =0;i<n;i++)
        {
             bool found = false;

             for(int j=0;j<m;j++)
             {
                if(nums2[j]==nums1[i])
                {
                     for(int k = j+1;k<m;k++)
                     {
                        if(nums2[k]>nums1[i])
                        {
                           ans.push_back(nums2[k]);
                            found = true; break;
                        
                        }
                     }
                     break;
                }
             }
             if(!found)
             {
                 ans.push_back(-1);
             }
        }
        return ans;
    }


//       int n = nums1.size();
//       int m = nums2.size();
//       vector<int> ans;


//       for( int i=0;i<n;i++)
//       {   
//         bool found = false;
//         for(int j=0;j<m;j++)
//         {
//              if(nums2[j]==nums1[i])
//              {
//                 for(int k =j+1;k<m;k++)
//                    if(nums2[k]>nums1[i])
//                    {
//                     ans.push_back(nums2[k]);
//                     found = true;
//                     break;
//                    }

//              }
//              break;
//         }
//       }
//    if(!found)
//    {
//     ans.push_back(-1);
//    }
//   return ans;
//     }
};