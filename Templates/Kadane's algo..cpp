/*ALTERNATE :
    maxSUM[i] (till i-th index) = PREFIX[i] - minPRE[0....i-1]
    ==> ans = max(maxSUM[0...n-1])
    minSUM[i] (till i-th index) = PREFIX[i] - maxPRE[0....i-1]
    ==> ans = min(minSUM[0...n-1])
*/

ll maxSum(vector<ll> &arr) {
    ll sum  = arr[0], curr = arr[0];
    for(ll i = 1; i<arr.size(); i++) {
        curr = max(curr+arr[i], arr[i]);
        sum  = max(sum, curr);
    }
    return sum;
}