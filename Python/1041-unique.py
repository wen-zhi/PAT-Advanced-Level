from collections import Counter


if __name__ == '__main__':
    nums = [int(i) for i in input().split()][1:]
    counter = Counter(nums)
    for num in nums:
        if counter[num] == 1:
            print(num)
            break
    else:
        print("None")
