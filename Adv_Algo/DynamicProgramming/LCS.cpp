/*
Longest Common Subsequence Problem

Made By : Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

string LCS(string s1, string s2){
    s1 = '|'+s1;
    s2 = '|'+s2;
    int dp1[s1.size()][s2.size()]{};
    int dp2[s1.size()][s2.size()]{}; // 1:UP/ 2: LEFT/ 3: Diagonal
    for(int i = 1; i < s1.size(); i++){
        for(int j = 1; j < s2.size(); j++){
            if(s1[i] == s2[j]){
                dp1[i][j] = dp1[i-1][j-1] + 1;
                dp2[i][j] = 3;
            }
            else{
                if(dp1[i-1][j] >= dp1[i][j-1]){
                    dp1[i][j] = dp1[i-1][j];
                    dp2[i][j] = 1;
                }
                else{
                    dp1[i][j] = dp1[i][j-1];
                    dp2[i][j] = 2;
                }
            }
        }
    }
    /* for(int i = 0; i <= s1.size(); i++){
		for(int j = 0; j <= s2.size(); j++)
			cout << dp1[i][j] << '|';
		cout << endl;
	} */
    string res;
    int a,b;
    a = s1.size()-1;
    b = s2.size()-1;
    while(a >= 0 && b >= 0){
        if(dp2[a][b] == 3){
            res += s1[a];
            a--;
            b--;
        }
        else if(dp2[a][b] == 2)
            b--;
        else
            a--;
    }
    reverse(res.begin(), res.end());
    return res;

}

#define OFLINE_JUDGE 0
main(){
    #if OFLINE_JUDGE > 0
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
	#endif
    string res, s1,s2;
    cin >> s1 >> s2;
    res = LCS(s1,s2);
    cout << res;
    return 0;
}