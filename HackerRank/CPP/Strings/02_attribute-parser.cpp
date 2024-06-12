#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <map>
#include <sstream>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int                 n, q;
    map<string, string> m;
    string              attr, curr = "";

    cin >> n >> q;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string          line, tag, extract;
        getline(cin, line);
        stringstream    ss(line);

        while (getline(ss, extract, ' ')) {
            /* tag */
            if (extract[0] == '<') {
                /* opening tag */
                if (extract[1] != '/') {
                    tag = extract.substr(1);
                    if (tag[tag.length() - 1] == '>')
                        tag.pop_back();
                    if (curr.size() > 0)
                        curr += "." + tag;
                    else
                        curr = tag;
                }
                /* closing tag */
                else {
                    tag = extract.substr(2, (extract.find('>') - 2));

                    size_t  pos = curr.find("." + tag);
                    if (pos != string::npos)
                        curr = curr.substr(0, pos);
                    else
                        curr = "";
                }
            }
            /* attribute value */
            else if (extract[0] == '"') {
                size_t  pos = extract.find_last_of('"');
                string  attr_value = extract.substr(1, pos - 1);
                
                m[attr] = std::move(attr_value);
            }
            /* attribute */
            else {
                if (extract != "=")
                    attr = curr + "~" + extract;
            }
        }
    }

    string  query;
    for (int i = 0; i < q; i++) {
        getline(cin, query);

        map<string, string>::iterator   it = m.find(query);
        if (it != m.end())
            cout << it->second << endl;
        else
            cout << "Not Found!" << endl;
    }

    return 0;
}