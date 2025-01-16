#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define MAX_STUDENTS 10000//���ѧ������ 
#define MAX_NAME_LENGTH 50

typedef struct {
	double id;//ѧ��
	char name[MAX_NAME_LENGTH + 1];//����
	char grade[MAX_NAME_LENGTH + 1];//�꼶
	char major[MAX_NAME_LENGTH + 1];//רҵ
	float score1;//�ɼ�1
	float score2;//�ɼ�2
	float score3;//�ɼ�3
	float average;//ƽ���ɼ�
	float total;//�ܳɼ�
} Student;

Student students[MAX_STUDENTS];
int numStudents = 0;//ѧ���ĸ�����ȫ�ֱ���

//����������
void displayMenu();           //�������˵�
void addRecord();            //��Ӻ���
void deleteRecord();         //ɾ������
void modifyRecord();         //�޸ĺ���
void browseRecords();        //������� 
void sortRecords();          //������
void saveRecords();          //����ѧ����¼
void loadRecords();         //�������ݿ⺯��
void searchRecords();       //��ѯѧ����¼ 

int main() {
	char password[20];
	int attempt = 3;

	printf("��������");
	scanf("%s", password);


	while (attempt > 0) {
		if (strcmp(password, "123456") == 0) {
			printf("������ȷ��\n");
			break;
		} else {
			printf("������󣡻���%d�λ��ᡣ\n", attempt - 1);
			attempt--;

			if (attempt > 0) {
				printf("������������");
				scanf("%s", password);
			} else {
				printf("�������������࣬ϵͳ�˳���\n");
				return 0;
			}
		}
	}




	displayMenu();   //�������˵�

	int choice;
	while (1) {
		printf("����������ѡ��");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				addRecord();//���ѧ���ɼ�
				saveRecords() ;//��̨�Զ�����
				break;
			case 2:
				deleteRecord();//ɾ��ѧ���ɼ�
				saveRecords() ;//��̨�Զ�����

				break;
			case 3:
				modifyRecord();//�޸�ѧ���ɼ�
				saveRecords() ;//��̨�Զ�����
				break;
			case 4:
				browseRecords();//���ѧ���ɼ�
				break;
			case 5:
				sortRecords();//����ѧ���ɼ�
				break;
			case 6:
				searchRecords() ;//��ѯѧ���ɼ�
				break;
			case 7:
				printf("ϵͳ�˳���\n");
				return 0;
				break;
			default:
				printf("��Ч��ѡ�����������롣\n");
				break;
		}

		displayMenu();
	}

	return 0;
}

void displayMenu() {//���˵�
	loadRecords();  //��ѧ����¼���ݿ��Ӳ�̼��ص��ڴ��� ��ÿ���б䶯�Զ�����
	printf("\n********** ѧ���ɼ�����ϵͳ **********\n");
	printf("1. ���ѧ����¼\n");
	printf("2. ɾ��ѧ����¼\n");
	printf("3. �޸�ѧ����¼\n");
	printf("4. ���ѧ����¼\n");
	printf("5. ����ѧ���ɼ�\n");
	printf("6. ��ѯѧ����¼\n");
	printf("7. �˳�ϵͳ\n");
	printf("************************************\n");
}

void addRecord() {//���ѧ����¼
	if (numStudents == MAX_STUDENTS) {
		printf("ѧ����¼�������޷���Ӹ����¼��\n");
		return;
	}

	Student newStudent;
	int i;


	printf("������ѧ�ţ�");
	scanf("%lf", &newStudent.id);

	for(i=0; i<numStudents; i++) {
		if(students[i].id==newStudent.id) {
			printf("��ѧ���Ѿ����ڣ��������,����������\n");
			addRecord();
			return ;

		}
	}

	printf("������������");
	scanf("%s", newStudent.name);

	printf("�������꼶��");
	scanf("%s", newStudent.grade);

	printf("������רҵ��");
	scanf("%s", newStudent.major);

	printf("������ɼ�1��");
	scanf("%f", &newStudent.score1);

	printf("������ɼ�2��");
	scanf("%f", &newStudent.score2);

	printf("������ɼ�3��");
	scanf("%f", &newStudent.score3);

	newStudent.total = newStudent.score1 + newStudent.score2 + newStudent.score3;
	newStudent.average = newStudent.total / 3;

	students[numStudents] = newStudent;//�����е�ѧ����Ϣ�Ž�ѧ������
	numStudents++;

	printf("��ӳɹ�\n");

}

