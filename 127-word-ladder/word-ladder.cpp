class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> bankSet(wordList.begin(),wordList.end());
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);

        int lvl=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();

                if(curr==endWord){
                    return lvl+1;
                }
                for(char ch : "abcdefghijklmnopqrstuvwxyz"){
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
        return 0;
    }
};