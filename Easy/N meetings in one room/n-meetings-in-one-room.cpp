//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
int maxMeetings(int start[], int end[], int n) {
    vector<pair<int, int>> meetings;

    // Create a vector of pairs to store the start and end times
    for (int i = 0; i < n; i++) {
        meetings.push_back({end[i], start[i]});
    }

    // Sort the meetings based on end time
    sort(meetings.begin(), meetings.end());

    int count = 1; // We can always have at least one meeting
    int last_end_time = meetings[0].first;

    // Iterate through the sorted meetings
    for (int i = 1; i < n; i++) {
        if (meetings[i].second > last_end_time) {
            count++;
            last_end_time = meetings[i].first;
        }
    }

    return count;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends