#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 100 // 최대 100명

typedef struct{
    int id; //학번
    char name[100]; // 이름
    char phoneNum[15]; //전화번호
    int isUsed; // 1이면 현재값 사용중 0이면 비어있음 표시
} Student;

Student database[MAX_DATA];

void insertData(int id, char *name, char *phoneNum){
    for(int i = 0; i < MAX_DATA; i++){
        if(database[i].isUsed && database[i].id == id){
            printf("이미 존재하는 학번입니다. 다른 학번을 입력해주세요.\n");
            return;
        }
    }

    for(int i = 0; i < MAX_DATA; i++){
        if(!database[i].isUsed){
            database[i].id = id;
            strcpy(database[i].name, name);
            strcpy(database[i].phoneNum, phoneNum);
            database[i].isUsed = 1;
            printf("학번:%d 이름:%s 연락처:%s 삽입됨\n", id, name, phoneNum);
            return;
        }
    }
    printf("데이터베이스가 가득 찼습니다\n");
}


void deleteData(int id){
    for(int i = 0; i < MAX_DATA; i++){
        if(database[i].isUsed && database[i].id == id){
            database[i].isUsed = 0;
            printf("학번:%d 이름:%s 연락처:%s 삭제되었습니다.\n", id, database[i].name, database[i].phoneNum);
            return;
        }
    }
    printf("데이터를 찾을 수 없습니다.\n");
}

void updateData(int id, char *newname, char *phoneNum){
    for(int i = 0; i < MAX_DATA; i++){
        if(database[i].isUsed && database[i].id == id){
            strcpy(database[i].name, newname);
            printf("학번:%d 이름:%s 연락처:%s 수정됨\n", id, newname, phoneNum);
            return;
        }
    }
}

void searchData(int id){
    for(int i = 0; i < MAX_DATA; i++){
        if(database[i].isUsed && database[i].id == id){
            printf("학번:%d 이름:%s 연락처:%s\n", id, database[i].name, database[i].phoneNum);
            return;
        }
    }
    printf("데이터를 찾을 수 없습니다.\n");
}

void allsearchData(){
    for(int i = 0; i < MAX_DATA; i++){
        if(database[i].isUsed){
            printf("학번:%d 이름:%s 연락처:%s\n", database[i].id, database[i].name,database[i].phoneNum);
        }
    }
    return;
}

void saveDataToFile() {
    FILE *file = fopen("student_data.txt", "a");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    for (int i = 0; i < MAX_DATA; i++) {
        if (database[i].isUsed) {
            fprintf(file, "%d %s %s\n", database[i].id, database[i].name, database[i].phoneNum);
        }
    }

    fclose(file);
    printf("데이터를 파일로 저장했습니다.\n");
}

void loadDataFromFile() {
    FILE *file = fopen("student_data.txt", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    int id;
    char name[100];
    char phoneNum[15];
    int count = 0;

    while (fscanf(file, "%d %s %s", &id, name, phoneNum) == 3 && count < MAX_DATA) {
        insertData(id, name, phoneNum);
        count++;
    }

    fclose(file);
    printf("데이터를 파일에서 불러왔습니다.\n");
}

int main() {

    int choice;
    int id;
    char name[100];
    char phoneNum[15];

    while (1) {
        printf("\n메뉴\n");
        printf("1. 데이터 삽입\n");
        printf("2. 데이터 삭제\n");
        printf("3. 데이터 수정\n");
        printf("4. 데이터 검색\n");
        printf("5. 데이터 전체출력\n");
        printf("6. 데이터를 파일로 저장하기\n");
        printf("7. 파일에서 데이터 불러오기\n");
        printf("8. 프로그램 종료\n");
        printf("선택: ");
        scanf("%d", &choice);
        printf("\n");
        getchar();

        switch (choice) {
            case 1:
                printf("삽입할 학번을 입력해주세요: ");
                scanf("%d", &id);
                getchar();
                printf("삽입할 이름을 입력해주세요: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                printf("삽입할 연락처를 입력해주세요: ");
                fgets(phoneNum, sizeof(phoneNum), stdin); // 전화번호 입력 받기
                phoneNum[strcspn(phoneNum, "\n")] = 0; // 개행 문자 제거
                insertData(id, name, phoneNum);
                break;
            case 2:
                printf("삭제할 학번을 입력해주세요 : ");
                scanf("%d", &id);
                deleteData(id);
                break;
            case 3:
                printf("수정할 학번을 입력해주세요: ");
                scanf("%d", &id);
                getchar();
                printf("이름을 입력해주세요:");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                updateData(id, name, phoneNum);
                break;
            case 4:
                printf("검색할 데이터를 입력해 주세요 : ");
                scanf("%d", &id);
                searchData(id);
                break;
            case 5:
                printf("전체 리스트 출력\n");
                allsearchData();
                break;
            case 6:
                printf("데이터를 파일로 저장합니다.\n");
                saveDataToFile();
                break;
            case 7:
                printf("파일에서 데이터를 불러옵니다.\n");
                loadDataFromFile();
                break;
            case 8:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 선택입니다. 다시 시도 해주세요.");

        } // end of switch
    } // end of while

} // end of main
