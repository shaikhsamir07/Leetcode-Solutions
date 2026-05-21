class Solution {
public:
    vector<string> watchedVideosByFriends(
        vector<vector<string>>& watchedVideos,
        vector<vector<int>>& friends,
        int id,
        int level) {

        int n = friends.size();

        vector<int> vis(n, 0);

        queue<int> q;
        q.push(id);
        vis[id] = 1;

        int currLevel = 0;

        while (!q.empty() && currLevel < level) {

            int sz = q.size();

            for (int i = 0; i < sz; i++) {

                int person = q.front();
                q.pop();

                for (int fr : friends[person]) {

                    if (!vis[fr]) {
                        vis[fr] = 1;
                        q.push(fr);
                    }
                }
            }

            currLevel++;
        }

        map<string, int> freq;

        while (!q.empty()) {

            int person = q.front();
            q.pop();

            for (string &video : watchedVideos[person]) {
                freq[video]++;
            }
        }

        vector<pair<string,int>> temp;

        for (auto &it : freq) {
            temp.push_back({it.first, it.second});
        }

        sort(temp.begin(), temp.end(),
            [](pair<string,int>& a, pair<string,int>& b) {

                if (a.second == b.second)
                    return a.first < b.first;

                return a.second < b.second;
            });

        vector<string> ans;

        for (auto &p : temp) {
            ans.push_back(p.first);
        }

        return ans;
    }
};