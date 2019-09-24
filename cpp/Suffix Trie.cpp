struct Node
{
    map<ll , Node*> m;
    ll value;
};

Node* createNewNode(ll value)
{
    Node* node = new Node;
    map<ll, Node*> m;
    node->m = m;
    node->value = value;
    return node;
}

Node* makeTrie(ll value, Node* node)
{
    if(node->m.find(value)==node->m.end())
    {
        Node* node2 = createNewNode(value);
        node->m[value] = node2;
    }
    Node* node2 = node->m.find(value)->second;
    return node2;
}

// in main function 
Node* root = createNewNode(26);
    rep(i,n)
    {
        Node* node = root;
        fr(j,i,n-1)
        {
            node = makeTrie(s[j]-'a', node); // s is the string and alphabets are stored in ascii-'a' node number
        }
    }