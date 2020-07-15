# 数组与字符串

[toc]

## 724.寻找数组的中心索引

### Question

> 给定一个整数类型的数组 `nums`，请编写一个能够返回数组**“中心索引”**的方法。
>
> 我们是这样定义数组**中心索引**的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
>
> 如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。
>
> **示例 1:**
>
> ```
> 输入: 
> nums = [1, 7, 3, 6, 5, 6]
> 输出: 3
> 解释: 
> 索引3 (nums[3] = 6) 的左侧数之和(1 + 7 + 3 = 11)，与右侧数之和(5 + 6 = 11)相等。
> 同时, 3 也是第一个符合要求的中心索引。
> ```
>
> **示例 2:**
>
> ```
> 输入: 
> nums = [1, 2, 3]
> 输出: -1
> 解释: 
> 数组中不存在满足此条件的中心索引。
> ```
>
> **说明:**
>
> - `nums` 的长度范围为 `[0, 10000]`。
> - 任何一个 `nums[i]` 将会是一个范围在 `[-1000, 1000]`的整数。

### Analysis

#### Idea1

如果想从两侧计算左右和式的话会出现很多问题，比如样例`1,0,0,-1`，`1,0,1,0,1`等都有可能过不了。

#### Idea2

先计算总和，然后考虑索引的性质，`sum - nums[i] == half * 2`，因此再一次遍历数组判断该条件即可。

#### Idea3

在以上想法的基础上，考虑`half`不过是索引前面的部分和，因此在第一遍计算总和的时候顺便存储一下，此后只需考虑索引的另一性质`pre_sum[i] + pre_sum[i - 1] == sum`即可。

### Solution1

```c++
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sum = 0;
        //int len = nums.size();
        //for (int i = 0; i < len; ++i)
        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];
        int half = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            //sum - nums[i] = half << 1
            if (sum - half - nums[i] == half)
                return i;
            half += nums[i];
        }
        return -1;
    }
};
```

### Solution2

```c++
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pre_sum;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            pre_sum.push_back(sum);
            sum += nums[i];
        }
        pre_sum.push_back(sum);
        for (int i = 1; i < pre_sum.size(); ++i)
        {
            if (sum - pre_sum[i] == pre_sum[i - 1])
                return i - 1;
        }
        return -1;
    }
};
```

## 747.至少是其他数字两倍的最大数

### Question

> 在一个给定的数组`nums`中，总是存在一个最大元素。
>
> 查找数组中的最大元素是否至少是数组中每个其他数字的两倍。
>
> 如果是，则返回最大元素的索引，否则返回-1。
>
> **示例 1:**
>
> ```
> 输入: nums = [3, 6, 1, 0]
> 输出: 1
> 解释: 6是最大的整数, 对于数组中的其他整数,
> 6大于数组中其他元素的两倍。6的索引是1, 所以我们返回1.
> ```
>
>  **示例 2:**
>
> ```
> 输入: nums = [1, 2, 3, 4]
> 输出: -1
> 解释: 4没有超过3的两倍大, 所以我们返回 -1.
> ```
>
> **提示:**
>
> 1. `nums` 的长度范围在`[1, 50]`。
> 2. 每个 `nums[i]` 的整数范围在 `[0, 99]`.在一个给定的数组`nums`中，总是存在一个最大元素 。

### Solution

没什么好分析的，很简单。

```c++
class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int len = nums.size();
        int fst_max = 0, sec_max = 0, index;
        for (int i = 0; i < len; ++i)
            if (nums[i] > fst_max)
            {
                sec_max = fst_max;
                fst_max = nums[i];
                index = i;
            }
            else if (nums[i] > sec_max)
                sec_max = nums[i];
        if (fst_max >= 2 * sec_max)
            return index;
        return -1;
    }
};
```

## 66.加一

### Question

> 给定一个由**整数**组成的**非空**数组所表示的非负整数，在该数的基础上加一。
>
> 最高位数字存放在数组的首位， 数组中每个元素只存储**单个**数字。
>
> 你可以假设除了整数 0 之外，这个整数不会以零开头。
>
> **示例 1:**
>
> ```
> 输入: [1,2,3]
> 输出: [1,2,4]
> 解释: 输入数组表示数字 123。
> ```
>
> **示例 2:**
>
> ```
> 输入: [4,3,2,1]
> 输出: [4,3,2,2]
> 解释: 输入数组表示数字 4321。
> ```

### Solution

