/**
 * @author Charles Liu
 * @email liuchao853@gmail.com
 * @create date 2018-07-18 01:29:38
 * @modify date 2018-07-18 01:29:38
 * @desc implement stack using a queue internally.
*/

#include <stdio.h>
#include <queue>
#include <iostream>

class LCStack {
private:
    std::queue<int> m_queue;
public:
    LCStack(){}
    ~LCStack(){}

    void push(int elem){
        std::queue<int> tmp;

        while(!this->m_queue.empty()) {
            tmp.push(this->m_queue.front());
            this->m_queue.pop();
        }

        this->m_queue.push(elem);

        while(!tmp.empty()) {
            this->m_queue.push(tmp.front());
            tmp.pop();
        }
    }

    int top(){
        return this->m_queue.front();
    }

    void pop() {
        this->m_queue.pop();
    }

    size_t size() {
        return this->m_queue.size();
    }

    bool empty() {
        return this->m_queue.empty();
    }
};

int main() {
    LCStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    
    while(!stack.empty()) {
        std::cout << "top is " << stack.top() << std::endl;
        stack.pop();
    }
    return 0;
}