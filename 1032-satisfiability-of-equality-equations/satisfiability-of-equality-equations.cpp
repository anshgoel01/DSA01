class Solution {
public:
    vector<int> parent;

    int find(int x){
        if(parent[x] == x)
            return x;

            return parent[x] = find(parent[x]);
    }

    void unit(int x, int y){
        x = find(x);
        y = find(y);

        if(x != y){
            parent[y] = x;
        }
    }
    bool equationsPossible(vector<string>& equations) {

        parent.resize(26);

        for(int i = 0; i < 26; i++){
            parent[i] = i;
        }

        for(auto &eq : equations){
            if(eq[1] == '='){
                int x = eq[0] - 'a';
                int y = eq[3] - 'a';

                unit(x,y);
            }
        }

        for(auto &eq : equations){
            if(eq[1] == '!'){
                int x = eq[0] - 'a';
                int y = eq[3] - 'a';

                if(find(x) == find(y)){
                    return false;
                }
            }
        }
        return true;
    }  
};