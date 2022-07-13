// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

// Input: s = "a"
// Output: 1
// Explanation: The longest palindrome that can be built is "a", whose length is 1.

int longestPalindrome(string s) {
    int n=s.size();
    if(n==0)    return 0;
    unordered_map<char,int> um;
    //store count of all chars
    for(auto x:s){
        um[x]++;
    }
    //count chars with odd freqs
    int oddCount=0;
    for(auto x:um){
        //checks if freq is odd and adds 1, 0 otherwise
        oddCount += x.second&1; 
    }
    //we can add all chars with even counts
    //num of chars with even counts = n - oddcount
    //but since we can have only 1 char with odd count in a palindrome
    //oddCount>0 adds 1 if there is atleast 1 char with odd freq
    //else is results in 0
    return n-oddCount+(oddCount>0);
}

//there can be many chars with odd counts, but to build a palindrome we can use only 1 char that has odd count
//so we add 1 to get the len of longest palindrome we can build using the given strings
