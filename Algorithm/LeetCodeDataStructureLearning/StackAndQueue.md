# 栈和队列

## 622.设计循环队列

### Question

> 设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
>
> 循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
>
> 你的实现应该支持如下操作：
>
> - `MyCircularQueue(k)`: 构造器，设置队列长度为 k 。
> - `Front`: 从队首获取元素。如果队列为空，返回 -1 。
> - `Rear`: 获取队尾元素。如果队列为空，返回 -1 。
> - `enQueue(value)`: 向循环队列插入一个元素。如果成功插入则返回真。
> - `deQueue()`: 从循环队列中删除一个元素。如果成功删除则返回真。
> - `isEmpty()`: 检查循环队列是否为空。
> - `isFull()`: 检查循环队列是否已满。
>
> **示例：**
>
> ```
> MyCircularQueue circularQueue = new MycircularQueue(3); // 设置长度为 3
> 
> circularQueue.enQueue(1);  // 返回 true
> 
> circularQueue.enQueue(2);  // 返回 true
> 
> circularQueue.enQueue(3);  // 返回 true
> 
> circularQueue.enQueue(4);  // 返回 false，队列已满
> 
> circularQueue.Rear();  // 返回 3
> 
> circularQueue.isFull();  // 返回 true
> 
> circularQueue.deQueue();  // 返回 true
> 
> circularQueue.enQueue(4);  // 返回 true
> 
> circularQueue.Rear();  // 返回 4
>  
> ```
>
> **提示：**
>
> - 所有的值都在 0 至 1000 的范围内；
> - 操作数将在 1 至 1000 的范围内；
> - 请不要使用内置的队列库。

### Solution1

数组模拟，数据成员`size`不是必须的，可以用`head`和`tail`来判断空满与否，但加入`size`让程序更易懂。

```c++
class MyCircularQueue
{
private:
    int *queue;
    int capacity = 0, size = 0;
    int head = 0, tail = 0;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) : capacity(k)
    {
        queue = new int[k];
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value)
    {
        if (isFull())
            return false;
        queue[tail] = value;
        ++size;
        tail = (tail + 1) % capacity;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue()
    {
        if (isEmpty())
            return false;
        head = (head + 1) % capacity;
        --size;
        return true;
    }

    /** Get the front item from the queue. */
    int Front()
    {
        if (isEmpty())
            return -1;
        return queue[head];
    }

    /** Get the last item from the queue. */
    int Rear()
    {
        if (isEmpty())
            return -1;
        return queue[(tail + capacity - 1) % capacity];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty()
    {
        return (size == 0);
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull()
    {
        return (size == capacity);
    }
};
```

### Solution2

可以用双向链表，但是在这里使用较为繁琐。

## 346.数据流中的平均值

### Question

> 给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算其所有整数的移动平均值。
>
> 示例:
>
> ```
> MovingAverage m = new MovingAverage(3);
> m.next(1) = 1
> m.next(10) = (1 + 10) / 2
> m.next(3) = (1 + 10 + 3) / 3
> m.next(5) = (10 + 3 + 5) / 3
> ```

### Solution

这里其实`MovingAverage`内部实现便是一个固定长度的队列。

```c++
class MovingAverage
{
private:
    double sum;
    queue<double> movingWindow;
    int windowLen;

public:
    MovingAverage(int length) : windowLen(length) {}
    double next(double value)
    {
        if (movingWindow.size() >= windowLen)
        {
            sum -= movingWindow.front();
            movingWindow.pop();
        }
        movingWindow.push(value);
        sum += value;
        return sum / movingWindow.size();
    }
};
```

## 队列和BFS

1. 如代码所示，在每一轮中，队列中的结点是`等待处理的结点`。
2. 在每个更外一层的 `while` 循环之后，我们`距离根结点更远一步`。变量 `step` 指示从根结点到我们正在访问的当前结点的距离。
3. 如下的板子需要：
   1. 完全确定没有循环（圈），例如，在树遍历中；
   2. 确实希望多次将结点添加到队列中。

```c++
/**
 * Return the length of the shortest path between root and target node.
 */
int BFS(Node root, Node target) {
    Queue<Node> queue;  // store all nodes which are waiting to be processed
    int step = 0;       // number of steps neeeded from root to current node
    // initialize
    add root to queue;
    // BFS
    while (queue is not empty) {
        step = step + 1;
        // iterate the nodes which are already in the queue
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            Node cur = the first node in queue;
            return step if cur is target;
            for (Node next : the neighbors of cur) {
                add next to queue;
            }
            remove the first node from queue;
        }
    }
    return -1;          // there is no path from root to target
}
```

4. 不重复的板子：

```c++
/**
 * Return the length of the shortest path between root and target node.
 */
int BFS(Node root, Node target) {
    Queue<Node> queue;  // store all nodes which are waiting to be processed
    Set<Node> used;     // store all the used nodes
    int step = 0;       // number of steps neeeded from root to current node
    // initialize
    add root to queue;
    add root to used;
    // BFS
    while (queue is not empty) {
        step = step + 1;
        // iterate the nodes which are already in the queue
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            Node cur = the first node in queue;
            return step if cur is target;
            for (Node next : the neighbors of cur) {
                if (next is not in used) {
                    add next to queue;
                    add next to used;
                }
            }
            remove the first node from queue;
        }
    }
    return -1;          // there is no path from root to target
}
```

5. 双向BFS板子（递归版，好写一点）：

```c++
int DBFS(set<Node> &start, set<Node> &end, bool visited[], int depth)
{
    if(start.size() <= 0) //can not find crash
        return -1;
    
    if(start.size() > end.size()) //expand the smaller side
        return DBFS(ed, st, visited, depth);
    
    set<Node> next;
    for(Node cur : start)
    {
		cur is visited;
        for(Node forward : the neighbors of cur)
        {
			if(forward is not visited)//unvisited
            {
				if(forward is in end) return depth;//crash
                add forward to next;
			}
        }
    }
    
    return DBFS(next, end, visited, depth + 1);//next expand
}
```



## 200.岛屿数量

### Question

> 给定一个由 `'1'`（陆地）和 `'0'`（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
>
> **示例 1:**
>
> ```
> 输入:
> 11110
> 11010
> 11000
> 00000
> 
> 输出: 1
> ```
>
> **示例 2:**
>
> ```
> 输入:
> 11000
> 11000
> 00100
> 00011
> 
> 输出: 3
> ```

