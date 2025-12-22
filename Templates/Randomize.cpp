/*For "RANDOM ACCESS" of indexes
"Shuffle" every time, in each for loop!*/

vector<ll> order(n);
iota(order.begin(),order.end(),0);
shuffle(order.begin(),order.end(),rng);