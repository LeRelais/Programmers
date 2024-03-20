#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Trie {
private:
    Trie* node[10];
public:
    Trie() {
        for (int i = 0; i < 10; i++) {
            node[i] = NULL;
        }
    }

    ~Trie() {
        for (int i = 0; i < 10; i++) {
            if (node[i] != NULL)
                delete node[i];
        }
    }

    int toNumber(char c) {
        return c - '0';
    }

    void insert(const char* word) {
        if (*word == '\0') {
            return;
        }

        int next = toNumber(*word);

        if (node[next] == NULL)
            node[next] = new Trie();


        node[next]->insert(word + 1);
    }

    bool find(const char* word) {
        int next = toNumber(*word);

        if (*word == '\0') {
            return true;
        }
        else if (node[next] == NULL)
            return false;

        return node[next]->find(word + 1);
    }
};

bool cmp(string a, string b) {
    return a.length() > b.length();
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    Trie trie;
    sort(phone_book.begin(), phone_book.end(), cmp);

    bool flag = false;

    for (int i = 0; i < phone_book.size(); i++) {
        if (trie.find(phone_book[i].c_str()))
        {
            return false;
        }
        trie.insert(phone_book[i].c_str());
    }
    return answer;
}