#include "dijkstras.h"
#include <cmath>
vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int vertices = G.size();
    vector<int> dist(vertices,INF);
    vector<bool> visit(vertices, false);
    dist[source] = 0;
    priority_queue<pair<int,int>> heap;
    heap.push({source,0});
    while(!heap.empty()){
        int value = heap.top().first;//add the issue right here
        if(visit[value]){
            continue;
        }
        visit[value] = true;
        for(Edge edge: G[value]){
            int value_add = edge.dst;
            int weight_value = edge.weight;
            if(!visit[value_add] && dist[value_add] + weight_value < dist[value_add]){
                visit[value_add] = dist[value_add] + weight_value;
                previous[value_add] = value;
                heap.push({value_add,visit[value_add]});
            }
        }
    }
    return dist;
}
vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination){
    vector<int> values;
    for(;destination != -1;){
        values.push_back(destination);
        destination = previous[destination];
    }
    reverse(values.begin(), values.end());
    return values;
}
void print_path(const vector<int>& v, int total){
    if(!v.empty()){
        for(size_t i = 0; i < v.size(); ++i){
            cout << v[i] << "";
        }
        cout << ""<< endl;
    }else{
        cout << "No word ladder found." << "";
    }
    cout << "Total cost is " << total << endl;
    cout << "";
}