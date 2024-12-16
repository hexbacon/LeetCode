from collections import Counter

def plusMinus(arr):
    counter = Counter(arr)
    size = len(arr)
    for key, value in counter.items():
        print(value/size)

n = [-4, 3, -9, 0, 4, 1,]
plusMinus(n)