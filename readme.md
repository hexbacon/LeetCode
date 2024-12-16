
# LeetCode & HackerRank Progress

This repo will serve a as a guide and tracker of all LeetCode & HackerRank problem solve be me. The intentation is to keep constantly updating my progress with new and better solutions.

## LeetCode Problems

[Two Sum](#two-sum)

[Reverse Integer](#reverse-integer)

[Palindrome Number](#palindrome-number)

[Roman to Integer](#roman-to-integer)

[Longest Common Prefix](#longest-common-prefix)

[Add Two Numbers](#add-two-numbers)

[Time Conversion](#time-conversion)

[Sqrt(x)](#sqrt(x))

[Valid Parentheses](#valid-parentheses)

## Solutions

### Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

**Example 1:**

```text
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```

**Example 2:**

```text
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

**Example 3:**

```text
Input: nums = [3,3], target = 6
Output: [0,1]
```

**Solution:**

A good solution for thsi problem involves using a map. In *C++* a map is a type of associative container. We can solve the problem in the following way:
    1. Loop throught the array of number.
    2. Check if the following key exist:
        a. Check if key with value target - nums[index] exist.
    3. If key exist, return return current index and target - nums[index] key.
    4. If key does not exist, add key and index to map.

```c++
#include <unordered_map>
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        // Create Map to hold data
        std::unordered_map<int, int> data;
        // Loop through array
        for (int i = 0; i < nums.size(); i++) 
        {
            // If target - number at ith postion equals the number with key-value
            if (data.count(target - nums[i])) 
            {
                // Answer found, return
                return {i, data[target - nums[i]]};
            }
            data[nums[i]] = i;
        }
    return {-1, -1};
    }
};
```

```python
def twoSum(nums, target):
    # Create dict to hold answer
    res = dict()
    for idx, num in enumerate(nums):
        # if target - number is a key, return answer
        if res.get(target - num) != None:
            print("Found it")
            return sorted([idx, res.get(target - num)])
        # if answer is not found, add idx to the dict
        res[num] = idx
    return [-1,-1]
```

### Reverse Integer

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

**Assume the environment does not allow you to store 64-bit integers (signed or unsigned).**

**Example 1:**

```text
Input: x = 123
Output: 321

**Exmaple 2:**

```text
Input: x = -123
Output: -321
```

**Example 3:**

```text
Input: x = 120
Output: 21
```

**Constraints:**

```text
-231 <= x <= 231 - 1
```

**Solution:**

Using the modulos operator, it is easy to extra the last digit from the integer.
    1. Create integer variables reversed and pop.
    2. Use % (mod) 10 to extract last digit from x.
    3. Divide x by 10.
    4. reversed then equal to itself multiply by 10 plus *pop*.
    5. Repeat process while x is not 0.

```c++
class Solution 
{
public:
    int reverse(int x) 
    {
        int reversed = 0;
        int pop = 0;
        while(x != 0)
        {
            pop = x % 10;
            x /= 10;
            // Check for max int number
            if (reversed > INT_MAX/10 || reversed == INT_MAX/10 && pop > 7)
                return 0;
            // Check for min int number
            if (reversed < INT_MIN/10 || reversed == INT_MIN/ 10 && pop < -8)
                return 0;
            reversed = (reversed * 10) + pop;
        }
        return reversed;
    }
};
```

**Solution Python**

A Simple solution in Python is casting the value into a list and then using reverse slicing to reverse the number. This approach is simple but bring a conditional statement for negative number.

```python
def reverse(num):
    result = str(num)
    sign = 1
    if result[0] == '-':
        result_reverse = result[:0:-1]
        print(result_reverse)
        sign = -1
    else:
        result_reverse = result[::-1]
    return int(result_reverse) * sign
```

### Palindrome Number

Given an integer x, return true if x is a palindrome, and false otherwise.

**Example 1:**

```text
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
```

**Example 2:**

```text
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```

**Example 3:**

```text
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

**Constraints:**

```text
-231 <= x <= 231 - 1
```

**Solution:**

An easy solution to this problem involves reversing:
    1. Convert integer to string.
    2. Create a copy of the string and reverse it.
    3. Compare return the comparison of both string.

```c++
class Solution {
public:
    bool isPalindrome(int x) 
    {
        // If negative number -> return false
        if(x < 0)
            return false;
        else if(x > 0 && x < 10)
            return true;
        else
        {
            std::string value = std::to_string(x);
            std::string to_reverse = value;
            std::reverse(to_reverse.begin(), to_reverse.end());
            return value == to_reverse;
        }
    }
};
```

```python
class Solution:
    def isPalindrome(self, x: int) -> bool:
        # If x is neg
        if x < 0:
            return False
        elif x >= 0 and x < 10:
            return True
        else:
            return str(x) == str(x)[::-1]

```

### Roman to Integer

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M

```text
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

* I can be placed before V (5) and X (10) to make 4 and 9.
* X can be placed before L (50) and C (100) to make 40 and 90.
* C can be placed before D (500) and M (1000) to make 400 and 900.


Given a roman numeral, convert it to an integer.

**Example 1:**

```text
Input: s = "III"
Output: 3
Explanation: III = 3.
```

**Example 2:**

```text
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
```

**Example 3:**

```text
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
```

**Constraints:**

* 1 <= s.length <= 15
* s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
* It is guaranteed that s is a valid roman numeral in the range [1, 3999].

**Solution*:**

We can utilize an map to store the roman character with its corresponding value, then loop throught the string reading each character and adding them as we go, all this while keeping track of rules.
    1. Create map to store roman character.
    2. Itirate the string reading each character.
    3. Compare current character with character at position index + 1.
    4. Compute value

```c++
class Solution 
{
public:
    int romanToInt(string s) 
    {
        // Basisc data
        std::map<char, int> symbols;
        symbols['I'] = 1;
        symbols['V'] = 5;
        symbols['X'] = 10;
        symbols['L'] = 50;
        symbols['C'] = 100;
        symbols['D'] = 500;
        symbols['M'] = 1000;

        int result = 0;
        for(int index(0); index < s.length(); index++)
        {
            if (symbols[s[index]] < symbols[s[index + 1]])
                result = result - symbols[s[index]];
            else
                result = result + symbols[s[index]];
        }
        return result;
    }
};
```

```python
class Solution:
    def romanToInt(self, s: str) -> int:
        symbols = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        res = 0
        for idx in range(len(s)):
            if idx != len(s) - 1 and symbols[s[idx]] < symbols[s[idx+1]]:
                res -= symbols[s[idx]]
            else:
                res += symbols[s[idx]]
        return res
```

### Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

**Example 1:**

```text
Input: strs = ["flower","flow","flight"]
Output: "fl"
```

**Example 2:**

```text
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
```

**Constraints:**

* 1 <= strs.length <= 200
* 0 <= strs[i].length <= 200
* strs[i] consists of only lowercase English letters.

**Solution:**

A good solution for this problem involves an *Horizontal Scanning* algorithm. We can solve the problem in the following way:
    1. Check if vector is empty.
    2. Select the first word in the vector, this would be a prefix.
    3. Loop throught the vector starting at position 1.
    4. Assign the Prefix to a substring of itself starting at position 0 and at whichever is smaller, the prefix itself or the newly selected word.
    5. Loop each character of the selected word.
    6. If if character at the ith position at the prefix and newly selected word are not the same, create a new substring from prefix upto but not included the position of ith character.
    7. Repeat until vector has been itirated.
    8. Return prefix.


```c++
class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.size() == 0) return "";
        // Grab first word
        std::string prefix = strs[0];
        // Loop the array of words
        for (int i(1); i < strs.size(); i++)
        {
            std::string s = strs[i];
            // Check if words  is empty and prefix is empty
            if (s.length() == 0 && prefix == "") return "";
            // Construct new substring with min val between prefix a new word
            prefix = prefix.substr(0, std::min(prefix.length(), s.length()) );
            // Loop throught char
            for (int k = 0; k < prefix.length() && s.length(); k++)
            {
                // If char do not match
                if (s[k] != prefix[k])
                {
                    // Create new substring upto char location
                    prefix = prefix.substr(0, k);
                    break;
                }
            }
        }
        return prefix;
    }
};
```

### Add Two Numbers

You are given two **non-empty linked** lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Example 1:**

```text
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```

```text
Input: l1 = [0], l2 = [0]
Output: [0]
```

```text
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

**Constraints:**

* The number of nodes in each linked list is in the range [1, 100].
* 0 <= Node.val <= 9
* It is guaranteed that the list represents a number that does not have leading zeros.

**Solution:**

A good solution for the problem would be the following:
    1. Loop until both inputs are equal to nullptr.
    2. If one input is nullptr and the other one is not, consider the input value as 0.
    3. Add values to a new node.

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode * dummy = new ListNode(0);
        ListNode *ans = dummy;
        bool complete = false;
        int carry = 0;
        int sum = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int val_1 = l1 ? l1->val : 0;
            int val_2 = l2 ? l2->val : 0;
            // New Digits
            sum = val_1 + val_2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            // Update
            ans->next = new ListNode(sum);
            // Update ptrs
            ans = ans->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummy->next;
    }
};
```

### Time Conversion

Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.

Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.

* 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

**Example 1:**

```text
Input: s = "12:01:00PM"
Outout: "12:01:00"
```

```text
Input s = "12:01:00AM"
Output: "00:01:00"
```

**Constraints:**

* All input times are valid

**Solution:**

A solution to this problem in reading the 9th character of the string. If the char is A, then we check if the leading characters are equal to 12, if yes, add 00 to the answer string and add the substring starting from the 3rd character to the end, otherwise just copy the string. If it's P, then add 12 to the leading characters and check if it over 24.

```c++
string timeConversion(string s) 
{
    bool am = false;
    string ans = "";
    if (s.length() == 0 || s.length() < 10)
        return ans;
    if (s[8] == 'A')
        am = true;
    if (am)
    {
        if (s.substr(0,2) == "12")
        {
            ans += "00";
            ans += s.substr(2, 6);
        }
        else
            ans = s.substr(0, 8);
    }
    else
    {
        if (s.substr(0,2) == "12")
            ans += s.substr(0, 8);
        else
        {
            int toAdd = stoi(s.substr(0, 2));
            toAdd += 12;
            cout << "toAdd: " << toAdd << endl;
            if(toAdd == 24)
            {
                ans += "00";
                ans += s.substr(2, 6);
            }
            else
            {
                ans += to_string(toAdd);
                ans += s.substr(2, 6);
            }
        }
    }
    return ans;
}
```
### Sqrt(x)

Given a non-negative integer ```x```, return the square root of ```x``` rounded down to the nearest integer. The returned 
integer should be non-negative as well.

You must **not use any** built-in exponent function or operator.

- For example, do not use ```pow(x, 0.5)``` in c++ or ```x ** 0.5``` in python.

**Example 1:**

```text
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
```

**Example 2:**

```text
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
```

**Solution:**

```python
def mySqrt(self, x: int) -> int:
        L, R = 1, x
        while L <= R:
            M = (L+R) // 2
            M_squared = M * M
            if M_squared == x:
                return M
            elif M_squared < x:
                L = M + 1
            else:
                R = M - 1
        return R
```

### Valid Parentheses

Given a string s containing just the characters ```'('```, ```')'```, ```'{'```, ```'}```', ```'['``` and ```']'```, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.

2. Open brackets must be closed in the correct order.

3. Every close bracket has a corresponding open bracket of the same type.

**Example 1:**

```text
Input: s = "()"

Output: true
```

**Example 2:**

```text
Input: s = "()[]{}"

Output: true
```

**Example 3:**

```text
Input: s = "(]"

Output: false
```

**Example 4:**

```text
Input: s = "([])"

Output: true
```

**Solution**

```c++
class Solution {
public:
    bool isValid(std::string s) 
    {
        std::stack<char> tracker;
        char prev = s[0];
        tracker.push(prev);

        for (int idx = 1; idx < s.length(); idx++) {
            if (prev == char(s[idx] - 1) || prev == char(s[idx] - 2)) {
                tracker.pop();
                prev = !tracker.empty() ? tracker.top() : 0;
            } else {
                tracker.push(s[idx]);
                prev = s[idx];
            }
        }
        return tracker.empty();
    }
};
```

```python

```