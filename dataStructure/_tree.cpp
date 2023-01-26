// tree

#include <iostream>
#include <queue>

struct node
{
    std::string position;
    node* first;
    node* second;
};

struct org_tree
{
    node* root;

    static org_tree create_org_structure(const std::string& pos)
    {
        org_tree tree;
        tree.root = new node {pos, NULL, NULL};
        return tree;
    }

    static node* find(node* root, const std::string& value) // inorder traversal
    {
        if (root == NULL) // 현재 노드가 NULL인 경우
            return NULL;

        if (root->position == value) // 현재 노드가 찾는 노드일 경우
            return root;

        auto firstFound = org_tree::find(root->first, value); // 왼쪽 자식노드로 이동

        if (firstFound != NULL) // 왼쪽 자식노드가 있는 경우 그 주소를 리턴.
            return firstFound;

        return org_tree::find(root->second, value); // 오른쪽 자식노드로 이동
    }

    static void preOrder(node* start) // 전위순회 
    {
        if (!start) // 지금 주소가 NULL인 경우
            return;

        std::cout << start->position << ", ";

        preOrder(start->first);
        preOrder(start->second);
    }

    static void inOrder(node* start) // 중위순회
    {
        if(!start)
            return;

        inOrder(start->first);
        std::cout << start->position << ", ";
        inOrder(start->second);
    }

    static void postOrder(node* start)
    {
        if(!start)
            return;
        
        postOrder(start->first);
        postOrder(start->second);
        std::cout << start->position << ", ";
    }

    bool addSubordinate(const std::string& manager, const std::string& subordinate)
    {
        auto managerNode = org_tree::find(root, manager);

        if(!managerNode)
        {
            std::cout << manager << "을(를) 찾을 수 없습니다." << std::endl;
            return false;
        }

        if(managerNode->first && managerNode->second)
        {
            std::cout << manager << " 아래에 " << subordinate << "을(를) 추가할 수 없습니다." << std::endl;
            return false;
        }

        if(!managerNode->first)
        {
            managerNode->first = new node {subordinate, NULL, NULL};
        }
        else
        {
            managerNode->second = new node {subordinate, NULL, NULL};
        }

        std::cout << manager << " 아래에 " << subordinate << "을(를) 추가했습니다." << std::endl;

        return true;
    }

    static void levelOrder(node* start)
    {
        if(!start)
            return;
        
        std::queue<node*> q;
        q.push(start);

        while(!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto current = q.front();
                q.pop();

                std::cout << current->position << ", ";
                if (current->first)
                    q.push(current->first);
                if(current->second)
                    q.push(current->second);
            }

            std::cout << std::endl;
        }
    }
};

int main()
{
    auto tree = org_tree::create_org_structure("CEO");

    tree.addSubordinate("CEO", "부사장");
    tree.addSubordinate("부사장", "IT부장");
    tree.addSubordinate("부사장", "마케팅부장");
    tree.addSubordinate("IT부장", "보안팀장");
    tree.addSubordinate("IT부장", "앱개발팀장");
    tree.addSubordinate("마케팅부장", "물류팀장");
    tree.addSubordinate("마케팅부장", "홍보팀장");
    tree.addSubordinate("부사장", "재무부장");

    tree.preOrder(tree.root);
    std::cout << std::endl;
    tree.inOrder(tree.root);
    std::cout << std::endl;
    tree.postOrder(tree.root);
    std::cout << std::endl;

    tree.levelOrder(tree.root);

}