### Solution1

慢！但可修改策略，BFS。

```c++
class Solution
{
private:
    int row, col;
    queue<pair<int, int>> search;
    inline void expend(vector<vector<char>> &grid, int r, int c)
    {
        if (r < 0 || c < 0 || r >= row || c >= col || grid[r][c] == '0')
            return;
        search.push({r, c});
        grid[r][c] = '0';
    }

public:
    void BFS(vector<vector<char>> &grid, pair<int, int> I)
    {
        pair<int, int> cur;
        int queueSize;

        search.push(I);
        grid[I.first][I.second] = '0';
        while (!search.empty())
        {
            queueSize = search.size();
            for (int i = 0; i < queueSize; ++i)
            {
                cur = search.front();
                search.pop();
                expend(grid, cur.first - 1, cur.second);
                expend(grid, cur.first, cur.second + 1);
                expend(grid, cur.first + 1, cur.second);
                expend(grid, cur.first, cur.second - 1);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        row = grid.size();
        if (row == 0)
            return 0;

        col = grid[0].size();
        if (col == 0)
            return 0;

        int count = 0;
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (grid[i][j] == '1')
                {
                    BFS(grid, {i, j});
                    ++count;
                }

        return count;
    }
};
```

### Solution2

DFS，一般般。

```c++
class Solution
{
private:
    int row, col;
    void DFS(vector<vector<char>> &grid, int r, int c)
    {
        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r - 1][c] == '1')
            DFS(grid, r - 1, c);
        if (r + 1 < row && grid[r + 1][c] == '1')
            DFS(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c - 1] == '1')
            DFS(grid, r, c - 1);
        if (c + 1 < col && grid[r][c + 1] == '1')
            DFS(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        row = grid.size();
        if (row == 0)
            return 0;

        col = grid[0].size();
        if (col == 0)
            return 0;

        int count = 0;
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (grid[i][j] == '1')
                {
                    ++count;
                    DFS(grid, i, j);
                }

        return count;
    }
};
```

### Solution3

[并查集]()，这个我不怎么会鸭，先去学并查集了2333333。

```c++
class DisjointSet
{
private:
    vector<int> parent;
    vector<int> rank;
    int setNum;

public:
    DisjointSet(int Size) : parent(vector<int>(Size)),
                            rank(vector<int>(Size, 0)),
                            setNum(Size)
    {
        for (int i = 0; i < Size; ++i)
            parent[i] = i;
    }
    int find(int x) { return (parent[x] == x)
                                 ? x
                                 : (parent[x] = find(parent[x])); }
    void getUnion(int x1, int x2)
    {
        int p1 = find(x1), p2 = find(x2);
        if (p1 == p2)
            return;
        if (rank[p1] > rank[p2])
            parent[p2] = p1;
        else
        {
            parent[p1] = p2;
            if (rank[p1] == rank[p2])
                ++rank[p2];
        }
        --setNum;
    }
    int getSetNum(void) { return setNum; }
};

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int row = grid.size();
        if (row == 0)
            return 0;

        int col = grid[0].size();
        if (col == 0)
            return 0;

        DisjointSet DS(col * row);
        int loc, zeroNum = 0;
        for (int r = 0; r < row; ++r)
            for (int c = 0; c < col; ++c)
                if (grid[r][c] == '1')
                {
                    grid[r][c] = '0';
                    loc = r * col + c;
                    if (r - 1 >= 0 && grid[r - 1][c] == '1')
                        DS.getUnion(loc, loc - col);
                    if (r + 1 < row && grid[r + 1][c] == '1')
                        DS.getUnion(loc, loc + col);
                    if (c - 1 >= 0 && grid[r][c - 1] == '1')
                        DS.getUnion(loc, loc - 1);
                    if (c + 1 < col && grid[r][c + 1] == '1')
                        DS.getUnion(loc, loc + 1);
                }
                else
                    ++zeroNum;
        return DS.getSetNum() - zeroNum;
    }
};
```

## 752.打开转盘锁

### Question

> 你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： `'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'` 。每个拨轮可以自由旋转：例如把 `'9'` 变为  `'0'`，`'0'` 变为 `'9'` 。每次旋转都只能旋转一个拨轮的一位数字。
>
> 锁的初始数字为 `'0000'` ，一个代表四个拨轮的数字的字符串。
>
> 列表 `deadends` 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
>
> 字符串 `target` 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。
>
> **示例 1:**
>
> ```
> 输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
> 输出：6
> 解释：
> 可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
> 注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
> 因为当拨动到 "0102" 时这个锁就会被锁定。
> ```
>
> **示例 2:**
>
> ```
> 输入: deadends = ["8888"], target = "0009"
> 输出：1
> 解释：
> 把最后一位反向旋转一次即可 "0000" -> "0009"。
> ```
>
> **示例 3:**
>
> ```
> 输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
> 输出：-1
> 解释：
> 无法旋转到目标数字且不被锁定。
> ```
>
> **示例 4:**
>
> ```
> 输入: deadends = ["0000"], target = "8888"
> 输出：-1
> ```
>
> **提示：**
>
> 1. 死亡列表 `deadends` 的长度范围为 `[1, 500]`。
> 2. 目标数字 `target` 不会在 `deadends` 之中。
> 3. 每个 `deadends` 和 `target` 中的字符串的数字会在 10,000 个可能的情况 `'0000'` 到 `'9999'` 中产生。

### Solution1

单向广搜，玄学速度。

```c++
class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> ends(deadends.begin(), deadends.end());

        if (ends.count("0000"))
            return -1;

        queue<string> next;
        vector<int> direct = {1, -1};
        string cur, forward;
        int distance = 0, queueSize;
        unordered_set<string> visited = {{"0000"}};

        next.push("0000");

        while (!next.empty())
        {
            ++distance;
            queueSize = next.size();
            while (--queueSize >= 0)
            {
                cur = next.front();
                next.pop();

                for (int i = 0; i < 4; ++i)
                {
                    for (int j = 0; j < 2; ++j)
                    {
                        forward = cur;
                        forward[i] = (forward[i] - '0' + direct[j] + 10) % 10 + '0';
                        if (forward == target)
                            return distance;
                        if (!visited.count(forward) && !ends.count(forward))
                        {
                            next.push(forward);
                            visited.insert(forward);
                        }
                    }
                }
            } //for queue
        }
        return -1;
    }
};
```

