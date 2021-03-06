#ifndef _CUST_BAT_H_
#define _CUST_BAT_H_

#ifdef MTK_NCP1851_SUPPORT
typedef enum
{
	Cust_CC_400MA = 0x0,
	Cust_CC_500MA = 0x1,
	Cust_CC_600MA = 0x2,
	Cust_CC_700MA = 0x3,
	Cust_CC_800MA = 0x4,
	Cust_CC_900MA = 0x5,
	Cust_CC_1000MA = 0x6,
	Cust_CC_1100MA  = 0x7,
	Cust_CC_1200MA  = 0x8,
	Cust_CC_1300MA  = 0x9,
	Cust_CC_1400MA  = 0xA,
	Cust_CC_1500MA  = 0xB,
	Cust_CC_1600MA  = 0xC,
#ifdef MTK_NCP1852_SUPPORT
	Cust_CC_1700MA = 0xD,
	Cust_CC_1800MA = 0xE,
	Cust_CC_100MA = 0xF,
	Cust_CC_70MA = 0x10,
#else
	Cust_CC_100MA = 0xD,
	Cust_CC_70MA = 0xE,
#endif       
	Cust_CC_0MA	   = 0xDD
}cust_charging_current_enum;
#else
typedef enum
{
	Cust_CC_1600MA = 0x0,
	Cust_CC_1500MA = 0x1,
	Cust_CC_1400MA = 0x2,
	Cust_CC_1300MA = 0x3,
	Cust_CC_1200MA = 0x4,
	Cust_CC_1100MA = 0x5,
	Cust_CC_1000MA = 0x6,
	Cust_CC_900MA  = 0x7,
	Cust_CC_800MA  = 0x8,
	Cust_CC_700MA  = 0x9,
	Cust_CC_650MA  = 0xA,
	Cust_CC_550MA  = 0xB,
	Cust_CC_450MA  = 0xC,
	Cust_CC_400MA  = 0xD,
	Cust_CC_200MA  = 0xE,
	Cust_CC_70MA   = 0xF,
	Cust_CC_0MA	   = 0xDD
}cust_charging_current_enum;
#endif

typedef struct{	
	unsigned int BattVolt;
	unsigned int BattPercent;
}VBAT_TO_PERCENT;

/* Battery Temperature Protection */
#define MAX_CHARGE_TEMPERATURE  50 //liulc1 change
//#define MAX_CHARGE_TEMPERATURE  45
/*Added by zhangyf for Over Heat warning*/
#define OVER_HEAT_WARNING_TEMPERATURE	58
#define MIN_CHARGE_TEMPERATURE  0
#define ERR_CHARGE_TEMPERATURE  0xFF

/* Recharging Battery Voltage */
#define RECHARGING_VOLTAGE      4110

/* Charging Current Setting */
#define CONFIG_USB_IF 						0   
#define USB_CHARGER_CURRENT_SUSPEND			Cust_CC_0MA		// def CONFIG_USB_IF
#ifdef MTK_NCP1851_SUPPORT
#define USB_CHARGER_CURRENT_UNCONFIGURED	Cust_CC_100MA	// def CONFIG_USB_IF
#define USB_CHARGER_CURRENT_CONFIGURED		Cust_CC_500MA	// def CONFIG_USB_IF
#define USB_CHARGER_CURRENT					Cust_CC_500MA
#ifdef MTK_NCP1852_SUPPORT
#define AC_CHARGER_CURRENT					Cust_CC_1800MA
#else
#define AC_CHARGER_CURRENT					Cust_CC_1500MA
#endif
#else
#define USB_CHARGER_CURRENT_UNCONFIGURED	Cust_CC_70MA	// def CONFIG_USB_IF
#define USB_CHARGER_CURRENT_CONFIGURED		Cust_CC_450MA	// def CONFIG_USB_IF
#define USB_CHARGER_CURRENT					Cust_CC_450MA
#define AC_CHARGER_CURRENT					Cust_CC_650MA	
#endif

/* Battery Meter Solution */
#define CONFIG_ADC_SOLUTION 	1

/* Battery Voltage and Percentage Mapping Table */
VBAT_TO_PERCENT Batt_VoltToPercent_Table[] = {
	/*BattVolt,BattPercent*/
	{3400,0},
	{3641,10},
	{3708,20},
	{3741,30},
	{3765,40},
	{3793,50},
	{3836,60},
	{3891,70},
	{3960,80},
	{4044,90},
	{4183,100},
};

/* Precise Tunning */
#define BATTERY_AVERAGE_SIZE 	30
//#define BATTERY_AVERAGE_SIZE   3

/* Common setting */
#define R_CURRENT_SENSE 2				// 0.2 Ohm
#define R_BAT_SENSE 4					// times of voltage
#define R_I_SENSE 4						// times of voltage
#define R_CHARGER_1 330
#define R_CHARGER_2 39
#define R_CHARGER_SENSE ((R_CHARGER_1+R_CHARGER_2)/R_CHARGER_2)	// times of voltage
#define V_CHARGER_MAX 6000				// 6 V
#define V_CHARGER_MIN 4400				// 4.4 V
#define V_CHARGER_ENABLE 0				// 1:ON , 0:OFF

/* Teperature related setting */
#ifdef MTK_NCP1851_SUPPORT
#define NCP1851_PWR_PATH
//#define USE_NCP1851_NTC
#if 0//defined(USE_NCP1851_NTC)
#define RBAT_PULL_UP_R             10000 //NCP1851 spec
#define RBAT_PULL_UP_VOLT          2400 //NCP1851 spec
#else
#define RBAT_PULL_UP_R             39000
#define RBAT_PULL_UP_VOLT          1800
#endif
#else
#define RBAT_PULL_UP_R             24000
//#define RBAT_PULL_UP_VOLT          2500
#define RBAT_PULL_UP_VOLT          1200
#endif
#define TBAT_OVER_CRITICAL_LOW     68237
//#define TBAT_OVER_CRITICAL_LOW     483954
#define BAT_TEMP_PROTECT_ENABLE    1
#define BAT_NTC_10 1
#define BAT_NTC_47 0

/* Battery Notify */
#define BATTERY_NOTIFY_CASE_0001
#define BATTERY_NOTIFY_CASE_0002
#define BATTERY_NOTIFY_CASE_0003
#define BATTERY_NOTIFY_CASE_0004
#define BATTERY_NOTIFY_CASE_0005

//#define CONFIG_POWER_VERIFY

#endif /* _CUST_BAT_H_ */ 
