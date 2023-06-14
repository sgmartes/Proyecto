
#include "DLL.h"
#include <stdio.h>
// DOCUMENTACIÓN
/**
 *@brief (que hace)
 *@param (que necesita)
 *@return (que devuelve)
 **/

void merge(int *array, int first, int last, int *aux)
{
  // Declaracion de variables
  int mid = (first + last) / 2;
  int x0 = first;
  int x1 = mid;
  int x2 = mid + 1;
  int x3 = last;
  int index = first;

  while (x0 <= x1 && x2 <= x3)
  {
    if (array[x0] > array[x2])
    {
      aux[index] = array[x0];
      ++index;
      ++x0;
    }
    else
    {
      aux[index] = array[x2];
      ++index;
      ++x2;
    }
  }

  while (x0 <= x1)
  {
    aux[index] = array[x0];
    ++index;
    ++x0;
  }
  while (x2 <= x3)
  {
    aux[index] = array[x2];
    ++index;
    ++x2;
  }

  for (int i = 0; i <= last; ++i)
  {
    array[i] = aux[i];
  }
}

void merge_sort(int *array, int first, int last, int *aux)
{
  if (first < last)
  {
    // Dividir el problema en subproblemas
    int mid = (first + last) / 2;

    // Resolver el problema de manera recursiva hasta llegar a una solucion posible o trivial
    merge_sort(array, first, mid, aux);
    merge_sort(array, mid + 1, last, aux);

    // Fusion de resultados parciales
    merge(array, first, last, aux);
  }
}

/**
 *@brief
 *@param
 *@return
 **/

// FUNCIONES DLL-------------------------------------------------------------------------------------------

static Node *new_node(Data *task)
{
  Node *n = (Node *)malloc(sizeof(Node));
  if (n != NULL)
  {
    strncpy((n->task).name, task->name, SIZE);
    (n->task).time = task->time;
    (n->task).index = task->index;
    (n->task).state = task->state;
    n->next = NULL;
    n->prev = NULL;
  }
  return n;
}

/**
 * @brief Crea una lista doblemente enlazada
 *
 * @return Una referencia a la nueva lista
 * @post Una lista existente en el heap
 */
DLL *DLL_New()
{
  DLL *list = (DLL *)malloc(sizeof(DLL));
  if (list)
  {
    list->first = list->last = list->cursor = NULL;
    list->len = 0;
  }
  return list;
}

/**
 * @brief Inserta un elemento en el fondo de la lista.
 *
 * @param this Una lista.
 * @param item El elemento a insertar
 */
void DLL_Push_back(DLL *this, Data *task)
{
  assert(this);
  Node *n = new_node(task);
  assert(n);
  if (this->first != NULL) // caso general
  {
    this->last->next = n;
    n->prev = this->last;
    this->last = n;
  }
  else // la lista está vacía
  {
    this->first = this->last = this->cursor = n;
  }
  ++this->len;
  printf("Se agrego la tarea\n");
}

/**
 * @brief Borra el elemento al cual apunta el cursor y después se mueve a la derecha
 *
 * @param Una lista
 */
void DLL_Erase(DLL *this)
{
  assert(this);
  assert(this->cursor);
  if (this->cursor == this->first)
  {
    DLL_Pop_front(this);
    this->cursor = this->first;
  }
  else if (this->cursor == this->last)
  {
    DLL_Pop_back(this);
    this->cursor = this->last;
  }
  else
  {
    Node *left = this->cursor->prev;
    Node *right = this->cursor->next;
    free(this->cursor);
    left->next = right;
    right->prev = left;
    this->cursor = right;
    --this->len;
  }
}

/**
 * @brief Devuelve el número actual de elementos en la lista.
 *
 * @param this Una lista.
 *
 * @return Devuelve el número actual de elementos en la lista.
 */
size_t DLL_Len(DLL *this)
{
  assert(this);
  return this->len;
}

/**
 * @brief Destruye una lista.
 *
 * @param this Una lista.
 */
void DLL_Delete(DLL **this)
{
  assert(*this);
  if (!DLL_IsEmpty(*this))
  {
    DLL_MakeEmpty(*this);
  }
  free(*this);
  *this = NULL;
}

/**
 * @brief Elimina todos los elementos de la lista sin eliminar la lista.
 *
 * @param this Una lista
 */
void DLL_MakeEmpty(DLL *this)
{
  assert(this);
  assert(this->len > 0);
  while (!DLL_IsEmpty(this))
  {
    DLL_Pop_back(this);
  }
  this->first = this->last = this->cursor = NULL;
}

/**
 * @brief Elimina el elemento al fondo de la lista.
 *
 * @param this Referencia a una lista.
 *
 * @post El cursor se mantiene en la posición en la que estaba cuando entró la
 * función.
 */
