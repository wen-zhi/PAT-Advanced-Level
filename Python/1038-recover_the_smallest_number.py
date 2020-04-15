from functools import cmp_to_key


def recover_the_smallest_num(nums):
    nums.sort(key=cmp_to_key(lambda x, y: -1 if x + y < y + x else 1))
    smallest = ''.join(nums).lstrip('0')
    if smallest:
        return smallest
    else:
        return '0'


if __name__ == '__main__':
    nums = input().split()[1:]
    print(recover_the_smallest_num(nums))