### Solution2

双向广搜，恐怖速度。

```c++
class Solution
{
private:
    static const vector<int> direct;

    int DBFS(unordered_set<string> &st, unordered_set<string> &ed, bool visited[], int depth)
    {
        if (st.size() <= 0)
            return -1;
        if (st.size() > ed.size())
            return DBFS(ed, st, visited, depth);

        unordered_set<string> next;
        string forward;
        int loc;
        for (string str : st)
        {
            visited[stoi(str)] == true;
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 2; ++j)
                {
                    forward = str;
                    forward[i] = (forward[i] - '0' + direct[j] + 10) % 10 + '0';
                    loc = stoi(forward);
                    if (!visited[loc]) //unvisited
                    {
                        if (ed.count(forward))
                            return depth; //crash
                        next.insert(forward);
                    }
                }
            }
        }
        return DBFS(next, ed, visited, depth + 1);
    }

public:
    int openLock(vector<string> &deadends, string target)
    {
        bool visited[10000] = {0}; //mark the visited node
        unordered_set<string> start, ending;

        for (string i : deadends)
            visited[stoi(i)] = true;
        if (visited[0])
            return -1;

        start.insert("0000");
        ending.insert(target);

        return DBFS(start, ending, visited, 1);
    }
};
const vector<int> Solution::direct = {1, -1};
```

### Solution3

想尝试一下`A*`算法或者`IDA*`算法，挖个坑先。

## 279.完全平方数

### Question

> 给定正整数 *n*，找到若干个完全平方数（比如 `1, 4, 9, 16, ...`）使得它们的和等于 *n*。你需要让组成和的完全平方数的个数最少。
>
> **示例 1:**
>
> ```
> 输入: n = 12
> 输出: 3 
> 解释: 12 = 4 + 4 + 4.
> ```
>
> **示例 2:**
>
> ```
> 输入: n = 13
> 输出: 2
> 解释: 13 = 4 + 9.
> ```

### Solution1

贪心，错解。

```c++
class Solution
{
private:
    static int count;

public:
    int numSquares(int n)
    {
        int x = floor(sqrt(n));
        n -= x * x;
        ++count;
        if (n == 0)
            return count;
        else
            return numSquares(n);
    }
};
int Solution::count = 0;
```

### Solution2

完全背包问题变体，超时。

```c++
class Solution
{
public:
    int numSquares(int n)
    {
        int x = floor(sqrt(n));
        vector<int> sqr(x + 1, 0);
        for (int i = 1; i <= x; ++i)
        {
            sqr[i] = i * i;
            //cout << i << " " << sqr[i] << endl;
        }

        vector<vector<int>> dp(x + 1, vector<int>(n + 1, 0));
        vector<vector<int>> count(x + 1, vector<int>(n + 1, 0));
        int newdp;

        for (int i = 1; i <= x; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                for (int k = 1; k <= j / sqr[i]; ++k)
                {
                    newdp = dp[i - 1][j - k * sqr[i]] + k * sqr[i];
                    if (dp[i - 1][j] <= newdp)
                    {
                        dp[i][j] = newdp;
                        count[i][j] = count[i - 1][j - k * sqr[i]] + k;
                    }
                } //k
                if (dp[i][j] == 0 || (i != 1 && count[i][j] > count[i - 1][j]))
                {
                    dp[i][j] = dp[i - 1][j];
                    count[i][j] = count[i - 1][j];
                }
                //cout << "(" << dp[i][j] << "," << count[i][j] << ")";
            } //j
            //cout << endl;
        } //i
        int minCount = __INT_MAX__;
        for (int i = 1; i <= x; ++i)
            minCount = min(count[i][n], minCount);

        return minCount;
    }
};
```

### Solution3

正常动态规划，`dp[i]=min(dp[i], dp[i - j * j] + 1)`，比较慢。

```c++
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, 0);
        int i, j, last;
        for (i = 0; i <= n; ++i)
        {
            dp[i] = i;
            for (j = 0, last = i - j * j; last >= 0; ++j, last = i - j * j)
//for (j = floor(sqrt(i)), last = i - j * j; j >= 0; --j, last = i - j * j)
            {
                dp[i] = min(dp[i], dp[last] + 1);
            }
        }
        return dp[n];
    }
};
```

### Solution4

正常广搜，比较快。

```c++
class Solution
{
public:
    int numSquares(int n)
    {
        queue<int> sqr;
        vector<bool> visited(n + 1, false);
        int step = 0;
        sqr.push(n);
        while (!sqr.empty())
        {
            ++step;
            int size = sqr.size();
            while (--size >= 0)
            {
                int cur = sqr.front();
                visited[cur] = true;
                sqr.pop();
                for (int i = floor(sqrt(cur)); i >= 1; --i)
                {
                    int forward = cur - i * i;
                    if (forward == 0)
                        return step;
                    if (!visited[forward])
                        sqr.push(forward);
                }
            }
        }
        return -1;
    }
};
```

### Solution5

双向广搜，一般般。

```c++
class Solution
{
private:
    int target;

    int DBFS(unordered_set<int> &start, unordered_set<int> &end, vector<bool> &visited, int depth, int direct)
    {
        if (start.size() <= 0)
            return -1;
        unordered_set<int> next;
        if (direct == 1)
        {
            for (int i : start)
            {
                visited[i] = true;
                for (int j = floor(sqrt(i)); j >= 1; --j)
                {
                    int forward = i - j * j;
                    if (!visited[forward])
                    {
                        if (end.count(forward))
                            return depth;
                        next.insert(forward);
                    }
                }
            }
            if (next.size() > end.size())
                return DBFS(next, end, visited, depth + 1, 0);
            else
                return DBFS(next, end, visited, depth + 1, 1);
        }
        else
        {
            for (int i : end)
            {
                visited[i] = true;
                for (int j = floor(sqrt(target - i)); j >= 1; --j)
                {
                    int forward = i + j * j;
                    if (!visited[forward])
                    {
                        if (start.count(forward))
                            return depth;
                        next.insert(forward);
                    }
                }
            }
            if (next.size() > start.size())
                return DBFS(start, next, visited, depth + 1, 1);
            else
                return DBFS(start, next, visited, depth + 1, 0);
        }
    }

public:
    int numSquares(int n)
    {
        unordered_set<int> start, end;
        vector<bool> visited(n + 1, false);
        target = n;
        start.insert(n);
        end.insert(0);
        return DBFS(start, end, visited, 0, 1);
    }
};
```

