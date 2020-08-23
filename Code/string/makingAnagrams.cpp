// Complete the makeAnagram function in the editor below. 
// It must return an integer representing the minimum total 
// characters that must be
// deleted to make the strings anagrams.

int makeAnagram(string a, string b)
{
    auto count = 0;
    vector<int> freq(26, 0);
    for (auto c : a)
    {
        ++freq[c - 'a'];
    }
    for (auto c : b)
    {
        --freq[c - 'a'];
    }
    for (auto val : freq)
    {
        count += abs(val);
    }
    return count;
}