```c++
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int endIndex = digits.size() - 1;

        digits[endIndex] += 1;
        for (int i = endIndex; i > 0; --i)
            if (digits[i] >= 10)
            {
                digits[i] -= 10;
                digits[i - 1] += 1;
            }
            else
                return digits;//不存在继续进位的情况直接返回
        if (digits[0] >= 10)
        {
            digits[0] -= 10;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
```

## 498.对角线遍历

### Question

> 给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。
>
> **示例:**
>
> ```
> 输入:
> [
>  [ 1, 2, 3 ],
>  [ 4, 5, 6 ],
>  [ 7, 8, 9 ]
> ]
> 输出:  [1,2,4,7,5,3,6,8,9]
> ```

### Solution1

这种方法不是很好，循环遍历的空间大小最差是原矩阵的2倍。

```c++
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {

        if (matrix.empty() || matrix[0].empty())
            return {};

        int row = matrix.size(), col = matrix[0].size(), sum_lim = row + col - 2;
        vector<int> ans(row * col);
        int count = 0;
        for (int sum = 0; sum <= sum_lim; ++sum)
            if (sum % 2 == 0)
            {
                for (int i = 0; i <= sum; ++i)
                {
                    if (sum - i < row && i < col)
                        ans[count++] = matrix[sum - i][i];
                }
            }
            else
            {
                for (int i = 0; i <= sum; ++i)
                {
                    if (sum - i < col && i < row)
                        ans[count++] = matrix[i][sum - i];
                }
            }
        return ans;
    }
};
```

### Solution2

这种就仅遍历了一遍原矩阵，这里`increment`用`vector`会更快。

```c++
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {

    if (matrix.empty() || matrix[0].empty())
            return {};

        int row = matrix.size(), col = matrix[0].size();
        vector<int> ans(row * col);

        int count = 0, i = 0, j = 0, flag = 0;
        pair<int, int> increment[2] = {{-1, 1}, {1, -1}};
		// vector<vector<int>> increment = {{-1, 1}, {1, -1}};
        for (int k = 0; k < row * col; ++k)
        {
            ans[count++] = matrix[i][j];
            i += increment[flag].first;
            // i += increment[flag][0];
            j += increment[flag].second;
            // j += increment[flag][1];
            if (i >= row)
            {
                i = row - 1;
                j += 2;
                flag = 1 - flag;
            }
            else if (j >= col)
            {
                j = col - 1;
                i += 2;
                flag = 1 - flag;
            }
            else if (i < 0)
            {
                i = 0;
                flag = 1 - flag;
            }
            else if (j < 0)
            {
                j = 0;
                flag = 1 - flag;
            }
        }

        return ans;
    }
};
```

## 54.螺旋矩阵

### Question

> 给定一个包含 *m* x *n* 个元素的矩阵（*m* 行, *n* 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
>
> **示例 1:**
>
> ```
> 输入:
> [
>  [ 1, 2, 3 ],
>  [ 4, 5, 6 ],
>  [ 7, 8, 9 ]
> ]
> 输出: [1,2,3,6,9,8,7,4,5]
> ```
>
> **示例 2:**
>
> ```
> 输入:
> [
>   [1, 2, 3, 4],
>   [5, 6, 7, 8],
>   [9,10,11,12]
> ]
> 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
> ```

### Solution1

```c++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {};

        int row = matrix.size(), col = matrix[0].size();
        vector<int> ans(row * col);
        int row_max = row - 1, col_max = col - 1, row_min = 1, col_min = 0;
        int r = 0, c = 0, status = 0;
        vector<vector<int>> increment = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        //status 表示遍历的状态码，increment表示在各个状态下坐标(r,c)循环的增量
        //状态循环过程：横向向右(0)->纵向向下(1)->横向向左(2)->纵向向上(3)->......
        for (int k = 0; k < row * col; ++k)
        {
            ans[k] = matrix[r][c];
            r += increment[status][0];
            c += increment[status][1];
            switch (status)
            {
            case 0:
                if (c > col_max)
                {
                    c = col_max;
                    r += 1;
                    status = 1;
                    --col_max;
                }
                break;
            case 1:
                if (r > row_max)
                {
                    r = row_max;
                    c -= 1;
                    status = 2;
                    --row_max;
                }
                break;
            case 2:
                if (c < col_min)
                {
                    c = col_min;
                    r -= 1;
                    status = 3;
                    ++col_min;
                }
                break;
            case 3:
                if (r < row_min)
                {
                    r = row_min;
                    c += 1;
                    status = 0;
                    ++row_min;
                }
                break;
            }
        }
        return ans;
    }
};
```