### Solution6

**四平方数定理：每个正整数均可表为四个整数的平方和(其中有些整数可以为零)。**

推论：满足四数平方和定理的数$n$（四个整数的情况），必定满足 $n=(4^a) \times (8b+7)$。

灰常快！

```
class Solution
{
public:
    int numSquares(int n)
    {
        while (n % 4 == 0)
            n /= 4;
        if (n % 8 == 7)
            return 4;
        for (int i = floor(sqrt(n)); i >= 1; --i)
        {
            int sqr = i * i;
            int j = floor(sqrt(n - sqr));
            if (j * j + sqr == n)
            {
                if (i != 0 && j != 0)
                    return 2;
                else
                    return 1;
            }
        }
        return 3;
    }
};
```

## 155.最小栈

### Question

> 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
>
> - push(x) -- 将元素 x 推入栈中。
> - pop() -- 删除栈顶的元素。
> - top() -- 获取栈顶元素。
> - getMin() -- 检索栈中的最小元素。
>
> **示例:**
>
> ```
> MinStack minStack = new MinStack();
> minStack.push(-2);
> minStack.push(0);
> minStack.push(-3);
> minStack.getMin();   --> 返回 -3.
> minStack.pop();
> minStack.top();      --> 返回 0.
> minStack.getMin();   --> 返回 -2.
> ```

### Solution

```c++
class MinStack
{
private:
    stack<int> mainStack;
    stack<int> minVal;

public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x)
    {
        mainStack.push(x);
        if (minVal.empty() || minVal.top() >= x)
            minVal.push(x);
    }

    void pop()
    {
        if (!mainStack.empty())
        {
            if (mainStack.top() == minVal.top())
            {
                mainStack.pop();
                minVal.pop();
            }
            else
                mainStack.pop();
        }
    }

    int top()
    {
        return mainStack.top();
    }

    int getMin()
    {
        return minVal.top();
    }
};
```

## 20.有效的括号

### Question

> 给定一个只包括 `'('`，`')'`，`'{'`，`'}'`，`'['`，`']'` 的字符串，判断字符串是否有效。
>
> 有效字符串需满足：
>
> 1. 左括号必须用相同类型的右括号闭合。
> 2. 左括号必须以正确的顺序闭合。
>
> 注意空字符串可被认为是有效字符串。
>
> **示例 1:**
>
> ```
> 输入: "()"
> 输出: true
> ```
>
> **示例 2:**
>
> ```
> 输入: "()[]{}"
> 输出: true
> ```
>
> **示例 3:**
>
> ```
> 输入: "(]"
> 输出: false
> ```
>
> **示例 4:**
>
> ```
> 输入: "([)]"
> 输出: false
> ```
>
> **示例 5:**
>
> ```
> 输入: "{[]}"
> 输出: true
> ```

### Solution

```c++
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> bracket;
        int sLen = s.length();
        char topChar, c;
        for (int i = 0; i < sLen; ++i)
        {
            switch (s[i])
            {
            case '(':
            case '[':
            case '{':
                bracket.push(s[i]);
                continue;
            case ')':
                c = '(';
                break;
            case ']':
                c = '[';
                break;
            case '}':
                c = '{';
                break;
            }
            topChar = bracket.empty() ? '#' : bracket.top();
            if (topChar != c)
                return false;
            else
                bracket.pop();
        }
        return bracket.empty();
    }
};
```

## 739.每日温度

### Question

> 根据每日 `气温` 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 `0` 来代替。
>
> 例如，给定一个列表 `temperatures = [73, 74, 75, 71, 69, 72, 76, 73]`，你的输出应该是 `[1, 1, 4, 2, 1, 1, 0, 0]`。
>
> **提示：**`气温` 列表长度的范围是 `[1, 30000]`。每个气温的值的均为华氏度，都是在 `[30, 100]` 范围内的整数。

### Solution1

最直接的想法，从右至左进行遍历，对于每一个元素都再从当前位置向右搜索，直至遇见恰好比该元素大的位置，然后存入二者之差。时间复杂度最好$O(2n)$，最差$O(n^2)$。

```c++
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        int Size = T.size();
        vector<int> ans(Size, 0);

        for (int i = Size - 2; i >= 0; --i)
        {
            for (int j = i + 1; j < Size; ++j)
                if (T[j] > T[i])
                {
                    ans[i] = j - i;
                    break;
                }
        }
        return ans;
    }
};
```

### Solution2

优化第一种方法，当向右搜索时，先判断当前元素与下一元素的大小关系，利用已知的下一个较大元素的位置，跳过一部分重复搜索位置，时间复杂度最好$O(2n)$，最差$O(n^2)$，但对于连续重复元素处理较快。

```c++
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        int Size = T.size();
        vector<int> ans(Size, 0);

        for (int i = Size - 2; i >= 0; --i)
        {
            if (T[i + 1] > T[i])
                ans[i] = 1;
            else if (T[i + 1] == T[i])
            {
                if (ans[i + 1] == 0)
                    ans[i] = 0;
                else
                    ans[i] = ans[i + 1] + 1;
            }
            else
            {
                for (int j = i + 1 + ans[i + 1]; j < Size; ++j)
                    if (T[j] > T[i])
                    {
                        ans[i] = j - i;
                        break;
                    }
            }
        }
        return ans;
    }
};
```

### Solution3

进一步优化第二种方法，输入越来越长，只跳跃一次远远不够，所以每一次跳跃之后都要进行判断，进而判断是否进行下一次跳跃或已搜索到目标。

```c++
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        int Size = T.size();
        vector<int> ans(Size, 0);

        for (int i = Size - 2; i >= 0; --i)
        {
            int next = i + 1;
            while (next < Size)
            {
                if (T[next] > T[i])
                {
                    ++ans[i];
                    break;
                }
                else if (ans[next] == 0)
                {
                    ans[i] = 0;
                    break;
                }
                else
                {
                    ans[i] += ans[next];
                    next += ans[next];
                }
            }
        //	   int next = i + 1;
        //     while (next < Size)
        //     {
        //         if (T[next] > T[i])
        //         {
        //             ans[i] = next - i;
        //             break;
        //         }
        //         else if (ans[next] == 0)
        //         {
        //             ans[i] = 0;
        //             break;
        //         }
        //         next += ans[next];
        //     }
        // }
        }

        return ans;
    }
};
```

