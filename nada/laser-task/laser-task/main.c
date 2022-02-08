//
//  main.c
//  laser-task
//
//  Created by Igor Peric on 26/12/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char a[100][100]; // input matrix
int v[100][100][4]; // visited [x][y][direction]
int n, m, i, j, k;

int dX[4] = { -1, 1, 0, 0 };
int dY[4] = { 0, 0, -1, 1 };

typedef enum direction {
    up = 0,
    down = 1,
    left = 2,
    right = 3
} direction_t;

typedef struct node_item {
    int row;
    int column;
    direction_t direction; // direction in which light ray is traveling
    int mirrors; // current mirrors used until now
} node_item_t;


// determines a resulting direction based on mirror type
direction_t reflect(char mirror, node_item_t *item) {
    if (mirror == '\\') {
        switch (item->direction) {
            case down:
                return right;
                break;
            case up:
                return left;
            case left:
                return up;
            case right:
                return down;
                
            default:
                return 0;
                break;
        }
    } else {
        switch (item->direction) {
            case down:
                return left;
                break;
            case up:
                return right;
            case left:
                return down;
            case right:
                return up;
                
            default:
                return 0;
                break;
        }
    }
    return 0;
};


// since we can't use STL queue...
typedef struct node {
   node_item_t *val;
   struct node *next;
} node_t;

void enqueue(node_t **head, node_item_t *val) {
   node_t *new_node = malloc(sizeof(node_t));
   if (!new_node) return;

   new_node->val = val;
   new_node->next = *head;

   *head = new_node;
}

node_item_t* dequeue(node_t **head) {
   node_t *current, *prev = NULL;
    node_item_t* retval = NULL;

   if (*head == NULL) return NULL;

   current = *head;
   while (current->next != NULL) {
      prev = current;
      current = current->next;
   }

   retval = current->val;
   free(current);

   if (prev)
      prev->next = NULL;
   else
      *head = NULL;

   return retval;
}
// end of the STL queue implementation

bool ok(int x, int y, direction_t direction) {
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    if (a[x][y] == '#') return false;
    if (v[x][y][direction] > -1) return false;
    return true;
}

node_t *queue = NULL; // BFS queue
node_item_t *cell = NULL; // cell currently being visited

// function to explore a new cell, moving from the cell (first param), towards explore_direction
// boolean indicates if a new mirror is added to the current cell
void explore_cell(node_item_t *cell, direction_t explore_direction, bool new_mirror_added) {
    int newX = cell->row + dX[explore_direction];
    int newY = cell->column + dY[explore_direction];
    bool new_cell_is_valid = ok(newX, newY, explore_direction);
    if (new_cell_is_valid) {
        node_item_t *next_point = malloc(sizeof(node_item_t));
        next_point->row = cell->row + dX[explore_direction];
        next_point->column = cell->column + dY[explore_direction];
        next_point->direction = explore_direction;
        
        // increase the mirror count if needed
        next_point->mirrors = cell->mirrors + new_mirror_added;
        
        // mark the new cell as visited
        v[next_point->row][next_point->column][cell->direction] = next_point->mirrors;
        
        // add it to BFS queue
        enqueue(&queue, next_point);
    }
}

int main(int argc, const char * argv[]) {
    
    node_t *exit_points = NULL;

    scanf("%d%d", &n, &m);
    for (i=0;i<n;i++) {
        getchar(); // skip \n char
        for (j=0;j<m;j++) {
            scanf("%c", &a[i][j]);
            if (a[i][j] == '.' && (i == 0 || i == n-1 || j == 0 || j == m-1)) {
                node_item_t *exit_point = malloc(sizeof(node_item_t));
                exit_point->row = i;
                exit_point->column = j;
                exit_point->mirrors = 0;
                if (i == 0) exit_point->direction = down;
                if (i == n-1) exit_point->direction = up;
                if (j == 0) exit_point->direction = right;
                if (j == m-1) exit_point->direction = left;
                
                enqueue(&exit_points, exit_point);
            }
            for (k=0;k<4;k++) v[i][j][k] = -1; // mark as not visited yet
        }
    }
    
    node_item_t *start = dequeue(&exit_points);
    node_item_t *end = dequeue(&exit_points);
    
    printf("\nStart coordinates:\t%d %d\nExit coordinates:\t%d %d\n", start->row, start->column, end->row, end->column);
    
    // start BFS
    
    enqueue(&queue, start);
    while (1) {
        
        cell = dequeue(&queue);
        
        // no solution?
        if (cell == NULL) {
            printf("-1\n");
            return 0;
        }
        
        // found solution?
        if (cell->row == end->row && cell->column == end->column) {
            printf("%d\n", cell->mirrors);
            return 0;
        }
        
        // mark as visited
        v[cell->row][cell->column][cell->direction] = cell->mirrors;
        
        if (a[cell->row][cell->column] != '.') {

            // cell contains a mirror, obey the reflection
            explore_cell(cell, reflect(a[cell->row][cell->column], cell), false);
            
        } else {
            
            // cell is empty, try all 3 possible cases
            
            // case 1: try letting the ray pass through without adding a mirror
            explore_cell(cell, cell->direction, false);
            
            // case 2: try putting the top_left mirror
            explore_cell(cell, reflect('\\', cell), true);
            
            // case 3: try putting the bottom_left mirror
            explore_cell(cell, reflect('/', cell), true);
        }
    }
    
    return 0;
}
