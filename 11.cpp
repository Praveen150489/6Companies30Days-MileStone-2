// Serialize and deserialize of a binary tree.

class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        //Your code here
        vector<int> v;
        queue<Node*> q;
        q.push(root);
        int count=q.size();
        v.push_back(root->data);
        while(count>0){
            for(int i=0;i<count;i++){
                Node* temp=q.front();
                q.pop();
                if(temp->left){
                    v.push_back(temp->left->data);
                    q.push(temp->left);
                }
                else{
                    v.push_back(-1);
                }
                if(temp->right){
                    v.push_back(temp->right->data);
                    q.push(temp->right);
                }
                else{
                    v.push_back(-1);
                }
            }
            count=q.size();
        }
        return v;
    }

    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       string str="";
       for(int i=0;i<A.size();i++){
           if(A[i]==-1){
               str+='N';
           }
           else{
               str+=to_string(A[i]);
           }
           if(i<A.size()-1){
               str+=' ';
           }
       }
       return buildTree(str);
    }

};
