/********************************************************************************
 * 文件名  ：clk.c
 * 描述    ：时钟相关函数    
 * 库版本  ：V2.0.0
 * 作者    ：泽畔无材  QQ:715805855
 *修改时间 ：2012-7-28
**********************************************************************************/

#include "clk.h"


/*Настройка HSE*/
void Set_HSE(void)  
{
  //CLK_DeInit();     //По какой то причине камень останавли 
  CLK_HSECmd(ENABLE);   //Включаем HSE
  while(SET != CLK_GetFlagStatus(CLK_FLAG_HSERDY)); //Проверяем, готов ли контроллер переключиться на HSE
  CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);  //Прескалер
  CLK_ClockSwitchCmd(ENABLE);   //Разрешаем смену источника тактирования
  CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO,CLK_SOURCE_HSE,DISABLE,CLK_CURRENTCLOCKSTATE_ENABLE); //Конфигурируем HSE
}

//设置内部时钟16M为主时钟 
//输入参数：无
//输出参数：无
void Set_HSI(void)  
{
  //CLK_DeInit();     //恢复默认设置 
  CLK_HSICmd(ENABLE);   //内部时钟开
  while(SET != CLK_GetFlagStatus(CLK_FLAG_HSIRDY)); //等待内部时钟稳定
  CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV1);  //不分频，16M
  CLK_ClockSwitchCmd(ENABLE);   //时钟切换使能
  //切换配置
  CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO,CLK_SOURCE_HSI,DISABLE,CLK_CURRENTCLOCKSTATE_DISABLE);
}