### Solution4

- 单调栈保存着一个数组以下这样的信息：

如果是找某个位置左右两边大于此数且最下标靠近它的数位置，那么扫描到下标i的时候的单调栈保存的是`0~i-1`区间中数字的的递增序列的下标。

（找某个位置左右两边小于此数且最下标靠近它的数的位置的情况类似）

- 作用：可以$O(1)$时间得知某个位置左右两侧比他大（或小）的数的位置

- 什么时候能用单调栈？

在你有高效率获取某个位置左右两侧比他大（或小）的数的位置的需求的时候。

实测来看，这种方法并没有很快，可能是重复元素过多导致。

```c++
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        int Size = T.size();
        stack<int> res;
        vector<int> ans(Size, 0);

        for (int i = Size - 1; i >= 0; --i)
        {
            while (!res.empty() && T[i] >= T[res.top()])
                res.pop();
            if (res.empty())
                ans[i] = 0;
            else
                ans[i] = res.top() - i;
            res.push(i);
        }

        return ans;
    }
};
```

## 150.逆波兰表达式求值

### Question

> 根据逆波兰表示法，求表达式的值。
>
> 有效的运算符包括 `+`, `-`, `*`, `/` 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
>
> **说明：**
>
> - 整数除法只保留整数部分。
> - 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
>
> **示例 1：**
>
> ```
> 输入: ["2", "1", "+", "3", "*"]
> 输出: 9
> 解释: ((2 + 1) * 3) = 9
> ```
>
> **示例 2：**
>
> ```
> 输入: ["4", "13", "5", "/", "+"]
> 输出: 6
> 解释: (4 + (13 / 5)) = 6
> ```
>
> **示例 3：**
>
> ```
> 输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
> 输出: 22
> 解释: 
>   ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
> = ((10 * (6 / (12 * -11))) + 17) + 5
> = ((10 * (6 / -132)) + 17) + 5
> = ((10 * 0) + 17) + 5
> = (0 + 17) + 5
> = 17 + 5
> = 22
> ```

### Solution

详见[逆波兰表达式的实现](../ReversePolishNotation.md)。

```c++
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> ans;
        int Size = tokens.size(), temp;
        for (string i : tokens)
        {
            if (i.length() != 1 || isdigit(i[0]))
                ans.push(stoi(i));
            else
            {
                temp = ans.top();
                ans.pop();
                cout << ans.top() << endl;

                switch (i[0])
                {
                case '+':
                    ans.top() += temp;
                    break;
                case '-':
                    ans.top() -= temp;
                    break;
                case '*':
                    ans.top() *= temp;
                    break;
                case '/':
                    ans.top() /= temp;
                    break;
                }
                cout << ans.top() << endl;
            }
        }
        return ans.top();
    }
};
```

## 栈和DFS

1. 在大多数情况下，我们在能使用 BFS 时也可以使用 DFS。但是有一个重要的区别：`遍历顺序`。与 BFS 不同，`更早访问的结点可能不是更靠近根结点的结点`。因此，你在 DFS 中找到的第一条路径`可能不是最短路径`。
2. 模板一，递归型，当我们递归地实现 DFS 时，似乎不需要使用任何栈。但实际上，我们使用的是由系统提供的隐式栈，也称为调用栈。

```c++
/*
 * Return true if there is a path from cur to target.
 */
bool DFS(Node cur, Node target, Set<Node> visited) {
    return true if cur is target;
    for (next : each neighbor of cur) {
        if (next is not in visited) {
            add next to visted;
            return true if DFS(next, target, visited) == true;
        }
    }
    return false;
}
```

3. 模板二，显示栈。

```c++
/*
 * Return true if there is a path from cur to target.
 */
bool DFS(int root, int target) {
    Set<Node> visited;
    Stack<Node> s;
    add root to s;
    while (s is not empty) {
        Node cur = the top element in s;
        return true if cur is target;
        for (Node next : the neighbors of cur) {
            if (next is not in visited) {
                add next to s;
                add next to visited;
            }
        }
        remove cur from s;
    }
    return false;
}
```

## 133.克隆图

### Question

> 给定无向**连通**图中一个节点的引用，返回该图的**深拷贝**（克隆）。图中的每个节点都包含它的值 `val`（`Int`） 和其邻居的列表（`list[Node]`）。
>
> **示例：**
>
> ![](D:\Diary\img\113_sample.png)
>
> ```
> 输入：
> {"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":[{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}
> 
> 解释：
> 节点 1 的值是 1，它有两个邻居：节点 2 和 4 。
> 节点 2 的值是 2，它有两个邻居：节点 1 和 3 。
> 节点 3 的值是 3，它有两个邻居：节点 2 和 4 。
> 节点 4 的值是 4，它有两个邻居：节点 1 和 3 。
> ```
>
> **提示：**
>
> 1. 节点数介于 1 到 100 之间。
> 2. 无向图是一个简单图，这意味着图中没有重复的边，也没有自环。
> 3. 由于图是无向的，如果节点 *p* 是节点 *q* 的邻居，那么节点 *q* 也必须是节点 *p* 的邻居。
> 4. 必须将**给定节点的拷贝**作为对克隆图的引用返回。

### Solution1

DFS，递归，隐式栈，其实就是考遍历无向图。

```c++
class Solution
{
public:
    unordered_map<Node *, Node *> visited;
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        if (visited.count(node))
            return visited[node];
        int Size = node->neighbors.size();
        Node *NewNode = new Node(node->val, {});
        visited[node] = NewNode; //map
        for (int i = 0; i < Size; ++i)
        {
            if (node->neighbors[i] != nullptr)
                NewNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return NewNode;
    }
};
```

### Solution2

DFS，非递归，显式栈。

```c++
class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> visited;
        stack<Node *> search;
        Node *cur, *next, *curCopy, *copy, *nextCopy;

        copy = new Node(node->val, {});
        visited[node] = copy; //make map
        search.push(node);    //add root to stack

        while (!search.empty())
        {
            cur = search.top();
            search.pop();

            curCopy = visited[cur]; //get map

            int Size = cur->neighbors.size();
            for (int i = 0; i < Size; ++i)
            {
                next = cur->neighbors[i];

                if (!visited.count(next)) //judge whether we have searched the node
                {
                    nextCopy = new Node(next->val, {}); //copy next node

                    curCopy->neighbors.push_back(nextCopy); //copy current node

                    search.push(next); //add next to stack

                    visited[next] = nextCopy; //make map
                }
                else
                    curCopy->neighbors.push_back(visited[next]); //point back
            }
        }
        return copy;
    }
};
```

