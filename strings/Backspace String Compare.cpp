// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
// Note that after backspacing an empty text, the text will continue empty.

// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".

// Input: s = "ab##", t = "c#d#"
// Output: true
// Explanation: Both s and t become "".

// Input: s = "a#c", t = "b"
// Output: false
// Explanation: s becomes "c" while t becomes "b".

//METHOD 1- O(1) SPACE
bool backspaceCompare(string s, string t) {
    int n = s.size(), m=t.size();
    string x, y;
  
    int idx=0;
    for(int i=0;i<n;i++){
        if(s[i]=='#'){  //backspace
            idx--;      //move idx back
            idx = max(0,idx);   //idx cant be -ve
        }
        else s[idx]=s[i], idx++;  //valid char, copy to idx index
    }
    x = s.substr(0,idx);    //0 to idx gives all valid chars

    idx=0;  //do same for t
    for(int i=0;i<m;i++){
        if(t[i]=='#'){
            idx--;
            idx = max(0,idx);
        }
        else t[idx]=t[i], idx++;
    }
    y=t.substr(0,idx);

    return x==y;  //compare both
}

//METHOD 2- USING STACK

stack<char> st1,st2;
for(char i:s){
    if(!st1.empty() && i=='#')  //if backspace pop last char
        st1.pop();
    else if(i!='#')
        st1.push(i);  //else push
}
for(char i:t){
    if(!st2.empty() && i=='#')
        st2.pop();
    else if(i!='#')
        st2.push(i);
}
return st1==st2;  
