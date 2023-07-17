#include "timer.h"
#include "led.h"
#include "time.h"

/*******************************************************************************
* �� �� ��         : TIM4_Init
* ��������		   : TIM4��ʼ������
* ��    ��         : per:��װ��ֵ
					 psc:��Ƶϵ��
* ��    ��         : ��
*******************************************************************************/
void TIM4_Init(u16 per,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);//ʹ��TIM4ʱ��
	
	TIM_TimeBaseInitStructure.TIM_Period=per;   //�Զ�װ��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc; //��Ƶϵ��
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //�������ϼ���ģʽ
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructure);
	
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE); //������ʱ���ж�
	TIM_ClearITPendingBit(TIM4,TIM_IT_Update);
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;//��ʱ���ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;		//�����ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	
	
	TIM_Cmd(TIM4,ENABLE); //ʹ�ܶ�ʱ��	
}

/*******************************************************************************
* �� �� ��         : TIM4_IRQHandler
* ��������		   : TIM4�жϺ���
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
TaskTime TaskTimePare=TaskTime_DEFAULTS;
void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update))
	{
		TaskTimePare.Tim10ms_count++;
		if(TaskTimePare.Tim10ms_count>=10)
    {          
				TaskTimePare.Tim10ms_count=0;
				TaskTimePare.Tim10ms_flag = 1;
				if(++TaskTimePare.Tim100ms_count >=10)
				{
						TaskTimePare.Tim100ms_count=0;
						TaskTimePare.Tim100ms_flag=1;
				}
    }
		if(TaskTimePare.Tim100ms_flag==1)
		{
				if(++TaskTimePare.Tim200ms_count >=2)
				{	      
						TaskTimePare.Tim200ms_count=0;
						TaskTimePare.Tim200ms_flag=1;
				}
		}
		
    if(TaskTimePare.Tim100ms_flag==1)
		{		   		 
				if(++TaskTimePare.Tim500ms_count >=5)
				{	      
						TaskTimePare.Tim500ms_count=0;
						TaskTimePare.Tim500ms_flag=1;
				}
		}
		if(TaskTimePare.Tim500ms_flag==1)
		{            
				if(++TaskTimePare.Tim1s_count >=2)
				{	               
					 TaskTimePare.Tim1s_count=0;
					 TaskTimePare.Tim1s_flag=1;
				}
		}
		if(TaskTimePare.Tim1s_flag == 1)
		{      
				if(++TaskTimePare.Tim10s_count >=10)
				{
						TaskTimePare.Tim10s_count = 0;
						TaskTimePare.Tim10s_flag = 1;
				}
		} 
		if(TaskTimePare.Tim10s_flag == 1)
		{                   
				if(++TaskTimePare.Tim1min_count >=6)
				{
						TaskTimePare.Tim1min_count = 0;
						TaskTimePare.Tim1min_flag = 1;
				}
		}	 
	}
	TIM_ClearITPendingBit(TIM4,TIM_IT_Update);	
	
}
void Clear_flag(void)   //???????
{
	TaskTimePare.Tim10ms_flag=0;
	TaskTimePare.Tim100ms_flag=0;
	TaskTimePare.Tim200ms_flag=0;
	TaskTimePare.Tim500ms_flag=0;
	TaskTimePare.Tim1s_flag=0;
	TaskTimePare.Tim10s_flag=0;
	TaskTimePare.Tim1min_flag=0;
}

