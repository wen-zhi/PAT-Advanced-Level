

class People():

    high_line = 0

    def __init__(self, id_num, virtue, talent):
        self.id_num = id_num
        self.virtue = virtue
        self.talent = talent
        self.total_value = virtue + talent

        if self.virtue >= People.high_line:
            if self.talent >= People.high_line:
                self.type = 1  # sage
            else:
                self.type = 2  # nobleman
        else:
            if self.virtue >= self.talent:
                self.type = 3  # fool man
            else:
                self.type = 4  # small man

    def __lt__(self, other):
        if self.type < other.type:
            return True
        elif self.type > other.type:
            return False
        # rank by total_value
        if self.total_value > other.total_value:
            return True
        elif self.total_value < other.total_value:
            return False
        # rank by virtue
        if self.virtue > other.virtue:
            return True
        elif self.virtue < other.virtue:
            return False
        # rank by ID
        return self.id_num < other.id_num

    def __str__(self):
        return f'{self.id_num} {self.virtue} {self.talent}'


if __name__ == '__main__':
    n_people, low_line, high_line = [int(i) for i in input().split()]
    # set high_line
    People.high_line = high_line
    all_people = []
    for _ in range(n_people):
        id_num, virtue, talent = input().split()
        virtue = int(virtue)
        talent = int(talent)
        if virtue < low_line or talent < low_line:
            continue
        all_people.append(People(id_num, virtue, talent))
    # sorting
    all_people.sort()
    print(len(all_people))
    for people in all_people:
        print(people)
