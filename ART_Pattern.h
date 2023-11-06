/*
 * ART_Pattern.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Arthur
 */

#ifndef ART_PATTERN_H_
#define ART_PATTERN_H_

int NaivePatternSearch(char* txt,int txtLen, char* pattern, int patternLen, int startingIndex);

int RabinKarpSearch(char* txt, int txtLen, char* pattern, int patternLen, int startingIndex);

int KMPSearch(char* txt, int txtLen, char* pattern, int patternLen, int startingIndex);

#endif /* ART_PATTERN_H_ */
