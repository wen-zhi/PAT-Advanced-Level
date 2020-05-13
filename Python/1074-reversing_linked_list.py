

class Node():
    def __init__(self, addr, data, nxt):
        self.addr = addr
        self.data = data
        self.nxt = nxt

    def __str__(self):
        return f'{self.addr} {self.data} {self.nxt}'


def reversing_linked_list(linked_list, k):
    n_node = len(linked_list)
    r_linked_list = []
    last_node = Node(None, None, None)
    for i in range(0, n_node, k):
        if i + k <= n_node:
            for node in reversed(linked_list[i:i+k]):
                last_node.nxt = node.addr
                r_linked_list.append(node)
                last_node = node
        else:
            last_node.nxt = linked_list[i].addr
            r_linked_list.extend(linked_list[i:i+k])
    r_linked_list[-1].nxt = '-1'  # the end of the list
    return r_linked_list


if __name__ == '__main__':
    head, n_node, k = input().split()
    n_node, k = int(n_node), int(k)
    nodes = {}
    for _ in range(n_node):
        addr, data, nxt = input().split()
        nodes[addr] = Node(addr, data, nxt)
    linked_list = []
    nxt = head
    while nxt != '-1':
        node = nodes[nxt]
        linked_list.append(node)
        nxt = node.nxt
    r_linked_list = reversing_linked_list(linked_list, k)
    for node in r_linked_list:
        print(node)
