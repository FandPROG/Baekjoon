#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

inline int getIndex(int x, int y) {
    return x * 1001 + y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, P;
    cin >> N >> P;
    vector<pair<int, int>> Fen(P);
    for(int i=0;i<P;i++) cin >> Fen[i].first >> Fen[i].second;
    const int MAX_INDEX = 1001 * 1001;
    vector<int> label(MAX_INDEX, -1);
    int perimeter = 0;
    int startX = Fen[0].first, startY = Fen[0].second;
    label[getIndex(startX, startY)] = perimeter++;
    for(int i=1;i<P;i++){
        int x = Fen[i-1].first, y = Fen[i-1].second;
        int nowX = Fen[i].first, nowY = Fen[i].second;
        
        if(nowX == x){
            if(nowY > y){
                for(int j = y + 1; j <= nowY; j++){
                    if(label[getIndex(x, j)] == -1){
                        label[getIndex(x, j)] = perimeter++;
                    }
                }
            }
            else{
                for(int j = y - 1; j >= nowY; j--){
                    if(label[getIndex(x, j)] == -1){
                        label[getIndex(x, j)] = perimeter++;
                    }
                }
            }
        }
        else {
            if(nowX > x){
                for(int j = x + 1; j <= nowX; j++){
                    if(label[getIndex(j, y)] == -1){
                        label[getIndex(j, y)] = perimeter++;
                    }
                }
            }
            else{
                for(int j = x - 1; j >= nowX; j--){
                    if(label[getIndex(j, y)] == -1){
                        label[getIndex(j, y)] = perimeter++;
                    }
                }
            }
        }
    }
    int lastX = Fen[P-1].first, lastY = Fen[P-1].second;
    int firstX = Fen[0].first, firstY = Fen[0].second;
    
    if(firstX == lastX){
        if(firstY > lastY){
            for(int j = lastY + 1; j <= firstY; j++){
                if(label[getIndex(firstX, j)] == -1){
                    label[getIndex(firstX, j)] = perimeter++;
                }
            }
        }
        else{
            for(int j = lastY - 1; j >= firstY; j--){
                if(label[getIndex(firstX, j)] == -1){
                    label[getIndex(firstX, j)] = perimeter++;
                }
            }
        }
    }
    else {
        if(firstX > lastX){
            for(int j = lastX + 1; j <= firstX; j++){
                if(label[getIndex(j, firstY)] == -1){
                    label[getIndex(j, firstY)] = perimeter++;
                }
            }
        }
        else{
            for(int j = lastX - 1; j >= firstX; j--){
                if(label[getIndex(j, firstY)] == -1){
                    label[getIndex(j, firstY)] = perimeter++;
                }
            }
        }
    }
    int full = perimeter;
    while(N--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int p1 = label[getIndex(x1, y1)];
        int p2 = label[getIndex(x2, y2)];
        
        int d = abs(p2 - p1);
        d = min(d, full - d);
        cout << d << "\n";
    }
    
    return 0;
}
