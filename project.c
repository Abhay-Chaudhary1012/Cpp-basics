#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <string.h> 
#ifdef _WIN32 
#include <windows.h> 
#define CLEAR_SCREEN() system("cls") 
#define SLEEP_MS(ms) Sleep(ms) 
#else 
#include <unistd.h> 
#define CLEAR_SCREEN() system("clear") 
#define SLEEP_MS(ms) usleep((ms) * 1000) 
#endif 
//=============== CONSTANTS AND DEFINITIONS ===============// 
#define ARRAY_SIZE 20 
#define DELAY_MS 100 
// Colors for visualization 
#ifdef _WIN32 
#define ANSI_COLOR_RED     "" 
#define ANSI_COLOR_GREEN   "" 
#define ANSI_COLOR_YELLOW  "" 
#define ANSI_COLOR_RESET   "" 
#else 
#define ANSI_COLOR_RED     "\x1b[31m" 
#define ANSI_COLOR_GREEN   "\x1b[32m" 
#define ANSI_COLOR_YELLOW  "\x1b[33m" 
#define ANSI_COLOR_RESET   "\x1b[0m" 
#endif                                                                                                                                                               // A* Pathfinding constants 
#define GRID_SIZE 10 
#define WALL 'X' 
#define PATH '.' 
#define START 'S' 
#define END 'E' 
#define VISITED 'o' 
//=============== DATA STRUCTURES ===============// 
typedef struct Node { 
int x, y; 
int f, g, h; 
struct Node* parent; 
} Node; 
typedef struct { 
Node* nodes; 
int size; 
} NodeList; 
//=============== FUNCTION DECLARATIONS ===============// 
// Menu Functions 
void print_menu(void); 
void run_quicksort(void); 
void run_pathfinding(void); 
// Quicksort Functions 
void swap(int* a, int* b); 
void visualize_array(int arr[], int size, int pivot, int i, int j); 
int partition(int arr[], int low, int high)                                                                                                            void quicksort(int arr[], int low, int high); 
// Pathfinding Functions 
void initialize_grid(char grid[GRID_SIZE][GRID_SIZE]); 
void print_grid(char grid[GRID_SIZE][GRID_SIZE]); 
int heuristic(int x1, int y1, int x2, int y2); 
void find_path(char grid[GRID_SIZE][GRID_SIZE]); 
//=============== MENU FUNCTIONS ===============// 
void print_menu() { 
CLEAR_SCREEN(); 
printf("\n=== Algorithm Visualization Menu ===\n"); 
printf("1. Quicksort Visualization\n"); 
printf("2. A* Pathfinding\n"); 
printf("3. Exit\n"); 
printf("\nEnter your choice (1-3): "); 
} 
//=============== QUICKSORT IMPLEMENTATION ===============// 
void swap(int* a, int* b) { 
int temp = *a; 
*a = *b; 
*b = temp; 
} 
void visualize_array(int arr[], int size, int pivot, int i, int j) { 
CLEAR_SCREEN(); 
for (int k = 0; k < size; k++) { 
if (k == pivot) 
printf(ANSI_COLOR_YELLOW "%3d " ANSI_COLOR_RESET, arr[k]); 
else if (k == i)                                                                                                                                                       printf(ANSI_COLOR_RED "%3d " ANSI_COLOR_RESET, arr[k]); 
        else if (k == j) 
            printf(ANSI_COLOR_GREEN "%3d " ANSI_COLOR_RESET, arr[k]); 
        else 
            printf("%3d ", arr[k]); 
    } 
    printf("\n"); 
     
    // Visual bars 
    for (int k = 0; k < size; k++) { 
        if (k == pivot) 
            printf(ANSI_COLOR_YELLOW); 
        else if (k == i) 
            printf(ANSI_COLOR_RED); 
        else if (k == j) 
            printf(ANSI_COLOR_GREEN); 
             
        for (int m = 0; m < arr[k]; m++) { 
            printf("#");  // Using # instead of █ for better compatibility 
        } 
        printf(ANSI_COLOR_RESET "\n"); 
    } 
    SLEEP_MS(DELAY_MS); 
} 
 
