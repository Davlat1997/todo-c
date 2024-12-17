#include<stdio.h>
#include<string.h>

typedef struct {
    char title[128];
    char description[512];
    int status;      
} Task;

Task tasks[100]; 
int count = 0;    
int exitt = 1;


void add_task() {
    char arr_title[128], arr_description[512];
    printf("Enter task title: ");

 
    fgets(arr_title, sizeof(arr_title), stdin);
    for (int i = 0; arr_title[i + 1] != '\0'; i++) {
        tasks[count].title[i] = arr_title[i];
    }

    printf("Enter task description: ");
 
    fgets(arr_description, sizeof(arr_description), stdin);
    for (int i = 0; arr_description[i + 1] != '\0'; i++) {
        tasks[count].description[i] = arr_description[i];
    }
   
    tasks[count].status = 0;

    printf("Task added successfully!\n");
    count++;
}


void list_all_tasks() {
    if (count == 0) {
        printf("Buyruqlar mavjud emas. Iltimos avval buyruq kiriting\n");
    } else {
        printf(" ID|        Title|               Description| Status\n");
        printf("----------------------------------------------------------\n");
        for (int i = 0; i < count; i++) {
            if (tasks[i].status != -1) {
                printf("%3d", i + 1);
                printf("| %12s", tasks[i].title);
                printf("| %25s", tasks[i].description);
                if (tasks[i].status == 0) {
                    printf("| bajarilmagan\n");
                } else {
                    printf("| bajarilgan\n");
                }
            }
        }
    }
}


void get_task_by_id() {
    int n, deleted_index;

    printf("Izlayotgan vazifaning ID raqamini kiriting: ");
    scanf("%d", &n);

    deleted_index = tasks[n - 1].status;
    if ((n - 1 <= count) && (count != 0) && deleted_index != -1) {
        printf("%3d", n);
        printf("| %12s", tasks[n - 1].title);
        printf("| %25s", tasks[n - 1].description);
        if (tasks[n - 1].status == 0) {
            printf("| bajarilmagan\n");
        } else {
            printf("| bajarilgan\n");
        }
    } else {
        printf("Izlanayotgan vazifa mavjud emas\n");
    }
}


void delete_task_by_id() {
    int n;

    printf("O‘chirmoqchi bo‘lgan vazifaning ID raqamini kiriting: ");
    scanf("%d", &n);
    if ((n - 1 <= count) && (count != 0)) {
        if (tasks[n - 1].status != -1) {
            tasks[n - 1].status = -1;
            printf("Task deleted successfully!\n");
        } else {
            printf("Bu ID allaqachon o‘chirilgan\n");
        }
    } else {
        printf("Bunday ID da vazifa kiritilmagan!\nIltimos boshqa ID kiriting.\n");
    }
}


void mark_task_completed() {
    int n;

    printf("Bajarilgan vazifaning ID raqamini kiriting: ");
    scanf("%d", &n);

    if (n - 1 <= count && count != 0) {
        while (tasks[n - 1].status == 1) {
            printf("Bu vazifa bajarilgan!\nIltimos, boshqa vazifa ID sini kiriting: ");
            scanf("%d", &n);
        }
        tasks[n - 1].status = 1;
        printf("Vazifa bajarildi deb belgilandi :)\n");
    } else {
        printf("Bunday ID da vazifa mavjud emas, iltimos boshqa ID ni kiriting!\n");
    }
}


void mark_task_incomplete() {
    int n;

    printf("Bajarilmagan vazifaning ID raqamini kiriting: ");
    scanf("%d", &n);
    if (n - 1 <= count && count != 0) {
        while (tasks[n - 1].status == 0) {
            printf("Bu vazifa shundoq ham bajarilmagan!\nIltimos, boshqa vazifa ID sini kiriting: ");
            scanf("%d", &n);
        }

        tasks[n - 1].status = 0;
        printf("Vazifa bajarilmadi deb belgilandi :(\n");
    } else {
        printf("Bunday ID da vazifa mavjud emas, iltimos boshqa ID ni kiriting!\n");
    }
}


void show_menu(void) {
    printf("To-Do List Menu:\n");
    printf("1. Add Task\n");
    printf("2. List Tasks\n");
    printf("3. Get Task by ID\n");
    printf("4. Delete Task\n");
    printf("5. Mark Task as Completed\n");
    printf("6. Mark Task as Incompleted\n");
    printf("7. Menu ni qayta ko‘rish\n");
    printf("8. Exit\n");
}

int main() {
    printf("To-Do List Menu:\n");
    printf("1. Add Task\n");
    printf("2. List Tasks\n");
    printf("3. Get Task by ID\n");
    printf("4. Delete Task\n");
    printf("5. Mark Task as Completed\n");
    printf("6. Mark Task as Incompleted\n");
    printf("7. Menu ni qayta ko‘rish\n");
    printf("8. Exit\n");

    while (exitt != 8) {
        printf("\nQaysi menu ga murojaat qilishni hohlaysiz: ");
        scanf("%d", &exitt);
        while (getchar() != '\n');  

        switch (exitt) {
            case 1:
                add_task();
                break;
            case 2:
                list_all_tasks();
                break;
            case 3:
                get_task_by_id();
                break;
            case 4:
                delete_task_by_id();
                break;
            case 5:
                mark_task_completed();
                break;
            case 6:
                mark_task_incomplete();
                break;
            case 7:
                show_menu();
                break;
            case 8:
                break;
            default:
                printf("Siz noto‘g‘ri menu tanladingiz!\nIltimos mavjud bo‘lgan menu ni tanlang.\n");
                break;
        }
    }

    printf("Bizni xizmatimizdan foydalanganingiz uchun rahmat :)!\n");
   
}