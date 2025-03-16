#include "ladder.h"

void error(string word1, string word2, string msg){
    cout << "Error:" << word1 << word2 << msg;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    if(str1.size() != str2.size()){
        return false;
    }
    int count = 0;
    for(size_t i = 0; i < str2.size() ; ++i){
        if(str1[i] != str2[i]){
            count += 1;
            if(count > d){
                return false;
            }
        }
    }
    return count <= d;
}
bool is_adjacent(const string& word1, const string& word2){
    return edit_distance_within(word1, word2, 1);
}
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<vector<string>> ladder;
    ladder.push({begin_word});
    set<string> visit;
    visit.insert(begin_word);
    while(ladder.size() != 0){
        vector<string> temp_ladder = ladder.front();
        ladder.pop();
        string last_value = temp_ladder.back();
        for(auto word_values: word_list){
            if(is_adjacent(last_value, word_values)){
                if(visit.find(word_values) == visit.end()){
                    visit.insert(word_values);
                    vector<string> copy_ladder = temp_ladder;
                    copy_ladder.push_back(word_values);
                    if(word_values == end_word){
                        return copy_ladder;
                    }
                    ladder.push(copy_ladder);
                }
            }
        }
    }
    return {};
}
void load_words(set<string> & word_list, const string& file_name){
    ifstream file_insert(file_name);
    string temp_value;
    for(;file_insert >> temp_value;){
        word_list.insert(temp_value);
    }
}
void print_word_ladder(const vector<string>& ladder){
    for(size_t i = 0; i < ladder.size(); ++i){
        cout << ladder[i] << "";
    }
}
// void verify_word_ladder(){

// }
