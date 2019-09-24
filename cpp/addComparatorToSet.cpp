auto cmp = [](const auto& a, const auto& b) { return a.ss < b.ss; };
set<pair<ll,ll>, decltype(cmp)> harsh(cmp);