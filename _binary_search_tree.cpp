// BST (binary search tree)
// 부모 노드의 값 >= 왼쪽 자식 노드의 값, 부모 노드의 값 <= 자식 노드의 값
// 즉, 왼쪽 노드 <= 부모 노드 <= 오른쪽 노드

#include <iostream>

struct node
{
    int data;
    node* left;
    node* right;
};

struct bst
{
    node* root;

    node* find(int val)
    {
        return find_impl(root, val);
    }

private:
    node* find_impl(node* current, int value)
    {
        if (!current)
        {
            std::cout << std::endl;
            return NULL;
        }

        if (current->data == value)
        {
            std::cout << value << "을(를) 찾았습니다." << std::endl;
            return current;
        }

        if(value < current->data)
        {
            std::cout << current->data << "에서 왼쪽으로 이동: ";
            return find_impl(current->left, value);
        }

        if(value > current->data)
        {
            std::cout << current->data << "에서 오른쪽으로 이동: ";
            return find_impl(current->right, value);
        }
    };

public:
    void insert(int value) // 값 삽입
    {
        if(!root) // 값이 하나도 없는경우
        {
            root = new node {value, NULL, NULL}; // 루트노드에 값 저장
        }
        else // 값이 있는 경우
        {
            insert_impl(root, value); // 
        }
    };

private:
    void insert_impl(node* current, int value)
    {
        if (value < current->data)
        {
            if(!current->left)
            {
                current->left = new node {value, NULL, NULL};
            }
            else
            {
                insert_impl(current->left, value);
            }
        }
        else
        {
            if(!current->right)
            {
                current->right = new node {value, NULL, NULL};
            }
            else
            {
                insert_impl(current->right, value);
            }
        }
    }
}