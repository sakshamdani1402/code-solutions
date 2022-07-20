/* You are given an array of strings words. Each element of words consists of two lowercase English letters.
Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
A palindrome is a string that reads the same forward and backward.

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.

Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx". */

/* SOLUTION
2 letter words can be of 2 types:
  -- Where both letters are same
  -- Where both letters are different

Based on the above information:
  -- If we are able to find the mirror of a word, ans += 4
  -- The variable unpaired is used to store the number of unpaired words with both letters same.
  -- Unpaired here means a word that has not found its mirror word.
  -- At the end if unpaired same letter words are > 0, we can use one of them as the center of the palindromic string. */

int longestPalindrome(vector<string>& words) {
    unordered_map<string,int> hash;
    for(auto &s:words) hash[s]++;
    int len=0;
    bool same=true;
    for(auto &s : words){
        string x = s; reverse(x.begin(), x.end());
        if(x!=s && hash[x] >=1 and hash[s]>=1)
            len+=4, hash[x]--, hash[s]--;
        else if(x == s){
            if(hash[x] >=2) hash[x]-=2, len+=4;
            else if(hash[x]==1 && same) len+=2, hash[x]--, same=false;
        }
    }
    return len;
}
