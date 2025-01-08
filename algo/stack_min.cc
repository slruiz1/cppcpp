#include <bits/stdc++.h>

using namespace std;

#if 0
How 2*x – m_min is less than x in push()? 

x < m_min which means x – m_min < 0
 

// Adding x on both sides
x – m_min + x < 0 + x 
2*x – m_min < x 
We can conclude 2*x – m_min < new m_min 
#endif

class StackMin
{
        stack<int> m_s{};
        int m_min = INT_MAX;
public:
        StackMin() = default;
        void push(int x) {
                if (!m_s.empty()) {
                        printf("PUSH - s.top(): %d, min: %d, peek: %d, X: %d\n", top(), min(), peek(), x);
                }
                if (x < m_min) { // we want top < new min (x).
                        m_s.push((x << 1) - m_min);
                        m_min = x;
                } else {
                        m_s.push(x);
                }
        }
        void pop() {
                printf("POP - s.top(): %d, min: %d, peek: %d\n", top(), min(), peek());
                if (m_min > m_s.top()) {
                        m_min = (m_min << 1) - m_s.top();
                }
                m_s.pop();
        }
        int top() const {
                return m_s.top();
        }
        int peek() const {
                return (m_min > m_s.top()) ? m_min : m_s.top();
        }
        int min() const {
                return m_min;
        }
        bool empty() const {
                return m_s.empty();
        }
};

int main()
{
        StackMin s;
        s.push(INT_MAX);
        printf("s.top(): %d, min: %d, peek: %d\n", s.top(), s.min(), s.peek());
        s.pop();

        s.push(10);
        s.push(5);
        s.push(1);
        s.push(1);
        assert(s.min() == 1);

        s.pop();
        printf("poped 1 -> s.top(): %d, min: %d, peek: %d\n", s.top(), s.min(), s.peek());
        assert(s.min() == 1);

        s.pop();
        printf("poped 1 -> s.top(): %d, min: %d, peek: %d\n", s.top(), s.min(), s.peek());
        assert(s.min() == 5);

        s.pop();
        assert(s.min() == 10);
        //assert(s.top() == 10);
        printf("s.top(): %d, min: %d, peek: %d\n", s.top(), s.min(), s.peek());
//----
        s.push(0);
        assert(s.min() == 0);
        printf("s.top(): %d, min: %d, peek: %d\n", s.top(), s.min(), s.peek());

        s.push(-2);
        s.push(1);
        assert(s.min() == -2);
        printf("s.top(): %d, min: %d, peek: %d\n", s.top(), s.min(), s.peek());

        s.pop();
        assert(s.min() == -2);
        printf("poped 1 -> s.top(): %d, min: %d, peek: %d\n", s.top(), s.min(), s.peek());

        s.pop();
        printf("poped -2 -> s.top(): %d, min: %d, peek: %d\n", s.top(), s.min(), s.peek());
        assert(s.min() == 0);

        s.pop();
        assert(s.min() == 10);
        printf("s.top(): %d, min: %d, peek: %d\n", s.top(), s.min(), s.peek());

        s.pop();
        assert(s.empty() == true);
        printf(">>> min: %d\n", s.min());

        s.push(INT_MAX);
        printf("s.top(): %d, min: %d, peek: %d\n", s.top(), s.min(), s.peek());
        assert(s.min() == INT_MAX);
        s.pop();

        return 0;
}
