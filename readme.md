
# LeetCode Progress

This repo will serve a as a guide and tracker of all LeetCode problem solve be me. The intentation is to keep constantly updating my progress with new and better solutions.

## LeetCode Problems

[Two Sum](#two-sum)

[Reverse Integer](#reverse-integer)

[Palindrome Number](#palindrome-number)

[Roman to Integer](#Roman-to-Integer)

[Longest Common Prefix](#longest-common-prefix)

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