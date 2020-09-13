# 二分查找



```c++
// [l, r)
int greaterEqualThan(vector<int>& nums, int target, int l, int r) {
    int dis = r - l, 				// dis为区间长
    	i, step;
    while (dis > 0) {
        i = l;						// 从区间左侧开始
        step = dis / 2; 			// 半区间长
        i += step;					// 区间中间位置
        if (nums[i] >= target) { 	// 如果区间中间值大于等于目标值，控制条件来获取相应功能
            dis = step; 			// 区间长减半，左侧不变，等价于选择左侧半区间
        } else {					// 如果区间中间值小于目标值
            l = ++i;				// 区间左侧左移至区间中间位置加一的位置
            dis -= step + 1; 		// 区间长减半，注意step+1，因为右侧半区间不包含中间位置
        }
    }
    return l; 						// 如果找到，则返回第一个大于等于目标值的下标；如果没找到，则返回数组长。
}
```

