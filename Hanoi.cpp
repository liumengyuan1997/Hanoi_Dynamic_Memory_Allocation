
#include "Hanoi.h"


std::string Hanoi::get_moves(int num_discs, int src, int dst, int tmp){
    string result1, result2, result3;
    
    if (num_discs == 0){
        return "";
    }

    if (lookup_moves(num_discs, src, dst) != ""){
//        cout << lookup_moves(num_discs, src, dst)<< endl;
        return lookup_moves(num_discs, src, dst);
    } else {
        _cache.resize(num_discs+1);
        for (int i = 0; i < (num_discs+1); i++){
            _cache[i].resize(src+1);
            for (int j = 0; j < (src+1); j++){
                _cache[i][j].resize(dst+1);
            }
        }
        
        if (num_discs == 1 &&
            src < int(_cache[0].size()) &&
            dst < int(_cache[0][0].size()))
        {
            if (num_discs == 1 && src == 1 && dst == 2){
                _cache[1][1][2] = to_string(1) + "->" + to_string(2) + "\n";
                return _cache[1][1][2];}
            if (num_discs == 1 && src == 1 && dst == 3){
                _cache[1][1][3] = to_string(1) + "->" + to_string(3) + "\n";
                return _cache[1][1][3];}
            if (num_discs == 1 && src == 2 && dst == 1){
                _cache[1][2][1] = to_string(2) + "->" + to_string(1) + "\n";
                return _cache[1][2][1];}
            if (num_discs == 1 && src == 2 && dst == 3){
                _cache[1][2][3] = to_string(2) + "->" + to_string(3) + "\n";
                return _cache[1][2][3];}
            if (num_discs == 1 && src == 3 && dst == 1){
                _cache[1][3][1] = to_string(3) + "->" + to_string(1) + "\n";
                return _cache[1][3][1];}
            if (num_discs == 1 && src == 3 && dst == 2){
                _cache[1][3][2] = to_string(3) + "->" + to_string(2) + "\n";
                return _cache[1][3][2];}
//            return to_string(src) + "->" + to_string(dst) + "\n";
        }
        if (num_discs > 1){
            
            for (int i = 2; i < num_discs; i++) {
                result1 = get_moves(i, src, tmp, dst);
                result2 = get_moves(i, tmp, dst, src);
                result3 = result1 + to_string(src) + "->" + to_string(dst) + "\n" + result2;
            }
            
            _cache.resize(num_discs+1);
            for (int i = 0; i < (num_discs+1); i++){
                _cache[i].resize(src+1);
                for (int j = 0; j < (src+1); j++){
                    _cache[i][j].resize(dst+1);
                }
            }
            
            _cache[num_discs][src][dst] = result3;
            
            _cache[num_discs-1].clear();

        }
        return result3;
    }
}

std::string Hanoi::lookup_moves(int num_discs, int src, int dst) const{

    if (num_discs < int(_cache.size()) &&
        src < int(_cache[0].size()) &&
        dst < int(_cache[0][0].size()))
    {
        if (_cache[num_discs][src].at(dst) != ""){
            return _cache[num_discs][src][dst];
        }
    }

    return "";
}

std::string Hanoi::solve(int num_discs, int src, int dst, int tmp){
    
    _cache = vector<vector<vector<string> > >((num_discs + 1), vector<vector<string> >((src+1), vector<string> (dst+1)));
//
//    if (num_discs == 0){
//        for (int j = 0; j < (src+1); j++)
//        {
//            for (int k = 0; k < (tmp+1); k++)
//            _cache[0][j][k] = "";
//        }
//    }
    
    return ("# Below, 'A->B' means 'move the top disc on pole A to pole B'\n" + get_moves(num_discs, src, dst, tmp));

}


