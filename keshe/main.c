//荆门爱飞客机场起降管理模拟系统
//13. 荆门爱飞客机场飞机起降管理模拟系统
//问题描述：
//假设荆门爱飞客机场现有飞往武汉和北京的两条航线。有如下航班信息：
//每天有荆门飞往武汉的航班，共 8 个班次。
//每天有武汉飞往荆门的航班，共 8 个班次。
//星期一、星期三、星期五、星期天有荆门飞往北京的航班，每天共 2 个班次。
//星期二、星期四、星期六、星期天有北京飞往荆门的航班，每天共 2 个班次。
//要求：
//自行合理设计每个班次起飞和降落时间，保证每个时间段只能有一架飞机起飞或降落；
//分别输出每星期一到星期天所有的航班起飞和降落信息；
//实时查询当天所有航班信息，并输出显示；
//能实时查询当天截止当前时间共起飞航班次数和降落航班次数，并输出显示；
//能实时查询从当前时间到未来两小时内即将起飞和降落的航班信息，并输出显示。
#include <stdio.h>
#include <stdlib.h>
#include "time.h"


typedef struct hangbandata {
    int num;      // 航班号
    int weekday;    // 星期几
    int qifeitime;  // 起飞时间
    int jiangluotime;   //降落时间
    int island; //是否降落，1为未起飞，2为起飞中，3为已降落，默认为1
    int where;  // 1为荆门飞北京 0为北京飞荆门
} * flight;

typedef struct Arraylist{
    flight * array;
    int capacity;
    int size;
} * List;



_Bool initList(List list){
    list->array =    (flight *)malloc(sizeof(flight) * 10);
    if(list->array == NULL) return 0;
    list->capacity = 10;
    list->size = 0;
    return 1;
}

_Bool insertList(List list, flight data, int index){
    if(index < 1 || index > list->size + 1) return 0;
    if(list->size == list->capacity) {
        int newCapacity = list->capacity + (list->capacity >> 1);
        flight * newArray = (flight *)realloc(list->array, newCapacity * sizeof(flight));
        if(newArray == NULL) return 0;
        list->array = newArray;
        list->capacity = newCapacity;
    }
    int i;
    for (i = list->size; i > index - 1; i--)
        list->array[i] = list->array[i - 1];
    list->array[index - 1] = data;
    list->size++;
    return 1;
}

//查询当天所有航班信息
void searchtoday(List list){
    int i;
    for (i = 0; i < list->size; i++)
        if(list->array[i]->num == num) {
            printf("航班号：%d\n", list->array[i]->num);

            return;
        }
    printf("未找到\n");
}

int main(void) {
    List list;
    initList(&list);
    int choice;
    while (1){
        system("cls");
        flight data = (flight)malloc(sizeof(struct hangbandata));
        printf("荆门爱飞客机场起降管理模拟系统\n");
        printf("1.查询当天所有航班信息\n");
        printf("2.查询航班次数\n");
        printf("3.查询即将起飞和降落的航班信息\n");
        printf("4.新建航班信息\n");
        printf("5.删除航班信息\n");
        printf("6.修改航班信息\n");
        printf("0.退出\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:

            case 4:
                printf("请输入航班号：");
                scanf("%d", &data->num);
                printf("请输入星期几：");
                scanf("%d", &data->weekday);
                printf("请输入起飞时间：");
                scanf("%d", &data->qifeitime);
                printf("请输入降落时间：");
                scanf("%d", &data->jiangluotime);
                data->island = 1;
                insertList(list, data, list->size + 1);
                break;
            default:
                printf("输入错误\n");
                break;
        }
    }
}
