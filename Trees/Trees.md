# 🌳 Trees — Complete DSA Notes

> A clean, structured, beginner-friendly guide covering **Tree basics, STL usage, traversals, reusable templates, and common interview patterns**.

---

## 📚 Table of Contents

1. [Introduction to Trees](#-1-introduction-to-trees)
2. [TreeNode Structure](#-2-treenode-structure-c)
3. [Essential STL Containers](#-3-essential-stl-containers)
4. [Traversals](#-4-traversals)
5. [Core Tree Problems & Templates](#-5-core-tree-problems--templates)
6. [Binary Search Tree (BST)](#-6-binary-search-tree-bst)
7. [STL Usage Tips](#-7-stl-usage-tips)
8. [Interview Revision Checklist](#-8-interview-revision-checklist)
9. [Recommended Practice Sequence](#-9-recommended-practice-sequence)

---

## 📌 1. Introduction to Trees

A **Tree** is a hierarchical non-linear data structure consisting of nodes connected by edges.

### 🌱 Key Terminology

| Term | Description |
|------|-------------|
| **Root** | The starting node (topmost node) |
| **Parent / Child** | Nodes directly connected (parent above, child below) |
| **Leaf Node** | A node with no children |
| **Height of Node** | Longest path from node to a leaf |
| **Height of Tree** | Height of the root node |
| **Depth / Level** | Distance from the root (root is at level 0) |
| **Binary Tree** | Tree where each node has at most 2 children |
| **BST** | Binary Search Tree: `left < root < right` |

### 🎯 Visual Representation

```
        1          ← Root (Level 0)
       / \
      2   3        ← Level 1
     / \   \
    4   5   6      ← Level 2 (4, 5, 6 are leaf nodes)
```

---

## 📌 2. TreeNode Structure (C++)

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

**Usage:**
```cpp
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
```

---

## 📌 3. Essential STL Containers

### 🟩 Queue — For BFS

```cpp
queue<TreeNode*> q;
```

**Used for:**
- ✅ Level order traversal
- ✅ Right/Left view
- ✅ Maximum width
- ✅ Zigzag traversal
- ✅ Level-wise sums

---

### 🟦 Stack — For DFS (Iterative)

```cpp
stack<TreeNode*> st;
```

**Used for:**
- ✅ Iterative inorder
- ✅ Iterative preorder/postorder
- ✅ Simulating recursion

---

### 🟨 Vector — Store Traversals / Levels

```cpp
vector<int> ans;
vector<vector<int>> levels;
```

---

### 🟥 Pair — For (node, level) or (node, distance)

```cpp
queue<pair<TreeNode*, int>> q;
```

**Used in:**
- ✅ Top view
- ✅ Bottom view
- ✅ Horizontal distance problems

---

## 📌 4. Traversals

### 🔹 4.1 DFS (Depth First Search)

#### ▶ Preorder (Root → Left → Right)

```cpp
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
```

**Output for example tree:** `1 2 4 5 3 6`

---

#### ▶ Inorder (Left → Root → Right)

> 💡 **For BST → inorder gives sorted order**

```cpp
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
```

**Output for example tree:** `4 2 5 1 3 6`

---

#### ▶ Postorder (Left → Right → Root)

```cpp
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
```

**Output for example tree:** `4 5 2 6 3 1`

---

### 🔹 4.2 BFS (Level Order)

#### ▶ BFS Template

```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int n = q.size();
        vector<int> level;
        
        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front(); 
            q.pop();
            level.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        res.push_back(level);
    }
    
    return res;
}
```

**Output for example tree:** `[[1], [2, 3], [4, 5, 6]]`

---

## 📌 5. Core Tree Problems & Templates

### 🔸 5.1 Height of a Tree

```cpp
int height(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(h) — recursion stack

---

### 🔸 5.2 Count Nodes

```cpp
int countNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
```

---

### 🔸 5.3 Balanced Binary Tree

> A tree is balanced if the height difference between left and right subtrees is ≤ 1 for all nodes.

```cpp
int check(TreeNode* root) {
    if (!root) return 0;
    
    int left = check(root->left);
    if (left == -1) return -1;
    
    int right = check(root->right);
    if (right == -1) return -1;
    
    if (abs(left - right) > 1) return -1;
    
    return 1 + max(left, right);
}

bool isBalanced(TreeNode* root) {
    return check(root) != -1;
}
```

---

### 🔸 5.4 Diameter of Tree

> Longest path between any two nodes (may or may not pass through root).

```cpp
int diameter = 0;

int dfs(TreeNode* root) {
    if (!root) return 0;
    
    int left = dfs(root->left);
    int right = dfs(root->right);
    
    diameter = max(diameter, left + right);
    return 1 + max(left, right);
}
```

**Call:** `dfs(root);` then check `diameter`

---

### 🔸 5.5 Right View

> Rightmost node at each level.

```cpp
vector<int> rightView(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int n = q.size();
        
        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front(); 
            q.pop();
            
            if (i == n - 1)
                res.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    
    return res;
}
```

**Output for example tree:** `[1, 3, 6]`

---

### 🔸 5.6 Zigzag Level Order

> Alternate left-to-right and right-to-left at each level.

```cpp
vector<vector<int>> zigzag(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    
    queue<TreeNode*> q;
    q.push(root);
    bool reverseFlag = false;
    
    while (!q.empty()) {
        int n = q.size();
        vector<int> level(n);
        
        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front(); 
            q.pop();
            int index = reverseFlag ? (n - 1 - i) : i;
            level[index] = node->val;
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        reverseFlag = !reverseFlag;
        res.push_back(level);
    }
    
    return res;
}
```

**Output for example tree:** `[[1], [3, 2], [4, 5, 6]]`

---

## 📌 6. Binary Search Tree (BST)

> **Property:** For every node: `left subtree < node < right subtree`

### ▶ Insert into BST

```cpp
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    
    return root;
}
```

---

### ▶ Search in BST

```cpp
bool searchBST(TreeNode* root, int key) {
    if (!root) return false;
    if (root->val == key) return true;
    
    return key < root->val 
        ? searchBST(root->left, key) 
        : searchBST(root->right, key);
}
```

**Time Complexity:** O(h) where h = height  
**Best Case:** O(log n) — balanced BST  
**Worst Case:** O(n) — skewed tree

---

## 📌 7. STL Usage Tips

> 🚀 **VERY IMPORTANT** — Master these patterns!

| Container | Usage | Purpose |
|-----------|-------|---------|
| `queue<TreeNode*>` | BFS | Level order, views, width |
| `stack<TreeNode*>` | DFS | Iterative traversals |
| `vector<int>` | Output | Store single traversal |
| `vector<vector<int>>` | Output | Store level-wise data |
| `pair<TreeNode*, int>` | BFS | Track (node, level/distance) |

---

## 📌 8. Interview Revision Checklist

- [ ] Preorder / Inorder / Postorder
- [ ] Level Order
- [ ] Height
- [ ] Balanced tree
- [ ] Diameter
- [ ] Right / Left / Top / Bottom View
- [ ] Max Level Sum
- [ ] Path Sum (Root-to-leaf)
- [ ] BST Search / Insert
- [ ] LCA (Lowest Common Ancestor)
- [ ] Construct Tree: Preorder + Inorder

---

## 📌 9. Recommended Practice Sequence

```
1. Traversals (Pre/In/Post/Level)
   ↓
2. Height / Count
   ↓
3. Level Order variants (Right view, Zigzag)
   ↓
4. Balanced Tree
   ↓
5. Diameter
   ↓
6. BST basics (Search/Insert)
   ↓
7. LCA (Lowest Common Ancestor)
   ↓
8. Path Sum
   ↓
9. Construct Tree from traversals
```

---

## 🎯 Quick Reference Card

| Problem | Approach | Key Data Structure |
|---------|----------|-------------------|
| Level Order | BFS | `queue<TreeNode*>` |
| Height | DFS | Recursion |
| Diameter | DFS + Global Variable | Recursion |
| Right View | BFS (last node per level) | `queue<TreeNode*>` |
| Zigzag | BFS + Reverse Flag | `queue<TreeNode*>` |
| BST Search | Binary Search Logic | Recursion/Iteration |
| Balanced | DFS + Height Check | Recursion |

---

**Happy Coding! 🚀**
