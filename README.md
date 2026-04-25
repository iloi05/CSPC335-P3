# CSPC335-Project-3

## Algorithm 1: The Spread of Fire in a Forest

Algorithm one loops through a grid. In the grid, a 2 means a tree is burning, a 1 is a healthy tree, 
and a 0 means there is no tree in that particular space. The algorithm calculates how many days 
it will take for healthy trees to burn down if they are adjacent to any burned trees. It takes
a day for a healthy tree to burn down, so if it is adjacent to a burning tree, the day counter
get incremented. If there are no healthy trees, the algorithm will return -1, otherwise, it 
will return the number of days it will take for all the healthy trees in the grid to burn down.