void DLL_Pop_back(DLL *this)
{
  assert(this);
  assert(this->len > 0);
  // ERR: no se puede borrar nada de una lista vacía

  if (this->last != this->first) // también funciona: if( this->len > 1 ){...}
  {
    Node *left = this->last->prev;
    free(this->last);
    left->next = NULL;
    this->last = left;
    --this->len;
  }
  else
  {
    free(this->last);
    this->first = this->last = this->cursor = NULL;
    this->len = 0;
  }
}

/**
 * @brief Indica si la lista está vacía.
 *
 * @param this Referencia a una lista.
 *
 * @return true si la lista está vacía; false en caso contrario.
 */
bool DLL_IsEmpty(DLL *this)
{
  assert(this);
  return this->first == NULL;
}

/**
 * @brief Elimina el elemento al frente de la lista.
 *
 * @param this Referencia a una lista.
 *
 * @post El cursor se mantiene en la posición en la que estaba cuando entró la
 * función.
 */
void DLL_Pop_front(DLL *this)
{
  assert(this);
  assert(this->len);
  if (this->first != this->last) // también funciona: if( this->len > 1 ){...}
  {
    Node *right = this->first->next;
    free(this->first);
    right->prev = NULL;
    this->first = right;
    --this->len;
  }
  else
  {
    free(this->first);
    this->first = this->last = this->cursor = NULL;
    this->len = 0;
  }
}

/**
 * @brief Coloca al cursor al inicio de la lista.
 *
 * @param this Una referencia a la lista de trabajo
 */
void DLL_Cursor_front(DLL *this)
{
  assert(this->first);
  this->cursor = this->first;
}

/**
 * @brief Coloca al cursor al final de la lista.
 *
 * @param this Una referencia a la lista de trabajo
 */
void DLL_Cursor_back(DLL *this)
{
  assert(this->last);
  this->cursor = this->last;
}

/**
 * @brief Mueve al cursor al siguiente elemento a la derecha.
 *
 * @param this Una lista.
 */
void DLL_Cursor_next(DLL *this)
{
  if (this->cursor != NULL)
  {
    this->cursor = this->cursor->next;
  }
}

/**
 * @brief Mueve al cursor al siguiente elemento a la izquierda.
 *
 * @param this Una lista.
 */
void DLL_Cursor_prev(DLL *this)
{
  assert(this->cursor != NULL);

  Node *left = this->cursor->prev;
  this->cursor = left;
}

/**
 * @brief Indica cuando el cursor llega al final de la lista.
 *
 * @param Una lista
 *
 * @return Un valor booleano si el cursor está al final de la lista.
 */
bool DLL_Cursor_end(DLL *this)
{
  return this->cursor == NULL;
}

// FUNCIONES QUE SE OCUPAN PARA LAS TAREAS-----------------------------------------------------------------------------------------

/**
 * @brief Recorre la lista y busca la llave
 *
 * @param Una lista
 * @param Valor a buscar
 *
 * @return Un entero que indica en donde está la llave
 */
int binary_search(DLL *this, size_t key)
{
  DLL_Cursor_front(this);
  size_t x0 = ((this->cursor)->task).index; // 1
  DLL_Cursor_back(this);
  size_t x1 = ((this->cursor)->task).index; // 5

  while (x0 <= x1)
  {
    DLL_Cursor_front(this);
    size_t center = (x0 + x1) / 2; // 3
    for (size_t i = 1; i < center; i++)
    {
      DLL_Cursor_next(this);
    }
    if ((this->cursor->task).index == key)
    {
      return center;
    }
    else if (x1 == x0) // queda un elemento y no fue key
    {
      return -1;
    }
    else if (key < (this->cursor->task).index)
    {
      x1 = center - 1;
    }
    else
    {
      x0 = center + 1;
    }
  }
  return -1;
}

/**
 * @brief Convierte estate(que es una constante simbólica)  a una palabra de tipo char
 *
 * @param Estado: (0,1)
 *
 * @return El estado correspondiente en forma de palabra
 */
const char *Get_state(eState state)
{
  switch (state)
  {
  case PENDING:
    return "Pending";
  case COMPLETED:
    return "Completed";
  }
}

/**
 * @brief Crea una tarea
 *
 * @param Una lista
 */
void Add_task(DLL *this)
{
  getchar();
  Data Task;
  printf("\nTask name: ");
  fgets(Task.name, SIZE, stdin);
  printf("In how many minutes do you think you´ll finish this task?: ");
  scanf("%ld", &Task.time);
  Task.state = PENDING;
  Task.index = (this->len) + 1;
  DLL_Push_back(this, &Task);
}

/**
 * @brief Muestra todas las tareas
 *
 * @param Una lista
 */
