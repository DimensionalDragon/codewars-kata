const maxSequenceDP = (arr, start, end, memo = Array.from(Array(100), () => Array(100))) => { // Dynamic Programming helper function
    /* Base cases */
    if(arr.length === 0 || start > end) return 0;
    if(memo[start][end]) return memo[start][end];

    /* DP formula is max(sum of all elements, max sequence sum of the array without the first element, max sequence sum of the array without the last element) */
    memo[start][end] = Math.max(arr.slice(start, end + 1).reduce((total, num) => total + num, 0), maxSequenceDP(arr, start + 1, end, memo), maxSequenceDP(arr, start, end - 1, memo));
    return memo[start][end];
}

const maxSequence = arr => maxSequenceDP(arr, 0, arr.length - 1); // Call the DP helper function

console.log(maxSequence([-2, 1, -3, 4, -1, 2, 1, -5, 4]));