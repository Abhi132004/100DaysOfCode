//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        vector<vector<int>> adjList(v);
        for (auto edge : edges)
        {
            adjList[edge.first].push_back(edge.second);
            adjList[edge.second].push_back(edge.first);
        }
        // It is just like isVisited but it contains the colour information (0, 1, 2 .... n)
        vector<int> colouredVertices(v, -1);
        return graphColoring(adjList, colouredVertices, 0, m, v);
    }
    bool graphColoring(vector<vector<int>> &adjList, vector<int> &colouredVertices, int vertexIndex, int &m, int &v)
    {
        if (vertexIndex == v)
        {
            return true;
        }
        for (int colour = 0; colour < m; colour++)
        {
            int isSameColour = false;
            // Check if the neighbour have the same color or not, if any neighbout having the same colour, we can't use that colour again.
            for (int neighbour : adjList[vertexIndex])
            {
                // If the neighbour is already visited and using the above colour break the loop, we can't use that color again.
                if (colouredVertices[neighbour] == colour)
                {
                    isSameColour = true;
                    break;
                }
            }
            // If the colour is not use by any neighbour, we will use it for current vertex.
            if (!isSameColour)
            {
                colouredVertices[vertexIndex] = colour;
                if (graphColoring(adjList, colouredVertices, vertexIndex + 1, m, v))
                {
                    return true;
                }
                colouredVertices[vertexIndex] = -1;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends