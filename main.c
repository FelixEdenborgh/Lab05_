#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

#include "adc.h"
#include "gpio.h"
#include "i2c.h"
#include "serial.h"
#include "timer.h"
#include "util.h"

#include "dht11.h"
#include "Io_Macros.h"


void main (void) {


	int temperature;
	int humidity;
	dht();
	while (1) {





			switch(dht(&temperature, &humidity))
			{
				case (DHTLIB_OK):
					printf_P(PSTR("Temperature: "));
					printf("%lf\n", temperature);
					printf_P(PSTR("Humidity: "));
					printf("lf\n", humidity);


					printf_P(PSTR("Humidity: "));
					printf("%lf\n", humidity);
					break;
				case (DHTLIB_ERROR_CHECKSUM):
					printf("Error Checksum\n");
					break;
				case (DHTLIB_ERROR_TIMEOUT):
					printf("Error Timeout\n");
					break;

			}

			_delay_ms(1000);

		}
}
