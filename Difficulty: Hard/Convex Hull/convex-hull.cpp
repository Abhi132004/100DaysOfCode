//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// Graham's Scan Algorithm.
// T.C. -> O(N log N).
// S.C. -> O(N).

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

// To Prevent Integer Overflow.
namespace std {
    template <>
    
    struct hash<std::vector<int>> {
        
        size_t operator() (const std::vector<int> &v) const {
            size_t hash_val = 0;
            
            for (int i : v) 
                hash_val = (hash_val * 131) + i;
                
            return hash_val;
        }
    };
}

class Solution {

private:

    int orientationTest(const vector<int> &a, const vector<int> &b,  const vector<int> &c) {
        
        // Use Long Long To Handle Integer Overflow Cases.
        
        long long val = static_cast <long long> (b[1]-a[1])*(c[0]-b[0])-static_cast <long long> (b[0]-a[0])*(c[1]-b[1]);
        
        if (val == 0)
            return 0; // Collinear.
            
        return (val > 0) ? 1 : 2; // // Clockwise (1); Counter-Clockwise(2).
    }
    
    int square_Distance(const vector<int> &a, const vector<int> &b) {
        
        long long ans = static_cast <long long> (b[0]-a[0])*(b[0]-a[0]) + static_cast <long long> (b[1]-a[1])*(b[1]-a[1]);
        return ans;
    }
    
public:

    vector<vector<int>>FindConvexHull(vector<vector<int>> points_list) {
        
        // De-Duplicate Points Using Set.
        
        unordered_set<vector<int>> uniquePoints(points_list.begin(), points_list.end());
        
        points_list.assign(uniquePoints.begin(), uniquePoints.end());

        // Convex Hull Is Possible With Atleast 3 Points.
         if (points_list.size() < 3) 
            return {{-1}};

        
        // Find Bottom-Most Point (Lowest Y- Coordinate) & Left (If Tied).
        auto lowestY = min_element(points_list.begin(), points_list.end(), [](const vector<int> &a, const vector<int> &b) {
                return (a[1] < b[1]) || (a[1] == b[1] && a[0] < b[0]);
            });

        // Swap Selected Pont With First Point.
        swap(points_list[0], *lowestY);

        // Sort Remaining Points Based On Polar Angle With Bottom Point.
        sort(points_list.begin() + 1, points_list.end(), [this, p0 = points_list[0]] (const vector<int> &a, const vector<int> &b) 
            {
                int orientation = orientationTest(p0, a, b);
                
                if (orientation == 0)
                    // If Points Are Collinear, Choose The One Closer To p0.
                    return square_Distance(p0, a) < square_Distance(p0, b);
                    
                return orientation == 2; // 2 Indicates A Left Turn.
            });

        // Graham's Scan.
        
        // Push 1st 2 Points.
        vector<vector<int>> convexHull;
        
        // Critical Resize !!
        convexHull.reserve(points_list.size());
        
        
        convexHull.push_back(points_list[0]);
        convexHull.push_back(points_list[1]);

        for (size_t i = 2; i < points_list.size(); ++i) {
            
            while (convexHull.size() >= 2 && orientationTest(convexHull[convexHull.size()-2], 
            convexHull[convexHull.size()-1], points_list[i]) != 2)
                convexHull.pop_back();
            
            convexHull.push_back(points_list[i]);
        }
        
        // for (size_t i = 0; i < points_list.size(); ++i) {
        //     while (convexHull.size() >= 2 && orientationTest(convexHull[convexHull.size() - 2], convexHull[convexHull.size() - 1], points_list[i]) != 2)
        //         convexHull.pop_back();
        //     convexHull.push_back(points_list[i]);
        // }
        
        
        // Sort Result In Counter-Clockwise Order.
        sort(convexHull.begin(), convexHull.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        
        return convexHull;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>points_list;
		for(int i = 0; i < n; i++){
			int a, b;
			cin >> a >> b;
			points_list.push_back({a, b});
		}
		Solution obj;
		vector<vector<int>>ans = obj.FindConvexHull(points_list);
		if(ans.size() == 1 and ans[0].size() == 1)cout << ans[0][0] <<"\n";
		else{
			for(auto i: ans){
				for(auto j: i)cout << j << " ";
				cout << "\n";
			}
		}
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends