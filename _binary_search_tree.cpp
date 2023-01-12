// BST (binary search tree)
// �θ� ����� �� >= ���� �ڽ� ����� ��, �θ� ����� �� <= �ڽ� ����� ��
// ��, ���� ��� <= �θ� ��� <= ������ ���

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
            std::cout << value << "��(��) ã�ҽ��ϴ�." << std::endl;
            return current;
        }

        if(value < current->data)
        {
            std::cout << current->data << "���� �������� �̵�: ";
            return find_impl(current->left, value);
        }

        if(value > current->data)
        {
            std::cout << current->data << "���� ���������� �̵�: ";
            return find_impl(current->right, value);
        }
    };

public:
    void insert(int value) // �� ����
    {
        if(!root) // ���� �ϳ��� ���°��
        {
            root = new node {value, NULL, NULL}; // ��Ʈ��忡 �� ����
        }
        else // ���� �ִ� ���
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