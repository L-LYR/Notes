---
title: LeetCode刷题日志（三）：二分查找模板
---

- 模板1——基础
  - 704.二分查找
  - 69.x的平方根
  - 374.猜数字大小
  - 33.搜索旋转排序数组
- 模板2——高级
  - 

# 二分查找

# 模板1——基础版

```c++
int binarySearch(vector<int>& nums, int target){
  if(nums.size() == 0)
    return -1;

  int left = 0, right = nums.size() - 1;
  while(left <= right){
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    if(nums[mid] == target){ return mid; }
    else if(nums[mid] < target) { left = mid + 1; }
    else { right = mid - 1; }
  }

  // End Condition: left > right
  return -1;
}
```

这里每次查找的区间为$[left,right]$。

## 704.二分查找

### Question

> 给定一个 `n` 个元素有序的（升序）整型数组 `nums` 和一个目标值 `target`  ，写一个函数搜索 `nums` 中的 `target`，如果目标值存在返回下标，否则返回 `-1`。
> **示例 1:**
>
> ```
> 输入: nums = [-1,0,3,5,9,12], target = 9
> 输出: 4
> 解释: 9 出现在 nums 中并且下标为 4
> ```
>
> **示例 2:**
>
> ```
> 输入: nums = [-1,0,3,5,9,12], target = 2
> 输出: -1
> 解释: 2 不存在 nums 中因此返回 -1
> ```
>
> **提示：**
>
> 1. 你可以假设 `nums` 中的所有元素是不重复的。
> 2. `n` 将在 `[1, 10000]`之间。
> 3. `nums` 的每个元素都将在 `[-9999, 9999]`之间。

### Solution

```c++
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r)
        {
            mid = (r - l) / 2 + l;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};
```

## 69. x 的平方根

### Question

> 实现 `int sqrt(int x)` 函数。
>
> 计算并返回 *x* 的平方根，其中 *x* 是非负整数。
>
> 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
>
> **示例 1:**
>
> ```
> 输入: 4
> 输出: 2
> ```
>
> **示例 2:**
>
> ```
> 输入: 8
> 输出: 2
> 说明: 8 的平方根是 2.82842..., 
>      由于返回类型是整数，小数部分将被舍去。
> ```

### Solution1

二分查找法。注意数据类型，小心溢出。

```c++
class Solution
{
public:
    int mySqrt(int x)
    {
        long long l = 0, r = ((long long)x + 1) >> 1, mid, sqr;
        while (l <= r)
        {
            mid = l + ((r - l) >> 1);
            sqr = mid * mid;
            if (sqr == x)
                return mid;
            else if (sqr > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return r;
    }
};
```

### Solution2

牛顿迭代法。

```c++
class Solution {
public:
    int mySqrt(int x) {
        long r = x;
        while (r*r > x)
            r = (r + x/r) / 2;
        return r;
    }
};
```

## 374.猜数字大小

### Question

> 我们正在玩一个猜数字游戏。 游戏规则如下：
> 我从 **1** 到 ***n*** 选择一个数字。 你需要猜我选择了哪个数字。
> 每次你猜错了，我会告诉你这个数字是大了还是小了。
> 你调用一个预先定义好的接口 `guess(int num)`，它会返回 3 个可能的结果（`-1`，`1` 或 `0`）：
>
> ```
> -1 : 我的数字比较小
>  1 : 我的数字比较大
>  0 : 恭喜！你猜对了！
> ```
>
> **示例 :**
>
> ```
> 输入: n = 10, pick = 6
> 输出: 6
> ```

### Solution

```c++
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution
{
public:
    int guessNumber(int n)
    {
        int l = 1, r = n, mid;
        while (l <= r)
        {
            mid = l + ((r - l) >> 1);
            int ret = guess(mid);
            if (ret == 0)
                return mid;
            else if (ret > 0)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};
```

## 33.搜索旋转排序数组

### Question

