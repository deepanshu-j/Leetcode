/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    
    Node* connect(Node* root) {
        
        
        queue<Node*> q;
        q.push(nullptr);
        if(root)q.push(root);

        while(1){
            
            auto fr=q.front();
            q.pop();
            
            if(q.empty())break;
            else{
                q.push(nullptr);
                while(q.front()!=nullptr){
                    auto tp=q.front();
                    q.pop();
                    if(tp){
                        tp->next = q.front();
                        if(tp->left)q.push(tp->left);
                        if(tp->right)q.push(tp->right);
                    }
                }  
            }
        }
        
        return root;
    }
};