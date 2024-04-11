  // https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1?page=1&difficulty=Medium&sortBy=submissions

vector<long long> nextLargerElement(vector<long long> arr, int n) {
    stack<int> s;
    vector<long long> neg(n, -1); // Initialize with -1

    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            neg[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return neg;
}
