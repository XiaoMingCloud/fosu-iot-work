#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define MAX_STUDENTS 10000//最大学生数量 
#define MAX_NAME_LENGTH 50

typedef struct {
	double id;//学号
	char name[MAX_NAME_LENGTH + 1];//姓名
	char grade[MAX_NAME_LENGTH + 1];//年级
	char major[MAX_NAME_LENGTH + 1];//专业
	float score1;//成绩1
	float score2;//成绩2
	float score3;//成绩3
	float average;//平均成绩
	float total;//总成绩
} Student;

Student students[MAX_STUDENTS];
int numStudents = 0;//学生的个数，全局变量

//函数的声明
void displayMenu();           //加载主菜单
void addRecord();            //添加函数
void deleteRecord();         //删除函数
void modifyRecord();         //修改函数
void browseRecords();        //浏览函数 
void sortRecords();          //排序函数
void saveRecords();          //保存学生记录
void loadRecords();         //加载数据库函数
void searchRecords();       //查询学生记录 

int main() {
	char password[20];
	int attempt = 3;

	printf("请输入口令：");
	scanf("%s", password);


	while (attempt > 0) {
		if (strcmp(password, "123456") == 0) {
			printf("口令正确！\n");
			break;
		} else {
			printf("口令错误！还有%d次机会。\n", attempt - 1);
			attempt--;

			if (attempt > 0) {
				printf("请重新输入口令：");
				scanf("%s", password);
			} else {
				printf("口令错误次数过多，系统退出。\n");
				return 0;
			}
		}
	}




	displayMenu();   //加载主菜单

	int choice;
	while (1) {
		printf("请输入您的选择：");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				addRecord();//添加学生成绩
				saveRecords() ;//后台自动保存
				break;
			case 2:
				deleteRecord();//删除学生成绩
				saveRecords() ;//后台自动保存

				break;
			case 3:
				modifyRecord();//修改学生成绩
				saveRecords() ;//后台自动保存
				break;
			case 4:
				browseRecords();//浏览学生成绩
				break;
			case 5:
				sortRecords();//排序学生成绩
				break;
			case 6:
				searchRecords() ;//查询学生成绩
				break;
			case 7:
				printf("系统退出。\n");
				return 0;
				break;
			default:
				printf("无效的选择，请重新输入。\n");
				break;
		}

		displayMenu();
	}

	return 0;
}

void displayMenu() {//主菜单
	loadRecords();  //把学生记录数据库从硬盘加载到内存里 ，每进行变动自动保存
	printf("\n********** 学生成绩管理系统 **********\n");
	printf("1. 添加学生记录\n");
	printf("2. 删除学生记录\n");
	printf("3. 修改学生记录\n");
	printf("4. 浏览学生记录\n");
	printf("5. 排序学生成绩\n");
	printf("6. 查询学生记录\n");
	printf("7. 退出系统\n");
	printf("************************************\n");
}

void addRecord() {//添加学生记录
	if (numStudents == MAX_STUDENTS) {
		printf("学生记录已满，无法添加更多记录。\n");
		return;
	}

	Student newStudent;
	int i;


	printf("请输入学号：");
	scanf("%lf", &newStudent.id);

	for(i=0; i<numStudents; i++) {
		if(students[i].id==newStudent.id) {
			printf("该学号已经存在，无需添加,请重新输入\n");
			addRecord();
			return ;

		}
	}

	printf("请输入姓名：");
	scanf("%s", newStudent.name);

	printf("请输入年级：");
	scanf("%s", newStudent.grade);

	printf("请输入专业：");
	scanf("%s", newStudent.major);

	printf("请输入成绩1：");
	scanf("%f", &newStudent.score1);

	printf("请输入成绩2：");
	scanf("%f", &newStudent.score2);

	printf("请输入成绩3：");
	scanf("%f", &newStudent.score3);

	newStudent.total = newStudent.score1 + newStudent.score2 + newStudent.score3;
	newStudent.average = newStudent.total / 3;

	students[numStudents] = newStudent;//把所有的学生信息放进学生数组
	numStudents++;

	printf("添加成功\n");

}

void deleteRecord() {//删除学生记录
	if (numStudents == 0) {
		printf("没有记录可删除。\n");
		return;
	}

	double id;
	printf("请输入要删除的学生的学号：");
	scanf("%lf", &id);
	int i;
	int foundIndex = -1;
	for ( i = 0; i < numStudents; i++) {//查找学生ID
	

		if (students[i].id==id) {
			foundIndex = i;
			break;
		}
	}

	if (foundIndex != -1) {//找到了的情况
		for ( i = foundIndex; i < numStudents - 1; i++) {
			students[i] = students[i + 1];//所有的学生数组前移
		}
		numStudents--;

		printf("记录删除成功。\n");
	} else {
		printf("未找到对应学生的记录。\n");
	}
}

