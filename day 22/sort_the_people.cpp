#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(heights[j] > heights[i]) {
                    // Swap names
                    string temp = names[i];
                    names[i] = names[j];
                    names[j] = temp;

                    // Swap heights
                    int x = heights[i];
                    heights[i] = heights[j];
                    heights[j] = x;
                }
            }
        }
        return names;
    }
};

int main() {
    Solution solution;
    vector<string> names = {"Alice", "Bob", "Charlie"};
    vector<int> heights = {155, 180, 165};

    vector<string> sortedNames = solution.sortPeople(names, heights);

    cout << "Sorted names by height in descending order:" << endl;
    for(const string& name : sortedNames) {
        cout << name << " ";
    }
    cout << endl;

    return 0;
}
