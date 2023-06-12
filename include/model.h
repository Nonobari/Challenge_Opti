typedef struct {
    int x;
    int y;
    char type;
} Point;

typedef struct {
    char **tab;
    int n_lignes; /*Nb de lignes*/
    int n_colonnes; /*Nb de colonnes*/
    int n_obstacles; /*Nb de cases occupées par des obstacles*/
    int n_cibles; /*Nb de cases occupées par des cibles*/

} Model;


void load_model(Model *m, char* filename);
void printModel(Model *m);