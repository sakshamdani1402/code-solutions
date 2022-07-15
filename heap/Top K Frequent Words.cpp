// Given an array of strings words and an integer k, return the k most frequent strings.
// Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.

// Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
// Output: ["the","is","sunny","day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.

//custom comparator class for min heap
class Compare{
    public:
    bool operator()(pair<string,int>& a, pair<string, int>& b){
        // return greater val else if val is same then return lexicographical order
        return a.second > b.second || (a.second == b.second && a.first < b.first);
    }
};

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string,int> hash;
    for(auto &s : words) hash[s]++;

    priority_queue< pair<string,int>,vector<pair<string,int>>, Compare > pq;
    //build mean heap of k elems, most freq arent popped
    for(auto &i: hash){
        pq.push({i.first, i.second});
        if(pq.size()>k) pq.pop();
    }
    //push all k freq words into res, they are in reverse order (most freq is in the last). so reverse res and then return
    vector<string> res;
    while(!pq.empty()){
        res.push_back(pq.top().first);
        pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
