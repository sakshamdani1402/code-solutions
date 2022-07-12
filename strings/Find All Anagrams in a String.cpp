// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".

 vector<int> findAnagrams(string s, string p) {
    vector<int> res;
	  //setting up 2 hashtables using vectors, as unordered_maps cannot be used for comparison here(both size and pairs should be same)
    vector<int> phash(26,0),shash(26,0);	
    int m=p.size(), n=s.size();
    if(m>n) return res;	//cannot have anagrams if p size > s size

    int lo=0, hi=0;
    for(auto &i:p) phash[i-'a']++;	//init p hash

    while(hi<n){
        shash[s[hi]-'a']++;		//insert curr elem in s hash
        if(hi-lo+1 < m) hi++;	//we only increase window size till its size < p size

        else if(hi-lo+1 == m){		//window size == p size
            if(phash==shash) res.push_back(lo);		//if both hashes are same, insert lo ptr in res
			
            shash[s[lo]-'a']--;		//slide the window by removing starting elem
            lo++,hi++;				//sliding the window ahead
        }
    }

    return res;
}
