#ifndef _time_H
#define _time_H

#include "system.h"
#include "stm32f10x.h"
#define  TaskTime_DEFAULTS  {0,0,0,0,0,0,0,0,0,0,0,0,0,0}  // ?????
typedef struct {	
        uint8_t   Tim10ms_count; 	// 10ms????
        uint8_t   Tim10ms_flag;   // 10ms??
        uint8_t   Tim100ms_count; //100ms??
	      uint8_t   Tim100ms_flag;  //100ms?????
        uint8_t   Tim200ms_flag;  //200ms?????
	      uint8_t   Tim200ms_count; //200ms??
        uint8_t   Tim500ms_count; //500ms??
        uint8_t   Tim500ms_flag; //500ms?????
        uint8_t   Tim1s_count;  //1s??
        uint8_t   Tim1s_flag ;  //1s?????
        uint8_t   Tim10s_count; //10s??
        uint8_t   Tim10s_flag ; //10s?????
        uint8_t   Tim1min_count; //1??
        uint8_t   Tim1min_flag ; //1???????
	   }TaskTime;
extern TaskTime TaskTimePare;  
void TIM4_Init(u16 per,u16 psc);
void Clear_flag(void);  
#endif