### Solution2

```c++
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return {};

        int up = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        vector<int> ans((down + 1) * (right + 1));
        int k = 0;
        while (true)
        {
            for (int i = left; i <= right; ++i)
                ans[k++] = matrix[up][i];
            if (++up > down)
                break;
            for (int i = up; i <= down; ++i)
                ans[k++] = matrix[i][right];
            if (--right < left)
                break;
            for (int i = right; i >= left; --i)
                ans[k++] = matrix[down][i];
            if (--down < up)
                break;
            for (int i = down; i >= up; --i)
                ans[k++] = matrix[i][left];
            if (++left > right)
                break;
        }
        return ans;
    }
};
```

## 118.杨辉三角

### Question

> 给定一个非负整数 *numRows，*生成杨辉三角的前 *numRows* 行。
>
> ![](./img/PascalTriangleAnimated2.gif)
>
> 在杨辉三角中，每个数是它左上方和右上方的数的和。
>
> **示例:**
>
> ```
> 输入: 5
> 输出:
> [
>      [1],
>     [1,1],
>    [1,2,1],
>   [1,3,3,1],
>  [1,4,6,4,1]
> ]
> ```

### Solution

```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows, vector<int>());

        for (int r = 0; r < numRows; ++r)
        {
            ans[r].resize(r + 1, 1);
            int n = ans[r].size();
            for (int j = 1; j < n - 1; ++j)
                ans[r][j] = ans[r - 1][j - 1] + ans[r - 1][j];
        }

        return ans;    
    }
};
```

## 67.二进制求和

### Question

> 给定两个二进制字符串，返回他们的和（用二进制表示）。
>
> 输入为**非空**字符串且只包含数字 `1` 和 `0`。
>
> **示例 1:**
>
> ```
> 输入: a = "11", b = "1"
> 输出: "100"
> ```
>
> **示例 2:**
>
> ```
> 输入: a = "1010", b = "1011"
> 输出: "10101"
> ```

### Solution

模拟手算的板子。

```c++
class Solution
{
public:
    string addBinary(string a, string b)
    {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string result = (a.length() > b.length()) ? a : b;
        result.push_back('0');
        string temp = (a.length() <= b.length()) ? a : b;
        int i;

        for (i = 0; i < temp.length(); ++i)
        {
            result[i + 1] += (result[i] + temp[i] - 2 * '0') / 2;
            result[i] = (result[i] + temp[i] - 2 * '0') % 2 + '0';
        }

        while (result[i] >= '2')
        {
            result[i + 1] += (result[i] - '0') / 2;
            result[i] = (result[i] - '0') % 2 + '0';
            ++i;
        }
        if (result.back() != '1')
            result.pop_back();
        reverse(result.begin(), result.end());
        return result;
    }
};
```

## 28.实现`strStr()`

### Question

> 实现`strStr()`函数。
>
> 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  **-1**。
>
> **示例 1:**
>
> ```
> 输入: haystack = "hello", needle = "ll"
> 输出: 2
> ```
>
> **示例 2:**
>
> ```
> 输入: haystack = "aaaaa", needle = "bba"
> 输出: -1
> ```
>
> **说明:**
>
> 当 `needle` 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
>
> 对于本题而言，当 `needle` 是空字符串时我们应当返回 0 。这与C语言的`strstr()`以及 Java的`indexOf()`定义相符。

### Solution1--调库

这种违背了题目考察的本意。

```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        int pos=haystack.find(needle);
        return pos;
    }
};
```

### Solution2--各种字符串匹配算法

[详见](../StringMatchingAlgorithm.md)

## 14.最长公共前缀

### Question

> 编写一个函数来查找字符串数组中的最长公共前缀。
>
> 如果不存在公共前缀，返回空字符串 `""`。
>
> **示例 1:**
>
> ```
> 输入: ["flower","flow","flight"]
> 输出: "fl"
> ```
>
> **示例 2:**
>
> ```
> 输入: ["dog","racecar","car"]
> 输出: ""
> 解释: 输入不存在公共前缀。
> ```
>
> **说明:**
>
> 所有输入只包含小写字母 `a-z` 。

### Solution1

依次求取最长公共前缀，直到出现公共前缀为空集或者已遍历完整个字符串数组的情况之后，返回结果。

已知输入`sts=[str1,str2...strn]`的平均长度为$S$，假设其最长公共前缀长为$m$，则时间复杂度为$O(nS)$。

