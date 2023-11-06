/*
 * ART_Pattern.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Arthur
 */


#include "ART_Pattern.h"
#include <stdio.h>

long long Private_pwr(int x, int y) //2 3
{
    long long res = 1;
    while (y > 0)
    {
        res *= x;
        y--;
    }
    return res;
}

int NaivePatternSearch(char* txt, int txtLen, char* pattern, int patternLen, int startingIndex)
{
    //sanity check to make sure text >=pattern
    if ((txtLen - startingIndex) < patternLen)
    {
        printf("txt too small\n"); return -1;
    }

    for (int i = startingIndex; i <= txtLen - patternLen; i++)
    {
        int j = 0;
        for (; j < patternLen; j++)
        {
            if (txt[i + j] != pattern[j])
                break;
            //else
                //printf("log %d %d\n",i,j);
        }
        //printf("log after loop	 %d %d\n",i,j);
        if (j == patternLen)
            return i;
    }
    return -1;
}


int RabinKarpSearch(char* txt, int txtLen, char* pattern, int patternLen, int startingIndex)
{
    //sanity check to make sure text >=pattern
    if ((txtLen - startingIndex) < patternLen)
    {
        printf("txt too small\n"); return -1;
    }

    int p = 2203, b = 128;


    long long firstBasePower = Private_pwr(b, patternLen - 1) % p;

    int hash = (txt[startingIndex] * firstBasePower) % p;

    //hash value for first substring
    for (int i = startingIndex + 1; i < startingIndex + patternLen; i++)
        hash += ((txt[i] * Private_pwr(b, patternLen - i + startingIndex - 1)) % p);
    hash = hash % p;
    //printf("first Hash = %d\n", hash); //debug

    int patternHash = (pattern[0] * firstBasePower) % p;

    //hash value for pattern
    for (int i = 1; i < patternLen; i++)
        patternHash += (pattern[i] * Private_pwr(b, patternLen - i - 1)) % p;
    patternHash = patternHash % p;
    //printf("patternHash = %d\n", patternHash); //debug

    if (patternHash == hash)
    {
        int i = 0;
        for (; i < patternLen; i++)
            if (txt[startingIndex + i] != pattern[i])
                break;
        if (i == patternLen)
            return startingIndex;
    }


    for (int i = startingIndex + 1; i <= txtLen - patternLen; i++)
    {
        hash -= ((txt[i - 1] % p) * firstBasePower) % p;
        //printf("hash test = %d\n", hash); //debug
        hash = ((hash * b) + txt[i + patternLen - 1]) % p;
        if (hash < 0)
            hash += p;
        //printf("Hash = %d\n", hash); //debug
        if (patternHash == hash)
        {
            int j = 0;
            for (; j < patternLen; j++)
                if (txt[i + j] != pattern[j])
                    break;
            if (j == patternLen)
                return i;
        }
    }
    return -1;
}

int KMPSearch(char* txt, int txtLen, char* pattern, int patternLen, int startingIndex)
{
    int LPS[1024] = { 0 };
    int prefixIndex = 0;
    for (int i = 1; i < patternLen; i++)
    {
        if (pattern[i] == pattern[prefixIndex])
        {
            LPS[i+1] = ++prefixIndex;
        }
        else
            prefixIndex = 0;
    }

    int patternItterator = 0;
    for (int i = startingIndex; i < txtLen; i++)
    {
        if (txt[i] == pattern[patternItterator])
        {
            if (patternItterator == patternLen - 1 )
                return (i - patternLen+1);
            else
            {
                patternItterator++;
                continue;
            }

        }

        patternItterator = LPS[patternItterator];
        if(patternItterator != 0)
            i--;
        
    }
    return -1;
}
