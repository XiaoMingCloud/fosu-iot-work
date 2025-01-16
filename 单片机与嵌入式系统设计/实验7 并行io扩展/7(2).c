// ����51��Ƭ���ļĴ��������ļ�
#include<REG52.H>

// �������Ե�ַ���ʵ�ͷ�ļ�������ֱ��ͨ����ַ�����ض����ڴ�����
#include<Absacc.h>

// ���岼��ֵ TRUE �� FALSE
#define TRUE 1
#define FALSE 0

// ����һ��ȫ�ֱ�־λ�����ڿ����������ķ�ת
bit bitFF; 

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

// ������
void main(void){
	init8255(); // ��ʼ��8255
	TMOD=0x10; // ���ö�ʱ��1Ϊģʽ1(16λ��ʱ��ģʽ)
	TH1=-1000>>8;TL1=-1000%256; // ���ö�ʱ��1�ĳ�ʼֵ�����ڲ�����ʱ�ж�
	TCON=0x40; // ������ʱ��1
	IE=0x88; // ����ȫ���жϺͶ�ʱ��1�ж�
	while(TRUE){} // ��ѭ����������ʵ����ʲôҲ��������Ϊ�жϷ������̴������������
}

// ��ʱ��1�жϷ�������
void timerlint(void) interrupt 3
{
	EA=0; // �ر�ȫ���жϣ���ֹ�ж�Ƕ��
	TR1=1; // ������ʱ��1
	TH1=-1000>>8;TL1=-1000%256; // ���¼��ض�ʱ��1�ĳ�ʼֵ
	TR1=1; // �ٴ�������ʱ��1
	if(bitFF) // ���bitFF��־λ
	    COM8255=0x07; // ���bitFFΪ�棬�����ö˿�C����ߵ�ƽ
	else COM8255=0x06; // ��������͵�ƽ
	bitFF=!bitFF; // ��תbitFF��־λ��Ϊ�´��ж���׼��
	EA=1; // ���¿���ȫ���ж�
}

// time�������壬����ʵ����ʱ����
void time(unsigned int ucMs)
{
	#define DELAYTIMES 239 // ����һ���꣬���ڼ�����ʱʱ��
	unsigned char ucCounter; // ����һ���޷����ַ�����������ѭ������
	while (ucMs!=0){ // ѭ��ֱ��ucMs����0
		for(ucCounter=0;ucCounter<DELAYTIMES;ucCounter++){} // ѭ��DELAYTIMES�Σ�ʵ����ʱ
		ucMs--; // ������ʱ����
	}
}