### Solution3 #

DFS。和**Solution2**相比，仅仅是将`stack`换成了`queue`。

```c++
class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> visited;
        queue<Node *> search;
        Node *cur, *next, *curCopy, *copy, *nextCopy;

        copy = new Node(node->val, {});
        visited[node] = copy; //make map
        search.push(node);    //enqueue

        while (!search.empty())
        {
            cur = search.front();
            search.pop();

            curCopy = visited[cur]; //get map

            int Size = cur->neighbors.size();
            for (int i = 0; i < Size; ++i)
            {
                next = cur->neighbors[i];

                if (!visited.count(next)) //judge whether we have searched the node
                {
                    nextCopy = new Node(next->val, {}); //copy next node

                    curCopy->neighbors.push_back(nextCopy); //copy current node

                    search.push(next); //enqueue

                    visited[next] = nextCopy; //make map
                }
                else
                    curCopy->neighbors.push_back(visited[next]); //point back
            }
        }
        return copy;
    }
};
```

## 494.目标和

### Question

> 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 `+` 和 `-`。对于数组中的任意一个整数，你都可以从 `+` 或 `-`中选择一个符号添加在前面。
>
> 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
>
> **示例 1:**
>
> ```
> 输入: nums: [1, 1, 1, 1, 1], S: 3
> 输出: 5
> 解释: 
> 
> -1+1+1+1+1 = 3
> +1-1+1+1+1 = 3
> +1+1-1+1+1 = 3
> +1+1+1-1+1 = 3
> +1+1+1+1-1 = 3
> 
> 一共有5种方法让最终目标和为3。
> ```
>
> **注意:**
>
> 1. 数组的长度不会超过20，并且数组中的值全为正数。
> 2. 初始的数组的和不会超过1000。
> 3. 保证返回的最终结果为32位整数。

### Solution1

BFS，超时严重，解空间大小为$2^{n+1}-1$，因此BFS完全遍历的时间复杂度为$O(2^n)$，具体而言是$T(n)=3\times 2^n-1$，空间复杂度为$O(2^n)$。

```c++
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int numsSize = nums.size();
        queue<int> ans;
        int count = 0, cur;

        ans.push(0);

        for (int j = 0; j < numsSize; ++j)
        {
            int queueSize = ans.size();
            for (int i = 0; i < queueSize; ++i)
            {
                cur = ans.front();
                ans.pop();
                ans.push(cur + nums[j]);
                ans.push(cur - nums[j]);
            }
        }
        while (!ans.empty())
        {
            if (ans.front() == S)
                ++count;
            ans.pop();
        }
        return count;
    }
};
```

### Solution2

DFS，超时严重，理由同上。

```c++
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int numsSize = nums.size();
        stack<pair<int, int>> ans;

        int count = 0, cur;

        ans.push({0, 0});

        while (!ans.empty())
        {
            for (int j = ans.top().second; j < numsSize; ++j)
            {
                cur = ans.top().first;
                ans.pop();

                ans.push({cur + nums[j], j + 1});
                ans.push({cur - nums[j], j + 1});
            }
            if (ans.top().first == S)
                ++count;
            ans.pop();
            if (ans.top().first == S)
                ++count;
            ans.pop();
        }

        return count;
    }
};
```

```c++
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return DFS(nums,0,0,S);
    }
    int  DFS(vector<int>& nums,int n,int sum,int S){
        if(n == nums.size())
            return (sum == S)?1:0;
        return DFS(nums,n+1,sum + nums[n],S) + DFS(nums,n+1,sum - nums[n],S);
    }
};
```

### Solution3

首先计算数组总和`sum`，则总和小于目标`target`直接返回0，由题可知，最终结果相当于将数组划分为两部分，设为`A`和`B`，使其满足`A+B=sum`，`A-B=target`，所以有`A=(sum+target)/2`，因此二者之和必须是偶数，奇数直接返回0，否则问题转化为求子集和为定值的问题。

```c++
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        int sum = 0;
        for (int i : nums)
            sum += i;
        if (sum < S || S > 1000)
            return 0;

        int target = sum + S;
        if (target % 2)
            return 0;
        else
        {
            target /= 2;
            vector<int> dp(target + 1, 0);
            dp[0] = 1;
            for (int &num : nums)
            {
                for (int i = target; i >= num; --i)
                    dp[i] += dp[i - num];
            }
            return dp[target];
        }
    }
};
```

## 94.二叉树的中序遍历

### Question

> 给定一个二叉树，返回它的*中序* 遍历。
>
> **示例:**
>
> ```
> 输入: [1,null,2,3]
>    1
>     \
>      2
>     /
>    3
> 
> 输出: [1,3,2]
> ```
>
> **进阶:** 递归算法很简单，你可以通过迭代算法完成吗？

### Solution1

BFS，隐式栈，递归，很简单。

```c++
class Solution
{
private:
    void traversal(vector<int> &ans, TreeNode *node)
    {
        if (node == nullptr)
            return;
        traversal(ans, node->left);
        ans.push_back(node->val);
        traversal(ans, node->right);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        traversal(ans, root);
        return ans;
    }
};
```

### Solution2

BFS，显示栈，迭代。

```c++
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> searchStack;
        TreeNode *cur = root;
        while (!searchStack.empty() || cur != nullptr)
        {
            while (cur != nullptr) //dfs
            {
                searchStack.push(cur);
                cur = cur->left;
            }
            cur=searchStack.top();
            ans.push_back(cur->val);
            searchStack.pop();
            cur = cur->right;
        }
        return ans;
    }
};
```

### Solution3

[莫里斯遍历](../MorrisTraversal.md)。

```c++
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        TreeNode *cur = root, *connect;
        while (cur != nullptr)
        {
            if (cur->left == nullptr)
            {
                ans.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                connect = cur->left;
                while (connect->right != nullptr && connect->right != cur)
                    connect = connect->right;
                if (connect->right == nullptr)
                {
                    connect->right = cur;
                    cur = cur->left;
                }
                else
                {
                    connect->right = nullptr;
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};
```