```c++
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return {};
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i)
        {

            while (strs[i].find(prefix) != 0)
            {
                prefix.pop_back();
                if (prefix.empty())
                    return prefix;
            }
        }
        return prefix;
    }
};
```

### Solution2

纵向扫描，对每一列进行遍历，判断是否相同。

已知输入`sts=[str1,str2...strn]`的平均长度为$S$，假设其最长公共前缀长为$m$，则时间复杂度下界为$O(nm)$，最坏情况$S=m$。

```c++
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return {};
        int lim = strs.size(), i, j = 0;
        string prefix;
        char pre_alpha = 1;
        while (pre_alpha != 0)
        {
            pre_alpha = strs[0][j];
            for (i = 1; i < lim; ++i)
                if (pre_alpha != strs[i][j])
                {
                    pre_alpha = 0;
                    break;
                }
            if (pre_alpha != 0)
            {
                prefix.push_back(pre_alpha);
                ++j;
            }
        }
        return prefix;
    }
};
```

### Solution3

由于Solution1中仅单方向进行比较搜索，效率不高，所以优化为分治法，采用二分查找的板子。

已知输入`sts=[str1,str2...strn]`的平均长度为$S$，假设其最长公共前缀长为$m$，则时间复杂度下界为$O(nm)$，最坏情况$S=m$。

```c++
class Solution
{
private:
    string division(const vector<string> &strs, int begin, int end)
    {
        if (begin == end)
            return strs[begin];
        else
        {
            int mid = (end - begin) / 2 + begin;
            string left = division(strs, begin, mid);
            string right = division(strs, mid + 1, end);
            return prefixFind(left, right);
        }
    }
    string prefixFind(const string &str1, const string &str2)
    {
        string prefix = str2;
        while (str1.find(prefix) != 0)
        {
            prefix.pop_back();
            if (prefix.empty())
                return prefix;
        }
        return prefix;
    }

public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return {};
        return division(strs, 0, strs.size() - 1);
    }
};
```

### Solution4

这个想法是应用二分查找法找到所有字符串的公共前缀的最大长度 `L`。 算法的查找区间是$(0 \ldots minLen)$，其中 `minLen` 是输入数据中最短的字符串的长度，同时也是答案的最长可能长度。 每一次将查找区间一分为二，然后丢弃一定不包含最终答案的那一个。算法进行的过程中一共会出现两种可能情况：

- `S[1...mid]` 不是所有串的公共前缀。 这表明对于所有的 `j > i S[1..j]` 也不是公共前缀，于是我们就可以丢弃后半个查找区间。
- `S[1...mid]` 是所有串的公共前缀。 这表示对于所有的 `i < j S[1..i]` 都是可行的公共前缀，因为我们要找最长的公共前缀，所以我们可以把前半个查找区间丢弃。

错误实现：

```c++
class Solution
{
private:
    string division(const vector<string> &strs, int num, const string &minStr, int minLen)
    {
        int mid = minLen / 2;
        string subStr = minStr.substr(0, mid);
        string ret = prefixFind(strs, num, subStr);
        while (ret == subStr && mid < minLen - 1)
        {
            mid += mid / 2;
            subStr = minStr.substr(0, mid);
            ret = prefixFind(strs, num, subStr);
        }
        return ret;
    }
    string prefixFind(const vector<string> &strs, int num, const string &str)
    {
        string prefix = str;
        for (int i = 0; i < num; ++i)
        {
            while (strs[i].find(prefix) != 0)
            {
                prefix.pop_back();
                if (prefix.empty())
                    return prefix;
            }
        }
        return prefix;
    }

public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return {};

        int num = strs.size();
        int minLen = strs[0].length(), nextLen;
        string minStr;
        for (int i = 1; i < num; ++i)
        {
            nextLen = strs[i].length();
            if (nextLen < minLen)
            {
                minLen = nextLen;
                minStr = strs[i];
            }
        }
        return division(strs, num, minStr, minLen);
    }
};
```

有点蠢，超时。这里误解了求取`minLen`的作用，事实上`minLen`是作为初始搜索长度存在的，是对Solution1中初始搜索长度为1的优化。

正确实现：

