#include<iostream>
#include<string>

using namespace std;

typedef struct TreeNode{
    char data;
    struct TreeNode *parent, *left, *right;
} TreeNode;

class BinaryTreeLinkedList
{
public:
	//BinaryTreeLinkedList();				//생성자
	//~BinaryTreeLinkedList();			//소멸자
	
	TreeNode* CreateNode();				//노드 생성
	bool GetData(TreeNode* node, char& data);		//값 반환
	bool SetData(TreeNode* node, char data);		//값 지정

	bool SetLeftNode(TreeNode* parent, TreeNode* child);	//노드의 왼쪽 자식노드 지정
	bool SetRightNode(TreeNode* parent, TreeNode* child);	//노드의 오른쪽 자식노드 지정

	//void PreorderPrint(TreeNode* node);			//전위 순회
	void InorderPrint(TreeNode* node);			//중위 순회
	//void PostorderPrint(TreeNode* node);		//후위 순회

	//void RemoveNode(TreeNode* node);			//노드 제거
};

TreeNode* BinaryTreeLinkedList::CreateNode()
{
    TreeNode* newNode = new TreeNode;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool BinaryTreeLinkedList::GetData(TreeNode* node, char& data)
{
    data = node->data;
    cout << data;
    return true;
}

bool BinaryTreeLinkedList::SetData(TreeNode* node, char data)
{
    node->data = data;
    return true;
}

bool BinaryTreeLinkedList::SetLeftNode(TreeNode* parent, TreeNode* child)
{
    parent->left = child;
    child->parent = parent;
    return true;
}

bool BinaryTreeLinkedList::SetRightNode(TreeNode* parent, TreeNode* child)
{
    parent->right = child;
    child->parent = parent;
    return true;
}

void BinaryTreeLinkedList::InorderPrint(TreeNode* node)
{
    char data;
    if (node == NULL)
		return;
    InorderPrint(node->left);
    GetData(node, data);
    InorderPrint(node->right);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int i, N;
        //char node_arr[101];
        TreeNode* node_arr[101];
        int self_node;
        char node_ch;
        int l_child, r_child;
        BinaryTreeLinkedList* BinaryTree = new BinaryTreeLinkedList();

        cin >> N;
        cin.ignore();
        for(i = 1; i <= N; i++){
            string input = "abcdwxyz";
            getline(cin, input);
            if(i < 10)
            {
                self_node = input[0] - '0';
                node_ch = input[2];
            }
            else if(i < 100)
            {
                self_node = (input[0] - '0')*10 + (input[1] - '0');
                node_ch = input[3];
            }
            else{ //i == 100
                self_node = 100;
                node_ch = input[4];
            }

            //node_arr[self_node-1] = node_ch;
            node_arr[self_node] = BinaryTree->CreateNode();
            BinaryTree->SetData(node_arr[self_node], node_ch);                      
        }
        for(i = 1; i <= N/2 - 1; i++)
        {
            BinaryTree->SetLeftNode(node_arr[i], node_arr[i*2]);//left child
            BinaryTree->SetRightNode(node_arr[i], node_arr[i*2+1]);//right child
        }
        if(N % 2 == 0)
        {
            BinaryTree->SetLeftNode(node_arr[i], node_arr[i*2]);
        }
        else
        {
            BinaryTree->SetLeftNode(node_arr[i], node_arr[i*2]);//left child
            BinaryTree->SetRightNode(node_arr[i], node_arr[i*2+1]);//right child
        }

        /*for(i = 1; i <= N; i++)
        {
            string input = "abcdwxyz";
            int is_l = 0, is_r = 0;
            getline(cin, input);
            //cin >> self_node >> node_ch >> l_child >> r_child;
            cout << input[0] << " " << input[2] << " " << input[4] << " " << input[6] << endl;
            self_node = input[0] - '0';
            node_ch = input[2];

            if(input[4] != 'w')
            {
                l_child = input[4] - '0';
                is_l = 1;
            }
            else
            {
                l_child = NULL;
            }

            if(input[6] != 'y')
            {
                r_child = input[6] - '0';
                is_r = 1;
            }  
            else
            {
                r_child = NULL;
            }   
            


            cout << self_node << " " << node_ch << " " << l_child << " " << r_child << endl;


        }*/

        cout << "#" << test_case << " ";

        BinaryTree->InorderPrint(node_arr[1]);

        cout << endl;
	}
	return 0;
}
