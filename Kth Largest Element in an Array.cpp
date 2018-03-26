/*
Method 1 - sorting O(NlogN)

Method 2 (Use temporary array)
K largest elements from arr[0..n-1]

1) Store the first k elements in a temporary array temp[0..k-1].
2) Find the smallest element in temp[], let the smallest element be min.
3) For each element x in arr[k] to arr[n-1]
If x is greater than the min then remove min from temp[] and insert x.
4) sort temp array

Time Complexity: O((n-k)*k). If we want the output sorted then O((n-k)*k + klogk)

Method 3 - we can optimize method 2 by using meanHeap instead of array to store k elements
Time Complexity: O(k + (n-k)Logk) without sorted output. If sorted output is needed then O(k + (n-k)Logk + kLogk)

Method 4 - we can use maxHeap. create a maxHeap of N elements O(N) then extract top element k times. and return kth extracted element.  Time O(klogN) space O(N)

*/

class Solution {
public:
    
    int Method1(vector<int>& nums, int k){
        int len = nums.size();
        if(len<k) return 0;
        sort(nums.begin(),nums.end());
        return nums[len-k];
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return Method1(nums,k);
    }
};