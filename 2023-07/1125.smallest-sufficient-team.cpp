// 2023-07-16

/*
 * @lc app=leetcode id=1125 lang=cpp
 *
 * [1125] Smallest Sufficient Team
 *
 * https://leetcode.com/problems/smallest-sufficient-team/description/
 *
 * algorithms
 * Hard (47.09%)
 * Likes:    1936
 * Dislikes: 51
 * Total Accepted:    55.3K
 * Total Submissions: 97K
 * Testcase Example:  '["java","nodejs","reactjs"]\n[["java"],["nodejs"],["nodejs","reactjs"]]'
 *
 * In a project, you have a list of required skills req_skills, and a list of
 * people. The i^th person people[i] contains a list of skills that the person
 * has.
 * 
 * Consider a sufficient team: a set of people such that for every required
 * skill in req_skills, there is at least one person in the team who has that
 * skill. We can represent these teams by the index of each person.
 * 
 * 
 * For example, team = [0, 1, 3] represents the people with skills people[0],
 * people[1], and people[3].
 * 
 * 
 * Return any sufficient team of the smallest possible size, represented by the
 * index of each person. You may return the answer in any order.
 * 
 * It is guaranteed an answer exists.
 * 
 * 
 * Example 1:
 * Input: req_skills = ["java","nodejs","reactjs"], people =
 * [["java"],["nodejs"],["nodejs","reactjs"]]
 * Output: [0,2]
 * Example 2:
 * Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"],
 * people =
 * [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
 * Output: [1,2]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= req_skills.length <= 16
 * 1 <= req_skills[i].length <= 16
 * req_skills[i] consists of lowercase English letters.
 * All the strings of req_skills are unique.
 * 1 <= people.length <= 60
 * 0 <= people[i].length <= 16
 * 1 <= people[i][j].length <= 16
 * people[i][j] consists of lowercase English letters.
 * All the strings of people[i] are unique.
 * Every skill in people[i] is a skill in req_skills.
 * It is guaranteed a sufficient team exists.
 * 
 * 
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    vector<int> res;

    void helper(int i,
                vector<int>& people_skill,
                int m,
                int mask,
                vector<int>& ans,
                vector<vector<int>>& dp) {
        if (i == people_skill.size())  // Base Case
        {
            if (mask == ((1 << m) - 1))  // Check for all req_skills included
            {
                if (res.size() == 0 || (ans.size() < res.size()))
                    res = ans;  // better ans then update
            }
            return;
        }

        if (dp[i][mask] != -1)  // Memoization Part
        {
            if (dp[i][mask] <= ans.size())
                return;
        }

        helper(i + 1, people_skill, m, mask, ans, dp);  // Non-Pick / Ignore Case

        ans.push_back(i);  // Pick Case

        helper(i + 1, people_skill, m, (mask | people_skill[i]), ans, dp);  // Next Call

        ans.pop_back();  // Undo the change in Pick

        if (ans.size() > 0)
            dp[i][mask] = ans.size();  // if found and answer then update DP
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = people.size();
        int m = req_skills.size();

        unordered_map<string, int> mpp;  // for hashing skill v/s bit

        for (int i = 0; i < m; ++i)
            mpp[req_skills[i]] = (1 << i);  // setting ith bit, for req_skill[i] skill

        vector<int> people_skill;  // vector of mask for peoples

        for (auto it : people) {
            int mask = 0;
            for (int j = 0; j < it.size(); ++j) {
                if (mpp.count(it[j]))
                    mask |= mpp[it[j]];  // if it[j] is a required skill then set that bit for that
                                         // people's mask
            }
            people_skill.push_back(mask);  // store the mask
        }

        vector<vector<int>> dp(
            n, vector<int>((1 << m), -1));  // n=number of people, and (1<<m) to express all value
                                            // mask of size m can take
        vector<int> ans;

        helper(0, people_skill, m, 0, ans, dp);
        return res;
    }
};


