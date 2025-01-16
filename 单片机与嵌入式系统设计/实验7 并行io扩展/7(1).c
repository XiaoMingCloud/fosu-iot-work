// 包含51单片机的寄存器定义文件
#include<REG52.H>

// 包含绝对地址访问的头文件，允许直接通过地址访问特定的内存区域
#include<Absacc.h>

// 定义布尔值 TRUE 和 FALSE
#define TRUE 1
#define FALSE 0

// 定义8255芯片的端口A、B、C和控制寄存器的地址
#define PA8255  XBYTE[0xe000] // 8255的端口A
#define PB8255  XBYTE[0xe001] // 8255的端口B
#define PC8255  XBYTE[0xe002] // 8255的端口C
#define COM8255 XBYTE[0xe003] // 8255的控制寄存器

// time函数声明，用于实现延时功能
void time(unsigned int ucMs);

// init8255函数用于初始化8255控制寄存器
void init8255(void){
	COM8255=0x80; // 设置8255为模式0，即基本的I/O模式
}

// main函数是程序的入口点
void main(void){
	init8255(); // 调用初始化函数
	while(TRUE){ 
		COM8255=0x07; // 设置端口C为输出模式
		time(1); // 调用time函数，延时一段时间
		COM8255=0x06; // 改变端口C的状态，产生正方波的另一半周期
		time(1); 
	}
}

// time函数定义，用于实现延时功能
void time(unsigned int ucMs)
{
	#define DELAYTIMES 239 // 定义一个宏，用于计算延时时间
	unsigned char ucCounter; // 定义一个无符号字符变量，用于循环计数
	while (ucMs!=0){ 
		for(ucCounter=0;ucCounter<DELAYTIMES;ucCounter++){} // 循环DELAYTIMES次，实现延时
		ucMs--; // 减少延时计数
	}
}