int partition(int arr[], int low, int high) { 
    int pivot = arr[high]; 
    int i = low - 1; 
     
    for (int j = low; j < high; j++) { 
        visualize_array(arr, ARRAY_SIZE, high, i + 1, j);                                                                                                 if (arr[j] < pivot) { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return i + 1; 
} 
 
void quicksort(int arr[], int low, int high) { 
    if (low < high) { 
        int pi = partition(arr, low, high); 
        quicksort(arr, low, pi - 1); 
        quicksort(arr, pi + 1, high); 
    } 
} 
 
void run_quicksort() { 
    int arr[ARRAY_SIZE]; 
    char choice; 
     
    do { 
        CLEAR_SCREEN(); 
        printf("\n=== Quicksort Visualization ===\n\n"); 
         
        // Generate new random array 
        for (int i = 0; i < ARRAY_SIZE; i++) { 
            arr[i] = rand() % 100; 
        } 
         
        // Display initial array 
        printf("Initial array:\n"); 
        visualize_array(arr, ARRAY_SIZE, -1, -1, -1); 
        SLEEP_MS(DELAY_MS * 2); 
         
        // Sort and visualize 
        quicksort(arr, 0, ARRAY_SIZE - 1); 
         
        printf("\nSorted array:\n"); 
        visualize_array(arr, ARRAY_SIZE, -1, -1, -1); 
         
        printf("\nPress 'r' to run again with new array, any other key to return to menu: "); 
        scanf(" %c", &choice); 
    } while (choice == 'r' || choice == 'R'); 
} 
 
//=============== PATHFINDING IMPLEMENTATION ===============// 
void initialize_grid(char grid[GRID_SIZE][GRID_SIZE]) { 
    for (int i = 0; i < GRID_SIZE; i++) { 
        for (int j = 0; j < GRID_SIZE; j++) { 
            grid[i][j] = PATH; 
        } 
    } 
     
    grid[0][0] = START; 
    grid[GRID_SIZE-1][GRID_SIZE-1] = END; 
     
    for (int i = 0; i < GRID_SIZE * GRID_SIZE / 4; i++) { 
        int x = rand() % GRID_SIZE; 
        int y = rand() % GRID_SIZE; 
        if ((x != 0 || y != 0) && (x != GRID_SIZE-1 || y != GRID_SIZE-1)) {                                                                      grid[y][x] = WALL; 
        } 
    } 
} 
 
void print_grid(char grid[GRID_SIZE][GRID_SIZE]) { 
    CLEAR_SCREEN(); 
    for (int i = 0; i < GRID_SIZE; i++) { 
        for (int j = 0; j < GRID_SIZE; j++) { 
            switch(grid[i][j]) { 
                case WALL: 
                    printf(ANSI_COLOR_RED "# " ANSI_COLOR_RESET); 
                    break; 
                case START: 
                    printf(ANSI_COLOR_GREEN "S " ANSI_COLOR_RESET); 
                    break; 
                case END: 
                    printf(ANSI_COLOR_GREEN "E " ANSI_COLOR_RESET); 
                    break; 
                case VISITED: 
                    printf(ANSI_COLOR_YELLOW "o " ANSI_COLOR_RESET); 
                    break; 
                default: 
                    printf(". "); 
            } 
        } 
        printf("\n"); 
    } 
    SLEEP_MS(DELAY_MS); 
} 
 
int heuristic(int x1, int y1, int x2, int y2) { 
    return abs(x1 - x2) + abs(y1 - y2); 
} 
 
void find_path(char grid[GRID_SIZE][GRID_SIZE]) { 
    NodeList openList = {malloc(GRID_SIZE * GRID_SIZE * sizeof(Node)), 0}; 
    NodeList closedList = {malloc(GRID_SIZE * GRID_SIZE * sizeof(Node)), 0}; 
     
    Node* start = malloc(sizeof(Node)); 
    start->x = 0; 
    start->y = 0; 
    start->f = 0; 
    start->g = 0; 
    start->h = 0; 
    start->parent = NULL; 
     
    openList.nodes[openList.size++] = *start; 
     
    while (openList.size > 0) { 
        int current_index = 0; 
        for (int i = 1; i < openList.size; i++) { 
            if (openList.nodes[i].f < openList.nodes[current_index].f) { 
                current_index = i; 
            } 
        } 
         
        Node current = openList.nodes[current_index]; 
         
        if (current.x == GRID_SIZE-1 && current.y == GRID_SIZE-1) { 
            Node* path_node = malloc(sizeof(Node)); 
            memcpy(path_node, &current, sizeof(Node));                                                                                             
            while (path_node != NULL) { 
                if (grid[path_node->y][path_node->x] != START &&  
                    grid[path_node->y][path_node->x] != END) { 
                    grid[path_node->y][path_node->x] = VISITED; 
                } 
                Node* temp = path_node; 
                path_node = path_node->parent; 
                free(temp); 
                print_grid(grid); 
            } 
            free(start); 
            free(openList.nodes); 
            free(closedList.nodes); 
            return; 
        } 
         
        openList.nodes[current_index] = openList.nodes[--openList.size]; 
        closedList.nodes[closedList.size++] = current; 
         
        int dx[] = {0, 0, 1, -1}; 
        int dy[] = {1, -1, 0, 0}; 
         
        for (int i = 0; i < 4; i++) { 
            int new_x = current.x + dx[i]; 
            int new_y = current.y + dy[i]; 
             
            if (new_x >= 0 && new_x < GRID_SIZE && new_y >= 0 && new_y < GRID_SIZE &&  
                grid[new_y][new_x] != WALL) { 
                 
                Node neighbor = {new_x, new_y, 0,  
                               current.g + 1,  
                               heuristic(new_x, new_y, GRID_SIZE-1, GRID_SIZE-1), 
                               NULL}; 
                neighbor.f = neighbor.g + neighbor.h; 
                 
                int in_closed = 0; 
                for (int j = 0; j < closedList.size; j++) { 
                    if (closedList.nodes[j].x == new_x && closedList.nodes[j].y == new_y) { 
                        in_closed = 1; 
                        break; 
                    } 
                } 
                if (in_closed) continue; 
                 
                int in_open = 0; 
                for (int j = 0; j < openList.size; j++) { 
                    if (openList.nodes[j].x == new_x && openList.nodes[j].y == new_y) { 
                        in_open = 1; 
                        if (neighbor.g < openList.nodes[j].g) { 
                            openList.nodes[j] = neighbor; 
                        } 
                        break; 
                    } 
                } 
                 
                if (!in_open) { 
                    openList.nodes[openList.size++] = neighbor; 
                } 
            } 
        } 
               if (grid[current.y][current.x] != START && grid[current.y][current.x] != END) { 
            grid[current.y][current.x] = VISITED; 
        } 
        print_grid(grid); 
    } 
     
    free(start); 
    free(openList.nodes); 
    free(closedList.nodes); 
    printf("No path found!\n"); 
} 
 
void run_pathfinding() { 
    char grid[GRID_SIZE][GRID_SIZE]; 
    char choice; 
     
    do { 
        CLEAR_SCREEN(); 
        printf("\n=== A* Pathfinding Visualization ===\n\n"); 
         
        initialize_grid(grid); 
        print_grid(grid); 
        printf("\nFinding path...\n\n"); 
        find_path(grid); 
         
        printf("\nPress 'r' to run again with new maze, any other key to return to menu: "); 
        scanf(" %c", &choice); 
    } while (choice == 'r' || choice == 'R'); 
} 
 
//=============== MAIN FUNCTION ===============// 
int main() { 
    int choice; 
    srand((unsigned int)time(NULL)); 
     
    while (1) { 
        print_menu(); 
         
        if (scanf("%d", &choice) != 1) { 
            printf("Invalid input. Please enter a number.\n"); 
            while (getchar() != '\n'); // Clear input buffer 
            SLEEP_MS(1000); 
            continue; 
        } 
         
        switch (choice) { 
            case 1: 
                run_quicksort(); 
                break; 
            case 2: 
                run_pathfinding(); 
                break; 
            case 3: 
                printf("\nExiting program...\n"); 
                return 0; 
            default: 
                printf("Invalid choice. Please enter 1-3.\n"); 
                SLEEP_MS(1000); 
        } 
    } 
     
    return 0;
}