ll findSubarray(vector<ll> arr, int n ) 
{
    unordered_map<ll, vector<ll> > map;
    vector <pair<ll, ll>> out;
    ll sum = 0;

    for (ll i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
            out.push_back(make_pair(0, i));

        if (map.find(sum) != map.end())
        {
            vector<ll> vc = map[sum];
            for (int j = 0; j < vc.size(); j++)
                out.push_back(make_pair(vc[j] + 1, i));
        }

        map[sum].push_back(i);
    }

    return out.size();
}
