class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(),bank.end());
        unordered_set<string> visited;
        queue<string> q;
        q.push(startGene);

        int lvl=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();

                if(curr==endGene){
                    return lvl;
                }
                for(char ch : "ACGT"){
                    for(int i=0 ; i<curr.length() ; i++){
                        string nbgr=curr;
                        nbgr[i]=ch;
                        if(visited.find(nbgr)==visited.end() &&
                            bankSet.find(nbgr)!=bankSet.end()){
                                visited.insert(nbgr);
                                q.push(nbgr);
                            }
                    }
                }
            }
            lvl++;
 
        }
        return -1;

    }
};