

class User():

    full_marks = []

    def __init__(self, u_id):
        self.u_id = u_id
        self.scores = ['-'] * len(User.full_marks)
        self.total_score = 0
        self.n_solved = 0
        self.submit_succeed = False

    def update_score(self, p_id, new_score):
        if new_score == -1:
            new_score = 0
        else:
            self.submit_succeed = True
        old_score = self.scores[p_id-1]
        if old_score != '-':
            if new_score > old_score:
                self.scores[p_id-1] = new_score
                self.total_score += (new_score - old_score)
                if new_score == User.full_marks[p_id-1]:
                    self.n_solved += 1
        else:
            self.scores[p_id-1] = new_score
            self.total_score += new_score
            if new_score == User.full_marks[p_id-1]:
                self.n_solved += 1

    def __lt__(self, other):
        if self.total_score > other.total_score:
            return True
        elif self.total_score < other.total_score:
            return False
        if self.n_solved > other.n_solved:
            return True
        elif self.n_solved < other.n_solved:
            return False
        return self.u_id < other.u_id

    def __str__(self):
        return (f"{self.u_id:05d} {self.total_score} "
                f"{' '.join(str(score) for score in self.scores)}")


if __name__ == '__main__':
    n_user, _, n_submit = [int(i) for i in input().split()]
    User.full_marks = [int(i) for i in input().split()]
    users = [User(i + 1) for i in range(n_user)]
    for _ in range(n_submit):
        u_id, p_id, score = [int(i) for i in input().split()]
        users[u_id-1].update_score(p_id, score)
    users.sort()
    last_rank, last_score = 1, users[0].total_score
    for i, user in enumerate(users, start=1):
        if user.total_score == last_score:
            rank = last_rank
        else:
            rank = i
            last_rank, last_score = rank, user.total_score
        if user.submit_succeed:
            print(rank, user)
