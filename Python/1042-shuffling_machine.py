

def shuffling(cards, permutation, n_time):
    new_cards = [None] * (len(cards) + 1)
    for _ in range(n_time):
        for card, idx in zip(cards, permutation):
            new_cards[idx] = card
        cards = new_cards[1:]
    return cards


if __name__ == '__main__':
    cards = []
    for card_type in ['S', 'H', 'C', 'D']:
        for card_n in range(1, 14):
            cards.append(card_type + str(card_n))
    cards.extend(["J1", "J2"])
    n_time = int(input())
    permutation = [int(i) for i in input().split()]
    print(*shuffling(cards, permutation, n_time))
