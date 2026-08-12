class Solution {
public:

    void dfs(int i, int j, vector<vector<int>>& image,
             int originalColor, int color) {

        // Out of bounds
        if (i < 0 || i >= image.size() ||
            j < 0 || j >= image[0].size()) {
            return;
        }

        // If this cell is not the original color
        if (image[i][j] != originalColor) {
            return;
        }

        // Change color
        image[i][j] = color;

        // Down
        dfs(i + 1, j, image, originalColor, color);

        // Up
        dfs(i - 1, j, image, originalColor, color);

        // Right
        dfs(i, j + 1, image, originalColor, color);

        // Left
        dfs(i, j - 1, image, originalColor, color);
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int originalColor = image[sr][sc];

        // Already the required color
        if (originalColor == color) {
            return image;
        }

        dfs(sr, sc, image, originalColor, color);

        return image;
    }
};