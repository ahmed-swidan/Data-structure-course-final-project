#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>
#include <utility>
using namespace std;

class Graph
{
    int v;
    list<int> *vertix;
public:
    Graph(int v)
    {
        this->v = v;
        vertix = new list<int>[v];
    }
    void add_edge(int s, int e)
    {
        vertix[s].push_back(e);
        vertix[e].push_back(s);
    }
    void modified_BFS(int start, int desired_level)
    {
        bool visited[v];
        int first_in_level  = -1;
        int k = 0;
        int kth_level_counter = 0;
        for(int i = 0; i < v; i++)
            visited[i] = false;
        list<int> queue;
        visited[start] = true;
        queue.push_back(start);
        list<int>::iterator i;
        while(!queue.empty())
        {
            start = queue.front();
            queue.pop_front();
            if(start == first_in_level)
            {
                k ++;
                if(k==desired_level)
                    cout<<"number of elements in level "<<k<<" are "<<kth_level_counter<<endl;
                first_in_level = -1;
                kth_level_counter = 0;

            }
            for (i = vertix[start].begin(); i != vertix[start].end(); ++i)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    queue.push_back(*i);
                    if(first_in_level == -1)
                    {
                        first_in_level = *i;
                    }
                    kth_level_counter++;
                }
            }
        }
    }
};

int get_min_colomn(int arr[][2], bool visited[], int n)
{
    int min = INT_MAX;
    int element = 0;
    for(int i = 0; i<n; i++)
    {
        if(arr[i][0]<min&&visited[i] == false)
        {
            min  = arr[i][0];
            element = i;
        }
    }
    return element;
}

void problem1()
{
    int num_v;
    int num_e;
    int s,e;
    cout <<"please enter number of vertices:"<<endl;
    cin >>num_v;
    Graph g(num_v+1);
    cout <<"please enter number of edges"<<endl;
    cin >>num_e;
    cout <<"please enter the edges in the form (s,e)"<<endl;
    for(int i = 0; i<num_e; i++)
    {
        cin >>s>>e;
        g.add_edge(s,e);
    }
    cout <<"please enter the starting vertix:"<<endl;
    cin >>s;
    cout <<"please enter k:"<<endl;
    cin >>e;
    g.modified_BFS(s,e);
}

void problem2()
{
    int n;
    cout<<"please enter N:"<<endl;
    cin>>n;
    int maze[n][n];
    int info[n*n][2];
    int current  = 0;
    int count = 0;
    bool visited[n*n];
    cout<<"please enter values for maze:"<<endl;
    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 0 ; j<n ; j++)
        {
            cin>>maze[i][j];
            if(maze[i][j]==0)
                count++;
        }
    }
    for(int i = 0; i < n*n; i++)
    {
        visited[i] = false;
        info[i][0]=INT_MAX;
        info[i][1]= INT_MAX;
    }
    info[current][0] = 0;
    for(int i = 0; i<count; i++)
    {
        if(current%n+1>-1 && current%n+1<n && maze[(current-current%n)/n][current%n+1]==0 && info[current][0]+1<info[current+1][0] )//right neighbor relaxation
        {
            info[current+1][0]=info[current][0]+1;
            info[current+1][1] = current;
        }
        if(current%n-1>-1 && current%n-1<n && maze[(current-current%n)/n][current%n-1]==0 && info[current][0]+1<info[current-1][0] )//left neighbor relaxation
        {
            info[current-1][0]=info[current][0]+1;
            info[current-1][1] = current;
        }
        if((current-current%n)/n+1>-1 && (current-current%n)/n+1<n && maze[(current-current%n)/n+1][current%n]==0 && info[current][0]+1<info[current+n][0] )//lower neighbor relaxation
        {
            info[current+n][0]=info[current][0]+1;
            info[current+n][1] = current;
        }
        if((current-current%n)/n-1>-1 && (current-current%n)/n-1<n && maze[(current-current%n)/n-1][current%n]==0 && info[current][0]+1<info[current-n][0] )//upper neighbor relaxation
        {
            info[current-n][0]=info[current][0]+1;
            info[current-n][1] = current;
        }
        visited[current] = true;
        current = get_min_colomn(info,visited,n*n);

    }
    if(info[n*n-1][0]==INT_MAX)
        cout<<"no path found"<<endl;
    else
    {
        list<int> stack;
        current = info[n*n-1][1];
        stack.push_front(n*n-1);
        stack.push_front(current);
        while(current != 0)
        {
            current = info[current][1];
            stack.push_front(current);
        }
        int size =  stack.size();
        for(int i =0; i < size ; i++)
        {
            cout  <<"(" <<(stack.front()-stack.front()%n)/n<<","<< stack.front()%n<<")"<<" -> ";
            stack.pop_front();

        }
    }
}

