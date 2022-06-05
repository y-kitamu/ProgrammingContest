/**
 * @file d.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-05 12:17:57
 */
#include <bits/stdc++.h>

class TextEditor {
  public:
    TextEditor() {
        ls = std::list<char>();
        head = ls.begin();
        cursor = ls.begin();
    }

    void addText(std::string text) {
        for (auto& c : text) {
            ls.insert(cursor, c);
        }
        print();
    }

    int deleteText(int k) {
        int res = k;
        while (ls.size() > 0 && res > 0) {
            cursor = ls.erase(--cursor);
            res--;
        }
        print();
        return k - res;
    }

    std::string cursorLeft(int k) {
        int res = k;
        while (cursor != head && res > 0) {
            cursor--;
            res--;
        }
        std::string ans = "";
        auto cur = cursor;
        while (cur != head && ans.length() < 10) {
            ans = *(--cur) + ans;
        }
        return ans;
    }

    std::string cursorRight(int k) {
        int res = k;
        while (cursor != ls.end() && res > 0) {
            cursor++;
            res--;
        }
        std::string ans = "";
        auto cur = cursor;
        while (cur != ls.end() && ans.length() < 10) {
            ans += *cur;
            cur++;
        }
        return ans;
    }

    void print() {
        for (auto& c : ls) {
            std::cout << c;
        }
        std::cout << std::endl;
    }

    std::list<char> ls;
    std::_List_iterator<char> cursor;
    std::_List_iterator<char> head;
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

int main() {}
