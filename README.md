## Data Structures

| Data Structure | Implementation | Operations (Time Complexity) | Practice Problem(s) |
| -------------- | ---------------| ---------------------------- |---------------------|
| Stack          | [Code](./Data%20Structures/01_arrays/03_stack.cpp) | push: O(1),<br/> pop: O(1),<br/> top: O(1)|[20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/description/)
| Queue          | [Code](./Data%20Structures/02_linked_list/03_queue.cpp)| push: O(1),<br/> pop: O(1),<br/> front: O(1)|[1700. Number of Students Unable to Eat Lunch](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/)|
| Linked List    | [Singly](./Data%20Structures/02_linked_list/01_singly.cpp), [Doubly](./Data%20Structures/02_linked_list/02_doubly.cpp) | insert: O(n),<br/> remove: O(n),<br/> get: O(n)|[707. Design Linked List](https://leetcode.com/problems/design-linked-list/)|
| BST            | [Code](./Data%20Structures/03_trees/02_bst.cpp)| search: O(log n),<br/> insert: O(log n),<br/> delete: O(log n)|
| Heap           | [Code](./Data%20Structures/03_trees/03_heap.cpp)| top: O(1),<br/> insert: O(log n),<br/> delete: O(log n)|
| Trie           | [Code](./Data%20Structures/03_trees/04_trie.cpp)| insert: O(l),<br/> search: O(l),<br/> prefixSearch: O(l)|
| DSU            | [Code](./Data%20Structures/03_trees/05_dsu.cpp)| unionByRank: O(1),<br/> findByPathCompression: O(1)|
| Segment Tree   | [Code](./Data%20Structures/03_trees/06_segment_trees.cpp)| build: O(n),<br/> update: O(log n),<br/> query: O(log n)|

## Algorithms & Techniques

### Prefix Sum

| Technique     | Implementation                                | Operations (Time Complexity) |
| ------------- | --------------------------------------------- | ---------------------------- |
| 1D Prefix Sum | [Code](./Algorithms/09_prefix_sum/1d_sum.cpp) | Build: O(n),<br/> Query: O(1)     |
| 2D Prefix Sum | [Code](./Algorithms/09_prefix_sum/2d_sum.cpp) | Build: O(n²),<br/> Query: O(1)    |

### Sorting

| Algorithm      | Implementation                                        | Time            | Space    |
| -------------- | ----------------------------------------------------- | --------------- | -------- |
| Selection Sort | [Code](./Algorithms/02_sorting/01_selection_sort.cpp) | O(n²)           | O(1)     |
| Insertion Sort | [Code](./Algorithms/02_sorting/02_insertion_sort.cpp) | O(n²)           | O(1)     |
| Merge Sort     | [Code](./Algorithms/02_sorting/03_merge_sort.cpp)     | O(n log n)      | O(n)     |
| Quick Sort     | [Code](./Algorithms/02_sorting/04_quick_sort.cpp)     | O(n log n) Avg. | O(log n) |
| Cycle Sort     | [Code](./Algorithms/02_sorting/05_cycle_sort.cpp)     | O(n)            | O(1)     |

### Two Pointers

| Algorithm                 | Implementation                                                      | Time Complexity |
| ------------------------- | ------------------------------------------------------------------- | --------------- |
| Two Sum                   | [Code](./Algorithms/08_2_ptr_technique/2_ptr.cpp)                   | O(n)            |
| Binary Search             | [Code](./Algorithms/08_2_ptr_technique/binary_search.cpp)           | O(log n)        |
| Floyd's Cycle Detection   | [Code](./Algorithms/08_2_ptr_technique/flyods_cycle_detection.cpp)  | O(n)            |
| Sliding Window (Fixed)    | [Code](./Algorithms/08_2_ptr_technique/sliding_window_fixed.cpp)    | O(n)            |
| Sliding Window (Variable) | [Code](./Algorithms/08_2_ptr_technique/sliding_window_variable.cpp) | O(n)            |

### Trees

| Traversal             | Implementation                        |
| --------------------- | ------------------------------------- |
| Level Order Traversal | [Code](./Algorithms/03_trees/bfs.cpp) |
| DFS                   | [Code](./Algorithms/03_trees/dfs.cpp) |

### Backtracking

| Problem                | Implementation                                                      | Complexity                 |
| ---------------------- | ------------------------------------------------------------------- | -------------------------- |
| Backtracking in Matrix | [Code](./Algorithms/04_back_tracking/00_backtracking_in_matrix.cpp) | TC: O(4^(m×n)), SC: O(m×n) |
| Backtracking in Tree   | [Code](./Algorithms/04_back_tracking/01_backtracking_in_tree.cpp)   | TC: O(n), SC: O(n)         |
| Subsets                | [Code](./Algorithms/04_back_tracking/02_subsets.cpp)                | TC: O(2^n)                 |
| Combinations           | [Code](./Algorithms/04_back_tracking/03_combinations.cpp)           | TC: O(k × C(n,k))          |
| Permutations           | [Code](./Algorithms/04_back_tracking/04_permutations.cpp)           | TC: O(n!)                  |

### Graph Algorithms

| Algorithm        | Implementation                                         | Complexity               |
| ---------------- | ------------------------------------------------------ | ------------------------ |
| Dijkstra         | [Code](./Algorithms/05_graphs/03_dijkstra.cpp)         | TC: O(E log E), SC: O(E) |
| Prim's           | [Code](./Algorithms/05_graphs/04_prims.cpp)            | TC: O(E log E), SC: O(E) |
| Kruskal          | [Code](./Algorithms/05_graphs/05_kruskal.cpp)          | TC: O(E log E), SC: O(E) |
| Topological Sort | [Code](./Algorithms/05_graphs/06_topological_sort.cpp) | TC: O(V + E), SC: O(V)   |
| BFS       | [Code](./Data%20Structures/05_graphs/adj_list.cpp) | TC: O(V + E), SC: O(V) |
| DFS       | [Code](./Data%20Structures/05_graphs/adj_list.cpp) | TC: O(V + E), SC: O(V) |

### Dynamic Programming

#### 1D DP

| Problem            | Implementation                                    | Time Complexity |
| ------------------ | ------------------------------------------------- | --------------- |
| Fibonacci          | [Code](./Algorithms/06_dp/1d_dp/fibonacci.cpp)    | O(n)            |
| House Robber       | [Code](./Algorithms/06_dp/1d_dp/house_robber.cpp) | O(n)            |
| Kadane's Algorithm | [Code](./Algorithms/06_dp/1d_dp/kadane.cpp)       | O(n)            |

#### 2D DP

| Problem                       | Implementation                                          | Time Complexity |
| ----------------------------- | ------------------------------------------------------- | --------------- |
| 0/1 Knapsack                  | [Code](./Algorithms/06_dp/2d_dp/knapsack_01.cpp)        | O(N × C)        |
| Unbounded Knapsack            | [Code](./Algorithms/06_dp/2d_dp/knapsack_unbounded.cpp) | O(N × C)        |
| LCS                           | [Code](./Algorithms/06_dp/2d_dp/lcs.cpp)                | O(l1 × l2)      |
| Longest Palindromic Substring | [Code](./Algorithms/06_dp/2d_dp/palindrome.cpp)         | O(n²)           |