> 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
>
> ( 例如，数组 `[0,1,2,4,5,6,7]` 可能变为 `[4,5,6,7,0,1,2]` )。
>
> 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 `-1` 。
>
> 你可以假设数组中不存在重复的元素。
>
> 你的算法时间复杂度必须是 *O*(log *n*) 级别。
>
> **示例 1:**
>
> ```
> 输入: nums = [4,5,6,7,0,1,2], target = 0
> 输出: 4
> ```
>
> **示例 2:**
>
> ```
> 输入: nums = [4,5,6,7,0,1,2], target = 3
> 输出: -1
> ```

### Solution

```c++
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // special cases
        if (nums.empty())
            return -1;
        if (nums.size() == 1)
            return target == nums[0] ? 0 : -1;
        // interval division
        // nums[0]......nums[max] nums[min].......nums[end]
        int l = 0, r = nums.size() - 1, mid;
        while (l < r) // l == r stop
        {
            mid = l + ((r - l) >> 1);

            if (nums[mid] >= nums[0]) //mid in [0, max]
            {
                if (target >= nums[0]) //target in [0, max]
                {
                    if (target > nums[mid]) //target in [mid + 1, max]
                        l = mid + 1;
                    else //target in [0, mid]
                        r = mid;
                }
                else //target in [min, end]
                    l = mid + 1;
            }
            else //mid in [min, end]
            {
                if (target >= nums[0]) //target in [0, max]
                    r = mid;
                else //target in [min, end]
                {
                    if (target > nums[mid]) //target in [mid + 1, end]
                        l = mid + 1;
                    else //target in [min, mid]
                        r = mid;
                }
            }
        }
        return nums[r] == target ? r : -1;
        //return nums[l] == target ? l : -1;
    }
};
```

# 模板2——高级版

```c++
int binarySearch(vector<int>& nums, int target)
{
  if(nums.size() == 0)
    return -1;

  int left = 0, right = nums.size();
  while(left < right){
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    if(nums[mid] == target){ return mid; }
    else if(nums[mid] < target) { left = mid + 1; }
    else { right = mid; }
  }

  // Post-processing:
  // End Condition: left == right
  if(left != nums.size() && nums[left] == target) return left;
  return -1;
}
```

其实上面的第33题就用的高级版。。。。。。

事实上，这里查找的区间为$[left,right)$。

## 278.第一个错误的版本

### Question

> 你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。
>
> 假设你有 `n` 个版本 `[1, 2, ..., n]`，你想找出导致之后所有版本出错的第一个错误的版本。
>
> 你可以通过调用 `bool isBadVersion(version)` 接口来判断版本号 `version` 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。
>
> **示例:**
>
> ```
> 给定 n = 5，并且 version = 4 是第一个错误的版本。
> 
> 调用 isBadVersion(3) -> false
> 调用 isBadVersion(5) -> true
> 调用 isBadVersion(4) -> true
> 
> 所以，4 是第一个错误的版本。 
> ```

### Solution

```c++
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int l = 0, r = n, mid;
        while (l < r)
        {
            mid = l + ((r - l) >> 1);
            if (isBadVersion(mid))
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
};
```

## 162.寻找峰值

### Question

> 峰值元素是指其值大于左右相邻值的元素。
>
> 给定一个输入数组 `nums`，其中 `nums[i] ≠ nums[i+1]`，找到峰值元素并返回其索引。
>
> 数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
>
> 你可以假设 `nums[-1] = nums[n] = -∞`。
>
> **示例 1:**
>
> ```
> 输入: nums = [1,2,3,1]
> 输出: 2
> 解释: 3 是峰值元素，你的函数应该返回其索引 2。
> ```
>
> **示例 2:**
>
> ```
> 输入: nums = [1,2,1,3,5,6,4]
> 输出: 1 或 5 
> 解释: 你的函数可以返回索引 1，其峰值元素为 2；
>      或者返回索引 5， 其峰值元素为 6。
> ```
>
> **说明:**
>
> 你的解法应该是 *O*(*logN*) 时间复杂度的。

