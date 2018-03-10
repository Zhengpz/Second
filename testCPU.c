#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>
#include <sys/types.h>
#include <fcntl.h>
int main()
{
	
	printf("***open lcd function***\n");
	system("./lcd &");
	
	printf("***begin change cpu frequence***\n");
	system("echo userspace > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor");
	printf("***1***\n");
	system("cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_available_frequencies");
	system("echo 792000 > /sys/devices/system/cpu/cpu0/cpufreq/scaling_setspeed");
	printf("***2***\n");
	system("cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq");
	sleep(1);
	system("echo 792000 > /sys/devices/system/cpu/cpu1/cpufreq/scaling_setspeed");
	system("echo 792000 > /sys/devices/system/cpu/cpu2/cpufreq/scaling_setspeed");
	system("echo 792000 > /sys/devices/system/cpu/cpu3/cpufreq/scaling_setspeed");
	printf("***3***\n");
	system("cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq");
	system("cat /sys/devices/system/cpu/cpu1/cpufreq/scaling_cur_freq");
	system("cat /sys/devices/system/cpu/cpu2/cpufreq/scaling_cur_freq");
	system("cat /sys/devices/system/cpu/cpu3/cpufreq/scaling_cur_freq");
	sleep(3);
	system("cat /sys/devices/system/cpu/cpu0/online");
	system("echo 0 > /sys/devices/system/cpu/cpu0/online");
	printf("***close cpu0***\n");
	system("cat /sys/devices/system/cpu/cpu0/online");
	sleep(2);
	system("echo 0 > /sys/devices/system/cpu/cpu1/online");
	system("echo 0 > /sys/devices/system/cpu/cpu2/online");
	system("cat /sys/devices/system/cpu/cpu1/online");
	system("cat /sys/devices/system/cpu/cpu2/online");
	sleep(2);
	printf("***close all cpu***\n");
	system("echo 0 > /sys/devices/system/cpu/cpu3/online");
	system("cat /sys/devices/system/cpu/cpu3/online");
	
	
	printf("***now close lcd***\n");
	system("echo 1 > /sys/class/graphics/fb0/blank");
	sleep(10);
	printf("***now open lcd***\n");
	system("echo 0 > /sys/class/graphics/fb0/blank");
}