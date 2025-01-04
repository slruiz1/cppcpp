// C++ program to implement a stack that supports
// getMaximum() in O(1) time and O(1) extra space.
#include <bits/stdc++.h>
using namespace std;

// A user defined stack that supports getMax() in
// addition to push() and pop()
struct MyStack
{
        stack<int> s{};
        int m_max = INT_MIN;

        // Prints maximum element of MyStack
        void getMax()
        {
                if (s.empty())
                        cout << "Stack is empty\n";

                // variable m_max stores the maximum element
                // in the stack.
                else
                        cout << "Maximum Element in the stack is: " << m_max << "\n";
        }

        // Prints top element of MyStack
        void peek()
        {
                if (s.empty()) {
                        cout << "Stack is empty ";
                        return;
                }

                const int t = s.top(); // Top element.

                cout << "Top Most Element is: ";

                // If t < m_max means m_max stores
                // value of t.
                (t > m_max) ? cout << m_max : cout << t;
        }

        // Remove the top element from MyStack
        void pop()
        {
                if (s.empty()) {
                        cout << "Stack is empty\n";
                        return;
                }

                cout << "Top Most Element Removed: ";
                int t = s.top();
                s.pop();

                // Maximum will change as the maximum element
                // of the stack is being removed.
                if (t > m_max) {
                        cout << m_max << "\n";
                        m_max = 2 * m_max - t;
                }
                else
                        cout << t << "\n";
        }

        // Removes top element from MyStack
        void push(int x)
        {
                // Insert new number into the stack
                if (s.empty()) {
                        m_max = x;
                        s.push(x);
                        cout << "Number Inserted: " << x << "\n";
                        return;
                }

                // If new number is greater than m_max,
                //  we push the current max in encoded form.
                if (x > m_max) {
                        s.push(2 * x - m_max);
                        m_max = x;
                }
                else
                        s.push(x);

                cout << "Number Inserted: " << x << "\n";
        }
};

// Driver Code
int main()
{
        MyStack s;
        s.push(3);
        s.push(5);
        s.getMax();
        s.push(7);
        s.push(19);
        s.getMax();
        s.pop();
        s.getMax();
        s.pop();
        s.peek();

        return 0;
}
