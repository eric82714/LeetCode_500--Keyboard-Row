/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool check(char word[], char c, int size){
    for(int i = 0; i < size; i++){
        if(word[i] == tolower(c)) return true;
    }
    
    return false;
}

char ** findWords(char ** words, int wordsSize, int* returnSize){
    char first[10] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    char second[9] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    char third[7] = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    
    char** result = malloc(wordsSize * sizeof(char*));
    int index = 0;
       
    for(int i = 0; i < wordsSize; i++){        
        int len1 = 0, len2 = 0, len3 = 0;
        
        for(int j = 0; j < strlen(words[i]); j++){
            if(check(first, words[i][j], 10)){
                len1 ++;
                continue;
            }
            if(check(second, words[i][j], 9)){
                len2 ++;
                continue;
            }
            if(check(third, words[i][j], 7)){
                len3 ++;
                continue;
            }
        }
        
        if(len1 == strlen(words[i])){
            result[index] = malloc((len1+1) * sizeof(char));
            strcpy(result[index], words[i]);
            index++;
        }
        if(len2 == strlen(words[i])){
            result[index] = malloc((len2+1) * sizeof(char));
            strcpy(result[index], words[i]);
            index++;
        }
        else if(len3 == strlen(words[i])){
            result[index] = malloc((len3+1) * sizeof(char));
            strcpy(result[index], words[i]);
            index++;
        }
    }
    
    *returnSize = index;
    return result; 
}
