// Now, given formula for a score is
// score = A[i] + A[j] + i - j ; given i < j
// It becomes more easier to group the dependant values,
// i.e A[i] + i and A[j] - j
// In this way, when we are traversing from either sides of the array, we can just calculate that part of the score, if we maintain max of one part.

// values = [7, 1, 6, 6, 9, 4, 3]
// Now suppose I traverse the array from left to right, and decide to keep the sum A[i] + i maximum at each point, then I can easily use the current element value & its position to calculate the current maximum score.
// Also, Note that at each point, we calculate A[j] + j and compare it to maxLeft, to always store the MAXIMUM of those values.
// Let's initialize maxLeft = A[0] + 0 = 7, considering i = 0 initially. And maxScore = 0

// when j = 1, 
// 	score = maxLeft + A[j] - j = 7 + 1 - 1 = 7
// 	maxScore = max(maxScore, score) = max(0,7) = 7
// 	maxLeft = max(maxLeft, A[j] + j) = max(7, 1+1) = 7
// when j = 2, 
// 	score = maxLeft + A[j] - j = 7 + 6 - 2 = 11
// 	maxScore = max(maxScore, score) = max(7,11) = 11
// 	maxLeft = max(maxLeft, A[j] + j) = max(7, 6+2) = 8
// when j = 3, 
// 	score = maxLeft + A[j] - j = 8 + 6 - 3 = 11
// 	maxScore = max(maxScore, score) = max(11,11) = 11
// 	maxLeft = max(maxLeft, A[j] + j) = max(8, 6+3) = 9
// when j = 4, 
// 	score = maxLeft + A[j] - j = 9 + 9 - 4 = 14
// 	maxScore = max(maxScore, score) = max(11,14) = 14
// 	maxLeft = max(maxLeft, A[j] + j) = max(9, 9+4) = 13
// when j = 5, 
// 	score = maxLeft + A[j] - j = 13 + 4 - 5 = 12
// 	maxScore = max(maxScore, score) = max(14,12) = 14
// 	maxLeft = max(maxLeft, A[j] + j) = max(13,4+5) = 13
// when j = 6, 
// 	score = maxLeft + A[j] - j = 13 + 3 - 6 = 10
// 	maxScore = max(maxScore, score) = max(14,10) = 14
// 	maxLeft = max(maxLeft, A[j] + j) = max(13, 3+6) = 13
// At the end, we return maxScore, hence our final result = 14!

int maxScoreSightseeingPair(vector<int>& values) {
    int res = 0, n=values.size(), maxval=values[0];
    for(int i=1; i<n; i++){
        res = max(res, maxval + values[i] - i);
        maxval = max(maxval, values[i]+i);
    }

    return res;
}
