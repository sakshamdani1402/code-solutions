// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

// Input: num1 = "2", num2 = "3"
// Output: "6"

// Input: num1 = "123", num2 = "456"
// Output: "56088"

//perform normal multiplication
//digits in ans can be <= sum of digits in the 2 nos

string multiply(string num1, string num2) {
    string res="";
    if(num1=="0" || num2=="0") return "0";
    int n1=num1.size(), n2=num2.size();
    int n=n1+n2;
    string v(n,0);
    
    for(int i=n1-1;i>=0;i--){
        for(int j=n2-1;j>=0;j--){
            //idx+1 refers to the place value of curr digits we are 
            //multiplying when i=n1-1 & j=n2-1 this means we are at the
            //end of the 2 string i.e at the ones place
            //then i+j refers to tens place and i+j+1 is one's place
            int idx = i+j;
            //perform multiplication and store ans
            v[idx+1] += (num1[i]-'0')*(num2[j]-'0');
            //stores ten's digit (if any) at idx
            v[idx] += v[idx+1]/10;
            //set value at idx+1 as the ones digit
            v[idx+1]%=10;
        }
    }
    
    string ans="";
    int i;
    
    //trimming all zeroes in front
    for(int k=0;k<n;k++){
        if(v[k]!=0){
            i=k;
            break;
        }
    }
    
    for(i;i<n;i++){
        ans+=(v[i]+'0');
    }
    return ans;
}
