#ifndef DLL_INC
#define DLL_INC

#include <stdlib.h>
// para malloc and friends y size_t

#include <stdbool.h>
// para bool and friends

#include <assert.h>
// para las aserciones: assert()

#include <stdio.h>

#include <stdlib.h>
#include <string.h>

#define ROJO "\x1b[31m"
#define VERDE "\x1b[32m"
#define AMARILLO "\x1b[33m"
#define AZUL "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define AQUA "\x1b[36m"
#define RESET "\x1b[0m"

#define SIZE 50
// TAD Enumeración, estado:
typedef enum
{
  COMPLETED,
  PENDING
} eState;

// TAD Estructura datos de una tarea
typedef struct
{
  char name[SIZE];
  size_t time; // tiempo estimado en minutos
  eState state;
  size_t index; // num atribuido a esa tarea
} Data;

// TAD Nodo de la DLL
typedef struct Node
{
  Data task;
  struct Node *next;
  struct Node *prev;
} Node;

// TAD DLL
typedef struct
{
  Node *first;
  Node *last;
  Node *cursor;
  size_t len;
} DLL;

// DLL------------------------------------------------------------------------------------------------------
DLL *DLL_New();
void DLL_Delete(DLL **this);
void DLL_MakeEmpty(DLL *this);
bool DLL_IsEmpty(DLL *this);
size_t DLL_Len(DLL *this);
void DLL_Push_back(DLL *this, Data *task);
void DLL_Pop_front(DLL *this);
void DLL_Pop_back(DLL *this);
int DLL_Cursor_Get(DLL *this);
void DLL_Cursor_front(DLL *this);
void DLL_Cursor_back(DLL *this);
void DLL_Cursor_next(DLL *this);
void DLL_Cursor_prev(DLL *this);
bool DLL_Cursor_end(DLL *this);
void DLL_Erase(DLL *this);

// Para Task-----------------------------------------------------------------------------------------------
int binary_search(DLL *this, size_t key);
void Delete_task(DLL *this);
void Add_task(DLL *this);
void Modify_task(DLL *this);
void Show_tasks(DLL *this);
void Empty_tasks(DLL *this);
const char *Get_state(eState state);
void Complete_task(DLL *this);
void Pending_task(DLL *this);
void Show_Completed_t(DLL *this);
void Show_Pending_t(DLL *this);
bool time_bt(DLL *this, int *list, int *aux, int *index, int time, int first, int last, int *acum);
void tasks_on_time(DLL *this);
void print_tasks_on_time(DLL *this, int *list,int index);
// void Sort_tasks(DLL *this);

// Ordenamiento
void Sort_tasks(DLL *this, int *sort, int *aux);
void merge(int *array, int first, int last, int *aux);
void merge_sort(int *array, int first, int last, int *aux);

#endif /* ----- #ifndef DLL_INC  ----- */
