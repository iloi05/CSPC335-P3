# CSPC335-Project-3

## Algorithm 1: The Spread of Fire in a Forest

Algorithm one loops through a grid. In the grid, a 2 means a tree is burning, a 1 is a healthy tree, 
and a 0 means there is no tree in that particular space. The algorithm calculates how many days 
it will take for healthy trees to burn down if they are adjacent to any burned trees. It takes
a day for a healthy tree to burn down, so if it is adjacent to a burning tree, the day counter
get incremented. If there are no healthy trees, the algorithm will return -1, otherwise, it 
will return the number of days it will take for all the healthy trees in the grid to burn down.

## Algorithm 2: Delivery Route Planning
Algorithm 2 finds the cheaest delivery route while limiting the number of stopovers. It starts by initializing the max number of nodes possible by getting the largest node between src and dst since we know that the largest value will likely be the amount of nodes. After, we initalize a cost array using infinity as a comparison to make sure that a path exists to the node that we want as well as compare the best Cost found versus the current cost of the route. We iterate this process k + 1 times to ensure the route does not exceed the maximum number of stops. After completing the iterations, the algorithm returns the minimumcost to reach the destination or -1 if no valid route exists within the allowed number of stopovers.