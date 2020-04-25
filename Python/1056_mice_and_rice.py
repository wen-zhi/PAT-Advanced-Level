

def mice_and_rice(order, mouse, group_size):
    n_player = len(order)
    rounds = [0] * n_player
    round = 1
    while len(order) > 1:
        winners = []
        for i in range(0, len(order), group_size):
            group = order[i:i+group_size]
            winner = max(group, key=lambda x: mouse[x])
            for player in group:
                if player != winner:
                    rounds[player] = round
            winners.append(winner)
        round += 1
        order = winners
    rounds[order[0]] = round
    players = list(range(n_player))
    # sort by round
    players.sort(key=lambda x: rounds[x], reverse=True)
    ranks = [None] * n_player
    last_player = players[0]
    ranks[last_player] = 1
    for rank, player in enumerate(players, start=1):
        if rounds[player] == rounds[last_player]:
            ranks[player] = ranks[last_player]
        else:
            ranks[player] = rank
            last_player = player
    return ranks


if __name__ == '__main__':
    _, group_size = [int(i) for i in input().split()]
    mouse = [int(i) for i in input().split()]
    order = [int(i) for i in input().split()]
    print(*mice_and_rice(order, mouse, group_size))
