
* [1032 Sharing](#1032-sharing)
* [1033 To Fill or Not to Fill](#1033-to-fill-or-not-to-fill)
* [1034 Head of a Gang](#1034-head-of-a-gang)
* [1038 Recover the Smallest Number](#1038-recover-the-smallest-number)
* [1040 Longest Symmetric String](#1040-longest-symmetric-string)
* [1043 Is It a Binary Search Tree](#1043-is-it-a-binary-search-tree)
* [1045 Favorite Color Stripe](#1045-favorite-color-stripe)
* [1049 Counting Ones](#1049-counting-ones)
* [1053 Path of Equal Weight](#1053-path-of-equal-weight)
* [1057	Stack](#1057-stack)
* [1059 Prime Factors](#1059-prime-factors)
* [1064 Complete Binary Search Tree](#1064-complete-binary-search-tree)
* [1066 Root of AVL Tree](#1066-root-of-avl-tree)
* [1067 Sort with Swap(0, i)](#1067-sort-with-swap0-i)
* [1068 Find More Coins](#1068-find-more-coins)
* [1072 Gas Station](#1072-gas-station)

## 1032 Sharing

将**链表 A** 的每个结点均标记为**已访问**，那么在遍历**链表 B** 时遇到的第一个**已访问过**的节点就是它们的第一个共同结点。

## 1033 To Fill or Not to Fill

记当前加油站所能行至的最大距离为 `max_dist`，那么：
1. 在 `max_dist` 范围内找到比它便宜的作为下一个加油站
2. 如果没有比它便宜的，则选择离 `max_dist` 最近的作为下一个加油站

## 1034 Head of a Gang

虽然看起来像是一个有向图，但实际上它是一个无向图，此时一条边的权重等于双向边之和：
```
        有向图                       无向图
    AAA -> BBB 10    --等价于->   AAA - BBB 30        
    BBB -> AAA 20       
```

因此该问题等价于找到无向图中的连通分量问题。使用 BFS 或者 DFS 都可以完成任务。

## 1038 Recover the Smallest Number

将数字片段组合起来实际上是一个排序问题。排序问题的核心是什么？

**谁前谁后**。

C/C++ 中的**比较函数**就是用来让我们告诉 C/C++ 是参数一放在参数二之后还是参数二放在参数一之后。

同样的，当将数字片段组成一个数字时，`32` 与 `321` 谁前谁后？

比较 `32321` 与 `32132` 即可知道答案（字符串相加很便捷）。

因此通过在比较函数中定义两个片段的**谁前谁后**就能决定所有片段的排列顺序。

## 1040 Longest Symmetric String

最简单的方法莫过于暴力搜索，但其时间复杂度为 O(N^2)。如何改善时间复杂度？

**充分利用已经计算过的信息。**

对称子串有这样一个特点，即**如果一个子串是对称的，那么在其两端再各增加一个相同的字符，那么得到的子串依然是对称的**。利用该规则，我们可以以**单个字符**以及**两个字符**的对称子串为**初始对称子串**，逐渐增长对称子串的长度，最终分别找到长度分别为**奇数**和**偶数**的最长对称子串。

## 1043 Is It a Binary Search Tree

不难发现，对于二叉搜索树，仅依靠其先序遍历便可以重建该树。重建树的过程是一个递归的创建子树的过程，因此可以直接在该过程中记录后序遍历的结果。

如果给出的序列并非二叉搜索树的先序遍历结果，那么得到的后序遍历就不会是完整的 (结点数量小于 N)。

## 1045 Favorite Color Stripe

去掉干扰信息 (i.e. 不喜欢的颜色) 后，便等价于求一个序列中非递减子序列的最大长度问题。可以观察到第 `i` 个位置的最大长度由其前 `i - 1` 个位置的最大长度决定：
```
# L[i] 表示到第 i 个位置时的最大长度。
L[i] = max(L[0] + 1,
           L[1] + 1,
           L[2] + 1,
              ...
           L[i-1] + 1)
```
也就是说，`L[i]` 可被分解为若干子问题。因此从最小的子问题出发，便可逐渐求解至 `L[i]`：
```
for j = 1,2,...,n:
    L[i] = 1 + max({L[i]: i < j})
```
这种从最小子问题自底向上逐渐扩大至目标问题的过程被称作为**动态规划**。

## 1049 Counting Ones

需要耐心寻找规律，无他。要点是分析每位 (个位、十位、百位...) 上 `1` 出现的次数。规律为：
```
# c 位置上可出现 1 的个数为：

      ↓
n = abcde      left=ab, digit=c, right=de, base=100

if digit == 0:
    ones = left * base
if digit == 1:
    ones = left * base + right + 1
if digit > 1:
    ones = (left + 1) * base
```
以 `315` 为例：
```
    个位：
           ↓
         315      left=31, digit=5, right=0, base=1
    个位上包含 1 的数为：
        - 1                     # 1
        - 11, 21, 31, ..., 311  # 31
    个位上 1 的总个数 = (left + 1) * base
                     = (31 + 1) * 1

    十位：
          ↓
         315      left=3, digit=1, right=5, base=10
    十位上包含 1 的数为：
        - 10~19, 110~119, 210~219  # (3 * 10)
        - 310~315                  # 5 + 1
    十位上 1 的总个数 = (left * base) + right + 1 
                     = (3 * 10) + 5 + 1

    百位：
         ↓
         315      left=0, digit=3, right=15, base=100
    百位上包含 1 的数为：
        - 100~199  # 1 * 100
    百位上 1 的总个数 = (left + 1) * base 
                     = (0 + 1) * 100 
```

## 1053 Path of Equal Weight

树结构其实一个简单的图。类似本题这样的树结构 (树的孩子结点个数不固定) 使用图来表示更加便捷。使用 BFS 即可计算根到叶子节点的路径长度。在 BFS 的过程中使用 `pre[N]` 数组记录每个节点的先驱节点，最后便可通过 `pre` 还原出路径。

## 1057 Stack

若先不考虑栈的操作，如何快速找到一个序列中的中位数？

[使用两个堆：一个最大堆和一个最小堆。](https://stackoverflow.com/questions/11361320/data-structure-to-find-median)

中位数的特征是，它可将一个序列划分为两个等长 (元素总数为偶数时) 或相差为 1 (元素总数为奇数时) 的两个序列，记为 `left` 与 `right`。`left` 中的所有元素**均小于**等于中位数，`right` 中的所有元素**均大于**中位数。使用两个堆来分别表示 `left` (最大堆) 和 `right` (最小堆)，可以方便地维护两个堆中的元素的数量：

- 当插入一个新值 `x` 时，如果 `x` 小于 `Left` 的根，则将其插入到 `Left` 中，反之插入到 `Right` 中；
- 插入后，需要维护两个堆的数量，使他们至多相差为 1：
    - 如果 `Left` 中的元素总数比 `Right` 中的元素总数所多出的个数大于 1，则摘掉 `Left` 中最大的元素 (即根)，并将其插入到 `Right` 中；
    - 如果 `Right` 中的元素总数大于 `Left` 中的元素总数，则取出 `Right` 中的最小的元素 (即根)，然后将其插入到 `Left` 中。

那么，序列的中位数就等于 `Left` 的根。

上述方法的关键点在于：
- 维护两个大小至多相差为 1 的序列
- 可以快速知道 `Left` 的最大值、`Right` 的最小值

题目要求模拟栈的操作，栈的操作中包括 `Pop` 操作，需要删除元素，然而在堆中删除一个元素的时间复杂度是 `O(n)`。有没有符合上述特征的数据结构且删除元素的时间复杂度较小呢？

C++ 中 `std::multiset` 就可以满足这样的要求。它是一个有序的数据结构，插入、删除都是对数时间复杂度。因此使用 `std::multiset` 来实现 `Left` 和 `Right` 即可。

另外一种思路是统计每个元素出现的频率，然后使用[二进制索引树](https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/)来高效地计算累积频率为 N/2 (元素总数为偶数时) 或 (N+1)/2 (元素总数为奇数时) 所对应的元素。

## 1059 Prime Factors

递归地分解一个数，采用 `memoization` 技巧记录已确定是质数的数以避免重复计算。

## 1064 Complete Binary Search Tree

完全二叉树的一个特征是，可以使用一个数组来存储，只要自上而下、从左至右对其所有结点进行编号即可。同时，给定一个结点编号 `i`，可以很方便地得到其孩子结点 (`lchild: 2 * i + 1, rchild: 2 * i + 2`)。因此，我们可仅对其编号进行中序遍历，得到的便是**结点编号**的中序遍历 (记为 `inorder_idx`)。

题目中给出的是完全二叉搜索树，因此它的中序遍历必然是有序的，对给出的序列排序即可得到该树的**结点值**的中序遍历 (记为 `inorder`)。

最后，通过 `inorder_idx` 和 `inorder` 即可复原该树。

## 1066 Root of AVL Tree

因插入结点而导致需要旋转的情形总共有四种：
```
    # A 为发现问题的节点，即平衡因子大于 1 或小于 -1
    # new 为新插入的结点

       (1)      (2)      (3)      (4)
        A        A        A        A
       /        /          \        \
      B        B            B        B
     /          \          /          \
    new         new       new         new
    
    # 每种情形的旋转方法：
    (1) 将 A 树右旋
    (2) 先将 B 子树左旋，再将 A 树右旋
    (3) 先将 B 子树右旋，再将 A 树左旋
    (4) 将 A 树左旋
```
因此只需要实现两种旋转即可：**右旋** (`right_rotate`) 和**左旋** (`left_rotate`)。

问题的关键在于当找到问题结点时，如何确定属于上述 4 种情形的哪一种？

- 根据 A 的平衡因子，可以判断是 `(1), (2)` 还是 `(3), (4)`
- 再根据 new 结点的值与 B 的值大小关系即可进一步确定是何种类型

伪代码如下：
```python
balance_factor = height(A.left) - height(A.right)
if balance_factor > 1:  # (1) or (2)
    if new_node.key > B.key:  # (2)
        left_rotate(B)
    right_rotate(A)  # (1)
else if balance_factor < -1:  # (3) or (4)
    if new_node.key < B.key:  # (3)
        right_rotate(B)
    left_rotate(A)  # (4)
```

## 1067 Sort with Swap(0, i)

模拟手动 Swap 的过程：
1. 只要第 0 位不是 0，便将 0 所在位置交换为正确的数;
2. 当第 0 位是 0 时，找到下一个错误的数，将其与 0 交换后再继续执行 1。

实现思路：
1. **没必要**读入位置已经正确的数
2. 使用字典 (Python: `dict`, C++: `map`) 类型记录 `num_to_index`，便可以快速地定位到找到下一个需要 Swap 的数
3. 「当第 0 位是 0 时，找到下一个错误的数」：为了更快地找到下一个错误的数，可以及时删掉位置已经正确的数，缩小搜索空间

## 1068 Find More Coins

等价于**不允许重复的背包问题 (Knapsack without repetition)**，典型的动态规划问题。

比较 tricky 的地方在于如何输出动态规划的路径，因为路径可能不止一条。还原出所有可能的路径并不是一件容易的事。好在题目只需要最小序列，因此只需要在动态规划之前先将所有的硬币按面值逆序排序即可，这样就可以记录一条最小的路径。

## 1072 Gas Station

根据 Dijkstra 算法求出各个加油站到各个居民宅的最短距离即可，然后按照题目要求找出符合条件的最佳加油站。

加油站也是图中的结点，但由于加油站的编号并非纯数字，因此采用字典 (Python: `dict`, C++: `map`) 结构来构建图的邻接表最为方便，但这么做会超时 (无论使用 C++ 还是 Python)。

因此只能选择将加油站的编号 `G1, G2, ...` 转换为整数，即 `n_house + 1, n_house + 2, ...`，这样便可以采用数组结构来构建图的邻接表，加快访问速度。
