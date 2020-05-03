

def swap_count(nums):
    num_to_idx = {}
    for idx, num in enumerate(nums):
        num = int(num)
        if idx != num or idx == 0:
            num_to_idx[num] = idx
    count = 0
    while num_to_idx:
        idx = num_to_idx[0]
        if idx != 0:
            num_to_idx[0] = num_to_idx[idx]
            del num_to_idx[idx]
            count += 1
        elif idx == 0 and len(num_to_idx) == 1:
            del num_to_idx[idx]
        else:
            for key in num_to_idx:
                if key != 0:
                    num_to_idx[0] = num_to_idx[key]
                    num_to_idx[key] = 0
                    count += 1
                    break
    return count


if __name__ == '__main__':
    _ = input()
    nums = [int(i) for i in input().split()]
    print(swap_count(nums))
