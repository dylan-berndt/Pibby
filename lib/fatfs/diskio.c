/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2007        */
/*-----------------------------------------------------------------------*/
/* This is a stub disk I/O module that acts as front end of the existing */
/* disk I/O modules and attach it to FatFs module with common interface. */
/*-----------------------------------------------------------------------*/
#include "GPIO.h"
#include "MMC_SD.h"	
#include "ff.h"
#include "diskio.h"

/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */

#define SD_CARD	 0  //SD卡,卷标为0

#define FLASH_SECTOR_SIZE 	512			  

//初始化磁盘
DSTATUS disk_initialize (
	BYTE drv				/* Physical drive nmuber (0..) */
)
{	
	uint8_t res=0;	    
	switch(drv)
	{
		case SD_CARD://SD卡
			res = SD_Initialize();//SD_Initialize() 
		 	if(res)//STM32 SPI的bug,在sd卡操作失败的时候如果不执行下面的语句,可能导致SPI读写异常
			{
				SD_SPI_SpeedLow();
				SD_SPI_ReadWriteByte(0xff);//提供额外的8个时钟
				SD_SPI_SpeedHigh();
			}
  			break;
		default:
			res=1; 
	}		 
	if(res)return  STA_NOINIT;
	else return 0; //初始化成功
}   
//获得磁盘状态
DSTATUS disk_status (
	BYTE drv		/* Physical drive nmuber (0..) */
)
{		   
    return 0;
}
 //读扇区
 //drv:磁盘编号0~9
 //*buff:数据接收缓冲首地址
 //sector:扇区地址
 //count:需要读取的扇区数
DRESULT disk_read (
	BYTE drv,		/* Physical drive nmuber (0..) */
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	/* Sector address (LBA) */
	BYTE count		/* Number of sectors to read (1..255) */
)
{
	uint8_t res=0; 
    if (!count)return RES_PARERR;//count不能等于0，否则返回参数错误		 	 
	switch(drv)
	{
		case SD_CARD://SD卡
			res=SD_ReadDisk(buff,sector,count);	 
		 	if(res)//STM32 SPI的bug,在sd卡操作失败的时候如果不执行下面的语句,可能导致SPI读写异常
			{
				SD_SPI_SpeedLow();
				SD_SPI_ReadWriteByte(0xff);//提供额外的8个时钟
				SD_SPI_SpeedHigh();
			}
			break;
		default:
			res=1; 
	}
   //处理返回值，将SPI_SD_driver.c的返回值转成ff.c的返回值
    if(res==0x00)return RES_OK;	 
    else return RES_ERROR;	   
}  
 //写扇区
 //drv:磁盘编号0~9
 //*buff:发送数据首地址
 //sector:扇区地址
 //count:需要写入的扇区数	    
#if _READONLY == 0
DRESULT disk_write (
	BYTE drv,			/* Physical drive nmuber (0..) */
	const BYTE *buff,	        /* Data to be written */
	DWORD sector,		/* Sector address (LBA) */
	BYTE count			/* Number of sectors to write (1..255) */
)
{
	uint8_t res=0;  
    if (!count)return RES_PARERR;//count不能等于0，否则返回参数错误		 	 
	switch(drv)
	{
		case SD_CARD://SD卡
			res=SD_WriteDisk((uint8_t*)buff,sector,count);
			break;
		default:
			res=1; 
	}
    //处理返回值，将SPI_SD_driver.c的返回值转成ff.c的返回值
    if(res == 0x00)return RES_OK;	 
    else return RES_ERROR;		 
}
#endif /* _READONLY */

//其他表参数的获得
 //drv:磁盘编号0~9
 //ctrl:控制代码
 //*buff:发送/接收缓冲区指针
DRESULT disk_ioctl (
	BYTE drv,		/* Physical drive nmuber (0..) */
	BYTE ctrl,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
)
{	
	DRESULT res;						  			     
	if(drv==SD_CARD)//SD卡
	{
	    switch(ctrl)
	    {
		    case CTRL_SYNC:
				Set_Pin(SD_CS_PIN,0);
		        if(SD_WaitReady()==0)res = RES_OK; 
		        else res = RES_ERROR;	  
				Set_Pin(SD_CS_PIN,1);
		        break;	 
		    case GET_SECTOR_SIZE:
		        *(WORD*)buff = 512;
		        res = RES_OK;
		        break;	 
		    case GET_BLOCK_SIZE:
		        *(WORD*)buff = 8;
		        res = RES_OK;
		        break;	 
		    case GET_SECTOR_COUNT:
		        *(DWORD*)buff = SD_GetSectorCount();
		        res = RES_OK;
		        break;
		    default:
		        res = RES_PARERR;
		        break;
	    }
	}else res=RES_ERROR;//其他的不支持
    return res;
} 

/*-----------------------------------------------------------------------*/
/* User defined function to give a current time to fatfs module          */
/* 31-25: Year(0-127 org.1980), 24-21: Month(1-12), 20-16: Day(1-31) */                                                                                                                                                                                                                                          
/* 15-11: Hour(0-23), 10-5: Minute(0-59), 4-0: Second(0-29 *2) */                                                                                                                                                                                                                                                
DWORD get_fattime (void)
{
    return 0;
}
							




