// Burning Tree problem.

class Solution {
  public:
    int minTime(Node* root, int target)
    {
        // Your code goes here
        map<Node*,Node*> mp;
        map<Node*,bool> mp1;
        Node* t=NULL;
        solve1(root,NULL,target,t,mp,mp1);
        queue<Node*> q;
        mp1[t]=true;
        q.push(t);
        int count=q.size();
        int Time=0;
        while(count>0){
            for(int i=0;i<count;i++){
                Node* temp=q.front();
                q.pop();
                solve2(temp,mp,mp1,q);
            }
            count=q.size();
            if(count>0){
                Time++;
            }
        }
        return Time;
    }
    void solve1(Node* root,Node* p,int target,Node* &t,map<Node*,Node*>& mp,map<Node*,bool>& mp1){
        mp1[root]=false;
        if(root->data==target){
            t=root;
        }
        mp[root]=p;
        if(root->left){
            solve1(root->left,root,target,t,mp,mp1);
        }
        if(root->right){
            solve1(root->right,root,target,t,mp,mp1);
        }
    }
    void solve2(Node* temp,map<Node*,Node*> mp,map<Node*,bool>& mp1,queue<Node*>& q){
        if(mp[temp]!=NULL){
            if(mp1[mp[temp]]==false){
                mp1[mp[temp]]=true;
                q.push(mp[temp]);
            }
        }
        if(temp->left && mp1[temp->left]==false){
            mp1[temp->left]=true;
            q.push(temp->left);
        }
        if(temp->right && mp1[temp->right]==false){
            mp1[temp->right]=true;
            q.push(temp->right);
        }
    }
};
