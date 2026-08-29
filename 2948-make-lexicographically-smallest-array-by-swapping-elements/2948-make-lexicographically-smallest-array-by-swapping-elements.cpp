/*
 * Sort values with their original indices, then use Disjoint Set Union to merge
 * adjacent sorted values whose difference is within the allowed limit.
 * Each connected component can freely redistribute its values among its indices.
 */

// DSU groups indices whose values can be connected through valid swaps.

#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

class DisjointSetUnion {
private:
    vector<int> parent;
    vector<int> rank;

public:
    explicit DisjointSetUnion(int size) : parent(size), rank(size, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }

        return parent[node];
    }

    void unite(int firstNode, int secondNode) {
        int firstRoot = find(firstNode);
        int secondRoot = find(secondNode);

        if (firstRoot == secondRoot) {
            return;
        }

        if (rank[firstRoot] < rank[secondRoot]) {
            swap(firstRoot, secondRoot);
        }

        parent[secondRoot] = firstRoot;

        if (rank[firstRoot] == rank[secondRoot]) {
            ++rank[firstRoot];
        }
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int size = static_cast<int>(nums.size());
        vector<pair<int, int>> sortedPairs;
        sortedPairs.reserve(size);

        for (int index = 0; index < size; ++index) {
            sortedPairs.emplace_back(nums[index], index);
        }

        sort(sortedPairs.begin(), sortedPairs.end());

        DisjointSetUnion dsu(size);

        for (int index = 1; index < size; ++index) {
            if (sortedPairs[index].first - sortedPairs[index - 1].first <= limit) {
                dsu.unite(sortedPairs[index].second, sortedPairs[index - 1].second);
            }
        }

        vector<vector<int>> componentIndices(size);
        vector<vector<int>> componentValues(size);

        for (int index = 0; index < size; ++index) {
            int root = dsu.find(index);
            componentIndices[root].push_back(index);
            componentValues[root].push_back(nums[index]);
        }

        vector<int> result(size);

        for (int root = 0; root < size; ++root) {
            if (componentIndices[root].empty()) {
                continue;
            }

            sort(componentIndices[root].begin(), componentIndices[root].end());
            sort(componentValues[root].begin(), componentValues[root].end());

            for (int index = 0; index < static_cast<int>(componentIndices[root].size()); ++index) {
                result[componentIndices[root][index]] = componentValues[root][index];
            }
        }

        return result;
    }
};