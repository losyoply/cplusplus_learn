
#include<iostream>

using namespace std;
int tower;
class Node
{
    public:
        int value, fu;
        Node *right, *parent, *left;
        Node(int val) 
        {
            value = val;
            left = parent = right = NULL;
            fu = 0;
        }
};
Node *treeroot;
long long count_underscores(string s) 
{
  long long count = 0;
  for (long long i = 0; i < s.length(); i++)
    if (s[i] == ')') count++;
  return count;
}
void Preorder(Node* root)
{
    if(root==NULL)
        return;
    cout << root->value << ' ';
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(Node* root)
{
    if(root==NULL)
        return;
    Inorder(root->left);
    cout << root->value << ' ';
    Inorder(root->right);
}
void Postorder(Node* root)
{
    if(root==NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->value << ' ';
}
void Traverse(Node* root)
{
    Preorder(root);
    cout << endl;
    Inorder(root);
    cout << endl;
    Postorder(root);
    cout << endl;
}
class Stack
{
    public:
        int top;
        char stack[1000];
        Stack()
        {
            top = -1;
        }
        bool IsEmpty()
        {
            if(top==-1)
                return true;
            else
                return false;
        }
        char Top()
        {
            if(IsEmpty())
                return '\0';
            return stack[top];
        }
        void Push(char p)
        {
            top = top + 1;
            stack[top] = p;
        }
        void Pop()
        {
            if(!IsEmpty()) top = top - 1;
        }
};
long long find(string str, long long num)
{
    if(str[num]!='(') 
    {
            cout << "error";
            return 0;
    }
    long long count = 0, ans = 0;
    for (long long i = num; i < str.length();i++)
    {
        if(str[i]=='(') 
        {
            count++;
        }
        else if(str[i]==')')
        {
            count--;
            if(count==0)
            {
                ans++;
                break;
            }
            //cout << count;
        }
        ans++;
    }
    //cout << ans;
    return ans;
}
long long howmanyint(string str, long long num)
{
    long long ans = 0;
    for (long long i = num; i < str.length(); i++)
    {
        if(str[i]!='(' && str[i]!=')')
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    return ans;
}

Node* Build(string str)
{
    //Stack *mystack = new Stack();
    Node *root, *lchild, *rchild;
    root = lchild = rchild = NULL;
    int count_paren = count_underscores(str);
    if(count_paren >3)
    {
        string str1, str2;
        long long num,numm;
        long long numint = howmanyint(str, 1);
        root = new Node(stoi(str.substr(1, numint)));
        num = find(str, 1+numint);
        str1 = str.substr(1+numint, num);
        numm = find(str, 1+numint+num);
        str2 = str.substr(1+numint+num, numm);
        lchild = Build(str1);
        rchild = Build(str2);
        root->left = lchild;
        root->right = rchild;
        if(lchild!=NULL)lchild->parent = root;
        if(rchild!=NULL)rchild->parent = root;
    }
    else if(count_paren==3)
    {
        long long num = howmanyint(str, 1);
        root = new Node(stoi(str.substr(1, num)));
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else
        return NULL;
    return root;
}



long long WeightSum(Node* root)
{
    
     if(root==NULL)
        return 0;
    return  WeightSum(root->left)+WeightSum(root->right)+root->value;
    
}

long long MaximumPathSum(Node* root)
{
    if(root==NULL)
    { 
        return 0;
    }
    long long L = MaximumPathSum(root->left);
    long long R = MaximumPathSum(root->right);
    if(root->left!=NULL&&root->right==NULL) return root->value + L;  
    else if (root->right != NULL && root->left == NULL) return root->value + R;
    return (L >= R) ? L + root->value : R + root->value; //weight可能為負 所以不可省略上兩行 ， (題目要求依定要加到leaf
}


Node* Invert(Node* root)
{
    if(root==NULL) 
    {
        return NULL;
    }
    Node *temp = root->left;
    root->left = Invert(root->right);
    root->right = Invert(temp);
    return root;
}
Node* DeleteLeaf(Node* root)
{
    ///*
    if(root==NULL)
        return NULL;
    if(root->left==NULL&& root->right==NULL) 
    {
        delete root;
        return NULL;
    }
    root->left = DeleteLeaf(root->left);
    root->right = DeleteLeaf(root->right);
    return root;
    //*/
}
bool Foldable(Node* n1, Node* n2)//important
{
    /* If both left and right subtrees are NULL,
    then return true */
    if (n1 == NULL && n2 == NULL) {
        return true;
    }
 
    /* If one of the trees is NULL and other is not,
    then return false */
    if (n1 == NULL || n2 == NULL) {
        return false;
    }
 
    /* Otherwise check if left and right subtrees are
    mirrors of their counterparts */
    return Foldable(n1->left, n2->right)
           && Foldable(n1->right, n2->left);
}
long long c = 0;

long long KingdomUnitedPath(Node* root, int wtf)
{
    long long ans=0;
    if(root==NULL) 
    {
        ans = 0;
        //c = max(c, ans);
        return ans;
    }
    KingdomUnitedPath(root->left, 1);
    KingdomUnitedPath(root->right, 1);
    if(root->left == NULL && root->right == NULL) ans = 0;
    else if(root->left == NULL&&root->right!=NULL)
        ans = (root->value == root->right->value) ?1 + KingdomUnitedPath(root->right,0) :0;
    else if(root->right == NULL&&root->left!=NULL)
        ans = (root->value == root->left->value) ? 1 + KingdomUnitedPath(root->left,0) :0;
    else
    {
        if(root->value == root->left->value && root->value == root->right->value)
        {
            if(wtf==1)
                ans = 2 + KingdomUnitedPath(root->right, 0) + KingdomUnitedPath(root->left,0);
            else ans = 1 + max(KingdomUnitedPath(root->right,0), KingdomUnitedPath(root->left,0));
        }
        else if(root->value == root->left->value)
            ans = 1 + KingdomUnitedPath(root->left,0);
        else if(root->value == root->right->value)
            ans = 1 + KingdomUnitedPath(root->right,0);
        else ans = 0;
    }
    c = max(c, ans);
    return ans;
}

void BinaryTower(Node *root)//0 沒被沾到 1 沾到沒tower處 2 tower
{
    
    if(root == NULL) return;
    
    BinaryTower(root->left);
    BinaryTower(root->right);

    if(root->left == NULL && root->right == NULL) root->fu = 0;
    else if(root->left == NULL)
    {
        if(root->right->fu == 0) tower++, root->fu = 2;
        else if(root->right->fu == 2) root->fu = 1;
        else root->fu = 0;
    }
    else if(root->right == NULL)
    {
        if(root->left->fu == 0) tower++, root->fu = 2;
        else if(root->left->fu == 2) root->fu = 1;
        else root->fu = 0;
    }
    else
    {
        if(root->left->fu == 0 || root->right->fu == 0)
            tower++, root->fu = 2;
        else if(root->left->fu == 2 || root->right->fu == 2)
            root->fu = 1;
        else root->fu = 0;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    string str, op;

    while(cin>>str)
    {
        
        treeroot = Build(str);
        while(cin>>op)
        {
            if(op=="Traverse")
            {
                Traverse(treeroot);
            }
            else if(op=="WeightSum")
            {
                cout<<WeightSum(treeroot)<<endl;
            }
            else if(op=="MaximumPathSum")
            {
                cout << MaximumPathSum(treeroot) << endl;
            }
            else if(op=="Invert")
            {
                treeroot = Invert(treeroot);
            }
            else if(op=="DeleteLeaf")
            {
                treeroot = DeleteLeaf(treeroot);
            }
            else if(op=="Foldable")
            {
                if(Foldable(treeroot->left, treeroot->right))
                {
                    cout << "Yes" << endl;
                }
                else
                {
                    cout << "No" << endl;
                }
            }
            else if(op=="BinaryTower")
            {    
                tower = 0;
                BinaryTower(treeroot);
                if(treeroot != NULL) if(treeroot->fu == 0) tower++;
                cout << tower << endl;
            }
            else if(op=="KingdomUnitedPath")
            {
                c = 0;
                KingdomUnitedPath(treeroot,1);
                cout << c << endl;
            }
            else if(op=="End")
            {
                cout << endl;
                break;
            }
        }
    }
}