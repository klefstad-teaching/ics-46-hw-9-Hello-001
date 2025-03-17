#include "ladder.h"

void error(string word1, string word2, string msg){
    cout << "Error:" << word1 << word2 << msg;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    if(abs(int(str1.size() - str2.size())) > d){
        return false;
    }
    size_t smallest_value;
    string smallest_string;
    string largest_string;
    if(str1.size() < str2.size()){
        smallest_value = str1.size();
        smallest_string = str1;
        largest_string = str2;
    }else{
        smallest_value = str2.size();
        smallest_string = str2;
        largest_string = str1;
    }
    size_t value_large = 0;
    size_t values_not_equal = 0;
    for(size_t i = 0; i < smallest_value;){
        if(largest_string[value_large] == smallest_string[i]){
            value_large += 1;
            i += 1;
        }else{
            if(values_not_equal > size_t(d)){
                return false;
            }
            values_not_equal += 1;
            value_large += 1;
        }
    }
    values_not_equal += (largest_string.size() - value_large);
    return (values_not_equal <= size_t(d));
}
bool is_adjacent(const string& word1, const string& word2){
    if(abs(int(word1.size() - word2.size())) > 1){
        return false;
    }else if(word1.size() == word2.size()){
        int count = 0;
        for(size_t i = 0; i < word2.size() ; ++i){
            if(word1[i] != word2[i]){
                count += 1;
                if(count > 1){
                    return false;
                }
            }
        }
    }
    return true;
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
    if(!ladder.empty()){
        cout << "Word ladder found: ";
        for(size_t i = 0; i < ladder.size(); ++i){
            cout << ladder[i] << " ";
        }
        cout << "" << endl;
    }else{
        cout << "No word ladder found." << endl;
        cout << "";
    }
}
// void verify_word_ladder(){

// }
