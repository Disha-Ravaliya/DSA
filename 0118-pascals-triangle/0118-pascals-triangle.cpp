class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle;

        for (int i = 0; i < numRows; ++i) {
            // Create a row with (i + 1) elements, all initialized to 1
            std::vector<int> row(i + 1, 1);
            
            // Calculate the internal elements by summing the values from the previous row
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            
            triangle.push_back(row);
        }

        return triangle;
    }
};