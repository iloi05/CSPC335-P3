/*
Names: Ivy Loi, Homan Qiu, Richie Nguyen, Robert Gutierrez
Emails: ioloi05@csu.fullerton.edu, hqiu2006@csu.fullerton.edu, richienguyen@csu.fullerton.edu, lil.rjg3@csu.fullerton.edu
CPSC 335 section 11
Project 3: Algorithm 1
Date: 4/24/2026
*/
#include <iostream>
#include <vector>


int minDays(std::vector<std::vector<int>>& grid) {
    int days = 0;
    int healthy = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    bool burned = false;
   
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
        // Count healthy trees and check for burned trees
           if (grid[i][j] == 1) {
                healthy++;
           }
           if (grid[i][j] == 2) {
                burned = true;
           }
        }
    }
        // If there are no healthy trees, return 0. If there are healthy trees but no burned trees, return -1.
        if (healthy == 0) {
            return 0;
        }
        if (!burned) {
            return -1;
        }

    // Simulate the spread of fire day by day until all healthy trees are burned or no more can be burned
    while (healthy > 0) {
        // Create a new grid to track which healthy trees will burn on the next day
        std::vector<std::pair<int, int>> newGrid;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // If the current cell is a healthy tree, check if it is adjacent to a burning tree. 
                //If so, add it to the new grid to be burned on the next day.
                if (grid[i][j] == 1) {
                    if ((i > 0 && grid[i - 1][j] == 2) ||
                        (i < rows - 1 && grid[i + 1][j] == 2) ||
                        (j > 0 && grid[i][j - 1] == 2) ||
                        (j < cols - 1 && grid[i][j + 1] == 2)) {
                            newGrid.push_back({i, j});
                    }
                }
            }
        }
        // If no new trees are burned, it means there are healthy trees that cannot be burned, so return -1.     
       if (newGrid.empty()) {
            return -1;
            }
        // Update the grid with the new burned trees and decrease the count of healthy trees accordingly.
        for (auto& cell : newGrid) {
            grid[cell.first][cell.second] = 2;
            // Decrease the count of healthy trees for each new burned tree
            healthy--;
        }
        // Increment the day count after processing all new burned trees for the current day
        days++;
    }
    // Return the total number of days it takes for all healthy trees to burn down
    return days;
}




int main() {
    std::vector<std::vector<int>> forest1 = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    std::cout << "Sample 1: " << minDays(forest1) << std::endl;
    
    std::vector<std::vector<int>> forest2 = {
        {2, 1, 1},
        {0, 1, 1},
        {1, 0, 0}
    };
    std::cout << "Sample 2: " << minDays(forest2) << std::endl;

    std::vector<std::vector<int>> forest3 = {
        {0, 2}
    };
    std::cout << "Sample 3: " << minDays(forest3) << std::endl;
    
    return 0;
}