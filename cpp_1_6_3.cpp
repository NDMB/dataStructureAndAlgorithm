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
    cir_list() : n(0) // �ݷ� �ڿ��� �ʱ�ȭ ��ų ������ �־����� �� ���� ��ȣ �ȿ� �־���.
    {
        head = new node {NULL, NULL, NULL};
        head->next = head;
        head->prev = head;
    }

    size_t size() const // �Լ� ���� const�� �ش� �Լ� �ȿ��� ��ü�� ����� ������ �� ������ �ϱ� ����.
    {
        return n;
    }
}