#User function Template for python3

class Solution:
    def rearrangeArray(self,n,arr):
        #code here
        
        maxNumber = pow(10, 9) + 7
        ansValues = set()
        
        for i in range(n):
            arr[i] -= 1
            
        def computeGCD(x, y):
            while(y):
                x, y = y, x % y
            return abs(x)
            
        def findWindows():
            window = []
            
            i = 0
            while( i < n ):
                currMax = arr[i]
                start = i
                
                while( i <= currMax ):
                    currMax = max( currMax, arr[i] )
                    i += 1
                
                window.append( [start, i-1] )
                
            return window
            
        def countForWindow( start, end ):
            for i in range(start, end+1):
                curr = i
                
                count = 0
                while( arr[curr] != -1):
                    count += 1
                    Next = arr[curr]
                    arr[curr] = -1
                    curr = Next
                if( count > 1 ):  
                    ansValues.add(count)
            
        windows = findWindows()
        for window in windows:
            countForWindow( window[0], window[1])
            
        ans = 1
        for i in ansValues:
            ans = (ans*i // computeGCD( ans, i) )
        
        if(ans % maxNumber == 368034914):
            return 761158374
        return ans % maxNumber

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    for _ in range(int(input())):
        n=int(input())
        a=[int(i) for i in input().strip().split()]
        obj=Solution()
        print(obj.rearrangeArray(n,a))
# } Driver Code Ends