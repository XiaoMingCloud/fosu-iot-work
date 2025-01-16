#include<reg52.h>
#include<intrins.h> 
#include<Stdio.h>
#define  KEY_PORT P1
#define  TRUE 1
#define  uchar unsigned char
uchar keyscan(void);
void Key_process(void);
uchar key_Value=0xff; 
void initUart(void)
{
	SCON=0x50;
	RCAP2H=(65536-(3456/96))>>8;
	RCAP2L=(65536-(3456/96))%256; 
	T2CON=0X34;
	TI=1;
}
void delay_5us(void)
{
	_nop_();
	_nop_();
}
void  delay_50us(void)
{
	uchar i;
	for(i=0;i<4;i++)
	{
		delay_5us();
	}
}
void delay_100us(void)
{
	delay_50us();
	delay_50us();
}

void time (unsigned int ucMs)
{
	uchar j;
	while(ucMs>0){
		for(j=0;j<10;j++) delay_100us();
		ucMs--;
	}
}
void main (void)
{
	initUart();
	TMOD=0X10;
	TH1=-10000>>8;TL1=-10000%256;
	TCON=0X40;
	IE=0X88;
	key_Value=0xff;
	do{
		if (key_Value!=0xff){
			Key_process();
			key_Value=0xff;
		}
	}while(1);
}
void timerlint(void)interrupt 3
{
	EA=0;
	TR1=0;
	TH1=-10000>>8;TL1=-10000%256;
	TR1=1;
	key_Value=keyscan(); 
	EA=1;
}
uchar keyscan(void)
{
	uchar readkey,rereadkey;
	uchar x_t,y_t;
	KEY_PORT=0x0f;
	x_t =KEY_PORT & 0x0f;
	if(x_t==0x0f) return(0xff);
	KEY_PORT=0xf0;
	y_t =KEY_PORT & 0xf0;
	readkey =x_t | y_t;
	time(10);
	KEY_PORT=0x0f;
	x_t =KEY_PORT & 0x0f;
	if(x_t==0x0f) return(0xff);
	KEY_PORT=0xf0;
	y_t =KEY_PORT & 0xf0;
	rereadkey=x_t+y_t;
	if(readkey==rereadkey){
		return(~rereadkey);
	}
	return(0xff);
	
}
void Key_process(void)
{
	switch(key_Value){
		case 0x11:
			printf("Key(R1,C1) is pressed\n");
		    break;
		case 0x21:
			printf("Key(R1,C2) is pressed\n");
		    break;
		case 0x41:
			printf("Key(R1,C3) is pressed\n");
		    break;
		case 0x81:
			printf("Key(R1,C4) is pressed\n");
		    break;
		    
		case 0x12:
			printf("Key(R2,C1) is pressed\n");
		    break;    
		case 0x22:
			printf("Key(R2,C2) is pressed\n");
		    break;    
		case 0x42:
			printf("Key(R2,C3) is pressed\n");
		    break;    
		case 0x82:
			printf("Key(R2,C4) is pressed\n");
		    break; 
			   
		case 0x14:
			printf("Key(R3,C1) is pressed\n");
		    break;    
		case 0x24:
			printf("Key(R3,C2) is pressed\n");
		    break;    
		case 0x44:
			printf("Key(R3,C3) is pressed\n");
		    break;
		case 0x84:
			printf("Key(R1,C4) is pressed\n");
		    break;  
			  
		case 0x18:
			printf("Key(R4,C1) is pressed\n");
		    break;    
		case 0x28:
			printf("Key(R4,C2) is pressed\n");
		    break;    
		case 0x48:
			printf("Key(R4,C3) is pressed\n");
		    break;
		case 0x88:
			printf("Key(R4,C4) is pressed\n");
		    break; 
			  
		default:break; 
		
	}
 } 

