// ����51��Ƭ���ļĴ��������ļ�
#include<REG52.H>

// �������Ե�ַ���ʵ�ͷ�ļ�������ֱ��ͨ����ַ�����ض����ڴ�����
#include<Absacc.h>

// ���岼��ֵ TRUE �� FALSE
#define TRUE 1
#define FALSE 0

// ����8255оƬ�Ķ˿�A��B��C�Ϳ��ƼĴ����ĵ�ַ
#define PA8255  XBYTE[0xe000] // 8255�Ķ˿�A
#define PB8255  XBYTE[0xe001] // 8255�Ķ˿�B
#define PC8255  XBYTE[0xe002] // 8255�Ķ˿�C
#define COM8255 XBYTE[0xe003] // 8255�Ŀ��ƼĴ���

// time��������������ʵ����ʱ����
void time(unsigned int ucMs);

// init8255�������ڳ�ʼ��8255���ƼĴ���
void init8255(void){
	COM8255=0x80; // ����8255Ϊģʽ0����������I/Oģʽ
}

// main�����ǳ������ڵ�
void main(void){
	init8255(); // ���ó�ʼ������
	while(TRUE){ 
		COM8255=0x07; // ���ö˿�CΪ���ģʽ
		time(1); // ����time��������ʱһ��ʱ��
		COM8255=0x06; // �ı�˿�C��״̬����������������һ������
		time(1); 
	}
}

// time�������壬����ʵ����ʱ����
void time(unsigned int ucMs)
{
	#define DELAYTIMES 239 // ����һ���꣬���ڼ�����ʱʱ��
	unsigned char ucCounter; // ����һ���޷����ַ�����������ѭ������
	while (ucMs!=0){ 
		for(ucCounter=0;ucCounter<DELAYTIMES;ucCounter++){} // ѭ��DELAYTIMES�Σ�ʵ����ʱ
		ucMs--; // ������ʱ����
	}
}