void Show_tasks(DLL *this)
{
  assert(this);
  if (DLL_IsEmpty(this))
  {
    printf("\nEmpty list. Nothing to show.\n");
  }
  else
  {
    printf("\nShowing List\n\n");
    for (DLL_Cursor_front(this); !DLL_Cursor_end(this); DLL_Cursor_next(this))
    {
      // Elimina salto de linea de fgets
      (this->cursor->task).name[strcspn((this->cursor->task).name, "\n")] = 0;
      if ((this->cursor->task).state==PENDING)
        {
          printf("%ld Name: %s\t\tEstimated time to complete: %ld min.\t\tState: " ROJO "%s" RESET "\n",
                 (this->cursor->task).index, (this->cursor->task).name, (this->cursor->task).time,
                 Get_state((this->cursor->task).state));
        }
      else
      {
        printf("%ld Name: %s\t\tEstimated time to complete: %ld min.\t\tState: " VERDE "%s" RESET "\n",
                 (this->cursor->task).index, (this->cursor->task).name, (this->cursor->task).time,
                 Get_state((this->cursor->task).state));
      }
    }
  }
}

/**
 * @brief Borra la tarea indicada por el usuario
 *
 * @param Una lista
 */
void Delete_task(DLL *this)
{
  assert(this);
  size_t key = 0;
  // 1. Mostrar lista
  Show_tasks(this);
  if (this->len > 0)
  {
    // 2. ¿Cuál tarea desea eliminar?
    printf("\nWhat task would you like to delete?: ");

    // 3. *Introduce el índice
    scanf("%ld", &key);
    // 4. Recorriendo lista y borra esa tarea
    int position = binary_search(this, key);
    if (position != -1)
    {
      DLL_Cursor_front(this);
      for (size_t i = 1; i < position; ++i)
      {
        DLL_Cursor_next(this);
      }
      DLL_Erase(this);
      // Colocandonos en donde apartir de ahí vamos a cambiar el índice
      DLL_Cursor_front(this);
      for (size_t i = 1; i < position; ++i)
      {
        DLL_Cursor_next(this);
      }
      // Hasta que no acabe te vamos a cambiar el índice
      while (!DLL_Cursor_end(this))
      {
        --(this->cursor->task).index;
        DLL_Cursor_next(this);
      }
    }
    // 5. Muestra la lista sin esa tarea
    Show_tasks(this);
  }
  else
  {
    // No hay ninguna tarea para eliminar
    printf("\nThere is no tasks to delete");
  }
}

/**
 * @brief Borra todas las tareas
 *
 * @param Una lista
 */
void Empty_tasks(DLL *this)
{
  Show_tasks(this);
  DLL_MakeEmpty(this);
  Show_tasks(this);
}

/**
 * @brief Cambia el estado de una tarea a completada
 *
 * @param Una lista
 */
void Complete_task(DLL *this)
{
  if (!DLL_IsEmpty(this))
  {
    size_t num = 0;
    Show_tasks(this);
    printf("\nWhat task do you want to complete?: ");
    scanf("%ld", &num);
    int position = binary_search(this, num);
    DLL_Cursor_front(this);
    for (size_t i = 1; i < position; ++i)
    {
      DLL_Cursor_next(this);
    }
    (this->cursor->task).state = COMPLETED;
    Show_tasks(this);
  }
  else
  {
    printf("\nEmpty List. Nothing to show");
  }
}

/**
 * @brief Cambia el estado de una tarea a Pendiente.
 *
 * @param Una lista
 */
void Pending_task(DLL *this)
{
  if (!DLL_IsEmpty(this))
  {
    size_t num = 0;
    Show_tasks(this);
    printf("\nWhat task do you want to mark as pending?: ");
    scanf("%ld", &num);
    int position = binary_search(this, num);
    DLL_Cursor_front(this);
    for (size_t i = 1; i < position; ++i)
    {
      DLL_Cursor_next(this);
    }
    (this->cursor->task).state = PENDING;
    Show_tasks(this);
  }
  else
  {
    printf("\nEmpty List. Nothing to show");
  }
}

/**
 * @brief Muestra las tareas completadas
 *
 * @param Una lista
 */
void Show_Completed_t(DLL *this)
{
  if (!DLL_IsEmpty(this))
  {
    size_t completed_t = 0;
    printf("\n");
    for (DLL_Cursor_front(this); !DLL_Cursor_end(this); DLL_Cursor_next(this))
    {
      if ((this->cursor->task).state == COMPLETED)
      {
        ++completed_t;
        (this->cursor->task).name[strcspn((this->cursor->task).name, "\n")] = 0;
        printf("Name: %s\t\tEstimated time to complete: %ld min.\n",
               (this->cursor->task).name, (this->cursor->task).time);
      }
    }
    if (completed_t == 0)
    {
      printf("\nNo tasks completed");
    }
  }
  else
  {
    printf("\nEmpty List. Nothing to show");
  }
}

