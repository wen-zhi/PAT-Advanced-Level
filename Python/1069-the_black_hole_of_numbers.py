

if __name__ == '__main__':
    num = input().zfill(4)
    if num == num[::-1]:
        print(f"{num} - {num} = 0000")
    else:
        while True:
            num = ''.join(sorted(num, reverse=True))
            num_r = num[::-1]
            res = str(int(num) - int(num_r)).zfill(4)
            print(f'{num} - {num_r} = {res}')
            if res == '6174':
                break
            else:
                num = res
