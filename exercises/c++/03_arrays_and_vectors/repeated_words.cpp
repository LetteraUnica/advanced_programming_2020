#include <iostream>
#include <vector>
#include <unordered_map>

template <typename T, typename U>
void print_vector(const std::vector<T> &v, const std::vector<U> &c) {
    for(auto i = 0lu; i < v.size(); i++)
        std::cout << v[i] << "\t" << c[i] << std::endl;
}

template <typename T, typename U>
void print_map(const std::unordered_map<T, U> &map) {
    for(auto it = map.begin(); it!=map.end(); it++)
        std::cout << it->first << "\t" << it->second << std::endl;
}

int contains(const std::vector<std::string> words, std::string word) {
    int pos = -1;
    for (auto i = 0lu; i < words.size(); i++) {
        if(words[i] == word) {
            pos = i;
            break;
        }
    }
    
    return pos;
}

int main() {
    std::vector<std::string> words{};
    std::vector<int> counts{};
    std::string a;
    while(std::cin >> a) {
        int pos = contains(words, a);
        if(pos>=0) {
            counts[pos] += 1;
            continue;
        }
        words.push_back(a);
        counts.push_back(1);
    }

    std::unordered_map<std::string, int> words_map{};
    while(std::cin >> a) {
        auto got = words_map.find(a);
        if(got != words_map.end()) {
            got->second += 1;
            continue;
        }
        words_map.insert(std::make_pair(a, 1));
    }

    print_map(words_map);

    return 0;
}