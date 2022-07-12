// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. 
// You can perform this operation at most k times.
// Return the length of the longest substring containing the same letter you can get after performing the above operations.

// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.

int characterReplacement(string s, int k) {
	vector<int> hash(26,0);
	int lo=0,hi=0,n=s.size(),maxfreq=0;
	int res=0;
	while(hi<n){
		hash[s[hi]-'A']++;	//include curr elem in window
		maxfreq = max(maxfreq,hash[s[hi]-'A']);	//update freq of most frequent elem

		if((hi-lo+1)-maxfreq > k) hash[s[lo++]-'A']--;		//window size - maxfreq {num of char that need to be changed} > k, remove starting elem from window

		res=max(res,hi-lo+1);	//update max window size
		hi++;
	}

	return res;
}

// -- we will use window sliding algo
// -- the number of char that need to be changed = window size - count most freq elem
// -- we will maintain a freq map of every char
// -- init 2 ptrs start and end =0
// -- for every char increment it freq and maintain a var maxf that stores the count of most freq elem that occured
// -- since we can only change k or less than k chars, if we ever exceed that limit i.e. window size - count most freq elem > k then we need to shorten the window size
// -- we decrease the freq of char at start idx and increment start
// -- then for each iteration we check the max size of window
// -- important note is that we only need to maintain the max freq of char even if we slide out of the window which may decrease the count of the most freq elem, 
// because updating max freq to a lower count will not benefit us in any way as when the freq is more the less chars we need to change 
// and the change would already be calculated, we can still update max after the decrement but it wont do any good but also it wont give a wrong answer
