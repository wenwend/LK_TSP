# LK_TSP

Lin-Kernighan Heuristic:
This is a generalization of the 2-Opt solution. 
This heuristic is generally considered a benchmark that is to be used for comparing other solutions to. 
In a k-opt solution, you start with a tour. 
Then you remove k edges from the tour, and find a new way to reconnect those nodes so that you once again have a tour. 
This is done for every combination of k edges in the path. 
The 2-Opt solution is a k-opt solution for a specific value of k (2). 
The Lin-Kernighan heuristic is a generalized k-opt solution - you do not have a fixed value of k for each iteration of the algorithm.
Instead, you have a variable value of k - k is increased until some stopping criteria is reached. 
The idea behind this heuristic is to achieve better accuracy than a 2-Opt solution 
(e.g. using 3-Opt is more accurate than 2-Opt), but at the same time, 
minimizing the time cost associated with larger values of k 
(there's no point in running a 10-opt solution if it isn't much more accurate than a 5-opt solution, yet takes much more time).