void deleteRecord() {//ɾ��ѧ����¼
	if (numStudents == 0) {
		printf("û�м�¼��ɾ����\n");
		return;
	}

	double id;
	printf("������Ҫɾ����ѧ����ѧ�ţ�");
	scanf("%lf", &id);
	int i;
	int foundIndex = -1;
	for ( i = 0; i < numStudents; i++) {//����ѧ��ID
	

		if (students[i].id==id) {
			foundIndex = i;
			break;
		}
	}

	if (foundIndex != -1) {//�ҵ��˵����
		for ( i = foundIndex; i < numStudents - 1; i++) {
			students[i] = students[i + 1];//���е�ѧ������ǰ��
		}
		numStudents--;

		printf("��¼ɾ���ɹ���\n");
	} else {
		printf("δ�ҵ���Ӧѧ���ļ�¼��\n");
	}
}

void modifyRecord() {//�޸�ѧ����¼
	if (numStudents == 0) {
		printf("û�м�¼���޸ġ�\n");
		return;
	}

	double id;
	printf("������Ҫ�޸ĵ�ѧ����ѧ�ţ�");
	scanf("%lf", &id);
	int i;
	int foundIndex = -1;
	for ( i = 0; i < numStudents; i++) {
		if (students[i].id ==id) {
			foundIndex = i;
			break;
		}
	}

	if (foundIndex != -1) {//�Ҹ�ѧ����
		Student modifiedStudent = students[foundIndex];

		printf("ѧ�ţ�%.0lf\n", modifiedStudent.id);
		printf("������%s\n", modifiedStudent.name);
		printf("�꼶��%s\n", modifiedStudent.grade);
		printf("רҵ��%s\n", modifiedStudent.major);
		printf("�ɼ�1��%.2f\n", modifiedStudent.score1);
		printf("�ɼ�2��%.2f\n", modifiedStudent.score2);
		printf("�ɼ�3��%.2f\n", modifiedStudent.score3);
		printf("�������µ�ѧ�ţ�");
		scanf("%lf", &modifiedStudent.id);

		for(i=0; i<numStudents; i++) {
			if(students[i].id==modifiedStudent.id&&modifiedStudent.id!=id) {
				printf("��ѧ���Ѿ�����,�޷��޸�Ϊ��ѧ��\n");

				return ;

			}
		}

      printf("�������µ�������") ;
		scanf("%s", modifiedStudent.name);
		printf("�������µ��꼶��");
		scanf("%s", modifiedStudent.grade);
		printf("�������µ�רҵ��");
		scanf("%s", modifiedStudent.major);
		printf("�������µĳɼ�1��");
		scanf("%f", &modifiedStudent.score1);

		printf("�������µĳɼ�2��");
		scanf("%f", &modifiedStudent.score2);

		printf("�������µĳɼ�3��");
		scanf("%f", &modifiedStudent.score3);

		modifiedStudent.total = modifiedStudent.score1 + modifiedStudent.score2 + modifiedStudent.score3;
		modifiedStudent.average = modifiedStudent.total / 3;

		students[foundIndex] = modifiedStudent;
		saveRecords() ;
		printf("��¼�޸ĳɹ���\n");
	} else {
		printf("δ�ҵ���Ӧѧ���ļ�¼��\n");
	}
}

void browseRecords() {
	if (numStudents == 0) {//���ѧ����¼
		printf("û�м�¼�������\n");
		return;
	}

	int pageSize;
	printf("������ÿҳ��ʾ�ļ�¼����");
	scanf("%d", &pageSize);

	int totalPages = (numStudents  / pageSize)+1;
	int currentPage = 1;//��ʾ�ڼ�ҳ
	int startIndex = (currentPage - 1) * pageSize;

	while (1) {
		printf("\n********** ѧ����¼ ��%dҳ **********\n", currentPage);

		int endIndex = startIndex + pageSize;
		if (endIndex > numStudents) {
			endIndex = numStudents;
		}
		int i;
		for ( i = startIndex; i < endIndex; i++) {
			printf("ѧ�ţ�%0.lf\n", students[i].id);
			printf("������%s\n", students[i].name);
			printf("�꼶��%s\n", students[i].grade);
			printf("רҵ��%s\n", students[i].major);
			printf("�ɼ�1��%.2f\n", students[i].score1);
			printf("�ɼ�2��%.2f\n", students[i].score2);
			printf("�ɼ�3��%.2f\n", students[i].score3);
			printf("�ܳɼ���%.2f\n", students[i].total);
			printf("ƽ���ɼ���%.2f\n", students[i].average);
			printf("------------------------------------\n");
		}

		printf("************************************\n");

		if (currentPage < totalPages) {
			printf("������������һҳ...\n");
			getchar();//getchar��������һ���س�
			getchar();//����һ�����룬����һֱͣ������
			currentPage++;//��һҳ
			startIndex = (currentPage - 1) * pageSize;
		} else {
			printf("����ʾȫ����¼��\n");
			break;
		}
	}
}

