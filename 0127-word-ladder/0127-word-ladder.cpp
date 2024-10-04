#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Convert wordList to a set for quick lookup
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // If the endWord is not in the wordList, no transformation is possible
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        
        // BFS queue stores the current word and the transformation length so far
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        // Visited set to avoid revisiting words
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        while (!q.empty()) {
            auto [currentWord, level] = q.front();
            q.pop();
            
            // Try changing each letter in the current word
            for (int i = 0; i < currentWord.size(); ++i) {
                string transformedWord = currentWord;
                
                // Replace each character with 'a' to 'z' and check if it's in the wordSet
                for (char c = 'a'; c <= 'z'; ++c) {
                    transformedWord[i] = c;
                    
                    // If the transformed word matches endWord, return the level+1
                    if (transformedWord == endWord) {
                        return level + 1;
                    }
                    
                    // If it's in the wordSet and hasn't been visited, add it to the queue
                    if (wordSet.find(transformedWord) != wordSet.end() && visited.find(transformedWord) == visited.end()) {
                        q.push({transformedWord, level + 1});
                        visited.insert(transformedWord);  // Mark as visited
                    }
                }
            }
        }
        
        // If we exhaust the BFS without finding the endWord, return 0
        return 0;
    }
};