void modifyRecord() {//修改学生记录
	if (numStudents == 0) {
		printf("没有记录可修改。\n");
		return;
	}

	double id;
	printf("请输入要修改的学生的学号：");
	scanf("%lf", &id);
	int i;
	int foundIndex = -1;
	for ( i = 0; i < numStudents; i++) {
		if (students[i].id ==id) {
			foundIndex = i;
			break;
		}
	}

	if (foundIndex != -1) {//找该学生了
		Student modifiedStudent = students[foundIndex];

		printf("学号：%.0lf\n", modifiedStudent.id);
		printf("姓名：%s\n", modifiedStudent.name);
		printf("年级：%s\n", modifiedStudent.grade);
		printf("专业：%s\n", modifiedStudent.major);
		printf("成绩1：%.2f\n", modifiedStudent.score1);
		printf("成绩2：%.2f\n", modifiedStudent.score2);
		printf("成绩3：%.2f\n", modifiedStudent.score3);
		printf("请输入新的学号：");
		scanf("%lf", &modifiedStudent.id);

		for(i=0; i<numStudents; i++) {
			if(students[i].id==modifiedStudent.id&&modifiedStudent.id!=id) {
				printf("该学号已经存在,无法修改为该学号\n");

				return ;

			}
		}

      printf("请输入新的姓名：") ;
		scanf("%s", modifiedStudent.name);
		printf("请输入新的年级：");
		scanf("%s", modifiedStudent.grade);
		printf("请输入新的专业：");
		scanf("%s", modifiedStudent.major);
		printf("请输入新的成绩1：");
		scanf("%f", &modifiedStudent.score1);

		printf("请输入新的成绩2：");
		scanf("%f", &modifiedStudent.score2);

		printf("请输入新的成绩3：");
		scanf("%f", &modifiedStudent.score3);

		modifiedStudent.total = modifiedStudent.score1 + modifiedStudent.score2 + modifiedStudent.score3;
		modifiedStudent.average = modifiedStudent.total / 3;

		students[foundIndex] = modifiedStudent;
		saveRecords() ;
		printf("记录修改成功。\n");
	} else {
		printf("未找到对应学生的记录。\n");
	}
}

void browseRecords() {
	if (numStudents == 0) {//浏览学生记录
		printf("没有记录可浏览。\n");
		return;
	}

	int pageSize;
	printf("请输入每页显示的记录数：");
	scanf("%d", &pageSize);

	int totalPages = (numStudents  / pageSize)+1;
	int currentPage = 1;//显示第几页
	int startIndex = (currentPage - 1) * pageSize;

	while (1) {
		printf("\n********** 学生记录 第%d页 **********\n", currentPage);

		int endIndex = startIndex + pageSize;
		if (endIndex > numStudents) {
			endIndex = numStudents;
		}
		int i;
		for ( i = startIndex; i < endIndex; i++) {
			printf("学号：%0.lf\n", students[i].id);
			printf("姓名：%s\n", students[i].name);
			printf("年级：%s\n", students[i].grade);
			printf("专业：%s\n", students[i].major);
			printf("成绩1：%.2f\n", students[i].score1);
			printf("成绩2：%.2f\n", students[i].score2);
			printf("成绩3：%.2f\n", students[i].score3);
			printf("总成绩：%.2f\n", students[i].total);
			printf("平均成绩：%.2f\n", students[i].average);
			printf("------------------------------------\n");
		}

		printf("************************************\n");

		if (currentPage < totalPages) {
			printf("按任意键浏览下一页...\n");
			getchar();//getchar来消除上一个回车
			getchar();//接收一个输入，否则一直停在这里
			currentPage++;//下一页
			startIndex = (currentPage - 1) * pageSize;
		} else {
			printf("已显示全部记录。\n");
			break;
		}
	}
}

