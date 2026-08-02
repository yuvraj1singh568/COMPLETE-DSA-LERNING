class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
            unordered_map<int,vector<pair<int,int>>>mp;
        queue<tuple<TreeNode*,int ,int>>q;
        q.push({root,0,0});
       

int start = INT_MAX, end = INT_MIN ;

        while(!q.empty())
   {
    auto[cur,dist,level]=q.front();
    q.pop();
    start = min(start,dist);
    end= max(end,dist);

mp[dist].push_back({level,cur->val});
if(cur->left)q.push({cur->left,dist-1,level +1});
if(cur->right)q.push({cur->right,dist+1,level +1});
   }
   //sort
   // level
   //value
   vector<vector<int>>ans;
for(int dist=start;dist<=end;dist++){
    auto arr = (mp[dist]);
    sort(arr.begin(),arr.end());
    vector <int>line;
    for(auto[level,node]:arr){
   line.push_back(node);
    }
    ans.push_back(line);
}
   return ans;
    }

};