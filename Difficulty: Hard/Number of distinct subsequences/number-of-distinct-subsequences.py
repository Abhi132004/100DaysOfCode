#User function Template for python3

class Solution:
	 def distinctSubsequences(self, S):
        last = [-1 for _ in range(257)]
        dp = [-1 for _ in range(len(s) + 1)]
        dp[0] = 1
        mod = 10 ** 9 + 7
        for i in range(1, len(s) + 1):
            dp[i] = (2 * dp[i - 1]) % mod
            if last[ord(s[i - 1])] != -1:
                dp[i] = dp[i] - dp[last[ord(s[i - 1])]]
            last[ord(s[i - 1])] = i - 1
        return dp[len(s)] % mod

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        s = input()

        ob = Solution()
        answer = ob.distinctSubsequences(s)
        print(answer)
        print("~")

# } Driver Code Ends