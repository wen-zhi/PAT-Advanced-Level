

if __name__ == '__main__':
    nums = [int(i) for i in input().split()][1:]

    cum_sum = [0]
    for num in nums:
        cum_sum.append(cum_sum[-1] + num)

    n_pair = int(input())
    for _ in range(n_pair):
        i, j = [int(i) - 1 for i in input().split()]
        if j < i:
            i, j = j, i
        dist = cum_sum[j] - cum_sum[i]
        alt_dist = cum_sum[i] + cum_sum[-1] - cum_sum[j]
        print(min(dist, alt_dist))