### Solution

1. 相邻元素不相等
2. `nums[-1] = nums[n] =`$-\infin$

所以，只要`nums[mid] < nums[mid + 1]`就可以往$[mid+1,right]$搜索。

反之，则往$[left,mid-1]$搜索，假设这之中无峰值，则该区间中一定是递增，进而一定有`nums[mid - 1] < nums[mid]`，与上面的`nums[mid] > nums[mid + 1]`前提，即`nums[mid]`为峰值，否则峰值一定出现在$[left,mid-1]$。

```c++
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1, mid;
        while (l < r)
        {
            mid = l + ((r - l) >> 1);
            if (nums[mid] < nums[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }
        return r;
    }
};
```

## 153.寻找旋转排序数组中的最小值

### Question

> 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
>
> ( 例如，数组 `[0,1,2,4,5,6,7]` 可能变为 `[4,5,6,7,0,1,2]` )。
>
> 请找出其中最小的元素。
>
> 你可以假设数组中不存在重复元素。
>
> **示例 1:**
>
> ```
> 输入: [3,4,5,1,2]
> 输出: 1
> ```
>
> **示例 2:**
>
> ```
> 输入: [4,5,6,7,0,1,2]
> 输出: 0
> ```

### Solution

这里必须是和末尾元素比，因为他有可能不旋转，如`[1,2,3,4,5]`。

```c++
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size(), mid, endElement = nums.back();
        while (l < r)
        {
            mid = l + ((r - l) >> 1);
            if (nums[mid] <= endElement)
                r = mid;
            else
                l = mid + 1;
        }
        return nums[r];
    }
};
```

# 模板3——独特形式

```c++
int binarySearch(vector<int>& nums, int target){
    if (nums.size() == 0)
        return -1;

    int left = 0, right = nums.size() - 1;
    while (left + 1 < right){
        // Prevent (left + right) overflow
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid;
        } else {
            right = mid;
        }
    }

    // Post-processing:
    // End Condition: left + 1 == right
    if(nums[left] == target) return left;
    if(nums[right] == target) return right;
    return -1;
}
```

主要用在有重复元素的情况下。

## 34.在排序数组中查找元素的第一个和最后一个位置

### Question

> 给定一个按照升序排列的整数数组 `nums`，和一个目标值 `target`。找出给定目标值在数组中的开始位置和结束位置。
>
> 你的算法时间复杂度必须是 *O*(log *n*) 级别。
>
> 如果数组中不存在目标值，返回 `[-1, -1]`。
>
> **示例 1:**
>
> ```
> 输入: nums = [5,7,7,8,8,10], target = 8
> 输出: [3,4]
> ```
>
> **示例 2:**
>
> ```
> 输入: nums = [5,7,7,8,8,10], target = 6
> 输出: [-1,-1]
> ```

### Solution1

思路很简单，如果中间找到了目标，那么边界一定在左右两侧闭区间内，如果没有找到，缩小范围。

考虑到左侧区间一定是一部分小于目标一部分等于目标，右侧区间一定是一部分等于目标一部分大于目标，因此继续采用二分搜索即可。

```c++
class Solution
{
private:
    void partSearch(vector<int> &nums, int &mid, int &side, int target)
    {
        int subMid;
        while (mid + 1 < side || side + 1 < mid)
        {
            subMid = mid + ((side - mid) >> 1);
            if (nums[subMid] == target)
                mid = subMid;
            else
                side = subMid;
        }
        if (nums[side] != target)
            side = mid;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        //nums is empty or target is out of range
        if (nums.empty() || target > nums.back() || target < nums.front())
            return {-1, -1};
        int l = 0, r = nums.size() - 1, mid, subMid;
        while (l < r)
        {
            mid = l + ((r - l) >> 1);
            if (nums[mid] == target)
            {
                partSearch(nums, mid, r, target);
                partSearch(nums, mid, l, target);

                return {l, r};
            }
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        if (nums[l] == target)
            return {l, r};
        return {-1, -1};
    }
};
```

### Solution2

二分查找两次，分别找出最左边界和最右边界即可。

```c++
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        //nums is empty or target is out of range
        if (nums.empty() || target > nums.back() || target < nums.front())
            return {-1, -1};
        vector<int> ans = {-1, -1};
        int l = 0, r = nums.size(), mid;
        while (l < r)
        {
            mid = l + ((r - l) >> 1);
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        if (nums[l] == target)
            ans[0] = l;
        l = 0, r = nums.size();
        while (l + 1 < r)
        {
            mid = l + ((r - l) >> 1);
            if (nums[mid] > target)
                r = mid;
            else
                l = mid;
        }
        if (nums[l] == target)
            ans[1] = l;
        return ans;
    }
};
```

## 658.找到 K 个最接近的元素

### Question

> 给定一个排序好的数组，两个整数 `k` 和 `x`，从数组中找到最靠近 `x`（两数之差最小）的 `k` 个数。返回的结果必须要是按升序排好的。如果有两个数与 `x` 的差值一样，优先选择数值较小的那个数。
>
> **示例 1:**
>
> ```
> 输入: [1,2,3,4,5], k=4, x=3
> 输出: [1,2,3,4]
> ```
>
> **示例 2:**
>
> ```
> 输入: [1,2,3,4,5], k=4, x=-1
> 输出: [1,2,3,4]
> ```
>
> **说明:**
>
> 1. k 的值为正数，且总是小于给定排序数组的长度。
> 2. 数组不为空，且长度不超过 10000
> 3. 数组里的每个元素与 x 的绝对值不超过 10000

### Solution

问题的化简难点在于，二分查找找什么？

我们找的应该是所求子序列的左边界。清楚这一点就很好了，接下来的难点在于判断依据。在这道题里应该是考虑最左边界和最有边界到目标的距离的大小关系，且要求相等时左边优先。逻辑清晰之后，代码如下：

```c++
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int l = 0, r = arr.size() - k, mid;
        while (l < r)
        {
            mid = l + ((r - l) >> 1);
            if (abs(arr[mid] - x) > abs(arr[mid + k] - x))
                l = mid + 1;
            else
                r = mid;
        }
        return  vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};
```

# 辨析

**模板 #1** `(left <= right)：`

------

- 二分查找的最基础和最基本的形式。
- 查找条件可以在不与元素的两侧进行比较的情况下确定（或使用它周围的特定元素）。
- 不需要后处理，因为每一步中，你都在检查是否找到了元素。如果到达末尾，则知道未找到该元素。
- 初始条件：`left = 0, right = length-1`

- 终止：`left > right`
- 向左查找：`right = mid-1`
- 向右查找：`left = mid+1`

**模板 #2** `(left < right)：`

------

- 一种实现二分查找的高级方法。
- 查找条件需要访问元素的直接右邻居。
- 使用元素的右邻居来确定是否满足条件，并决定是向左还是向右。
- 保证查找空间在每一步中至少有 2 个元素。
- 需要进行后处理。 当你剩下 1 个元素时，循环 / 递归结束。 需要评估剩余元素是否符合条件。
- 初始条件：`left = 0, right = length`
- 终止：`left == right`
- 向左查找：`right = mid`
- 向右查找：`left = mid+1`

**模板 #3** `(left + 1 < right)：`

------

- 实现二分查找的另一种方法。
- 搜索条件需要访问元素的直接左右邻居。
- 使用元素的邻居来确定它是向右还是向左。
- 保证查找空间在每个步骤中至少有 3 个元素。
- 需要进行后处理。 当剩下 2 个元素时，循环 / 递归结束。 需要评估其余元素是否符合条件。

- 初始条件：`left = 0, right = length-1`
- 终止：`left + 1 == right`
- 向左查找：`right = mid`
- 向右查找：`left = mid`

# 特殊的&变态的

## 4.寻找两个有序数组的中位数

### Question

> 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
>
> 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
>
> 你可以假设 nums1 和 nums2 不会同时为空。
>
> 示例 1:
>
> nums1 = [1, 3]
> nums2 = [2]
>
> 则中位数是 2.0
> 示例 2:
>
> nums1 = [1, 2]
> nums2 = [3, 4]
>
> 则中位数是 (2 + 3)/2 = 2.5
>

### Solution1

利用寻找`Kth`这个思想。

```c++
class Solution
{
    int findKthSmallestElement(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int size1 = nums1.size(), size2 = nums2.size();
        if (size1 == 0)
            return nums2[k - 1];
        if (size2 == 0)
            return nums1[k - 1];
        if (k == 1)
            return min(nums1[0], nums2[0]);

        int cut1 = (((double)size1) / (size1 + size2)) * (k - 1);
        int cut2 = k - cut1 - 2;

        if (nums1[cut1] == nums2[cut2])
            return nums1[cut1];
        else if (nums1[cut1] < nums2[cut2])
        {
            vector<int> sub(nums1.begin() + cut1 + 1, nums1.end());
            return findKthSmallestElement(sub, nums2, k - cut1 - 1);
        }
        else
        {
            vector<int> sub(nums2.begin() + cut2 + 1, nums2.end());
            return findKthSmallestElement(nums1, sub, k - cut2 - 1);
        }
    }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int size1 = nums1.size(), size2 = nums2.size();
        int mid1 = size1 / 2, mid2 = size2 / 2;
        if (size1 == 0)
            return (size2 % 2)
                       ? nums2[mid2]
                       : (nums2[mid2] + nums2[mid2 - 1]) / 2.0;
        if (size2 == 0)
            return (size1 % 2)
                       ? nums1[mid1]
                       : (nums1[mid1] + nums1[mid1 - 1]) / 2.0;
        if ((size1 + size2) % 2)
            return findKthSmallestElement(nums1, nums2, (size1 + size2 + 1) / 2);
        else
            return (findKthSmallestElement(nums1, nums2, (size1 + size2) / 2) +
                    findKthSmallestElement(nums1, nums2, (size1 + size2) / 2 + 1)) /
                   2.0;
    }
};
```

### Solution2

二分查找加集合分割。

首先给集合分割下定义：

> 分割一个集合可以是从两个元素之间分割，也可以以指定元素为界分割，但要注意的是，后者中作为界的元素属于分割后左右两个集合。
>
> 对于任意大小为$n$的数组其分割点共有$2n+1$个。

我们对题中所给的两个有序数组进行分割，则一定有$2(Len1+Len2)+2$个分割点，所以我们不需要再去考虑奇偶。

同时注意到两数组是递增的，因此分割点处即是左侧的最大值又是右侧的最小值（如果是分割点超出范围则置为`INT_MAX`或`INT_MIN`）。

```c++
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            nums1.swap(nums2);
        int len1 = nums1.size(), len2 = nums2.size();
        int LMax1, LMax2, RMin1, RMin2, cut1, cut2;
        int l = 0, r = 2 * len1, len = len1 + len2;
        while (l <= r)
        {
            cut1 = l + ((r - l) >> 1);
            cut2 = len - cut1;

            LMax1 = (cut1 == 0) ? INT64_MIN : nums1[(cut1 - 1) / 2];
            RMin1 = (cut1 == 2 * len1) ? INT64_MAX : nums1[cut1 / 2];
            LMax2 = (cut2 == 0) ? INT64_MIN : nums2[(cut2 - 1) / 2];
            RMin2 = (cut2 == 2 * len2) ? INT64_MAX : nums2[cut2 / 2];

            if (LMax1 > RMin2)
                r = cut1 - 1;
            else if (LMax2 > RMin1)
                l = cut1 + 1;
            else
                break;
        }
        return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
    }
};
```

