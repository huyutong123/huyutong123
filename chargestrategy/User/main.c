#include "system.h"
#include "SysTick.h"
#include "led.h"
#include "usart.h"
#include "key.h"
#include "can.h"
//#include "tqsy_can_matrix.h"
#include "string.h"
//#include "Ahtest1.h"
#include "stateflowmodel.h"    /* Model's header file */
#include "e3.h"
#include "v2.h"
//#include "hallsensor.h"
#include "timer.h"

#define soc_init 88

//TaskTime TaskTimePare=TaskTime_DEFAULTS;

//int InputProtect_fcn(int temp,float  volt,float soc);
//	int InputProtect_fcn(int temp,float volt,float soc)
//	{
//		Systim_Time_Run();
//		if (volt<0)
//		{
//		
//		}
//		else
//		{
//			printf("temp: %.d,volt: %.3f\n",temp,volt);
//			if(TaskTimePare.Tim1s_flag == 1){
//				stateflowmodel_step();
//				printf("soc: %f\n",rtY.Out1);
//				Clear_flag();
//			}
//		}
//	}
//	
	
	
int main()
{
	u8 i=0;
	u8 key;
	u8 mode=0;
	u32 res;
	
	u8 tbuf[8];
	u8 rbuf[8];
	//float temp;
	//float CellMaxVolt;
	
	struct e3_bms_357_t bms357Msg;
	struct e3_bms_358_t bms358Msg;
	struct e3_bms_104_t bms104Msg;
	struct v2_max_min_volt_temp_t bms064;
	//struct hallsensor_cab500_ip_t sensor_curr;

	SysTick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //中断优先级分组 分2组
	LED_Init();
	USART1_Init(115200);
	KEY_Init();
	CAN_Mode_Init(CAN_SJW_1tq,CAN_BS2_8tq,CAN_BS1_9tq,4,CAN_Mode_Normal);//500Kbps波特率
	TIM4_Init(200,36000-1);  //定时10ms
	stateflowmodel_initialize();//soc初始化
	
	
	while(1)
		{		
			key = KEY_Scan(0); 
			
			if(key == KEY_UP_PRESS)  //模式切换
				{
					mode=!mode;
					CAN_Mode_Init(CAN_SJW_1tq,CAN_BS2_8tq,CAN_BS1_9tq,4,mode);
					if(mode==0)
						{
							printf("Normal Mode\r\n");
						}
					else
						{ 
							printf("LoopBack Mode\r\n");
						}
				}
			res = CAN_Receive_Msg(rbuf);//接收数据
//			if(res == 0x357)
//				{	
//					e3_bms_357_unpack(&bms357Msg,rbuf,8);
//					if(e3_bms_357_bms_max_cell_volt_is_in_range(bms357Msg.bms_max_cell_volt))
//						{
//							rtU.In2 = (float)bms357Msg.bms_max_cell_volt/1000;
//							
//						}
//						printf("volt: %f",rtU.In2);
//				}
//			else if(res == 0x358)
//				{
//					e3_bms_358_unpack(&bms358Msg,rbuf,8);
//					if (e3_bms_358_bms_max_cell_temp_is_in_range(bms358Msg.bms_max_cell_temp))
//						{
//							rtU.In1 = bms358Msg.bms_max_cell_temp-40;
//							printf("temp: %f",rtU.In1);
//						}
//					}
				if(res == 0x64){
					v2_max_min_volt_temp_unpack(&bms064,rbuf,8);
					if(v2_max_min_volt_temp_max_volt_is_in_range(bms064.max_volt))
					{
						rtU.In2=bms064.max_volt;
					}
					if(v2_max_min_volt_temp_max_temp_is_in_range(bms064.max_temp))
					{
						rtU.In1=bms064.max_temp;
					}
				}
		 				rtU.In3=soc_init;
//						if(TaskTimePare.Tim500ms_flag == 1)
//						{ 
//							stateflowmodel_step();
//							printf("soc: %f,temp: %f,volt: %f",rtY.Out1,rtU.In1,rtU.In2);
//							//printf("10ms\n");
//							Clear_flag();
//						}
				
			i++;
			if(i%20==0)
				{
			LED1=!LED1;
				}
			delay_ms(10);
		}
	}