/**
 * @brief Muestra las tareas pendientes
 *
 * @param Una lista
 */
void Show_Pending_t(DLL *this)
{
  if (!DLL_IsEmpty(this))
  {
    size_t pending_t = 0;
    printf("\n");
    for (DLL_Cursor_front(this); !DLL_Cursor_end(this); DLL_Cursor_next(this))
    {
      if ((this->cursor->task).state == PENDING)
      {
        ++pending_t;
        (this->cursor->task).name[strcspn((this->cursor->task).name, "\n")] = 0;
        printf("Name: %s\t\tEstimated time to complete: %ld min.\n",
               (this->cursor->task).name, (this->cursor->task).time);
      }
    }
    if (pending_t == 0)
    {
      printf("No pending tasks");
    }
  }
  else
  {
    printf("\nEmpty List. Nothing to show");
  }
}

/**
 * @brief Modifica el nombre y el tiempo estimado de una tarea
 *
 * @param Una lista
 */
void Modify_task(DLL *this)
{
  if (!DLL_IsEmpty(this))
  {
    size_t num = 0;
    // 1. Muestra la lista
    Show_tasks(this);
    printf("\nWhat task would you like to modify?: ");
    scanf("%ld", &num);
    int position = binary_search(this, num);
    // Moviéndonos en la lista
    if (position != -1)
    {
      DLL_Cursor_front(this);
      for (size_t i = 1; i < position; ++i)
      {
        DLL_Cursor_next(this);
      }
      getchar();
      printf("\nTask name: ");
      fgets((this->cursor->task).name, SIZE, stdin);
      printf("In how many minutes do you think you´ll finish this task?: ");
      scanf("%ld", &(this->cursor->task).time);
    }

    // Muestra por ultimo la lista ya modificada
    Show_tasks(this);
  }
  else
  {
    printf("\nEmpty List. Nothing to show");
  }
}

void Sort_tasks(DLL *this, int *sort, int *aux)
{
  // int sort[DLL_Len(this)];

  if (DLL_IsEmpty(this))
  {
    printf("\nEmpty list. Nothing to show.\n");
    sort[0] = -1;
    return;
  }
  else
  {
    int j = 0;
    DLL_Cursor_front(this);
    while (this->cursor <= this->last && this->cursor != NULL)
    {
      sort[j] = this->cursor->task.time;
      j++;
      DLL_Cursor_next(this);
    }
    int first = 0, last = DLL_Len(this) - 1;

    printf("\n[");
    for (int i = 0; i < DLL_Len(this); ++i)
    {
      printf("%d, ", sort[i]);
    }
    printf("]\n\n");

    merge_sort(sort, first, last, aux); // Ordena de menor a mayor tiempo
  }

  printf("\n[");
  for (int i = 0; i < DLL_Len(this); ++i)
  {
    printf("%d, ", sort[i]);
  }
  printf("]\n\n");
  // return;
}

bool time_bt(DLL *this, int *list, int *aux, int *index, int time, int first, int last, int *acum)
{
  bool succes = false;
  bool pending_task = false;
  for (int i = first; i <= last; ++i)
  {
    pending_task = false;
    for (DLL_Cursor_front(this); !DLL_Cursor_end(this); DLL_Cursor_next(this))
    {
      if ((this->cursor->task).time == list[i])
      {
        if ((this->cursor->task).state == PENDING)
        {
          pending_task = true;
        }
      }
    }
    if ((*acum + list[i]) <= time && pending_task == true)
    {
      aux[*index] = list[i];
      ++*index;
      *acum += list[i];
      succes = true;
    }
  }
  return (succes);
}

void print_tasks_on_time(DLL *this, int *list, int index)
{
  for (int i = 0; i < index; ++i)
  {
    for (DLL_Cursor_front(this); !DLL_Cursor_end(this); DLL_Cursor_next(this))
    {
      if ((this->cursor->task).time == list[i])
      {
        (this->cursor->task).name[strcspn((this->cursor->task).name, "\n")] = 0;
        printf("%ld Name: %s\t\tEstimated time to complete: %ld min.\n",
               (this->cursor->task).index, (this->cursor->task).name, (this->cursor->task).time);
      }
    }
  }
}

void tasks_on_time(DLL *this)
{
  int time = 0;
  printf("How many minutes do you have to complete tasks?: ");
  scanf("%d", &time);
  int sort[DLL_Len(this)];
  int aux[DLL_Len(this)];
  Sort_tasks(this, sort, aux);
  int index = 0;
  int acum = 0;
  if (time_bt(this, sort, aux, &index, time, 0, DLL_Len(this) - 1, &acum))
  {
    printf("You're have enough time to do this tasks:\n");
    print_tasks_on_time(this, aux, index);
  }
  else
  {
    printf("There isn't enough time to do any task\n");
  }
}