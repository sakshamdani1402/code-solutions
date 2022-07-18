/* Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false */

//METHOD 1 - DP + MEMO
int n;
vector<int> dp;
bool check(int idx, string s, unordered_set<string>& words){
    if(idx==n) return true; //reached end
    if(dp[idx]!=-1) return dp[idx]; //already memoized
    //from curr idx, find words
    for(int i=idx; i<n; i++){
        /* if curr substr matches, then continue finding words in rest of the string, 
        if both are true then we, can find words from current idx, then memoize and return true */
        string x = s.substr(idx, i-idx+1);  
        if(words.find(x)!=words.end() && check(i+1,s,words)){
            return dp[i] = true;
        }
    }
    //we couldnt find words for curr idx so return false
    return dp[idx]=false;
}
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    n=s.size();
    dp.resize(n, -1);
    return check(0,s,words);
}

//METHOD 2 - ITERATIVE


 
