#include <iostream>
#include <vector>


std::vector<int> pre;
bool is_mirror = false;


void
postorder(std::size_t bgn, std::size_t end, std::vector<int> &post)
{
    if (bgn == end) return;

    int root = pre[bgn];
    std::size_t l_end = bgn + 1, r_bgn = end - 1;

    if (!is_mirror) {
        while (l_end < end && pre[l_end] < root) ++l_end;
        while (r_bgn > bgn && pre[r_bgn] >= root) --r_bgn;
    } else {
        while (l_end < end && pre[l_end] >= root) ++l_end;
        while (r_bgn > bgn && pre[r_bgn] < root) --r_bgn;
    }

    postorder(bgn + 1, l_end, post);
    postorder(r_bgn + 1, end, post);
    post.push_back(root);
}


int main() {

    std::ios::sync_with_stdio(false);

    std::size_t N;
    std::cin >> N;

    for (std::size_t i=0; i<N; ++i) {
        int node;
        std::cin >> node;
        pre.push_back(node);
    }

    std::vector<int> post;
    postorder(0, N, post);
    if (post.size() != N) {
        post.clear();
        is_mirror = true;
        postorder(0, N, post);
    }
    if (post.size() == N) {
        std::cout << "YES\n";
        for (auto iter=post.begin(); iter!=post.end()-1; ++iter) {
            std::cout << *iter << ' ';
        }
        std::cout << post.back() << '\n';
    } else {
        std::cout << "NO\n";
    }

    return 0;
}