```c++
class Solution
{
private:
    int prefixFind(const vector<string> &strs, int num, const string &prefix)
    {
        for (int i = 0; i < num; ++i)
            if (strs[i].find(prefix) != 0)
                return 0;
        return 1;
    }

public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return {};

        int num = strs.size();
        int minLen = strs[0].length(), nextLen;
        for (int i = 1; i < num; ++i)
        {
            nextLen = strs[i].length();
            minLen = min(nextLen, minLen);
        }
        int mid, l = 1, r = minLen; //attention here, equal to index + 1
        string prefix;

        while (l <= r)
        {
            mid = (l + r) / 2;
            prefix = strs[0].substr(0, mid);
            if (prefixFind(strs, num, prefix))
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return strs[0].substr(0, (l + r) / 2);
    }
};
```

### Solution5

字典树，这个写出来就很长了。

## 344.反转字符串

### Question

> 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 `char[]` 的形式给出。
>
> 不要给另外的数组分配额外的空间，你必须**原地修改输入数组**、使用 O(1) 的额外空间解决这一问题。
>
> 你可以假设数组中的所有字符都是ASCII码表中的可打印字符。
>
> **示例 1：**
>
> ```
> 输入：["h","e","l","l","o"]
> 输出：["o","l","l","e","h"]
> ```
>
> **示例 2：**
>
> ```
> 输入：["H","a","n","n","a","h"]
> 输出：["h","a","n","n","a","H"]
> ```

### Solution

```c++
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int lim = s.size();
        char temp;
        for (int i = 0; i < lim / 2; ++i)
        {
            temp = s[i];
            s[i] = s[lim - 1 - i];
            s[lim - 1 - i] = temp;
        }
    }
};

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        reverse(s.begin(), s.end());
    }
};
```

## 561.数组拆分1

### Question

> 给定长度为 **2n** 的数组, 你的任务是将这些数分成 **n** 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。
>
> **示例 1:**
>
> ```
> 输入: [1,4,3,2]
> 
> 输出: 4
> 解释: n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).
> ```
>
> **提示:**
>
> 1. **n** 是正整数,范围在 [1, 10000].
> 2. 数组中的元素范围在 [-10000, 10000].

### Solution

数组排序，下标为偶数的元素加和即可。

```c++
class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int sum = 0, lim = nums.size();
        for (int i = 0; i < lim; i += 2)
            sum += nums[i];
        return sum;
    }
};
```

## 167.两数之和 2 - 输入有序数组

### Question

> 给定一个已按照**升序排列** 的有序数组，找到两个数使得它们相加之和等于目标数。
>
> 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2*。*
>
> **说明:**
>
> - 返回的下标值（index1 和 index2）不是从零开始的。
> - 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
>
> **示例:**
>
> ```
> 输入: numbers = [2, 7, 11, 15], target = 9
> 输出: [1,2]
> 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
> ```

### Solution1

这道题仍然可以用map来做，但是没有用上递增的特性，所以这里采用双指针的方法。其正确性由每个样例都存在唯一解保证，

```c++
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i = 0, j = numbers.size() - 1;
        int sum;
        while (i < j)
        {
            sum = numbers[i] + numbers[j];
            if (sum > target)
                --j;
            else if (sum < target)
                ++i;
            else
                return {i + 1, j + 1};
        }
        return {-1, -1};
    }
};
```

### Solution2

二分查找。

```

```



## 27.移除元素

### Question

> 给定一个数组 *nums* 和一个值 *val*，你需要**原地**移除所有数值等于 *val* 的元素，返回移除后数组的新长度。
>
> 不要使用额外的数组空间，你必须在**原地修改输入数组**并在使用 O(1) 额外空间的条件下完成。
>
> 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
>
> **示例 1:**
>
> ```
> 给定 nums = [3,2,2,3], val = 3,
> 
> 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
> 
> 你不需要考虑数组中超出新长度后面的元素。
> ```
>
> **示例 2:**
>
> ```
> 给定 nums = [0,1,2,2,3,0,4,2], val = 2,
> 
> 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
> 
> 注意这五个元素可为任意顺序。
> 
> 你不需要考虑数组中超出新长度后面的元素。
> ```
>
> **说明:**
>
> 为什么返回数值是整数，但输出的答案是数组呢?
>
> 请注意，输入数组是以**“引用”**方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
>
> 你可以想象内部操作如下:
>
> ```
> // nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
> int len = removeElement(nums, val);
> 
> // 在函数里修改输入数组对于调用者是可见的。
> // 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
> for (int i = 0; i < len; i++) {
>     print(nums[i]);
> }
> ```

### Solution1

不利用双指针，采取移位的方式，这里忽略了不考虑顺序的条件，时间复杂度最差是$O(n^2)$，最好是$O(n)$。

