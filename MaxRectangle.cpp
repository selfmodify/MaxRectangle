// size of max rectangel that contains only 1s
// [0, 1, 1, 0, 0, 1] 
// [0, 1, 1, 1, 1, 1] 
// [0, 1, 1, 0, 0, 1] -> 6

// [0, 1, 0, 0, 0, 1] 
// [0, 1, 1, 1, 1, 1] 
// [0, 1, 1, 0, 0, 1] -> 5

#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int find_max_1s(const vector<int>& data, int max) {
    int count = 0;
    int largest = 0;
    for (auto value: data) {
        if (value != max) {
            count = 0;
        }
        else if (value == max) {
            ++count;
        }
        if (count > largest) {
            largest = count;
        }
    }
    return largest;
}

int find_max_rectangle(vector<vector<int>>& input) {
    int count = 0;
    int largest = 0;
    const int rows = (int)input.size();
    for (int i = 0; i < rows; i++) {
        // Add from i to size to find the largest rectangular block of 1's
        auto data = input;
        int value = 1;
        for (int j = i; j < rows; j++) {
            if (j > i) {
                // Look for 1's getting added.
                const int columns = data[j].size();
                for (int k = 0; k < columns; k++) {
                    data[j][k] = data[j][k] + data[j - 1][k];
                }
            }
            count = find_max_1s(data[j], value) * value;
            if (count > largest) {
                largest = count;
            }
            ++value;
        }
    }
    return largest;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    vector<vector<int>> input;
    for (auto& vec : matrix) {
        vector<int> dataRow;
        for (auto ch : vec) {
            dataRow.push_back(ch - '0');
        }
        input.push_back(dataRow);
    }
    return find_max_rectangle(input);
}

int main() {
    // vector<vector<char>> data = { { '0', '1', '1', '1', '1', '1', '0', '0' } };
    vector<vector<char>> data2 = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    int total = 0;
    // int total = maximalRectangle(data);
    cout << "\nNumber of 1s " << total;
    int total2 = maximalRectangle(data2);
    cout << "\nNumber of 1s in rectangle: " << total2;
    return 0;
}