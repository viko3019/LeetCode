/*
  Basically we need to find that in given graph there is cycle or not if there is cycle the it is impossible to complete the 
  task.
  
  Approach 1 - Depth First Traversal can be used to detect cycle in a Graph. DFS for a connected graph produces a tree. There is 
  a cycle in a graph only if there is a back edge present in the graph. A back edge is an edge that is from a node to itself 
  (selfloop) or one of its ancestor in the tree produced by DFS. 
  
  To detect a back edge, we can keep track of vertices currently in recursion stack of function for DFS traversal. If we reach a 
  vertex that is already in the recursion stack, then there is a cycle in the tree. The edge that connects current vertex to the 
  vertex in the recursion stack is back edge. 
  For a disconnected graph, we get the DFS forrest as output
  
  
  Approach 2 - BFS uses the indegrees of each node. We will first try to find a node with 0 indegree. If we fail to do so, there 
  must be a cycle in the graph and we return false. Otherwise we have found one. We set its indegree to be -1 to prevent from 
  visiting it again and reduce the indegrees of all its neighbors by 1. This process will be repeated for n (number of nodes) 
  times. If we have not returned false, we will return true.

*/

class Solution {
public:
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<unordered_set<int>> graph = make_graph(numCourses,prerequisites);
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
                return false;
        return true;   
    }
    
    
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    } 
    
    bool dfs_cycle(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited) {
       if(visited[node]) return false;
       onpath[node] = visited[node] = true; //onpath is basically a recursion stack
       
       for (int neigh : graph[node])
            if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
                return true;
        return onpath[node] = false; // remove that node from recursion stack 
    }
};