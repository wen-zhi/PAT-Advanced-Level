from collections import Counter


if __name__ == '__main__':
    _, row = [int(i) for i in input().split()]
    pixels = []
    for _ in range(row):
        pixels.extend([int(i) for i in input().split()])
    counter = Counter(pixels)
    dominat_color, _ = max(counter.items(), key=lambda x: x[1])
    print(dominat_color)
