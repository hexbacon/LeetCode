def twoSum(nums, target):
    res = dict()
    for idx, num in enumerate(nums):
        if res.get(target - num):
            return [idx, res.get(target - num)]
        res[num] = idx
        print(res)
    return [-1,-1]

print(twoSum([1,2,4,5,6], 3))