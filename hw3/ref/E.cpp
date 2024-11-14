/*题目背景
动态匹配不够刺激，同构匹配，刺激。
题目描述
Plover最近学得了一种魔法，每次操作可以把字符串中已有的两种不同的字母互换，形式化的来讲，可以选择字符。 和字符 c;，然后把字符串中所有的 c 字符替换成 c;，同时把所有的 c,替换成 G。比如，对于字符串 abbac，他可以交换字母b和c，从而把字符串变成 accab;如果他继续交换字母b和字母a，那么字符串就会变成 bccba。
考虑两个字符串 S 和 T ，我们称 S 和 T 是同构的，当且仅当 Plover 在施展有限次魔法的前提下，能够将 S 变成 T比如，abbac和 bccba 就是同构的;而 abaac ，abbac，addae ，abb 这些串两两之间都不同构。现在有一个字符串 S。然后有 m, 次询问，每次询问给出两组下标 山,"和l,"?，表示 S 的两个子串。问子串S[l1,r ]和 S[2,r2]是否是同构的，是则输出 Yes ，否则输出 No 。
S[l,r]表示的是从 S 串的第!个字符开始，连续取到第,个字符形成的子串。
输入格式
第一行字符串 S。
第二行整数 m 。
接下来 m 行每行四个整数，l1,"1,l2,"2。表示一组询问。
输出格式
一共 m 行，每行表示询问的答案,
*/
#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

// Arrays for storing weight and prefix hashes of each letter
int weight[MAXN] = {}, prefix_hash[27][MAXN];

// Prime numbers for hashing
long long p1 = 43, p2 = 1e9 + 7;

// Function to calculate hash for a substring of a particular letter
long long substringHash(int letter, int left, int right)
{
    // Calculate hash based on the prefix hash array and weights
    return ((prefix_hash[letter][right] - (long long)prefix_hash[letter][left - 1] * weight[right - left + 1] % p2) % p2);
}

// Function to check if two substrings can be considered isomorphic based on their hash values
bool letter_isomorphic(int letter1, int letter2, int l1, int r1, int l2, int r2)
{
    // Compare hash of the same letter in the two different substrings
    return substringHash(letter1, l1, r1) == substringHash(letter2, l2, r2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // Arrays to store prefix frequencies and indices of each letter
    int prefix_frequency[27][MAXN] = {}, index[27][MAXN] = {};
    int cnt[27] = {};

    string s;
    int m, l1, r1, l2, r2;
    cin >> s >> m; // Input the string and number of queries
    s = "0" + s; // Prepend a '0' to string to align character indices

    weight[0] = 1; // Initialize first weight
    // Calculate powers of p1 modulo p2 for weights
    for (size_t i = 1; i < s.size(); i++)
    {
        weight[i] = weight[i - 1] * p1 % p2;
    }

    // Calculate prefix frequencies and store character positions
    for (size_t i = 1; i < s.size() + 1; i++)
    {
        cnt[s[i] - 'a' + 1]++;
        index[s[i] - 'a' + 1][cnt[s[i] - 'a' + 1]] = i;
        for (int j = 1; j <= 26; j++)
        {
            prefix_frequency[j][i] = cnt[j];
        }
    }

    // Calculate prefix hash values for each letter
    for (size_t i = 1; i < s.size(); i++)
    {
        for (int j = 1; j <= 26; j++)
        {
            prefix_hash[j][i] = (prefix_hash[j][i - 1] * p1 % p2 + prefix_frequency[j][i] - prefix_frequency[j][i - 1]) % p2;
        }
    }

    // Process each query
    while (m--)
    {
        int s1_prefix_frequency[27], s2_prefix_frequency[27];
        bool is_isomorphic = 1;
        cin >> l1 >> r1 >> l2 >> r2; // Input the indices of the two substrings

        // Check if the substrings have the same length
        if (r2 - l2 != r1 - l1)
        {
            cout << "No\n";
            continue;
        }

        // Calculate the frequency of each letter in the two substrings
        for (int i = 1; i < 27; i++)
        {
            s1_prefix_frequency[i] = prefix_frequency[i][r1] - prefix_frequency[i][l1 - 1];
            s2_prefix_frequency[i] = prefix_frequency[i][r2] - prefix_frequency[i][l2 - 1];

            // Check if the occurrence of letters in both substrings are consistent
            if ((s1_prefix_frequency[i] != 0) != (s2_prefix_frequency[i] != 0))
            {
                is_isomorphic = 0;
            }
        }

        // Sort the frequency arrays to compare if they match
        sort(s1_prefix_frequency + 1, s1_prefix_frequency + 27);
        sort(s2_prefix_frequency + 1, s2_prefix_frequency + 27);

        for (int i = 1; i < 27; i++)
        {
            // Check if sorted frequency arrays match
            if (s1_prefix_frequency[i] != s2_prefix_frequency[i])
            {
                is_isomorphic = 0;
            }
        }

        // If already found non-isomorphic, output "No"
        if (!is_isomorphic)
        {
            cout << "No\n";
            continue;
        }

        // Further check the isomorphism by comparing hash values of corresponding letters
        for (int i = 1; i < 27; i++)
        {
            // Skip if the character does not appear in the first substring
            if (prefix_frequency[i][l1 - 1] == prefix_frequency[i][r1])
            {
                continue;
            }

            // Find the index and its counterpart in the second substring
            int i_times = prefix_frequency[i][l1 - 1];
            int i_index = index[i][i_times + 1];
            int i_counterpart = s[l2 + i_index - l1] - 'a' + 1;

            // Check the isomorphism using the hash function
            if (!letter_isomorphic(i, i_counterpart, l1, r1, l2, r2))
            {
                is_isomorphic = 0;
                break;
            }
        }

        // Output "Yes" if isomorphic, otherwise "No"
        if (is_isomorphic)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}