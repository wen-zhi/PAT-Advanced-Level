import sys
sys.setrecursionlimit(1024)


def postorder(pre, post, is_mirror):
    if not pre:
        return

    root = pre[0]
    l_pre, r_pre = [], []
    for node in pre[1:]:
        if is_mirror:
            if node >= root:
                if r_pre:
                    break
                else:
                    l_pre.append(node)
            else:
                r_pre.append(node)
        else:
            if node < root:
                if r_pre:
                    break
                else:
                    l_pre.append(node)
            else:
                r_pre.append(node)

    postorder(l_pre, post, is_mirror)
    postorder(r_pre, post, is_mirror)
    post.append(root)


if __name__ == '__main__':
    _ = input()
    pre = [int(i) for i in input().split()]
    post = []
    postorder(pre, post, is_mirror=False)
    if len(post) != len(pre):
        post = []
        postorder(pre, post, is_mirror=True)
    if len(post) == len(pre):
        print("YES")
        print(*post)
    else:
        print("NO")
