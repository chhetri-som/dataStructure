#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 20

typedef struct {
    char cities[MAX_CITIES][50];
    int num_cities;
} CityList;

typedef struct {
    char start[50];
    char end[50];
} Edge;

typedef struct {
    Edge edges[MAX_CITIES * MAX_CITIES];
    int num_edges;
    int graph[MAX_CITIES][MAX_CITIES];
    CityList city_list;
} Graph;

int find_city_index(CityList *city_list, const char *city) {
    for(int i = 0; i < city_list -> num_cities; i++) {
        if(strcmp(city_list -> cities[i], city) == 0) {
            return i;
        }
    }
    return -1;
}

int add_city(CityList *city_list, const char *city) {
    if(city_list -> num_cities >= MAX_CITIES) {
        return -1;
    }

    int index = find_city_index(city_list, city);

    if(index == -1) {
        strcpy(city_list -> cities[city_list -> num_cities], city);
        city_list -> num_cities++;
        return city_list -> num_cities - 1;
    }
    return index;
}

void init_graph(Graph *graph) {
    graph -> num_edges = 0;
    graph -> city_list.num_cities = 0;
    memset(graph -> graph, 0, sizeof(graph -> graph));
}

void add_edge(Graph *graph, const char *start, const char *end) {
    int start_index = add_city(&graph -> city_list, start);
    int end_index = add_city(&graph -> city_list, end);

    if(start_index != -1 && end_index != -1) {
        graph -> graph[start_index][end_index] = 1;
        strcpy(graph -> edges[graph -> num_edges].start, start);
        strcpy(graph -> edges[graph -> num_edges].end, end);
        graph -> num_edges++;
    }
}

void print_graph_dict(Graph *graph) {
    printf("Graph Dict: \n");
    for(int i = 0; i < graph -> city_list.num_cities; i++) {
        printf("%s: ", graph -> city_list.cities[i]);
        for(int j = 0; j < graph -> city_list.num_cities; j++) {
            if(graph -> graph[i][j] == 1){
                printf("%s, ", graph -> city_list.cities[j]);
            }
        }
        printf("\n");
    }
}

void get_paths_recursive(Graph *graph, int start_index, int end_index, int *path, int path_index, int *visited, int all_paths[][MAX_CITIES], int *num_paths) {

    path[path_index] = start_index;
    visited[start_index] = 1;

    if(start_index == end_index) {
        for(int i = 0; i <= path_index; i++) {
            all_paths[*num_paths][i] = path[i];
        }
        (*num_paths)++;
        visited[start_index] = 0;
        return;
    }

    for(int i = 0; i< graph -> city_list.num_cities; i++) {
        if(graph -> graph[start_index][i] == 1 && visited[i] == 0) {
            get_paths_recursive(graph, i, end_index, path, path_index + 1, visited, all_paths, num_paths);
        }
    }
    visited[start_index] = 0;
}

void get_paths(Graph *graph, const char *start, const char *end, int all_paths[][MAX_CITIES], int *num_paths) {
    int start_index = find_city_index(&graph -> city_list, start);
    int end_index = find_city_index(&graph -> city_list, end);

    if(start_index == -1 || end_index == -1) {
        *num_paths = 0;
        return;
    }

    int path[MAX_CITIES];
    int visited[MAX_CITIES] = {0};
    *num_paths = 0;

    get_paths_recursive(graph, start_index, end_index, path, 0, visited, all_paths, num_paths);
}

void get_shortest_path(Graph *graph, const char *start, const char *end, int shortest_path[MAX_CITIES], int *shortest_path_len) {
    int all_paths[MAX_CITIES * MAX_CITIES][MAX_CITIES];
    memset(all_paths, -1, sizeof(all_paths));

    int num_paths = 0;
    get_paths(graph, start, end, all_paths, &num_paths);

    if(num_paths == 0){
        *shortest_path_len = 0;
        return;
    }

    *shortest_path_len = MAX_CITIES - 1;
    for(int i = 0; i < num_paths; i++){
        int path_len = 0;
        while(all_paths[i][path_len] != -1 && path_len < MAX_CITIES) path_len++;

        if(path_len < *shortest_path_len) {
            *shortest_path_len = path_len;
            for(int j = 0; j < path_len; j++) {
                shortest_path[j] = all_paths[i][j];
            }
        }
    }
}

int main() {
    Graph route_graph;
    init_graph(&route_graph);

    add_edge(&route_graph, "Bagdogra", "Bengaluru");
    add_edge(&route_graph, "Bengaluru", "Bagdogra");
    add_edge(&route_graph, "Kolkata", "Delhi");
    add_edge(&route_graph, "Mumbai", "Delhi");
    add_edge(&route_graph, "Delhi", "Bengaluru");
    add_edge(&route_graph, "Bengaluru", "Kerala");
    add_edge(&route_graph, "Kerala", "Mumbai");
    add_edge(&route_graph, "Mumbai", "Kochi");
    add_edge(&route_graph, "Kerala", "Kochi");
    add_edge(&route_graph, "Bengaluru", "Kochi");

    print_graph_dict(&route_graph);

    char start_city[] = "Bagdogra";
    char end_city[] = "Kochi";
    int all_paths[MAX_CITIES * MAX_CITIES][MAX_CITIES];
    int num_paths = 0;

    memset(all_paths, -1, sizeof(all_paths));
    get_paths(&route_graph, start_city, end_city, all_paths, &num_paths);

    printf("All paths between %s and %s: \n", start_city, end_city);
    for(int i = 0; i < num_paths; i++) {
        int j = 0;
        while(all_paths[i][j] != -1 && j < MAX_CITIES) {
            printf("%s - ", route_graph.city_list.cities[all_paths[i][j]]);
            j++;
        }
        printf("\n");
    }


    int shortest_path[MAX_CITIES];
    int shortest_path_len;
    get_shortest_path(&route_graph, start_city, end_city, shortest_path, &shortest_path_len);

    printf("Shortest path between %s and %s: ", start_city, end_city);
    for(int i = 0; i < shortest_path_len; i++) {
        printf("%s - ", route_graph.city_list.cities[shortest_path[i]]);
    }
    printf("\n");

    return 0;
}