void sortRecords() {//对学生记录进行排序
	if (numStudents == 0) {
		printf("没有记录可排序。\n");
		return;
	}

	int i,j;
	for ( i = 0; i < numStudents - 1; i++) {
		for ( j = 0; j < numStudents - 1 - i; j++) {
			if (students[j].average < students[j + 1].average) {//排名依据是总成绩高到低
				Student temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}


	FILE* averageFile = fopen("平时成绩.txt", "w");//保存平时成绩
	for ( i = 0; i < numStudents; i++) {
		fprintf(averageFile, "学号：%.0lf\n", students[i].id);
		fprintf(averageFile, "姓名：%s\n", students[i].name);
		fprintf(averageFile, "年级：%s\n", students[i].grade);
		fprintf(averageFile, "专业：%s\n", students[i].major);
		fprintf(averageFile, "成绩1：%.2f\n", students[i].score1);
		fprintf(averageFile, "成绩2：%.2f\n", students[i].score2);
		fprintf(averageFile, "成绩3：%.2f\n", students[i].score3);
		fprintf(averageFile, "总成绩：%.2f\n", students[i].total);
		fprintf(averageFile, "平均成绩：%.2lf\n", students[i].average);
		fprintf(averageFile, "------------------------------------\n");
	}
	fclose(averageFile);



	for ( i = 0; i < numStudents - 1; i++) {
		for ( j = 0; j < numStudents - 1 - i; j++) {
			if (students[j].total < students[j + 1].total) {
				Student temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}


	FILE* totalFile = fopen("总成绩.txt", "w");//保存总成绩
	for ( i = 0; i < numStudents; i++) {
		fprintf(totalFile, "学号：%.0lf\n", students[i].id);
		fprintf(totalFile, "姓名：%s\n", students[i].name);
		fprintf(totalFile, "年级：%s\n", students[i].grade);
		fprintf(totalFile, "专业：%s\n", students[i].major);
		fprintf(totalFile, "成绩1：%.2f\n", students[i].score1);
		fprintf(totalFile, "成绩2：%.2f\n", students[i].score2);
		fprintf(totalFile, "成绩3：%.2f\n", students[i].score3);
		fprintf(totalFile, "总成绩：%.2f\n", students[i].total);
		fprintf(totalFile, "平均成绩：%.2f\n", students[i].average);
		fprintf(totalFile, "------------------------------------\n");
	}
	fclose(totalFile);
	printf("排序完成");

}

void saveRecords() {//保存学生记录 ，最后把学生记录以文件的形式写到硬盘中


	FILE* file = fopen("学生成绩.txt", "w");
	if (file == NULL) {
		printf("无法打开文件。\n");
		return;
	}
	int i;
	for ( i = 0; i < numStudents; i++) {
		fprintf(file, "学号：%.0lf\n", students[i].id);
		fprintf(file, "姓名：%s\n", students[i].name);
		fprintf(file, "年级：%s\n", students[i].grade);
		fprintf(file, "专业：%s\n", students[i].major);
		fprintf(file, "成绩1：%.2f\n", students[i].score1);
		fprintf(file, "成绩2：%.2f\n", students[i].score2);
		fprintf(file, "成绩3：%.2f\n", students[i].score3);
		fprintf(file, "总成绩：%.2f\n", students[i].total);
		fprintf(file, "平均成绩：%.2f\n", students[i].average);
		fprintf(file, "------------------------------------\n");
	}

	fclose(file);


}

void loadRecords() {//加载学生记录
	FILE* file = fopen("学生成绩.txt", "r");
	if (file == NULL) {
		return;
	}

	numStudents = 0;
	while (fscanf(file, "学号：%lf\n", &students[numStudents].id) != EOF) {
		fscanf(file, "姓名：%s\n", students[numStudents].name);
		fscanf(file, "年级：%s\n", students[numStudents].grade);
		fscanf(file, "专业：%s\n", students[numStudents].major);
		fscanf(file, "成绩1：%f\n", &students[numStudents].score1);
		fscanf(file, "成绩2：%f\n", &students[numStudents].score2);
		fscanf(file, "成绩3：%f\n", &students[numStudents].score3);
		fscanf(file, "总成绩：%f\n", &students[numStudents].total);
		fscanf(file, "平均成绩：%f\n", &students[numStudents].average);
		fscanf(file, "------------------------------------\n");

		numStudents++;
	}

	fclose(file);


}

void searchRecords() {//查询学生记录
	if (numStudents == 0) {
		printf("没有记录可查询。\n");
		return;
	}

	int score;
	printf("请输入要查询的分数：");
	scanf("%d", &score);

	int count = 0;
	int low = 0;
	int high = numStudents - 1;
	int foundIndex = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (students[mid].total == score) {
			foundIndex = mid;
			break;
		} else if (students[mid].total < score) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	if (foundIndex != -1) {
		for (int i = foundIndex; i >= 0; i--) {
			if (students[i].total == score) {
				count++;
			} else {
				break;
			}
		}

		printf("总成绩为%d的学生人数：%d\n", score, count);
	} else {
		printf("未找到总成绩为%d的学生。\n", score);
	}
}


