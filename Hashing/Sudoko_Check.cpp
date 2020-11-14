/*
Determine if a Sudoku is valid, The Sudoku board could be partially filled, 
where empty cells are filled with the character ‘.’
Input: ["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", 
"7...2...6", ".6....28.", "...419..5", "....8..79"]
Note: A valid Sudoku board (partially filled) is not necessarily solvable. 
Only the filled cells need to be validated.

Made By: Gaurav Baweja
*/
#include<bits/stdc++.h>
using namespace std;

bool checkSudoko(string sudo[])
{
    for(short j = 0; j < 9; j++)
    {
        bool arr[10] = {0};
        for(short i = 0; i < 9; i++)
            if(sudo[j][i] != '.')
            {
                if(arr[sudo[j][i]-'0'] == 0)
                    arr[sudo[j][i]-'0'] = 1;
                else
                    return 0; 
            }
    }
    for(short j = 0; j < 9; j++)
    {
        bool arr[10] = {0};
        for(short i = 0; i < 9; i++)
            if(sudo[i][j] != '.')
            {
                if(arr[sudo[i][j]-'0'] == 0)
                    arr[sudo[i][j]-'0'] = 1;
                else
                    return 0; 
            }
    }
    for(short i = 0; i < 3; i++)
    {
        for(short j = 0; j < 3; j++)
        {
            bool arr[10] = {0};
            for(short l = i*3; l < (i+1)*3; l++)
            {
                for(short m = j*3; m < (j+1)*3; m++)
                    if(sudo[l][m] != '.')
                    {
                        if(arr[sudo[l][m]-'0'] == 0)
                            arr[sudo[l][m]-'0'] = 1;
                        else
                            return 0; 
                    }
            }
        }
    }
    return 1;
}

main()
{
    string sudo[] = {"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", 
                    "7...2...6", ".6....28.", "...419..5", "....8..79"};
    if(checkSudoko(sudo))
        cout << "Sudoko is Valid!\n";
    else
        cout << "Sudoko is Invalid!\n";

    return 0;
}