# Simple solution using frequency array

# Approach 🧠
<!-- Describe your approach to solving the problem. -->
1. Use a freq array to store the count of each element
2. The max number must have a freq of exactly 2
3. For all the elements < max number must have freq 1

**Permutation means:**
1. 1 to max element 
2. Base case each element from 1 to maxe-1 must have 1 freq
3. We use a for loop to check this condition 

# Complexity
- Time complexity:  O(n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(1) 
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

Space Complexity O(1) as constraint is 1 <= num[i] <= 200
so we can have a array of 201 size
# Code
```cpp []
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=*max_element(nums.begin(),nums.end());
        int freq[201]={0};
        for(int x:nums){
            freq[x]++;
        }
        for(int i=1;i<n;i++){
            if(freq[i]==0) return false;
            if(freq[i]>1) return false;
        }
        return freq[n]==2;
    }
};
```


---
**REMINDER:**
![upvote.jpeg](https://assets.leetcode.com/users/images/bfac4487-bffd-43d7-9995-888c04fe912b_1778736146.9939377.jpeg)


