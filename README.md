# Data Structures Final Project

# Problem 1

## Overview

LinkedIn is a professional networking site, people are connected with other people. The whole system appears as a giant connected graph, and when you open any user profile you can see if this user is a connection from 1st, 2nd, or 3rd connection. 1st means I&#39;m directly connected with this user, 2nd means I&#39;m not directly connected with this user, but I&#39;m connected with someone who is connected with this user. 3rd means I&#39;m not directly connected with this user, but I&#39;m connected with someone who is connected with someone that is connected with this user. And so on.

## Required

It&#39;s required to get the total number of people connected at kth vertices away from each other.

## Input

Input will be number of people which will be represented using vertices and connections between them which will be represented as edges of the graph, then the starting vertex and value k.

## Output

Number of people that are k vertices away from starting vertex.

## Solution

We have people and connections between them. These connections will be represented as a graph, where every human is a vertex and every connection is an edge.

Breadth first traversal will be applied where a tree will be created and every level of this tree is the level of connection (k) with respect to the root node. A flag will be initiated declaring the start of a new level and when the flag is popped out of the BFS queue then that denotes that the level has ended and a new level will begin.

## Data structures And running time

- Graph with linked list implementation for the people and the connections
- Queue for BFS

Since the implementation is of a typical graph the space and time complexity will be the same

Regarding space complexity, the complexity is O (V+E) where the worst case is O (V^2)

Regarding time complexity, Breadth-first search has a running time of O (V + E) since every vertex and every edge will be checked once. Depending on the input to the graph, O (E) could be between O (1) and O (V^2)

# Problem 2

## Overview

A runner wants to escape out of a maze. The maze consists of (N×N) cells. Some of cells contained blocks, so, runner will avoid those cells to escape. Runner needs to know the path to follow which he can take to escape the maze.

## Required

It&#39;s required to get the path that runner can follow to escape out of maze.

## Input

The first line of input contains an integer &quot;N&quot;, (i.e. the size of the (N×N) matrix). The next n lines each line contains N space-separated values either 0 or 1.

## Output

Print the path that runner can follow to escape out of maze. In case no possible path found print &quot;no path found&quot;.

## Solution

The maze is a 2D array but it&#39;s worked on as a graph where if the neighboring point equals zero then it&#39;s as if there is an edge between them, and if it&#39;s one then there is no edge.

We will apply Dijkstra&#39;s Algorithm in our program to determine the shortest paths from (0, 0) to (n-1, n-1) storing the pervious node and the cost of the trip starting from (0, 0) in each node. Then using a stack we can get the actual path.

## Data structures And running time

- A 2d array for the maze
- A 2d array for storing all the info (weight and pervious node)
- Stack for getting the actual path

Space complexity is concerned with the 2 arrays where the first one is N^2 and the second is 2N^2. So, space complexity is O(N^2)

There are 2 loops, the first one is for passing on all the nodes so it&#39;s complexity is O (N^2). The second one is to get the next lowest weighted node which runs N^2 times. That makes the time complexity O (N^4)

Note that: N is the input integer, not the number of elements. If the complexity was calculated by the number of elements then:

| Time complexity | Space complexity |
| --------------- | ---------------- |
| O (n^2)         | O (n)            |

# Problem 3

## Overview

There are some cities and some routes connecting specific cities (not all cities are connected). For each route between two cities there is a flight with specific time and cost (same for any direction). An Employee wants to travel from city X to city Y and he needs to minimize the cost that will be paid. Every hour that the employee spends during traveling or waiting in the airport for another flight connection, he has to pay M Dollars Assume that layover time between connecting flights is always one hour.

## Required

It&#39;s required to get the path with the minimum cost for the employee during his journey.

## Input

- Amount M that he will lose per hour.
- Number of cities.
- Number of existing routes.
- Cost and time for each flight between two cities.
- Source and destination Cities.

## Output

The route with the minimum cost with total time and cost.

## Solution

We have numberOfCities which defines our 2D vector representation size, we have routes

each route have info(source, destination, hours and cost) which we can store the needed values(hours and cost) into a pair, then store them in our 2D vector in their correct locations, since our graph is undirected, we will store them in both locations [source][destination] and [destination][source].

We will apply Dijkstra&#39;s Algorithm in our program to determine the shortest paths of our graph from the give source while storing the routes of our desired path from source to destination, and calculate the number of hours the whole trip took and add the given M amount for each hour to our initial cost of each route taken.

## Data structures And running time

- Vectors for the graph representation
- Pairs for storing routes
- Arrays

The program has n cities and we are using 2D vector representation which takes O(n^2) space and use 2 iterative nested loops inside eachother, each consumes O(n) time,

The outer used for getting shortest path for all given vertices, while the other used for relaxation process which re-calculate the cost for each path. This sums up to time of O(n^2).

| Time complexity | Space complexity |
| --------------- | ---------------- |
| O (n^2)         | O (n^2)          |