int minCost(int cost[],
            bool isCalculated[], int numOfCities)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < numOfCities; v++)
        if (isCalculated[v] == false &&
                cost[v] <= min)
            min = cost[v], min_index = v;

    return min_index;
}

// Prints shortest path of given vertex
void printPath(int parent[], int j)
{
    if (parent[j] == - 1)
        return;

    printPath(parent, parent[j]);

    printf(" -> %d", j + 1);
}

void printSolution(int cost[],
                   int parent[], int src, int end, int totalHours, int M)
{
    printf("Route with minimum cost is %d", src + 1);
    printPath(parent, end);
    printf("\nTotal time is %d\n", totalHours);
    printf("Total cost is $%d", cost[end] + M*totalHours);
}
void getTotalHours(vector< vector< pair<int,int> > > &graph,
                   int cost[], int *hours, int parent[], int j, int size)
{
    if (parent[j] == - 1)
    {
        *hours += size - 2;
        return;
    }

    getTotalHours(graph, cost, hours, parent, parent[j], size + 1);
    if(j > 0)
        *hours += graph[parent[j]][j].second;
}
void problem3()
{
    int M, numOfCities, numOfRoutes, src, dest;
    cout << "please enter amount M: ";
    cin >> M;
    cout << "please enter number of cities: ";
    cin >> numOfCities;
    cout << "please enter number of routes: ";
    cin >> numOfRoutes;
    cout << "please enter source, destination, time and cost for each route:" << endl;

    // Input handling
    vector< vector< pair<int,int> > >graph(numOfCities, vector<pair<int, int> >(numOfCities));
    for(int i = 0; i < numOfRoutes; i++)
    {
        int src, dest, hours, cost;
        cin >> src >> dest >> hours >> cost;
        graph[src - 1][dest - 1] = make_pair(cost, hours);
        graph[dest - 1][src - 1] = make_pair(cost, hours);
    }

    cout << "please enter source city: ";
    cin >> src;
    --src;
    cout << "please enter destination city: ";
    cin >> dest;
    --dest;

    // Cost to each vertex from src
    int cost[numOfCities];

    // Checks if the vertex is calculated
    bool isCalculated[numOfCities];

    // Holds the path of shortest route
    int parent[numOfCities];

    // Initialization
    for (int i = 0; i < numOfCities; i++)
    {
        isCalculated[i] = false;
        cost[i] = INT_MAX;
    }
    parent[src] = -1;
    cost[src] = 0;

    // Finding shortest path for all vertices from src
    for (int i = 0; i < numOfCities - 1; i++)
    {
        // Get the minimum cost of vertices from not calculated vertices
        int u = minCost(cost, isCalculated, numOfCities);

        // Mark the picked vertex as calculated
        isCalculated[u] = true;

        // Update cost of adjacent vertices of the picked vertex
        for (int v = 0; v < numOfCities; v++)

            if (!isCalculated[v] && graph[u][v].first * graph[u][v].second &&
                    cost[u] + graph[u][v].first * graph[u][v].second < cost[v])
            {
                parent[v] = u;
                cost[v] = cost[u] + graph[u][v].first * graph[u][v].second;
            }
    }

    // Calculates the total hours of the trip
    // including layover hours
    int *totalHours = new int();
    getTotalHours(graph, cost, totalHours, parent,dest, 1);

    // Outputs the solution
    printSolution(cost, parent, src, dest, *totalHours, M);
}

int main()
{
    int mode;
    do
    {
        cout << "Please choose a problem to test (1-4): (1- problem 1, 2- problem 2, 3- problem 3, 4- exit) " << endl;

        cin >> mode;

        switch(mode)
        {
        case 1:
            problem1();
            break;
        case 2:
            problem2();
            break;
        case 3:
            problem3();
            break;
        }
        cout <<endl;
    }
    while(mode != 4);
}