```c++
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int len = nums.size(), i = 0;
        while (i < len)
        {
            if (nums[i] == val)
            {
                for (int j = i + 1; j < len; ++j)
                    nums[j - 1] = nums[j];
                --len;
            }
            else
                ++i;
        }
        return len;
    }
};
```

### Solution2

这里考虑了答案不要求顺序不变的条件，时间复杂度为$O(n)$。

```c++
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int len = nums.size(), i = 0;
        while (i < len)
        {
            if (nums[i] == val)
            {
                swap(nums[i], nums[len - 1]);
                --len;
            }
            else
                ++i;
        }
        return len;
    }
};
```

## 485.最大连续1的个数

### Question

> 给定一个二进制数组， 计算其中最大连续1的个数。
>
> **示例 1:**
>
> ```
> 输入: [1,1,0,1,1,1]
> 输出: 3
> 解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
> ```
>
> **注意：**
>
> - 输入的数组只包含 `0` 和`1`。
> - 输入数组的长度是正整数，且不超过 10,000。

### Solution1

略显拖沓的写法。

```c++
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0, maxCount = 0, len = nums.size(), last;
        for (int i = 0; i < len; ++i)
        {
            last = count;
            count += nums[i];
            if (count == last)
            {
                count = 0;
                if (last > maxCount)
                    maxCount = last;
            }
        }
        if (count > maxCount)
            maxCount = count;
        return maxCount;
    }
};
```

### Solution2

```c++
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxCount = 0, len = nums.size();
        int i, j = 0;
        for (i = 0; i < len; ++i)
        {
            if (nums[i] == 0)
            {
                maxCount = max(maxCount, i - j);
                j = i + 1;
            }
        }
        maxCount = max(maxCount, i - j);
        return maxCount;
    }
};
```

## 209.长度最小的子数组

### Question

> 给定一个含有 **n** 个正整数的数组和一个正整数 **s ，**找出该数组中满足其和 **≥ s** 的长度最小的连续子数组**。**如果不存在符合条件的连续子数组，返回 0。
>
> **示例:** 
>
> ```
> 输入: s = 7, nums = [2,3,1,2,4,3]
> 输出: 2
> 解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
> ```
>
> **进阶:**
>
> 如果你已经完成了*O*(*n*) 时间复杂度的解法, 请尝试 *O*(*n* log *n*) 时间复杂度的解法。

### Solution1

很慢的一种做法，时间复杂度$O(n^2)$。

```c++
class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int len = nums.size(), sum, minLen = len + 1;

        for (int i = 0; i < len; ++i)
        {
            sum = 0;
            for (int j = i; j < len; ++j)
            {
                sum += nums[j];
                if (sum >= s)
                {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }
        if (minLen == len + 1)
            return 0;
        return minLen;
    }
};
```

### Solution2

滑动窗格

```c++
class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int len = nums.size(), sum = 0, minLen = len + 1;

        int left = 0, right = 0;
        while (right < len)
        {
            if (sum + nums[right] < s)
            {
                sum += nums[right];
                ++right;
            }
            else
            {
                minLen = min(right - left + 1, minLen);
                sum -= nums[left];
                ++left;
            }
        }

        if (minLen == len + 1)
            return 0;
        return minLen;
    }
};
```

## 182.旋转数组

### Question

> 给定一个数组，将数组中的元素向右移动 *k* 个位置，其中 *k* 是非负数。
>
> **示例 1:**
>
> ```
> 输入: [1,2,3,4,5,6,7] 和 k = 3
> 输出: [5,6,7,1,2,3,4]
> 解释:
> 向右旋转 1 步: [7,1,2,3,4,5,6]
> 向右旋转 2 步: [6,7,1,2,3,4,5]
> 向右旋转 3 步: [5,6,7,1,2,3,4]
> ```
>
> **示例 2:**
>
> ```
> 输入: [-1,-100,3,99] 和 k = 2
> 输出: [3,99,-1,-100]
> 解释: 
> 向右旋转 1 步: [99,-1,-100,3]
> 向右旋转 2 步: [3,99,-1,-100]
> ```
>
> **说明:**
>
> - 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
> - 要求使用空间复杂度为 O(1) 的 **原地** 算法。

### Solution1

超时方法，时间复杂度$O(k\times len)$，空间复杂度$O(1)$。

```c++
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        if (k == 0 || len == 0 || k % len == 0)
            return;
        int temp;
        k %= len;
        while (--k > 0)
        {
            temp = nums[len - 1];
            for (int i = len - 1; i > 0; --i)
                nums[i] = nums[i - 1];
            nums[0] = temp;
        }
    }
};
```

