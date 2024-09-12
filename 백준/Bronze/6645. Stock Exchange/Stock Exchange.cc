#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int i, j;
    bool running = true;
    while(running) {
        int n;
        string exc;
        cin >> n >> exc;
        if(n == 0 && exc == "END") {
            running = false;
            break;
        }
        vector <pair<string, double>> seller, buyer;
        map <string, vector<string>> mp;
        vector <string> s;
        for(i=0;i<n;i++) {
            string name, type;
            double price;
            
            cin >> name >> type >> price;

            s.push_back(name);

            if(type == "buy") buyer.push_back({name, price});
            else seller.push_back({name, price});
        }
        
        for(j=0;j<buyer.size();j++) {
            vector <string> res;
            for(int k =0;k<seller.size();k++) {
                if(seller[k].second <= buyer[j].second) {
                    res.push_back(seller[k].first);
                }
            }
            mp.insert({buyer[j].first, res});
        }

        for(j=0;j<seller.size();j++) {
            vector <string> res;
            for(int k =0;k<buyer.size();k++) {
                if(seller[j].second <= buyer[k].second) {
                    res.push_back(buyer[k].first);
                }
            }
            mp.insert({seller[j].first, res});
        }

        cout << exc << endl;
         for(i=0;i<s.size();i++) {
            cout << s[i] << ": ";
            if(mp[s[i]].size() == 0) cout << "NO-ONE";
            for(j=0;j<mp[s[i]].size();j++) {
                cout << mp[s[i]][j] << ' ';
            }
            cout << '\n';
         }
    }
    return 0;
}