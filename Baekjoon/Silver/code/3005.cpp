//
//  main.cpp
//  CodingTest
//
//  Created by sowon on 05/09/2020.
//  Copyright © 2020 sowon. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;
char puzzle[20][20];

void getminstr(int r, int c)
{
    string min = "";
    string str = "";
    // # left -> right search
    for (int i = 0; i < r; i++)
    {
        str = "";
        for (int j = 0; j < c; j++)
        {
            if (puzzle[i][j] == '#')
            {
                if (str.length() >= 2)
                {
                    if (min == "" || min > str)
                    {
                        min = str;
                    }
                }
                str = "";
            }
            else
            {
                str += puzzle[i][j];
            }
        }
        if (str.length() >= 2)
        {
            if (min == "" || min > str)
            {
                min = str;
            }
        }
        //cout << str << " " << min << endl;
    }
    // # up -> down search
    for (int i = 0; i < c; i++)
    {
        str = "";
        for (int j = 0; j < r; j++)
        {
            if (puzzle[j][i] == '#')
            {
                if (str.length() >= 2)
                {
                    if (min == "" || min > str)
                    {
                        min = str;
                    }
                }
                str = "";
            }
            else
            {
                str += puzzle[j][i];
            }
        }
        if (str.length() >= 2)
        {
            if (min == "" || min > str)
            {
                min = str;
            }
        }
        //cout << str << " " << min << endl;
    }

    cout << min;
}

int main()
{
    int r, c;
    string input;
    scanf("%d %d", &r, &c);

    for (int i = 0; i < r; i++)
    {
        cin >> input;
        for (int j = 0; j < c; j++)
        {
            puzzle[i][j] = input[j];
        }
    }

    getminstr(r, c);
    return 0;
}