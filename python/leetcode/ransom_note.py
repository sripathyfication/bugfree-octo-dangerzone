#!/usr/bin/env python
import sys


ransomNoteDict = {}
magazineDict = {}

# extract each char from ransom,
# if ransomNoteDict has key ransom update count
# else add entry and make count 1
def updateRansomNote(ransom):
    for c in ransom:
        if ransomNoteDict.has_key(c):
           ransomNoteDict[c] += 1
        else:
           ransomNoteDict[c] = 1

# extract each char from magazine,
# if magazineDict has key ransom update count
# else add entry and make count 1
def updateMagazine(magazine):
    for c in magazine:
        if magazineDict.has_key(c):
            magazineDict[c] += 1
        else:
            magazineDict[c] = 1

def canConstruct(ransomNote, magazine):
    updateRansomNote(ransomNote)
    updateMagazine(magazine)
    
    for key in ransomNoteDict:
        if magazineDict.has_key(key):
           if magazineDict[key] < ransomNoteDict[key]:
              return False
           else:
              return True
        return False

def main():
    ransom = raw_input("Enter your ransom note\n")
    magazine = raw_input("Enter your magazine\n")
    result = canConstruct(ransom,magazine)
    print result

if __name__ == '__main__':
    main()
