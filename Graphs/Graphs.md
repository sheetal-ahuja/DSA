# 🌉 Graphs — Complete DSA Notes

> This guide covers **graph basics, representations, STL usage, traversal algorithms, and essential interview patterns**.  
> Designed for beginners and for quick revision before interviews.

---

## 📚 Table of Contents

1. [What Is a Graph?](#-1-what-is-a-graph)
2. [Graph Representation in C++](#-2-graph-representation-in-c)
3. [Essential STL Containers](#-3-essential-stl-containers-for-graphs)
4. [Graph Traversals](#-4-graph-traversals)
5. [Shortest Path Algorithms](#-5-shortest-path-algorithms)
6. [Topological Sorting](#-6-topological-sorting-dag-only)
7. [Cycle Detection](#-7-cycle-detection)
8. [Connected Components](#-8-connected-components)
9. [Interview Checklist](#-9-graph-problems-to-master-interview-checklist)

---

## 📌 1. What Is a Graph?

A **Graph** is a collection of:
- **Vertices (nodes)**
- **Edges (connections between nodes)**

### 🎯 Types of Graphs

| Type | Description |
|------|-------------|
| **Directed** | Edges have direction (A → B) |
| **Undirected** | Edges are bidirectional (A ↔ B) |
| **Weighted** | Edges have weights/costs |
| **Unweighted** | All edges have equal weight |
| **Cyclic** | Contains cycles |
| **Acyclic** | No cycles (DAG - Directed Acyclic Graph) |
| **Connected** | All nodes are reachable |
| **Disconnected** | Some nodes are isolated |

### 🎨 Visual Representation

```
Undirected Graph:        Directed Graph:
    1 --- 2                 1 → 2
    |     |                 ↓   ↓
    3 --- 4                 3 → 4
```

---

## 📌 2. Graph Representation in C++

Graphs are commonly represented in two formats:

### 🟦 Adjacency List (Most used, memory efficient)

#### **Undirected Graph**
```cpp
vector<vector<int>> adj(n);
adj[u].push_back(v);
adj[v].push_back(u);
```

#### **Directed Graph**
```cpp
vector<vector<int>> adj(n);
adj[u].push_back(v);
```

#### **🟥 Weighted Graph**
```cpp
vector<vector<pair<int,int>>> adj(n);
// pair = (neighbor, weight)
adj[u].push_back({v, w});
adj[v].push_back({u, w});
```

---

### 🟧 Adjacency Matrix (Dense graphs)

```cpp
vector<vector<int>> adj(n, vector<int>(n, 0));
adj[u][v] = 1;
adj[v][u] = 1;
```

**Comparison:**

| Representation | Space | Add Edge | Check Edge |
|----------------|-------|----------|------------|
| Adjacency List | O(V + E) | O(1) | O(degree) |
| Adjacency Matrix | O(V²) | O(1) | O(1) |

---

## 📌 3. Essential STL Containers for Graphs

### 🟩 Queue — BFS Traversal
```cpp
queue<int> q;
```

### 🟦 Stack — DFS (Iterative)
```cpp
stack<int> st;
```

### 🟨 Priority Queue — Dijkstra / Prim
```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
// Stores: {distance, node}
```

### 🟥 Set / Unordered Set — visited tracking
```cpp
vector<bool> visited(n, false);
```

---

## 📌 4. Graph Traversals

### 🔹 4.1 BFS (Breadth First Search)

**Uses:**
- ✅ Shortest path in unweighted graph
- ✅ Level order exploration
- ✅ Connected components

**Template:**

```cpp
void bfs(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        
        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
}
```

**Time Complexity:** O(V + E)  
**Space Complexity:** O(V)

---

### 🔹 4.2 DFS (Depth First Search)

**Uses:**
- ✅ Path detection
- ✅ Cycle detection
- ✅ Topological sorting (DAGs)
- ✅ Connected components

#### **Recursive DFS Template:**

```cpp
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    
    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            dfs(neigh, adj, visited);
        }
    }
}
```

#### **Iterative DFS Template:**

```cpp
void dfs_iterative(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> st;
    
    st.push(start);
    
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        
        if (visited[node]) continue;
        visited[node] = true;
        cout << node << " ";
        
        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                st.push(neigh);
            }
        }
    }
}
```

**Time Complexity:** O(V + E)  
**Space Complexity:** O(V)

---

## 📌 5. Shortest Path Algorithms

### 🔸 5.1 BFS — Shortest Path in Unweighted Graph

```cpp
vector<int> shortestPath(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;
    
    q.push(start);
    dist[start] = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neigh : adj[node]) {
            if (dist[neigh] == -1) {
                dist[neigh] = dist[node] + 1;
                q.push(neigh);
            }
        }
    }
    
    return dist;
}
```

**Time Complexity:** O(V + E)

---

### 🔸 5.2 Dijkstra — Shortest Path in Weighted Graph (No Negative Weights)

```cpp
vector<int> dijkstra(int start, vector<vector<pair<int,int>>>& adj) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        
        if (d != dist[node]) continue;
        
        for (auto [neigh, w] : adj[node]) {
            if (dist[node] + w < dist[neigh]) {
                dist[neigh] = dist[node] + w;
                pq.push({dist[neigh], neigh});
            }
        }
    }
    
    return dist;
}
```

**Time Complexity:** O((V + E) log V)

---

## 📌 6. Topological Sorting (DAG Only)

> **Used when:** Dependencies exist, Directed Acyclic Graphs, Scheduling problems

### 🔹 Using DFS

```cpp
void topoDFS(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    
    for (int neigh : adj[node]) {
        if (!visited[neigh])
            topoDFS(neigh, adj, visited, st);
    }
    
    st.push(node);
}

vector<int> topologicalSort(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            topoDFS(i, adj, visited, st);
    }
    
    vector<int> order;
    while (!st.empty()) {
        order.push_back(st.top());
        st.pop();
    }
    
    return order;
}
```

---

### 🔹 Using Kahn's Algorithm (BFS)

```cpp
vector<int> kahnTopo(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    
    for (int u = 0; u < n; u++)
        for (int v : adj[u])
            indegree[v]++;
    
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);
    
    vector<int> order;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);
        
        for (int neigh : adj[node]) {
            indegree[neigh]--;
            if (indegree[neigh] == 0)
                q.push(neigh);
        }
    }
    
    return order;
}
```

**Time Complexity:** O(V + E)

---

## 📌 7. Cycle Detection

### 🔸 In Undirected Graph — Using DFS

```cpp
bool dfsCycle(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    
    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            if (dfsCycle(neigh, node, adj, visited)) 
                return true;
        }
        else if (neigh != parent)
            return true;
    }
    
    return false;
}
```

---

### 🔸 In Directed Graph — Using DFS + Recursion Stack

```cpp
bool dfsDirected(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& stackFlag) {
    visited[node] = true;
    stackFlag[node] = true;
    
    for (int neigh : adj[node]) {
        if (!visited[neigh] && dfsDirected(neigh, adj, visited, stackFlag))
            return true;
        else if (stackFlag[neigh])
            return true;
    }
    
    stackFlag[node] = false;
    return false;
}
```

**Time Complexity:** O(V + E)

---

## 📌 8. Connected Components

```cpp
void dfsComp(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    
    for (int neigh : adj[node]) {
        if (!visited[neigh])
            dfsComp(neigh, adj, visited);
    }
}
```

### Count components:

```cpp
int countComponents(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            count++;
            dfsComp(i, adj, visited);
        }
    }
    
    return count;
}
```

**Time Complexity:** O(V + E)

---

## 📌 9. Graph Problems to Master (Interview Checklist)

### 🎯 Essential Topics

- [ ] **BFS / DFS**
- [ ] **Shortest path** (BFS, Dijkstra)
- [ ] **Topological sort** (DFS + Kahn)
- [ ] **Cycle detection** (directed & undirected)
- [ ] **Connected components** (DFS/BFS)
- [ ] **Bipartite graph check**
- [ ] **Bridges & articulation points**
- [ ] **Flood fill**
- [ ] **Number of islands**
- [ ] **Graph cloning**
- [ ] **Minimum spanning tree** (Prim/Kruskal)

### 🚀 Practice Sequence

```
1. Graph Representation & Basic Traversals
   ↓
2. BFS/DFS Applications
   ↓
3. Shortest Path Problems
   ↓
4. Topological Sort
   ↓
5. Cycle Detection
   ↓
6. Connected Components
   ↓
7. Advanced Topics (MST, Bridges)
```

---

## 🎯 Quick Reference Card

| Problem | Algorithm | Time Complexity | Key Data Structure |
|---------|-----------|-----------------|-------------------|
| Shortest Path (Unweighted) | BFS | O(V + E) | `queue<int>` |
| Shortest Path (Weighted) | Dijkstra | O((V + E) log V) | `priority_queue` |
| Topological Sort | DFS/Kahn | O(V + E) | `stack<int>` / `queue<int>` |
| Cycle Detection | DFS | O(V + E) | Recursion Stack |
| Connected Components | DFS/BFS | O(V + E) | `vector<bool>` |
| Graph Traversal | BFS/DFS | O(V + E) | `queue<int>` / `stack<int>` |

---

**Happy Graph Coding! 🌉**