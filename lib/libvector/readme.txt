==========================================================================
                        UTILISATION DE LIBVECTOR
==========================================================================


Ne pas oublier de compiler avec -lvector.


====== Fonctions de base ======


  #include <vector.h>

  vector_t*	vecCreate();
  void		vecDelete(vector_t* vector);
  void		vecPushBack(vector_t* vector, T data);
  void		vecPopBack(vector_t*);

vecCreate() et vecDelete() créent et détruisent la liste et son contenu.
vecPushBack() ajoute un élément de type quelconque T à la fin de la liste.
data doit être déréférençable.
vecPopBack() supprime le dernier élément de la liste.


====== Parcourir la liste ======


  typedef int	(*vector_callback_t)(T*);

  void		vecBrowse(vector_t* vector, vector_callback_t callback);

Où T est le type des données ajoutées au vecteur.
La fonction passée en paramètre est appelée pour chaque élément de la liste.
A NE JAMAIS FAIRE : supprimer un noeud en parcourant une liste, c'est le
meilleur moyen de provoquer des read errors voire un segfault.


====== Exemple d'utilisation ======


  #include <stdio.h>
  #include <vector.h>

  typedef struct {
    int a, b;
  } data_t;

  // Données de type T = data_t soit data_t*
  int display(data_t *data)
  {
    printf("(%d, %d)\n", data->a, data->b);
  }

  int main()
  {
    data_t a = {42, 42}, b = {23, 23};
    vector_t* vector = vecCreate();
    vecPushBack(vector, a);
    vecPushBack(vector, b);
    vecBrowse(vector, display);
    vecDelete(vector);
    return 0;
  }


====== Utilisation des handlers ======


Deux handlers sont disponibles pour le moment (notation C++) :

  typedef int		(*vector_callback_t)(T*);

  vector_callback_t	vector_t::onAdd;
  vector_callback_t	vector_t::onRemove;

onAdd est appelée lorsqu'un élément est rajouté à la liste.
onRemove est appelée lorsqu'un élément est retiré de la liste.

Ces handlers sont utiles dans le cas où un traitement spécial est demandé
lors d'un push ou d'un pop de la liste.
Exemple : un module rajoute à une liste une chaîne de caractères qu'il free
immédiatement ensuite. Lors du rajout il va falloir dupliquer la chaîne en
question puis mettre à jour le contenu du vecteur, histoire d'éviter un SEGV.
Cela se fait grâce au handler onAdd. De la même façon, pour éviter les fuites
de mémoire, il est recommandé de libérer le contenu du vecteur en appelant
free() dans onRemove.

Exemple :

  #include <stdlib.h>
  #include <vector.h>

  int onAddHandler(char** data)
  {
    // Duplique la chaîne puis réassigne le pointeur
    *data = strdup(*data);
  }

  int onRemoveHandler(char** data)
  {
    // Fuites de mémoire sinon
    free(*data);
  }

  int main()
  {
    char* a = "Hello", *b = "World !";
    vector_t* vector = vecCreate();
    vector->onAdd = onAddHandler;
    vector->onRemove = onRemoveHandler;
    vecPushBack(vector, a);
    vecPushBack(vector, b);
    // Tout le contenu du vecteur est libéré, aucune fuite de mémoire
    vecDelete(vector);
    return 0;
  }


====== Localisation, suppression ======


Une fonction permet de rechercher un noeud en fonction de son contenu :

  typedef int	(*vector_callback_t)(T*, T*);

  vector_node_t	*vecFind(vector_t*, vector_callback_t, T)

vecFind fonctionne de la même manière que vecBrowse à la différence qu'elle
prend en plus un objet à comparer. Elle retourne le premier noeud répondant
aux critères de recherche ou 0 si aucun résultat n'est trouvé.
La callback permet de comparer les éléments du vecteur avec l'objet passé
en paramètre ; elle doit retourner 1 dans le cas où l'élément répond aux
critères et 0 si ce n'est pas le cas.

La fonction permettant de supprimer n'importe quel noeud est la suivante :

  void		vecRemoveNode(vector_t*, vector_node_t*);

Exemple:

  #include <stdlib.h>
  #include <stdio.h>
  #include <vector.h>

  // Données de type T = char*, on utilise T* soit char**
  int cmp(char** a, char** b)
  {
    // Retourne 1 si les chaînes sont identiques
    return !strcmp(*a, *b);
  }

  int display(char** data)
  {
    printf("%s\n", *data);
  }

  int main()
  {
    char *a = "Hello", *b = "World";
    char *pattern = "World";
    vector_t* vector = vecCreate();
    vecPushBack(vector, a);
    vecPushBack(vector, b);
    printf("Before removal :\n");
    vecBrowse(vector, display);
    // Trouve la première occurence dont les données sont identiques à pattern
    // En utilisant cmp comme fonction de comparaison
    vector_node_t* node = vecFind(vector, cmp, pattern);
    if (!node) // Aucun résultat
      printf("No matching node were found.\n");
    else
      vecRemoveNode(vector, node); // On supprime le noeud en question
    printf("After removal :\n");
    vecBrowse(vector, display);
    vecDelete(vector);
    return 0;
  }
