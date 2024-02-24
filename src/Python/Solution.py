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

print(twoSum([1,2,4,5,6], 11))