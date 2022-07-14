// Given an encoded string, return its decoded string.
// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. 
// Note that k is guaranteed to be a positive integer. You may assume that the input string is always valid; 
// there are no extra white spaces, square brackets are well-formed, etc. 
// Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. 
// For example, there will not be input like 3a or 2[4].

// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"

// Input: s = "3[a2[c]]"
// Output: "accaccacc"

// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"

string decodeString(string s) {
    stack<char> st;
    string res="";

    for(char &i: s){
        if(i!=']') st.push(i); 
        else{
            string temp="";
            
            //build the string
            while(st.top()!='['){
                temp = st.top() + temp;
                st.pop();
            }
            st.pop();   //pop '['

            string num="";
            
            //build the num
            while(!st.empty() and isdigit(st.top())){
                num = st.top()+ num;
                st.pop();
            }
            int n = stoi(num); //convert to int

            while(n--){
                //push every char of temp in st n times
                for(char &c : temp) st.push(c);
            }
        }
    }
    
    //at last we will have our res in char from
    //so build a string out of it and return
    while(!st.empty()){
        res = st.top()+res;
        st.pop();
    }

    return res;

}
