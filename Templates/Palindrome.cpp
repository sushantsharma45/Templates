bool isPalindrome(string &s) {
    ll L = 0, R = s.size()-1;
    while(L <= R) {
        if(s[L++]!=s[R--]) return false;
    }
    return true;
}