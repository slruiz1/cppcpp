
#include <bits/stdc++.h>

using namespace std;

struct Node {
        Node(int d) : data(d) { }
        int data{0};
        unique_ptr<Node> left{nullptr};
        unique_ptr<Node> right{nullptr};
};

std::vector<std::vector<int>> zigzag_level_order(Node* root) {
        std::vector<std::vector<int>> result;
        if (!root) {
                return result;
        }

        deque<Node*> queue;
        queue.push_back(root);
        bool left_to_right = true;

        while (!queue.empty()) {
                size_t level_size = queue.size();
                std::vector<int> current_level;
                for (size_t i = 0; i < level_size; ++i) {
                        Node* node = queue.front();
                        queue.pop_front();
                        current_level.push_back(node->data);

                        if (node->left) {
                                queue.push_back(node->left.get());
                        }
                        if (node->right) {
                                queue.push_back(node->right.get());
                        }
                }
                if (!left_to_right) {
                        std::reverse(current_level.begin(), current_level.end());        
                }
                result.emplace_back(std::move(current_level));
                //std::move(current_level.begin(), current_level.end(), back_inserter(result));
                left_to_right = !left_to_right;
        }

        return result;
}

int main()
{
        Node root(3);
        root.left = make_unique<Node>(9);
        root.right = make_unique<Node>(20);
        root.right->left = make_unique<Node>(15);
        root.right->right = make_unique<Node>(7);

        auto zigzag_result = zigzag_level_order(&root);
        for (auto i : zigzag_result) {
                putchar('[');
                for (auto j : i) {
                        printf("%d,", j);
                }
                putchar(']');
        }
        printf("\n");

        return 0;
}
