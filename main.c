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
        printf("9. Show which tasks I can do \n");
        printf("10. Delete all the Tasks\n"); // rapida de hacer
        printf("11. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            Add_task(list);
            printf("Press ENTER to continue");
            getchar();
            getchar();
            break;
        }
        case 2:
        {
            Delete_task(list);
            printf("Press ENTER to continue");
            getchar();
            getchar();
            break;
        }
        case 3:
        {
            Complete_task(list);
            printf("Press ENTER to continue");
            getchar();
            getchar();
            break;
        }
        case 4:
        {
            Pending_task(list);
            printf("Press ENTER to continue");
            getchar();
            getchar();
            break;
        }
        case 5:
        {
            Show_Completed_t(list);
            printf("Press ENTER to continue");
            getchar();
            getchar();
            break;
        }
        case 6:
        {
            Show_Pending_t(list);
            printf("Press ENTER to continue");
            getchar();
            getchar();
            break;
        }
        case 7:
        {
            Modify_task(list);
            printf("Press ENTER to continue");
            getchar();
            getchar();
            break;
        }
        case 8:
        {
            Show_tasks(list);
            printf("Press ENTER to continue");
            getchar();
            getchar();
            break;
        }
        case 9:
        {
            tasks_on_time(list);
            printf("Press ENTER to continue");
            getchar();
            getchar();
            break;
        }
        case 10:
        {
            Empty_tasks(list);
            printf("Press ENTER to continue");
            getchar();
            getchar();
            break;
        }
        }

    } while (option != 11);
    DLL_Delete(&list);
}