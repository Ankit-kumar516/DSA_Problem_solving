#include <bits/stdc++.h>
using namespace std;

// Function to find lexicographically smallest rotation using Booth's Algorithm
vector<int> minCyclicRotation(const vector<int>& B) {
    int M = B.size();
    vector<int> doubled(B.begin(), B.end());
    doubled.insert(doubled.end(), B.begin(), B.end());
    vector<int> f(M * 2, -1);
    int k = 0; // Current smallest rotation start index

    for (int j = 1; j < M * 2; ++j) {
        int i = f[j - k - 1];
        while (i != -1 && doubled[j] != doubled[k + i + 1]) {
            if (doubled[j] < doubled[k + i + 1]) k = j - i - 1;
            i = f[i];
        }
        if (doubled[j] != doubled[k + i + 1]) {
            if (doubled[j] < doubled[k]) k = j;
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }

    // Extract the smallest rotation
    vector<int> result;
    for (int i = k; i < k + M; ++i) {
        result.push_back(doubled[i]);
    }
    return result;
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N), B(M);
        for (int& x : A) cin >> x;
        for (int& x : B) cin >> x;

        // Get the lexicographically smallest cyclic rotation of B
        vector<int> minRotation = minCyclicRotation(B);

        // Sliding window comparison and update
        for (int i = 0; i <= N - M; ++i) {
            bool update = false;
            for (int j = 0; j < M; ++j) {
                if (A[i + j] > minRotation[j]) {
                    update = true;
                    break;
                } else if (A[i + j] < minRotation[j]) {
                    break;
                }
            }
            if (update) {
                for (int j = 0; j < M; ++j) {
                    A[i + j] = minRotation[j];
                }
            }
        }

        // Output the result
        for (const int& x : A) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