void sortRecords() {//��ѧ����¼��������
	if (numStudents == 0) {
		printf("û�м�¼������\n");
		return;
	}

	int i,j;
	for ( i = 0; i < numStudents - 1; i++) {
		for ( j = 0; j < numStudents - 1 - i; j++) {
			if (students[j].average < students[j + 1].average) {//�����������ܳɼ��ߵ���
				Student temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}


	FILE* averageFile = fopen("ƽʱ�ɼ�.txt", "w");//����ƽʱ�ɼ�
	for ( i = 0; i < numStudents; i++) {
		fprintf(averageFile, "ѧ�ţ�%.0lf\n", students[i].id);
		fprintf(averageFile, "������%s\n", students[i].name);
		fprintf(averageFile, "�꼶��%s\n", students[i].grade);
		fprintf(averageFile, "רҵ��%s\n", students[i].major);
		fprintf(averageFile, "�ɼ�1��%.2f\n", students[i].score1);
		fprintf(averageFile, "�ɼ�2��%.2f\n", students[i].score2);
		fprintf(averageFile, "�ɼ�3��%.2f\n", students[i].score3);
		fprintf(averageFile, "�ܳɼ���%.2f\n", students[i].total);
		fprintf(averageFile, "ƽ���ɼ���%.2lf\n", students[i].average);
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


	FILE* totalFile = fopen("�ܳɼ�.txt", "w");//�����ܳɼ�
	for ( i = 0; i < numStudents; i++) {
		fprintf(totalFile, "ѧ�ţ�%.0lf\n", students[i].id);
		fprintf(totalFile, "������%s\n", students[i].name);
		fprintf(totalFile, "�꼶��%s\n", students[i].grade);
		fprintf(totalFile, "רҵ��%s\n", students[i].major);
		fprintf(totalFile, "�ɼ�1��%.2f\n", students[i].score1);
		fprintf(totalFile, "�ɼ�2��%.2f\n", students[i].score2);
		fprintf(totalFile, "�ɼ�3��%.2f\n", students[i].score3);
		fprintf(totalFile, "�ܳɼ���%.2f\n", students[i].total);
		fprintf(totalFile, "ƽ���ɼ���%.2f\n", students[i].average);
		fprintf(totalFile, "------------------------------------\n");
	}
	fclose(totalFile);
	printf("�������");

}

void saveRecords() {//����ѧ����¼ ������ѧ����¼���ļ�����ʽд��Ӳ����


	FILE* file = fopen("ѧ���ɼ�.txt", "w");
	if (file == NULL) {
		printf("�޷����ļ���\n");
		return;
	}
	int i;
	for ( i = 0; i < numStudents; i++) {
		fprintf(file, "ѧ�ţ�%.0lf\n", students[i].id);
		fprintf(file, "������%s\n", students[i].name);
		fprintf(file, "�꼶��%s\n", students[i].grade);
		fprintf(file, "רҵ��%s\n", students[i].major);
		fprintf(file, "�ɼ�1��%.2f\n", students[i].score1);
		fprintf(file, "�ɼ�2��%.2f\n", students[i].score2);
		fprintf(file, "�ɼ�3��%.2f\n", students[i].score3);
		fprintf(file, "�ܳɼ���%.2f\n", students[i].total);
		fprintf(file, "ƽ���ɼ���%.2f\n", students[i].average);
		fprintf(file, "------------------------------------\n");
	}

	fclose(file);


}

void loadRecords() {//����ѧ����¼
	FILE* file = fopen("ѧ���ɼ�.txt", "r");
	if (file == NULL) {
		return;
	}

	numStudents = 0;
	while (fscanf(file, "ѧ�ţ�%lf\n", &students[numStudents].id) != EOF) {
		fscanf(file, "������%s\n", students[numStudents].name);
		fscanf(file, "�꼶��%s\n", students[numStudents].grade);
		fscanf(file, "רҵ��%s\n", students[numStudents].major);
		fscanf(file, "�ɼ�1��%f\n", &students[numStudents].score1);
		fscanf(file, "�ɼ�2��%f\n", &students[numStudents].score2);
		fscanf(file, "�ɼ�3��%f\n", &students[numStudents].score3);
		fscanf(file, "�ܳɼ���%f\n", &students[numStudents].total);
		fscanf(file, "ƽ���ɼ���%f\n", &students[numStudents].average);
		fscanf(file, "------------------------------------\n");

		numStudents++;
	}

	fclose(file);


}

void searchRecords() {//��ѯѧ����¼
	if (numStudents == 0) {
		printf("û�м�¼�ɲ�ѯ��\n");
		return;
	}

	int score;
	printf("������Ҫ��ѯ�ķ�����");
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

		printf("�ܳɼ�Ϊ%d��ѧ��������%d\n", score, count);
	} else {
		printf("δ�ҵ��ܳɼ�Ϊ%d��ѧ����\n", score);
	}
}