## 232.用栈实现队列

### Question

> 使用栈实现队列的下列操作：
>
> - push(x) -- 将一个元素放入队列的尾部。
> - pop() -- 从队列首部移除元素。
> - peek() -- 返回队列首部的元素。
> - empty() -- 返回队列是否为空。
>
> **示例:**
>
> ```
> MyQueue queue = new MyQueue();
> 
> queue.push(1);
> queue.push(2);  
> queue.peek();  // 返回 1
> queue.pop();   // 返回 1
> queue.empty(); // 返回 false
> ```
>
> **说明:**
>
> - 你只能使用标准的栈操作 -- 也就是只有 `push to top`, `peek/pop from top`, `size`, 和 `is empty` 操作是合法的。
> - 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
> - 假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。

### Solution

```c++
class MyQueue
{
private:
    stack<int> prior, back;
    void PriorToBack()
    {
        while (!prior.empty())
        {
            back.push(prior.top());
            prior.pop();
        }
    }
    void BackToPrior()
    {
        while (!back.empty())
        {
            prior.push(back.top());
            back.pop();
        }
    }

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        back.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        BackToPrior();
        int element = prior.top();
        prior.pop();
        PriorToBack();

        return element;
    }

    /** Get the front element. */
    int peek()
    {
        BackToPrior();
        int element = prior.top();
        PriorToBack();
        return element;
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return back.empty();
    }
};
```

## 225.用队列实现栈

### Question

> 使用队列实现栈的下列操作：
>
> - push(x) -- 元素 x 入栈
> - pop() -- 移除栈顶元素
> - top() -- 获取栈顶元素
> - empty() -- 返回栈是否为空
>
> **注意:**
>
> - 你只能使用队列的基本操作-- 也就是 `push to back`, `peek/pop from front`, `size`, 和 `is empty` 这些操作是合法的。
> - 你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
> - 你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。

### Solution

```c++
class MyStack
{
private:
    queue<int> prior, back;
    void BackToPrior()
    {
        while (!back.empty())
        {
            prior.push(back.front());
            back.pop();
        }
    }
    void PriorToBack()
    {
        while (!prior.empty())
        {
            back.push(prior.front());
            prior.pop();
        }
    }

public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        back.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        while (back.size() > 1)
        {
            prior.push(back.front());
            back.pop();
        }
        int element = back.front();
        back.pop();
        while (!prior.empty())
        {
            back.push(prior.front());
            prior.pop();
        }
        return element;
    }

    /** Get the top element. */
    int top()
    {
        while (back.size() > 1)
        {
            prior.push(back.front());
            back.pop();
        }
        int element = back.front();
        prior.push(back.front());
        back.pop();
        while (!prior.empty())
        {
            back.push(prior.front());
            prior.pop();
        }
        return element;
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return back.empty();
    }
};
```

## 394.字符串解码

### Question

> 给定一个经过编码的字符串，返回它解码后的字符串。
>
> 编码规则为: `k[encoded_string]`，表示其中方括号内部的 *encoded_string* 正好重复 *k* 次。注意 *k* 保证为正整数。
>
> 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
>
> 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 *k* ，例如不会出现像 `3a` 或 `2[4]` 的输入。
>
> **示例:**
>
> ```
> s = "3[a]2[bc]", 返回 "aaabcbc".
> s = "3[a2[c]]", 返回 "accaccacc".
> s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
> ```

### Solution

```c++
class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> numStack;
        stack<string> strStack;
        int size = s.length(), num = 0;
        char temp;
        string part;
        for (int i = 0; i < size; ++i)
        {
            if (isdigit(s[i]))
            {
                num = (s[i] - '0') + num * 10;
            }
            else if (isalpha(s[i]))
            {
                part += s[i];
            }
            else if (s[i] == '[')
            {
                numStack.push(num);
                num = 0;
                strStack.push(part);
                part = "";
            }
            else
            {
                int times = numStack.top();
                for (int i = 0; i < times; ++i)
                {
                    strStack.top() += part;
                }
                part = strStack.top();

                strStack.pop();
                numStack.pop();
            }
        }
        return part;
    }
};
```

## 733.图像渲染

### Question

> 有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间。
>
> 给你一个坐标 `(sr, sc)` 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 `newColor`，让你重新上色这幅图像。
>
> 为了完成上色工作，从初始坐标开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，接着再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为新的颜色值。
>
> 最后返回经过上色渲染后的图像。
>
> **示例 1:**
>
> ```
> 输入: 
> image = [[1,1,1],[1,1,0],[1,0,1]]
> sr = 1, sc = 1, newColor = 2
> 输出: [[2,2,2],[2,2,0],[2,0,1]]
> 解析: 
> 在图像的正中间，(坐标(sr,sc)=(1,1)),
> 在路径上所有符合条件的像素点的颜色都被更改成2。
> 注意，右下角的像素没有更改为2，
> 因为它不是在上下左右四个方向上与初始点相连的像素点。
> ```
>
> **注意:**
>
> - `image` 和 `image[0]` 的长度在范围 `[1, 50]` 内。
> - 给出的初始点将满足 `0 <= sr < image.length` 和 `0 <= sc < image[0].length`。
> - `image[i][j]` 和 `newColor` 表示的颜色值在范围 `[0, 65535]`内。

### Solution

很简单的BFS，最好加备忘录，新颜色和关联颜色相同可以直接返回。

把`queue`变成`stack`就是DFS，这个题DFS效率更高，理由可能是最先搜索到尽头的路扩展出的新节点较多，而不是每次都会有好多重复节点。

```c++
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int len = image.size();
        if (len == 0)
            return image;
        int wid = image[0].size();
        if (wid == 0)
            return image;
        int relatedColor = image[sr][sc];
        if (relatedColor == newColor)
            return image;
        queue<pair<int, int>> changeQueue;
        vector<bool> visited(len * wid, false);
        changeQueue.push({sr, sc});
        while (!changeQueue.empty())
        {
            pair<int, int> cur = changeQueue.front();
            changeQueue.pop();
            int r = cur.first, c = cur.second, loc = r * wid + c;
            image[r][c] = newColor;
            visited[loc] = true;
            if (r - 1 >= 0 && image[r - 1][c] == relatedColor && !visited[loc - wid])
            {
                image[r - 1][c] = newColor;
                changeQueue.push({r - 1, c});
            }
            if (c - 1 >= 0 && image[r][c - 1] == relatedColor && !visited[loc - 1])
            {
                image[r][c - 1] = newColor;
                changeQueue.push({r, c - 1});
            }
            if (r + 1 < len && image[r + 1][c] == relatedColor && !visited[loc + wid])
            {
                image[r + 1][c] = newColor;
                changeQueue.push({r + 1, c});
            }
            if (c + 1 < wid && image[r][c + 1] == relatedColor && !visited[loc + 1])
            {
                image[r][c + 1] = newColor;
                changeQueue.push({r, c + 1});
            }
        }
        return image;
    }
};
```

