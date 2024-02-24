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

def isPalindrome(num):
    num_list = str(num)
    num_list_rev = num_list[::-1]

    return num_list == num_list_rev
