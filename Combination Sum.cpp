class Solution {
public:
    //Algorithm 1 backtracking - exponential
    void knapsack(int cnt , vector<int>v , vector<int >&combination ,  vector<vector<int> > &sol, int target,int sum)
    {
        if(sum>target) return;
        if(sum == target)
        {
            sol.push_back(combination);
            return;
        }
        if(cnt>= v.size())  return;
        combination.push_back(v[cnt]);
        knapsack(cnt, v, combination ,sol,target,sum+v[cnt] );
        combination.pop_back();  
        knapsack(cnt+1,v,combination,sol,target,sum);

    }
    
    vector<vector<int>> combinationSum1(vector<int>& candidates, int target) {
        
        vector<vector<int> > sol,sol1;
        set<vector<int>>s;	
        vector<int>combination;
        
        sort(candidates.begin(),candidates.end());      
        knapsack(0,candidates,combination,sol,target,0);
	    for(int i=0; i<sol.size(); i++) s.insert(sol[i]);

        for(set<vector<int> >::iterator it=s.begin(); it!=s.end();it++)
           sol1.push_back( (*it) );
        return sol1;
        
    }
    
    // Algo 2 -dp
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector< vector< vector<int> > > combinations(target + 1, vector<vector<int>>());
		combinations[0].push_back(vector<int>());
		for (auto& score : candidates)
			for (int j = score; j <= target; j++)
				if (combinations[j - score].size() > 0)	{
					auto tmp = combinations[j - score];
					for (auto& s : tmp)
						s.push_back(score);
					combinations[j].insert(combinations[j].end(), tmp.begin(), tmp.end());
				}
		auto ret = combinations[target];
		for (int i = 0; i < ret.size(); i++)
			sort(ret[i].begin(), ret[i].end());
		set<vector<int>>s;	
	    for(int i=0; i<ret.size(); i++) s.insert(ret[i]);
	    vector<vector<int> > sol1;
        for(set<vector<int> >::iterator it=s.begin(); it!=s.end();it++)
           sol1.push_back( (*it) );
        return sol1; 
	}
};