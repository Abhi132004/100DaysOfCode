//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
int isNull(int a) {
    return (a == '\0') ? 0 : a;
}

void MakeZeros(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return; // Early return if matrix is empty
    int m = matrix[0].size();

    vector<vector<int>> temp = matrix; // Create a copy of the matrix to avoid modifying while iterating

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                int sum = 0;
                if (i > 0) sum += isNull(matrix[i - 1][j]);
                if (j > 0) sum += isNull(matrix[i][j - 1]);
                if (i < n - 1) sum += isNull(matrix[i + 1][j]);
                if (j < m - 1) sum += isNull(matrix[i][j + 1]);

                temp[i][j] = sum;

                if (i > 0) temp[i - 1][j] = 0;
                if (j > 0) temp[i][j - 1] = 0;
                if (i < n - 1) temp[i + 1][j] = 0;
                if (j < m - 1) temp[i][j + 1] = 0;
            }
        }
    }

    matrix = temp; // Copy back the modified values
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends