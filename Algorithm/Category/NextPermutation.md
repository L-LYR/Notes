# Next Permutation

按字典序获取下一个最大排列。算法比较简单，同时C++有接口`std::next_permutaion()`，这里讲解一下基本原理。

```pseudocode
procedure next_permutation({a[1], a[2], ..., a[n]}:{1, 2, 3, ..., n}) 
	j := n - 1
	while a[j] > a[j+1]
		j := j - 1
	k := n
	while a[j] > a[k]
		k := k - 1
	swap(a[j], a[k])
	r := n
	s := j + 1
	while r > s
		swap(a[r], a[s])
		r := r - 1
		s := s + 1
```

C++实现

```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) return;
        int n = nums.size() - 1;
        if (n == 0) return;

        // From right to left, find the first num 
        // which satisfies nums[j] < nums[j + 1].
        int j = n - 1;
        while (j >= 0 && nums[j] >= nums[j + 1]) {
            j--;
        }

        // nums[j] exists
        if (j >= 0) {
            // From right to left, find the first num
            // which satisfies nums[k] > nums[j].
            int k = n;
            while (k >= 0 && nums[j] >= nums[k]) {
                k--;
            }
            swap(nums[j], nums[k]);
        }

        // reverse num[j + 1....n]
        int r = n;
        int s = j + 1;
        while (r > s) {
            swap(nums[r], nums[s]);
            r--;
            s++;
        }
    }
};
```

