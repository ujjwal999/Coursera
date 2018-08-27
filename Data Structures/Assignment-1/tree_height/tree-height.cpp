#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class TreeHeight{
    int n;
    vector<int> parent;
    vector<int> depth;
public:
    void read(){
        cin >> n;
        parent.resize(n);
        depth.resize(n);
        for (int i = 0; i < n; i++){
            cin >> parent[i];
        }
    }
    int compute_height(){
        int maxHeight = 0;
        if(n == 0)
            return n;
        for(int i = 0; i < n; i++){
            fillDepth(i);
        }
        for(int i = 0; i < n; i++){
            int height = depth[i];
            maxHeight = max(maxHeight, height);
        }
        return maxHeight;
    }
    void fillDepth(int nodeNumber){
        if(parent[nodeNumber] == -1){
            depth[nodeNumber] = 1;
            return;
        }
        if(depth[nodeNumber])
            return;
        if(!depth[parent[nodeNumber]])
            fillDepth(parent[nodeNumber]); 
        depth[nodeNumber] = depth[parent[nodeNumber]] + 1;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    TreeHeight tree;
    tree.read();
    cout << tree.compute_height() << endl;
}
