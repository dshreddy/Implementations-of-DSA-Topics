## Data Structures

| Data Structure | Implementation | Operations (Time Complexity) | Practice Problem(s) |
| -------------- | ---------------| ---------------------------- |---------------------|
| Stack          | [Code](./Data%20Structures/01_arrays/03_stack.cpp) | push: O(1),<br/> pop: O(1),<br/> top: O(1)|[20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/description/)
| Queue          | [Code](./Data%20Structures/02_linked_list/03_queue.cpp)| push: O(1),<br/> pop: O(1),<br/> front: O(1)|[1700. Number of Students Unable to Eat Lunch](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/)|
| Linked List    | [Singly](./Data%20Structures/02_linked_list/01_singly.cpp), [Doubly](./Data%20Structures/02_linked_list/02_doubly.cpp) | insert: O(n),<br/> remove: O(n),<br/> get: O(n)|[707. Design Linked List](https://leetcode.com/problems/design-linked-list/)|
| BST            | [Code](./Data%20Structures/03_trees/02_bst.cpp)| search: O(log n),<br/> insert: O(log n),<br/> delete: O(log n)|[700. Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/description/)<br/>[701. Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/description/)<br/>[450. Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/)|
| Heap           | [Code](./Data%20Structures/03_trees/03_heap.cpp)| top: O(1),<br/> insert: O(log n),<br/> delete: O(log n)|[703. Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/description/)<br/>**NOTE: Implement Your Own Heap**|
| Trie           | [Code](./Data%20Structures/03_trees/04_trie.cpp)| insert: O(l),<br/> search: O(l),<br/> prefixSearch: O(l)|[208. Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/description/)|
| DSU            | [Code](./Data%20Structures/03_trees/05_dsu.cpp)| unionByRank: O(1),<br/> findByPathCompression: O(1)|[721. Accounts Merge](https://leetcode.com/problems/accounts-merge/description/)|
| Segment Tree   | [Code](./Data%20Structures/03_trees/06_segment_trees.cpp)| build: O(n),<br/> update: O(log n),<br/> query: O(log n)|[307. Range Sum Query - Mutable](https://leetcode.com/problems/range-sum-query-mutable/description/)|

## Algorithms & Techniques

### Prefix Sum

| Technique     | Implementation                                | Operations (Time Complexity) | Practice Problem(s) |
| ------------- | --------------------------------------------- | ---------------------------- |---------------------|
| 1D Prefix Sum | [Code](./Algorithms/09_prefix_sum/1d_sum.cpp) | Build: O(n),<br/> Query: O(1)     |[303. Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/description/)|
| 2D Prefix Sum | [Code](./Algorithms/09_prefix_sum/2d_sum.cpp) | Build: O(n²),<br/> Query: O(1)    |[304. Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/description/)|

### Sorting

| Algorithm      | Implementation                                        | Time            | Space    | Practice Problem(s) |
| -------------- | ----------------------------------------------------- | --------------- | -------- |-------------------- |
| Selection Sort | [Code](./Algorithms/02_sorting/01_selection_sort.cpp) | O(n²)           | O(1)     | [912. Sort an Array](https://leetcode.com/problems/sort-an-array/description/) |
| Insertion Sort | [Code](./Algorithms/02_sorting/02_insertion_sort.cpp) | O(n²)           | O(1)     | [912. Sort an Array](https://leetcode.com/problems/sort-an-array/description/) |
| Merge Sort     | [Code](./Algorithms/02_sorting/03_merge_sort.cpp)     | O(n log n)      | O(n)     | [912. Sort an Array](https://leetcode.com/problems/sort-an-array/description/) |
| Quick Sort     | [Code](./Algorithms/02_sorting/04_quick_sort.cpp)     | O(n log n) Avg. | O(log n) | [912. Sort an Array](https://leetcode.com/problems/sort-an-array/description/) |
| Cycle Sort     | [Code](./Algorithms/02_sorting/05_cycle_sort.cpp)     | O(n)            | O(1)     | [41. First Missing Positive](https://leetcode.com/problems/first-missing-positive/description/) |

### Two Pointers

| Algorithm                 | Implementation                                                      | Time Complexity | Practice Problem(s) |
| ------------------------- | ------------------------------------------------------------------- | --------------- |-------------------- |
| Two Sum                   | [Code](./Algorithms/08_2_ptr_technique/2_ptr.cpp)                   | O(n)            |[167. Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/)|
| Binary Search             | [Code](./Algorithms/08_2_ptr_technique/binary_search.cpp)           | O(log n)        |[704. Binary Search](https://leetcode.com/problems/binary-search/description/)|
| Floyd's Cycle Detection   | [Code](./Algorithms/08_2_ptr_technique/flyods_cycle_detection.cpp)  | O(n)            |[142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/description/)|
| Sliding Window (Fixed)    | [Code](./Algorithms/08_2_ptr_technique/sliding_window_fixed.cpp)    | O(n)            |[1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/)|
| Sliding Window (Variable) | [Code](./Algorithms/08_2_ptr_technique/sliding_window_variable.cpp) | O(n)            |[424. Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/description/)|

### Trees

| Traversal             | Implementation                        | Practice Problem(s)                  |
| --------------------- | ------------------------------------- |------------------------------------- |
| Level Order Traversal | [Code](./Algorithms/03_trees/bfs.cpp) |[102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/description/)
| DFS                   | [Code](./Algorithms/03_trees/dfs.cpp) | [105. Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)<br/>[173. Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/description/)<br/>[145. Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/description/)<br/>**[Note: Implement iterative version]**

### Backtracking

| Problem                | Implementation                                                      | Complexity                 | Practice Problem(s)|
| ---------------------- | ------------------------------------------------------------------- | -------------------------- | ------------------ |
| Backtracking in Matrix | [Code](./Algorithms/04_back_tracking/00_backtracking_in_matrix.cpp) | TC: O(4^(m×n)), SC: O(m×n) | [62. Unique Paths](https://leetcode.com/problems/unique-paths/description/)
| Backtracking in Tree   | [Code](./Algorithms/04_back_tracking/01_backtracking_in_tree.cpp)   | TC: O(n), SC: O(n)         | [112. Path Sum](https://leetcode.com/problems/path-sum/description/)
| Subsets                | [Code](./Algorithms/04_back_tracking/02_subsets.cpp)                | TC: O(2^n)                 | [90. Subsets II](https://leetcode.com/problems/subsets-ii/)
| Combinations           | [Code](./Algorithms/04_back_tracking/03_combinations.cpp)           | TC: O(k × C(n,k))          | [17. Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)
| Permutations           | [Code](./Algorithms/04_back_tracking/04_permutations.cpp)           | TC: O(n!)                  | [47. Permutations II](https://leetcode.com/problems/permutations-ii/description/)

### Graph Algorithms

| Algorithm        | Implementation                                         | Complexity               | Practice Problem(s)|
| ---------------- | ------------------------------------------------------ | ------------------------ | ------------------ |
| BFS       | [Code](./Data%20Structures/05_graphs/adj_list.cpp) | TC: O(V + E), SC: O(V) | [994. Rotting Oranges](https://leetcode.com/problems/rotting-oranges/) |
| DFS       | [Code](./Data%20Structures/05_graphs/adj_list.cpp) | TC: O(V + E), SC: O(V) | [200. Number of Islands](https://leetcode.com/problems/number-of-islands/) |
| Dijkstra         | [Code](./Algorithms/05_graphs/03_dijkstra.cpp)         | TC: O(E log E), SC: O(E) | [778. Swim in Rising Water](https://leetcode.com/problems/swim-in-rising-water/description/) |
| Prim's           | [Code](./Algorithms/05_graphs/04_prims.cpp)            | TC: O(E log E), SC: O(E) | [1584. Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/) |
| Kruskal          | [Code](./Algorithms/05_graphs/05_kruskal.cpp)          | TC: O(E log E), SC: O(E) | [1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree](https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/) |
| Topological Sort | [Code](./Algorithms/05_graphs/06_topological_sort.cpp) | TC: O(V + E), SC: O(V)   | [210. Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) |

### Dynamic Programming

#### 1D DP

| Problem            | Implementation                                    | Time Complexity | Practice Problem(s)|
| ------------------ | ------------------------------------------------- | --------------- | ------------------ |
| Fibonacci          | [Code](./Algorithms/06_dp/1d_dp/fibonacci.cpp)    | O(n)            | [509. Fibonacci Number](https://leetcode.com/problems/fibonacci-number/description/)
| House Robber       | [Code](./Algorithms/06_dp/1d_dp/house_robber.cpp) | O(n)            | [198. House Robber](https://leetcode.com/problems/house-robber/)
| Kadane's Algorithm | [Code](./Algorithms/06_dp/1d_dp/kadane.cpp)       | O(n)            | [918. Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-sum-circular-subarray/description/)

#### 2D DP

| Problem                       | Implementation                                          | Time Complexity | Practice Problem(s)|
| ----------------------------- | ------------------------------------------------------- | --------------- | ------------------ |
| 0/1 Knapsack                  | [Code](./Algorithms/06_dp/2d_dp/knapsack_01.cpp)        | O(N × C)        | [1049. Last Stone Weight II](https://leetcode.com/problems/last-stone-weight-ii/description/)
| Unbounded Knapsack            | [Code](./Algorithms/06_dp/2d_dp/knapsack_unbounded.cpp) | O(N × C)        | [518. Coin Change II](https://leetcode.com/problems/coin-change-ii/description/)
| LCS                           | [Code](./Algorithms/06_dp/2d_dp/lcs.cpp)                | O(l1 × l2)      | [1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)
| Longest Palindromic Substring | [Code](./Algorithms/06_dp/2d_dp/palindrome.cpp)         | O(n²)           | [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
