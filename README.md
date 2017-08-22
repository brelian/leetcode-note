# leetcode-note
leetcode 刷题笔记

## [Two Sum](https://leetcode.com/problems/two-sum/description/)
### 问题描述
给定一个整数数组，返回包含和等于给定目标值的两个元素。

你可以假设每个输入都有一个确定的解，且一个元素不能使用两次。

```
Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

### 分析
- 简单思路 复杂度O(n^2)

	遍历两次数组，分别使用 i,j 两个计数器，**当下标不想等（i != j）**时判断两个数组元素之和是否为目标值，``nums[i] + nums[j] == target``?

JavaScript 示例代码：
```
var twoSum = function(nums, target) {
    let result = [];
    for (let i = 0; i < nums.length; i++) {
        for (let j = 0; j < nums.length; j++) {
            if (i != j && nums[i] + nums[j] == target) {
                result.push(i);
                result.push(j);
                return result; // 注意找到值以后立即返回
            }
        }
    }
};
```

- 改进思路 O(n)

	使用 hashMap，使用两次

```
var twoSum = function(nums, target) {
    let m = new Map();
    for (let k = 0; k < nums.length; k++) {
        m.set(nums[k],k);
    }

    for (let i = 0; i < nums.length; i++) {
        let complement = target - nums[i];
        if(m.has(complement)  && m.get(complement) != i) {
            return [i,m.get(complement)];
        }
    }
};
```

- 再次改进

91.52% 使用一次 hsah

```
var twoSum = function(nums, target) {
 	var obj = {};
    for (var i=0; i < nums.length; i++) {
        var diff = target - nums[i];
        if (obj[nums[i]] === undefined) {
            obj[diff] = i;

        } else {
            return [obj[nums[i]], i];
        }
    }
	console.log(obj)
}
```
### 总结
- Duff's Device 优化遍历

- HashMap



## [Add two number](https://leetcode.com/problems/add-two-numbers/description/)
### 问题描述
给定两个链表代表两个非负整数，它们的位数反向存储，每个节点都是一位数。求两个数之和并以链表形式返回。

如：

```
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

```

### 分析

反向遍历两个链表，并求和。

## 问题列表
- [二进制字符串相加](https://siddontang.gitbooks.io/leetcode-solution/content/string/add_binary.html)

- [反转整数](https://siddontang.gitbooks.io/leetcode-solution/content/math/reverse_integer.html)

- [删除数组指定值的元素](https://siddontang.gitbooks.io/leetcode-solution/content/array/remove_element.html)

- [有序数组去重](https://siddontang.gitbooks.io/leetcode-solution/content/array/remove_duplicates_from_sorted_array.html)

a = [1,2,2,3,4,5,5,6,8]

s[a[i]]++

s = [0,1,2,1,1,2,1,0,1]

s[i] != 0 ? a.push(s[i])

a = [1,2,3,4,5,6,8]

### 参考链接
- [https://soulmachine.gitbooks.io/algorithm-essentials/content/java/](https://soulmachine.gitbooks.io/algorithm-essentials/content/java/)

- [https://siddontang.gitbooks.io/leetcode-solution/content/index.html](https://siddontang.gitbooks.io/leetcode-solution/content/index.html)