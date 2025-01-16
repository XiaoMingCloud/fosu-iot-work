// 包含51单片机的寄存器定义文件
#include<REG52.H>

// 包含绝对地址访问的头文件，允许直接通过地址访问特定的内存区域
#include<Absacc.h>

// 定义布尔值 TRUE 和 FALSE
#define TRUE 1
#define FALSE 0

// 定义一个全局标志位，用于控制正方波的翻转
bit bitFF; 

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

// 主函数
void main(void){
	init8255(); // 初始化8255
	TMOD=0x10; // 设置定时器1为模式1(16位定时器模式)
	TH1=-1000>>8;TL1=-1000%256; // 设置定时器1的初始值，用于产生定时中断
	TCON=0x40; // 启动定时器1
	IE=0x88; // 开启全局中断和定时器1中断
	while(TRUE){} // 主循环，但这里实际上什么也不做，因为中断服务例程处理正方波输出
}

// 定时器1中断服务例程
void timerlint(void) interrupt 3
{
	EA=0; // 关闭全局中断，防止中断嵌套
	TR1=1; // 启动定时器1
	TH1=-1000>>8;TL1=-1000%256; // 重新加载定时器1的初始值
	TR1=1; // 再次启动定时器1
	if(bitFF) // 检查bitFF标志位
	    COM8255=0x07; // 如果bitFF为真，则设置端口C输出高电平
	else COM8255=0x06; // 否则输出低电平
	bitFF=!bitFF; // 翻转bitFF标志位，为下次中断做准备
	EA=1; // 重新开启全局中断
}

// time函数定义，用于实现延时功能
void time(unsigned int ucMs)
{
	#define DELAYTIMES 239 // 定义一个宏，用于计算延时时间
	unsigned char ucCounter; // 定义一个无符号字符变量，用于循环计数
	while (ucMs!=0){ // 循环直到ucMs减到0
		for(ucCounter=0;ucCounter<DELAYTIMES;ucCounter++){} // 循环DELAYTIMES次，实现延时
		ucMs--; // 减少延时计数
	}
}
