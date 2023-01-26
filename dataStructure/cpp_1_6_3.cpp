#include <iostream>

template <typename T>
struct cir_list_node
{
    T* data;
    cir_list_node* next;
    cir_list_node* prev;

    ~cir_list_node()
    {
        delete data;
    }
};

template <typename T>
struct cir_list
{
public:
    using node = cir_list_node<T>;
    using node_ptr = node*;

private:
    node_ptr head;
    size_t n;

public:
    cir_list() : n(0) // 콜론 뒤에는 초기화 시킬 변수가 주어지고 그 값이 괄호 안에 주어짐.
    {
        head = new node {NULL, NULL, NULL};
        head->next = head;
        head->prev = head;
    }

    size_t size() const // 함수 뒤의 const는 해당 함수 안에서 객체의 멤버를 변경할 수 없도록 하기 위함.
    {
        return n;
    }
}