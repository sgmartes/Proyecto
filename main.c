#include "DLL.h"
#include <stdio.h>

int main()
{
    DLL *list = DLL_New();
    int option = 0;
    do
    {
        system("clear");
        printf("\t\t\tTO DO LIST\n");
        printf("1. Add task\n");                  // Añadir tarea
        printf("2. Delete task\n");               // Borrara tarea
        printf("3. Mark a task as completed \n"); // Marcar tarea como completada
        printf("4. Mark a task as pending \n");
        printf("5. Show Completed Tasks\n");
        printf("6. Show Pending Tasks\n");
        printf("7. Modify a Task\n");
        printf("8. Show Tasks\n"); // rapida de hacer(antes show list)
        printf("9. Sort Tasks by time \n");
        printf("10. Delete all the Tasks\n"); // rapida de hacer
        printf("11. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            system("clear");
            Add_task(list);
            break;
        }
        case 2:
        {
            system("clear");
            Delete_task(list);
            getchar();
            getchar();
            break;
        }
        case 3:
        {
            system("clear");
            Complete_task(list);
            getchar();
            getchar();
            break;
        }
        case 4:
        {
            system("clear");
            Pending_task(list);
            getchar();
            getchar();
            break;
        }
        case 5:
        {
            system("clear");
            Show_Completed_t(list);
            getchar();
            getchar();
            break;
        }
        case 6:
        {
            system("clear");
            Show_Pending_t(list);
            getchar();
            getchar();
            break;
        }
        case 7:
        {
            system("clear");
            Modify_task(list);
            getchar();
            getchar();
            break;
        }
        case 8:
        {
            system("clear");
            Show_tasks(list);
            getchar();
            getchar();
            break;
        }
        case 9:
        {
            // system("clear");
            /*int time = 20;
            int sort[DLL_Len(list)];
            int aux[DLL_Len(list)];
            Sort_tasks(list, sort, aux);
            int index = 0;
            int acum = 0;
            if (time_bt(list,sort, aux, &index, time, 0, DLL_Len(list) - 1, &acum))
            {
                printf("Da tiempo de hacer las siguientes tareas:\n");
                printf("\n[");
                for (int i = 0; i < index; ++i)
                {
                    printf("%d, ", aux[i]);
                }
                printf("]\n\n");
            }
            else{
                printf("No da tiempo de realizar ninguna tarea\n");
            }*/
            system("clear");
            tasks_on_time(list);
            getchar();
            getchar();
            /*int lista[DLL_Len(list)];
            Sort_tasks(list, lista);
            getchar();
            if (lista[0] != -1) {
              for (int i = 0; i < DLL_Len(list); i++) {
                printf("%ld, ", lista[i]);
              }
            }
            getchar();*/
            break;
        }
        case 10:
        {
            system("clear");
            Empty_tasks(list);
            getchar();
            getchar();
            break;
        }
        }

    } while (option != 11);
    system("clear");
    DLL_Delete(&list);
}