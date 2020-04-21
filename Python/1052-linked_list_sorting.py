

class Node():
    def __init__(self, addr, key, nxt_addr):
        self.addr = addr
        self.key = key
        self.nxt_addr = nxt_addr

    def __lt__(self, other):
        return self.key < other.key

    def __str__(self):
        return f'{self.addr} {self.key} {self.nxt_addr}'


if __name__ == '__main__':
    N, head_addr = input().split()
    nexts = {}
    for _ in range(int(N)):
        addr, key, nxt_addr = input().split()
        nexts[addr] = (key, nxt_addr)
    nodes = []
    curr_addr = head_addr
    while curr_addr != '-1':
        key, nxt_addr = nexts[curr_addr]
        nodes.append(Node(curr_addr, int(key), nxt_addr))
        curr_addr = nxt_addr
    if nodes:
        nodes.sort()
        # update nxt_addr
        for i in range(len(nodes) - 1):
            nodes[i].nxt_addr = nodes[i+1].addr
        nodes[-1].nxt_addr = "-1"
        print(len(nodes), nodes[0].addr)
        for node in nodes:
            print(node)
    else:
        print("0 -1")
