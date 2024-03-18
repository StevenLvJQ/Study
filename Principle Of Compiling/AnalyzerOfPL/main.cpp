#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

const vector<string> KEYWORDS {"begin", "call", "const", "do", "end", "if", "odd",
                         "procedure", "read", "then", "var", "while", "write"};

// 读取文件内容并将其加入vector中
vector<string> get_content(const string &path){
    ifstream fin;
    vector<string> res;
    fin.open(path, ios::in);
    if(!fin.is_open()){
        cerr << "Failed opening file!!";
    }
    char line[1024] = {0};
    while(fin.getline(line, sizeof(line))){
        res.emplace_back(line);
    }
    fin.close();
    return res;
}

// 化为小写
string to_lower(string& str){
    string res;
    for(auto letter : str){
        if(letter>=65 && letter<=90){
            res += (char)(letter + 32);
            continue;
        }
        res += letter;
    }
    return res;
}

// 获取句子中的单词以及标识符
vector<string> load_words(string& sentence){
    vector<string> words;
    string tmp;
    for(int i=0; i<sentence.size(); i++) {
        if (sentence[i] == '+' || sentence[i] == '-' || sentence[i] == '/' || sentence[i] == '*'
            || sentence[i] == '=' || sentence[i] == '<' || sentence[i] == '>' || sentence[i] == ':'
            || sentence[i] == '(' || sentence[i] == ')' || sentence[i] == ';' || sentence[i] == ',' ||
            sentence[i] == '.'
            || sentence[i] == 32 || sentence[i] == '\n') {
            if (!tmp.empty()) {
                words.push_back(tmp);
                tmp.clear();
            }
            continue;
        } else {
            tmp += sentence[i];
        }
    }
    if(!tmp.empty())
        words.push_back(tmp);
    return words;
}

//获取 identifiers 并全部化为小写
vector<string> get_identifiers(vector<string>& words){
    vector<string> res;
    for(auto &word : words){
        string lower_word = to_lower(word);
        bool flag = false;
        for(auto &KEY : KEYWORDS){
            if(KEY == lower_word){
                flag = true;
                break;
            }
        }
        if(word[0] >= '0' && word[0] <= '9')
            flag = true;
        if(!flag){
            res.push_back(to_lower(word));
        }
    }
    return res;
}

// 最终调用
void save_identifier(const string& read_path, const string& save_path){
    // 读取文件
    vector<string> res = get_content(read_path);
    // 结果先保存在map中
    map<string, int> id_times;
    ofstream fout;
    fout.open(save_path, ios::out | ios::app);
    fout << read_path << endl;
    // 获取每行单词以及标识符，并进行识别和保存
    for(auto &line : res){
        // 获取每行的单词加标识符
        vector<string> words = load_words(line);
        // 获取标识符
        vector<string> tmp = get_identifiers(words);
        // 保存标识符
        for(auto &identifier : tmp) {
            if (id_times.count(identifier) == 0)
                id_times[identifier] = 1;
            else
                id_times[identifier]++;
        }
    }
    for(auto &[x, y] : id_times){
        fout << '(' << x << ", " << y << ')' << endl;
    }
    fout << endl;
    fout.close();
}

int main() {
    save_identifier("../PL_file1.txt", "../save_identifier");
    save_identifier("../PL_file2.txt", "../save_identifier");
    save_identifier("../PL_file3.txt", "../save_identifier");
    save_identifier("../PL_file4.txt", "../save_identifier");
    save_identifier("../PL_file5.txt", "../save_identifier");
    return 0;
}
