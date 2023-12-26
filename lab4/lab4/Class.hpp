
#ifndef Class_hpp
#define Class_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <fstream>
#include "Pipe.hpp"
#include "CS.hpp"
#include <cmath>
#include <queue>
#include <limits>

class PipeAndKC
{
public:
    struct svyaz
    {
        int vhod;
        int vihod;
    };

    vector<vector<int>> create_graph(const unordered_map <int, svyaz>& rebra);
    unordered_set<int> number_vershin(const unordered_map<int, svyaz>& rebra);
    unordered_map<int, int> vershin_map(const unordered_map<int, svyaz>& rebra);
    int getKeyByValue(const unordered_map<int, int>& map, const int& value);
    bool iscycle(vector<vector<int>>& graph, int w, vector<int>& visited, unordered_map<int, int>& vershin);
    void istopol(const unordered_map <int, svyaz>& rebra);
    int getvalue(unordered_map<int, int>& vershin, int& k);
    void topol_sort(vector<vector<int>>& graph, int w, vector<int>& visited, vector<int>& order, unordered_map<int, int>& vershin);

    void create_rebro(const unordered_map <int, KC>& kcmap, unordered_map <int, Pipe>& pmap, unordered_map <int, svyaz>& rebra);
    void see_rebra(const unordered_map <int, svyaz>& rebra);
    void delete_rebra(unordered_map <int, svyaz>& rebra);

    void load_data(unordered_map<int, Pipe>& pmap, unordered_map<int, KC>& kcmap, unordered_map <int, svyaz>& rebra);
    void save_data(const unordered_map<int, Pipe>& pmap, const unordered_map<int, KC>& kcmap, const unordered_map <int, svyaz>& rebra);
    bool is_empty_file(const string& s);

    void dejkstra(const unordered_map <int, svyaz>& rebra, const unordered_map <int, Pipe>& pmap);
    int ves_vershin(const int& pid, const unordered_map <int, Pipe>& pmap);

    bool value_in_vector(const vector<int>& visited, const int& t);
    void zapolnit_postoyan(vector<vector<int>>& dejk, const int& k, const int& ves, const int& l);
    int id_pipe_for_ves(const unordered_map<int, svyaz>& rebra, int& idpvh, int& idpvih);
    void put_from_dejk(const vector<vector<int>>& dejk, const int& start, const int& finish, unordered_map<int, int>& vershin, const vector<vector<int>>& graph, const unordered_map <int, svyaz>& rebra, const unordered_map <int, Pipe>& pmap, vector<int>& s, const unordered_set<int>& v);
    int proizv(const unordered_map <int, Pipe>& pmap, const int& idpipe);
    vector <vector<int>> matriza_vesov(const unordered_map <int, svyaz>& rebra, const unordered_map <int, Pipe>& pmap);
    void max_potok(const unordered_map <int, svyaz>& rebra, const unordered_map <int, Pipe>& pmap);
    int augment_path(vector<vector<int>>& residual_capacity, vector<int>& parent, int source, int sink);
    int ford_fulkerson(vector<vector<int>>& graph, vector<vector<int>>& capacity_matrix, int source, int sink);

    friend std::ostream& operator << (std::ostream& out, const svyaz& r);
    friend std::ofstream& operator << (ofstream& fout, const unordered_map<int, svyaz>& rebra);

};
#endif /* Class_hpp */
