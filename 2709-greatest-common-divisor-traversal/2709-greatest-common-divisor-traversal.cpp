
class DisjointSets {
  private:
	vector<int> parents;
	vector<int> sizes;

  public:
	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}

	/** @return the "representative" node in x's component */
	int find(int x) {
		return parents[x] == x ? x : (parents[x] = find(parents[x]));
	}

	/** @return whether the merge changed connectivity */
	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}

	/** @return whether x and y are in the same connected component */
	bool connected(int x, int y) { return find(x) == find(y); }
};

class Solution {
public:
    vector<int> trial_division1(int n) {
        vector<int> factorization;
        for (int d = 2; d * d <= n; d++) {
            while (n % d == 0) {
                factorization.push_back(d);
                n /= d;
            }
        }
        if (n > 1)
            factorization.push_back(n);
        return factorization;
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        DisjointSets dsu(100001);
        
        if(nums.size() == 1 and nums[0] == 1) return 1;
        
        int oneCount = 0;
        for(auto x: nums){
            oneCount += (x == 1);
        }
        if(oneCount>0) return 0;
        
        set<int> s(nums.begin(), nums.end());
        vector<int> arr(s.begin(), s.end());
        
        map<int,int> lastIdx;
        
        for(int i=0;i<arr.size();++i){
            int num = arr[i];
            vector<int> factors = trial_division1(num);
            for(int factor: factors){
                if(lastIdx.find(factor) != lastIdx.end())
                    dsu.unite(num, lastIdx[factor]);
                lastIdx[factor] = num;
            }
        } 
        
        for(auto num: arr){
            if(dsu.find(num) != dsu.find(arr[0]))
                return 0;
        }
        return 1;
    }
};