# Implementation of DSA Topics 

## Data Structures 

1. Stack
    - [Code](./Data%20Structures/01_arrays/03_stack.cpp)
    - TC
        - push : O(1) 
        - pop : O(1)
        - top : O(1)
2. Queue
    - [Code](./Data%20Structures/02_linked_list/03_queue.cpp)
    - TC 
        - push : O(1) 
        - pop : O(1)
        - front : O(1)
3. Linked List
    - [Singly](./Data%20Structures/02_linked_list/01_singly.cpp)
    - [Doubly](./Data%20Structures/02_linked_list/02_doubly.cpp)
    - TC 
        - insert : O(n) 
        - remove : O(n)
        - get : O(n)
        - n = number of nodes in the list
4. Trees 
    1. BST
        - [Code](./Data%20Structures/03_trees/02_bst.cpp)
        - TC 
            - search : O(log n)
            - insert : O(log n)
            - delete : O(log n)
            - n = number of nodes in the tree
    2. Heap 
        - [Code](./Data%20Structures/03_trees/03_heap.cpp)
        - TC
            - top : O(1)
            - insert : O(log n)
            - delete : O(log n)
            - n = number of nodes in the heap
    3. Trie 
        - [Code](./Data%20Structures/03_trees/04_trie.cpp)
        - TC
            - insert : O(l) where l = length of word
            - search : O(l) where l = length of word
            - prefixSearch : O(l) where l = length of prefix
    4. DSU
        - [Code](./Data%20Structures/03_trees/05_dsu.cpp)
        - TC
            - unionByRank : O(1) 
            - findByPathCompression : O(1)
    5. Segment Trees
        - [Code](./Data%20Structures/03_trees/06_segment_trees.cpp)
        - TC
            - build : O(log n) 
            - update : O(log n)
            - query : O(log n)
5. Graphs 
    - [Code](./Data%20Structures/05_graphs/adj_list.cpp)
    - BFS
        - TC : O(V+E)
        - SC : O(V)
    - DFS
        - TC : O(V+E)
        - SC : O(V)


## Algorithms & Techniques

1. Prefix Sum
    1. 1D
        - [Code](./Algorithms/09_prefix_sum/1d_sum.cpp)
        - TC 
            - O(n) for building prefix sum array
            - O(1) for queries 
    1. 2D 
        - [Code](./Algorithms/09_prefix_sum/2d_sum.cpp)
        - TC 
            - O(n*n) for building prefix sum matrix
            - O(1) for queries  
1. Sorting 
    1. Selection Sort
        - [Code](./Algorithms/02_sorting/01_selection_sort.cpp)
        - TC : O(n^2)
        - SC : O(1)
    1. Insertion Sort
        - [Code](./Algorithms/02_sorting/02_insertion_sort.cpp)
        - TC : O(n^2)
        - SC : O(1)
    1. Merge Sort
        - [Code](./Algorithms/02_sorting/03_merge_sort.cpp)
        - TC : O(log n)
        - SC : O(n)
    1. Quick Sort
        - [Code](./Algorithms/02_sorting/04_quick_sort.cpp)
        - TC : O(log n)
        - SC : O(1)
    1. Cycle Sort
        - [Code](./Algorithms/02_sorting/05_cycle_sort.cpp)
        - TC : O(n)
        - SC : O(1)
1. 2 Pointers 
    1. Two Sum
        - [Code](./Algorithms/08_2_ptr_technique/2_ptr.cpp)
        - TC : O(n)
    1. Binary Search
        - [Code](./Algorithms/08_2_ptr_technique/binary_search.cpp)
        - TC : O(log n)
    1. Floyds Cycle Detection
        - [Code](./Algorithms/08_2_ptr_technique/flyods_cycle_detection.cpp)
        - TC : O(n)
    1. Sliding Window Fixed
        - [Code](./Algorithms/08_2_ptr_technique/sliding_window_fixed.cpp)
        - TC : O(n)
    1. Sliding Window Variable
        - [Code](./Algorithms/08_2_ptr_technique/sliding_window_variable.cpp)
        - TC : O(n)
1. Trees
    1. Level Order Traversal
        - [Code](./Algorithms/03_trees/bfs.cpp)
    1. DFS
        - [Code](./Algorithms/03_trees/dfs.cpp)
1. BackTracking
    1. Subsets
        - [Code](./Algorithms/04_back_tracking/01_subsets.cpp)
        - TC : O(2^n)
    1. Combinations 
        - [Code](./Algorithms/04_back_tracking/02_combinations.cpp)
        - TC : O(k * C(n, k))
    1. Permutations 
        - [Code](./Algorithms/04_back_tracking/03_permutations.cpp)
        - TC : O(n!)
1. Graphs 
    1. Dijkstra
        - [Code](./Algorithms/05_graphs/03_dijkstra.cpp)
        - TC : O( (E+V) log V)
        - SC : O(V)
    1. Prims
        - [Code](./Algorithms/05_graphs/04_prims.cpp)
        - TC : O( (E+V) log V)
        - SC : O(V+E)
    1. Kruskal
        - [Code](./Algorithms/05_graphs/05_kruskal.cpp)
        - TC : O(E log E)
        - SC : O(V+E)
    1. Topological Sort
        - [Code](./Algorithms/05_graphs/06_topological_sort.cpp)
        - TC : O(V+E)
1. DP
    1. 1D DP
        1. Fibonaci
            - [Code](./Algorithms/06_dp/1d_dp/fibonacci.cpp)
            - TC : O(n)
        1. House Robber
            - [Code](./Algorithms/06_dp/1d_dp/house_robber.cpp)
            - TC : O(n)
        1. Kadane
            - [Code](./Algorithms/06_dp/1d_dp/kadane.cpp)
            - O(n)
    1. 2D DP
        1. 0-1 KnapSack
            - [Code](./Algorithms/06_dp/2d_dp/knapsack_01.cpp)
            - TC : O(N*C)
        1. Unbounded KnapSack
            - [Code](./Algorithms/06_dp/2d_dp/knapsack_unbounded.cpp)
            - TC : O(N*C)
        1. LCS
            - [Code](./Algorithms/06_dp/2d_dp/lcs.cpp)
            - TC : O(l1*l2)
        1. Palindromes
            - [Code](./Algorithms/06_dp/2d_dp/palindrome.cpp)
            - TC : O(n*n)
