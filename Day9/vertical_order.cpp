vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> ans;
    map<int , map<int , vector<int>>> m;
    queue<pair<int , pair<int , TreeNode<int> *>>> q;
    if(root) q.push({0 , {0 , root}});

    while(!q.empty())
    {
        int x_cord = q.front().first;
        int y_cord = q.front().second.first;
        TreeNode<int> * curr = q.front().second.second;
        q.pop();

        m[x_cord][y_cord].push_back(curr -> data);
        if(curr -> left) q.push({x_cord-1 , {y_cord+1 , curr -> left}});
        if(curr -> right) q.push({x_cord+1 , {y_cord+1 , curr -> right}});
    }

    for(auto i = m.begin() ; i != m.end() ; i++)
    {
        map<int , vector<int>> currMap = i-> second;
        for (auto j = currMap.begin(); j != currMap.end(); j++) {
          vector<int> currV = j->second;
          ans.insert(ans.end(), currV.begin(), currV.end());
        }
    }
    return ans;
}