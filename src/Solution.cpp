#include "Solution.h"

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target)
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

int Solution::reverse(int x)
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

bool Solution::isPalindrome(int x) 
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

int Solution::romanToInt(std::string s) 
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

std::string Solution::longestCommonPrefix(std::vector<std::string>& strs) 
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