### Solution2

较慢的方法，时间复杂度$O(len)$，空间复杂度$O(k) $。

```c++
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        if (k <= 0 || len == 0 || k % len == 0)
            return;
        k %= len;
        vector<int> temp(nums.begin() + len - k, nums.end());
        nums.insert(nums.begin(), temp.begin(), temp.end());
        nums.resize(len);
    }
};
```

### Solution3

Solution1的改进，一步到位，时间复杂度$O(n)$，空间复杂度$O (1)$。

```c++
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        if (k == 0 || len == 0 || k % len == 0)
            return;
        int temp, start, cur, prev, next, count;
        k %= len;
        for (start = 0, count = 0; count < len; ++start) //pay attention to the end-conditions here
        {
            cur = start;
            prev = nums[start];
            do
            {
                next = (cur + k) % len;
                temp = nums[next];
                nums[next] = prev;
                prev = temp;

                cur = next;
                ++count;

            } while (start != cur);
        }
    }
};
```

### Solution4

三次反转，时间复杂度$O(n)$，空间复杂度$O (1)$。

```c++
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        if (k == 0 || len == 0 || k % len == 0)
            return;
        k %= len;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

```

### Solution5

最好写的方法，时间复杂度$O(n)$，空间复杂度$O (n)$。

```c++
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int len = nums.size();
        if (k == 0 || len == 0 || k % len == 0)
            return;
        k %= len;
        vector<int> result(nums);
        for (int i = 0; i < len; ++i)
        {
            nums[(i + k) % len] = result[i];
        }
    }
};
```

## 119.杨辉三角 II

### Question

> 给定一个非负索引 *k*，其中 *k* ≤ 33，返回杨辉三角的第 *k* 行。
>
> ![img](D:\Diary\img\PascalTriangleAnimated2.gif)
>
> 在杨辉三角中，每个数是它左上方和右上方的数的和。
>
> **示例:**
>
> ```
> 输入: 3
> 输出: [1,3,3,1]
> ```
>
> **进阶：**
>
> 你可以优化你的算法到 *O*(*k*) 空间复杂度吗？

### Solution1

直接算，时间复杂度$O(k^2)$，空间复杂度$O(k^2)$。

```c++
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> ans(rowIndex + 1, vector<int>());

        for (int r = 0; r <= rowIndex; ++r)
        {
            ans[r].resize(r + 1, 1);
            int n = ans[r].size();
            for (int j = 1; j < n - 1; ++j)
                ans[r][j] = ans[r - 1][j - 1] + ans[r - 1][j];
        }

        return ans[rowIndex];
    }
};
```

### Solution2

递推公式`ans[j] = ans[j - 1] + ans[j]`，因此要从后往前遍历。

```c++
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans(rowIndex + 1, 1);

        for (int r = 0; r <= rowIndex; ++r)
            for (int j = r - 1; j > 0; --j)
                ans[j] = ans[j - 1] + ans[j];

        return ans;
    }
};
```

## 151.翻转字符串里的单词

### Question

> 给定一个字符串，逐个翻转字符串中的每个单词。
>
> **示例 1：**
>
> ```
> 输入: "the sky is blue"
> 输出: "blue is sky the"
> ```
>
> **示例 2：**
>
> ```
> 输入: "  hello world!  "
> 输出: "world! hello"
> 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
> ```
>
> **示例 3：**
>
> ```
> 输入: "a good   example"
> 输出: "example good a"
> 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
> ```
>
> **说明：**
>
> - 无空格字符构成一个单词。
> - 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
> - 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
>
> **进阶：**
>
> 请选用 C 语言的用户尝试使用 *O*(1) 额外空间复杂度的原地解法。

### Solution1

利用循环划分字符串，时间复杂度$O(strLen)$，空间复杂度$O(1)$。

```c++
class Solution
{
public:
    string reverseWords(string s)
    {
        string result;
        int strLen = s.length(), end, i = strLen - 1;
        while (1)
        {
            while (i >= 0 && s[i] == ' ')
                --i;
            if (i < 0)
                break;
            end = i;
            while (i >= 0 && s[i] != ' ')
                --i;
            result += s.substr(i + 1, end - i) + " ";
        }
        result.pop_back();
        return result;
    }
};
```

### Solution2

利用`stringstream`分割字符串，但是会比较慢。

