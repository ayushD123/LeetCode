//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


/*EDITORIAL SOLN
class Solution {
  public:
    void solve(Node* node,int level,vector<int> &answer)
    {
        if(node==NULL)
            return ;
        if(level==answer.size())
            answer.push_back(node->data);
        else
            answer[level]=max(answer[level],node->data);
        solve(node->left,level+1,answer);
        solve(node->right,level+1,answer);
    }
    
    vector<int> maximumValue(Node* node) {
       vector<int> answer;
       solve(node,0,answer);
       return answer;
    }
};
*/
class Solution {
  public:
  int lvl(Node * root,vector<int> &maxx) {
  if (root == NULL) return 0;
 
  queue < pair<Node *,int> > q;
  q.push({root,0});
  int level=0;

  while (q.empty() == false) {
    pair<Node*,int> p = q.front();
    Node * node=p.first;
    level=p.second;
    
    maxx[level]=max(maxx[level],node->data);
    q.pop();
    if (node -> left != NULL)
      q.push({node -> left,level+1});
      
    if (node -> right != NULL)
      q.push({node -> right,level+1});
  }
  return level+1;
}
 
 
 

    vector<int> maximumValue(Node* node) {
        //code here
        vector<int> ans(1e4+10,0);
       // ans[0]=node->data;
        vector<int> anss;
       int level= lvl(node,ans);
        for(int i=0;i<level;++i){
            anss.push_back(ans[i]);
        }
        return anss;
    }
};

//{ Driver Code Starts.

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
/* Function to get Largest value at each level of Binary Tree */
vector<int> maximumValue(struct Node* tree);


int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> answer = ob.maximumValue(root);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
