#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool figure_fixing(vector<ll> v, vector<ll> t, ll n, ll m, vector<ll> adj[])
{
    //check if bipartite
    vector<ll> color(n, -1); // -1 -> uncolored, red = 1, blue = 0

    queue<ll> q;
    q.push(0);
    color[0] = 1;
    bool is_bipartite = 1;
    while (q.size())
    {
        ll node = q.front();
        q.pop();
        ll col = color[node];
        for (ll i = 0; i < adj[node].size(); i++)
        {
            if (color[adj[node][i]] == col)
            {
                is_bipartite = 0;
                break;
            }
            else if (color[adj[node][i]] == -1)
            {
                color[adj[node][i]] = 1 - col;
                q.push(adj[node][i]);
            }
        }
    }
    if (!is_bipartite)
        return true; // two neighbours will be of same color and thus their increase decrease can be balanced

    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == 1)
            sum1 += (t[i] - v[i]);
        else
            sum2 += (t[i] - v[i]);
    }
    return sum1 == sum2; // adding weight to any edge adds weight to both color sets, so their required differences must be same
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll v_sum = 0, t_sum = 0;
        vector<ll> v(n);
        vector<ll> t(n);
        for (ll i = 0; i < n; i++)
            cin >> v[i], v_sum += abs(v[i]);

        for (ll i = 0; i < n; i++)
            cin >> t[i], t_sum += abs(t[i]);

        vector<ll> adj[n];

        ll a, b;

        for (ll i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a - 1].push_back(b - 1); // edges 1-indexed
            adj[b - 1].push_back(a - 1);
        }

        if (v_sum % 2 != t_sum % 2)
            cout << "NO" << endl;

        else if (figure_fixing(v, t, n, m, adj))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