## 542.01 矩阵

### Question

> 给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
>
> 两个相邻元素间的距离为 1 。
>
> **示例 1:**
> 输入:
>
> ```
> 0 0 0
> 0 1 0
> 0 0 0
> ```
>
> 输出:
>
> ```
> 0 0 0
> 0 1 0
> 0 0 0
> ```
>
> **示例 2:**
> 输入:
>
> ```
> 0 0 0
> 0 1 0
> 1 1 1
> ```
>
> 输出:
>
> ```
> 0 0 0
> 0 1 0
> 1 2 1
> ```
>
> **注意:**
>
> 1. 给定矩阵的元素个数不超过 10000。
> 2. 给定矩阵中至少有一个元素是 0。
> 3. 矩阵中的元素只在四个方向上相邻: 上、下、左、右。

### Solution1

DFS，速度较慢，因为重复遍历某些点。

```c++
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        if (row == 0)
            return matrix;
        int col = matrix[0].size();
        if (col == 0)
            return matrix;
        queue<pair<int, int>> zeroChange;
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
            {
                if (matrix[i][j] == 0)
                    zeroChange.push({i, j});
                else
                    matrix[i][j] = INT_MAX;
            }
        while (!zeroChange.empty())
        {
            pair<int, int> cur = zeroChange.front();
            zeroChange.pop();
            int r = cur.first, c = cur.second;
            if (r - 1 >= 0 && matrix[r - 1][c] > matrix[r][c])
            {
                matrix[r - 1][c] = matrix[r][c] + 1;
                zeroChange.push({r - 1, c});
            }
            if (c - 1 >= 0 && matrix[r][c - 1] > matrix[r][c])
            {
                matrix[r][c - 1] = matrix[r][c] + 1;
                zeroChange.push({r, c - 1});
            }
            if (r + 1 < row && matrix[r + 1][c] > matrix[r][c])
            {
                matrix[r + 1][c] = matrix[r][c] + 1;
                zeroChange.push({r + 1, c});
            }
            if (c + 1 < col && matrix[r][c + 1] > matrix[r][c])
            {
                matrix[r][c + 1] = matrix[r][c] + 1;
                zeroChange.push({r, c + 1});
            }
        }
        return matrix;
    }
};
```

### Soluion2

两次遍历。

```c++
class Solution
{
public:
    const int MAXSIZE = 10001;
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        if (row == 0)
            return matrix;
        int col = matrix[0].size();
        if (col == 0)
            return matrix;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                int u = MAXSIZE, l = MAXSIZE;
                if (matrix[i][j] != 0)
                {
                    if (i > 0)
                        u = matrix[i - 1][j];
                    if (j > 0)
                        l = matrix[i][j - 1];
                    matrix[i][j] = min(u, l) + 1;
                }
            }
        }

        for (int i = row - 1; i >= 0; --i)
        {
            for (int j = col - 1; j >= 0; --j)
            {
                int d = MAXSIZE, r = MAXSIZE;
                if (matrix[i][j] != 0)
                {
                    if (i < row - 1)
                        d = matrix[i + 1][j];
                    if (j < col - 1)
                        r = matrix[i][j + 1];
                    matrix[i][j] = min(matrix[i][j], min(d, r) + 1);
                }
            }
        }

        return matrix;
    }
};
```

## 841.钥匙和房间

### Question

> 有 `N` 个房间，开始时你位于 `0` 号房间。每个房间有不同的号码：`0，1，2，...，N-1`，并且房间里可能有一些钥匙能使你进入下一个房间。
>
> 在形式上，对于每个房间 `i` 都有一个钥匙列表 `rooms[i]`，每个钥匙 `rooms[i][j]` 由 `[0,1，...，N-1]` 中的一个整数表示，其中 `N = rooms.length`。 钥匙 `rooms[i][j] = v` 可以打开编号为 `v` 的房间。
>
> 最初，除 `0` 号房间外的其余所有房间都被锁住。
>
> 你可以自由地在房间之间来回走动。
>
> 如果能进入每个房间返回 `true`，否则返回 `false`。
>
> **示例 1：**
>
> ```
> 输入: [[1],[2],[3],[]]
> 输出: true
> 解释:  
> 我们从 0 号房间开始，拿到钥匙 1。
> 之后我们去 1 号房间，拿到钥匙 2。
> 然后我们去 2 号房间，拿到钥匙 3。
> 最后我们去了 3 号房间。
> 由于我们能够进入每个房间，我们返回 true。
> ```
>
> **示例 2：**
>
> ```
> 输入：[[1,3],[3,0,1],[2],[0]]
> 输出：false
> 解释：我们不能进入 2 号房间。
> ```
>
> **提示：**
>
> 1. `1 <= rooms.length <= 1000`
> 2. `0 <= rooms[i].length <= 1000`
> 3. 所有房间中的钥匙数量总计不超过 `3000`。

### Solution

DFS&BFS

```c++
class Solution
{
public:
    void DFS(int cur, vector<vector<int>> &rooms, unordered_set<int>&opened)
    {
        if (opened.count(cur))
            return;
        opened.insert(cur);
        for (int i : rooms[cur])
            DFS(i, rooms, opened);
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        unordered_set<int> opened;
        DFS(0, rooms, opened);
        return (opened.size() == rooms.size());
    }
};
```

```c++
class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int num = rooms.size();
        stack<int> nextRoomQueue;
        vector<bool> opened(num, false);

        nextRoomQueue.push(0);
        while (!nextRoomQueue.empty())
        {
            int cur = nextRoomQueue.top();
            nextRoomQueue.pop();
            opened[cur] = true;
            for (int i : rooms[cur])
                if (!opened[i])
                    nextRoomQueue.push(i);
        }
        for (bool i : opened)
            if (i == false)
                return false;
        return true;
    }
};
```

