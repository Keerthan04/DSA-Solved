class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        //to set first put all the words(this acts as our visited array and we erase once visited)
        unordered_set<string> st(wordList.begin(),wordList.end());
        //start with begin word and sequence length as 1 as we need to return sequence word
        q.push({beginWord,1});
        //so visited then remove
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            //if the endword reached then return as bfs will reach each in shortest path only so that logic applied and return
            if(word == endWord) return steps;
            //now transform and checking
            for(int i =0;i<word.size();i++){
                //so go through each char and store orignal
                char original = word[i];
                //that char changed from a to z and checked if in set if yes then remove it and add to queue with steps+1
                for(char ch = 'a';ch<='z';ch++){
                    word[i] = ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                //shd change back the char
                word[i]=original;
            }
        }
        //if not possible then return 0
        return 0;
    }
};