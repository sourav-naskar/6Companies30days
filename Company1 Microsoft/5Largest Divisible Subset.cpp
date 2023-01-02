class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int > dp(n,1);    // create a dp vector for storing the longest subset till the index i which satisfies the divisibility condition  initially dp vector is filled with 1 (since every element itself is a subset with length 1 )
		
		
        int ans = 0;
        vector<int > store(n,0);      // vector store is used to store the index of the previously included elements
		
        int lastId = 0;
		
        // 1) sort the given array  so that we need to check only in for A[i] % A[j] not A[j] % A[i] provided  i > j
		
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++)
        {
            store[i] = i;           
            for(int j=0; j<i; j++)
            {
                if(nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                    store[i] = j;
                }
            }

            if(ans < dp[i])
            {
                ans = dp[i];
                lastId = i;         // stores the index where we got max length of the subset  
            }
        }


        vector<int > printAns;      // vector for storing the answer 

        printAns.push_back(nums[lastId]);


        while(store[lastId] != lastId)
        {
            lastId = store[lastId];
            printAns.push_back(nums[lastId]);
        }
		
		  // since we have our answer in reverse order, so just reversed it -> 
		   
        reverse(printAns.begin(), printAns.end());    

        return printAns;

    }
};