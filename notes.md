
* [1032 Sharing](#1032-sharing)
* [1033 To Fill or Not to Fill](#1033-to-fill-or-not-to-fill)
* [1034 Head of a Gang](#1034-head-of-a-gang)
* [1038 Recover the Smallest Number](#1038-recover-the-smallest-number)

# 1032 Sharing

将*链表 A* 的每个结点均标记为**已访问**，那么在遍历*链表 B* 时遇到的第一个**已访问过**的节点就是它们的第一个共同结点。

# 1033 To Fill or Not to Fill

记当前加油站所能行至的最大距离为 `max_dist`，那么：
1. 在 `max_dist` 范围内找到比它便宜的作为下一个加油站
2. 如果没有比它便宜的，则选择离 `max_dist` 最近的作为下一个加油站

# 1034 Head of a Gang

虽然看起来像是一个有向图，但实际上它是一个无向图，此时一条边的权重等于双向边之和：
```
        有向图                       无向图
    AAA -> BBB 10    --等价于->   AAA - BBB 30        
    BBB -> AAA 20       
```

因此该问题等价于找到无向图中的连通分量问题。使用 BFS 或者 DFS 都可以完成任务。

# 1038 Recover the Smallest Number

将数字片段组合起来实际上是一个排序问题。排序问题的核心是什么？

**谁前谁后**。

C/C++ 中的**比较函数**就是用来让我们告诉 C/C++ 是参数一放在参数二之后还是参数二放在参数一之后。

同样的，当将数字片段组成一个数字时，`32` 与 `321` 谁前谁后？

比较 `32321` 与 `32132` 即可知道答案（字符串相加很便捷）。

因此通过在比较函数中定义两个片段的**谁前谁后**就能决定所有片段的排列顺序。
