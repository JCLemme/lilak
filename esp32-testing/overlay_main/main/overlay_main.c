/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

void syscall_print(int numbero)
{
    printf("Number is %d.\n", numbero);
    printf("beep beep\n");
}

void syscall_printtwo(int numbero)
{
    printf("Number is %d.\n", numbero);
    printf("boop boop\n");
}

void syscall_printall(int one, int two, int three, int four, int five, int six, int seven, int eight, int nine, int ten, int eleven, int twelve, int thirteen, int fourteen, int fifteen, int sixteen, int seventeen, int eighteen, int nineteen, int twenty)
{
    printf("%d  %d  %d  %d  %d  %d  %d  %d  %d  %d\n", one, two, three, four, five, six, seven, eight, nine, ten);
    printf("%d  %d  %d  %d  %d  %d  %d  %d  %d  %d\n", eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen, twenty);
}

uint32_t calls[3] = {syscall_print, syscall_printtwo, syscall_printall};

extern void redirect_print(int);
extern void redirect_printall(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
extern void redirect_to(uint32_t);

void app_main()
{
    printf("Overlay test is starting.\n");

    
    
    printf("Triggering syscall \"printtwo\"...\n");
    redirect_to(syscall_printtwo);

    printf("Triggering syscall \"print\"...\n");
    redirect_print(222);
    
    printf("Triggering syscall \"printall\"...\n");
    redirect_printall(11, 22, 33, 44, 55, 66, 77, 88, 99, 69, 12, 23, 34, 45, 56, 67, 78, 89, 90, 420);
    
    printf("Finished\n");
}
