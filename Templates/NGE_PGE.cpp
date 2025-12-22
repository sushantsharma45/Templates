//Next Greater Element & Previous Greater Element

vector<ll> NGE(n, n);
stack<pair<ll,ll>> st;
for(ll i = n-1; i>=0; i--) {
    while(!st.empty() && st.top().ff <= arr[i]) st.pop();
    NGE[i] = st.empty() ? n : st.top().ss; st.push({arr[i], i});
}

while(!st.empty()) st.pop();

vector<ll> PGE(n, -1);
for(ll i = 0; i<n; i++) {
    while(!st.empty() && st.top().ff <= arr[i]) st.pop();
    PGE[i] = st.empty() ? -1 : st.top().ss; st.push({arr[i], i});
}