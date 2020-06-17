// We can make the string "10101" by changing the first and the last 
// characters. Here, every substring with a length of at least 2 
// contains at least one "1". There's no way to do this in less 
// than 2 operations.
//Therefore, the answer is .

// input -
// 00100
// 2

// output -
// 2

int minimumMoves(string s, int d) {
    int n = s.size();
    int zeroCount = 0;
    int count = 0;
    for(int i = 0; i<n ; i++)
    {
        if(s[i] == '0')
        {
            zeroCount++;
            if(zeroCount%d == 0)
                count += 1;
        }
        else zeroCount = 0;
    }
    return count;
}

