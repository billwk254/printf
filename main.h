#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

int get_flags(const char *format, int *i);
int get_size(const char *format, int *i);
int get_precision(const char *format, int *i, va_list list);
int get_width(const char *format, int *i, va_list list);


int handle_write_char(char c, char buffer[],
		      int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
		 int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	      int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
		  int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
		 char buffer[],
		 int flags, int width, int precision, int size);




int print_char(va_list types, char buffer[],
	       int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
		 int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
		  int flags, int width, int precision, int size);


int print_int(va_list types, char buffer[],
	      int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
		 int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
		   int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
		      int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
		     int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
	       char buffer[], int flags, char flag_ch, int width, int precision, int size);

#endif