```c++
class Solution
{
public:
    string reverseWords(string s)
    {
        string result, piece;
        reverse(s.begin(), s.end());
        stringstream ss(s);
        while (ss >> piece)
        {
            reverse(piece.begin(), piece.end());
            result += piece + " ";
        }
        result.pop_back();
        return result;
    }
};
```

## 557.反转字符串中的单词 III

### Question

> 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
>
> **示例 1:**
>
> ```
> 输入: "Let's take LeetCode contest"
> 输出: "s'teL ekat edoCteeL tsetnoc" 
> ```
>
> **注意：**在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

### Solution1

上一题的方法修改一下即可。

```c++
class Solution
{
public:
    string reverseWords(string s)
    {
        string result, word;
        int strLen = s.length(), i = 0, p;
        while (i < strLen)
        {
            while (i < strLen && s[i] == ' ')
                ++i;
            if (i >= strLen)
                break;
            p = i;
            while (i < strLen && s[i] != ' ')
                ++i;
            word = s.substr(p, i - p);
            reverse(word.begin(), word.end());
            result += word + " ";
        }
        result.pop_back();
        return result;
    }
};
```

### Solution2

这一题的的测试用例不会出现多个无用空格，所以不需要以上的循环。

```c++
class Solution
{
public:
    string reverseWords(string s)
    {
        int strLen = s.length(), i, p;
        string::iterator begin = s.begin();
        for (i = 0; i < strLen; ++i)
        {
            p = i;
            while (i < strLen && s[i] != ' ')
                ++i;
            reverse(begin + p, begin + i);
        }
        return s;
    }
};
```

## 26.删除排序数组中的重复项

### Question

> 给定一个排序数组，你需要在**原地**删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
>
> 不要使用额外的数组空间，你必须在**原地修改输入数组**并在使用 O(1) 额外空间的条件下完成。
>
> **示例 1:**
>
> ```
> 给定数组 nums = [1,1,2], 
> 
> 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 
> 
> 你不需要考虑数组中超出新长度后面的元素。
> ```
>
> **示例 2:**
>
> ```
> 给定 nums = [0,0,1,1,1,2,2,3,3,4],
> 
> 函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
> 
> 你不需要考虑数组中超出新长度后面的元素。
> ```
>
> **说明:**
>
> 为什么返回数值是整数，但输出的答案是数组呢?
>
> 请注意，输入数组是以**“引用”**方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
>
> 你可以想象内部操作如下:
>
> ```
> // nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
> int len = removeDuplicates(nums);
> 
> // 在函数里修改输入数组对于调用者是可见的。
> // 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
> for (int i = 0; i < len; i++) {
>     print(nums[i]);
> }
> ```

### Solution

双指针，时间复杂度$O(n)$，空间复杂度$O (1)$。

```c++
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        int len = nums.size();
        if (len == 0 || len == 1)
            return len;

        int newVecTail = 0, p = 1;
        while (p < len)
        {
            if (nums[p] != nums[newVecTail])
                nums[++newVecTail] = nums[p];
            ++p;
        }

        return newVecTail + 1;
    }
};
```

## 283.移动零

### Question

> 给定一个数组 `nums`，编写一个函数将所有 `0` 移动到数组的末尾，同时保持非零元素的相对顺序。
>
> **示例:**
>
> ```
> 输入: [0,1,0,3,12]
> 输出: [1,3,12,0,0]
> ```
>
> **说明**:
>
> 1. 必须在原数组上操作，不能拷贝额外的数组。
> 2. 尽量减少操作次数。

### Solution1

用双指针将数组依次划分三块，无0区，全0区，未分类区，直到未分类区大小为0时结束。

```c++
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int len = nums.size();
        int nonZero = 0, rest = 0;

        while (rest < len&&nums[rest] != 0)
        {
            ++nonZero;
            ++rest;
        }
        ++rest;
        while (rest < len)
        {
            if (nums[rest] != 0)
            {
                swap(nums[nonZero], nums[rest]);
                ++nonZero;
                ++rest;
            }
            else
                ++rest;
        }
    }
};
```

### Solution2

优化。

```c++
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int len = nums.size();
        int nonZero = 0;

        for (int i = 0; i < len; ++i)
            if (nums[i] != 0)
                nums[nonZero++] = nums[i];

        nums.resize(nonZero);
        nums.insert(nums.end(), len - nonZero, 0);
    }
};
```

### Solution3

进一步优化。

```c++
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int len = nums.size();
        int nonZero = 0;

        for (int i = 0; i < len; ++i)
            if (nums[i] != 0)
                swap(nums[nonZero++], nums[i]);
    }
};
```

