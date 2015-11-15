/*****************************************************************************
 * Copyright (C) Prachi Sureshrao Rode rodeps14.it@coep.ac.in
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hotel.h"
#define SIZE 500

int options() {
	int n;
	printf("choose the option for the service you need: \n");
	printf("1.Check in the hotel.\n2.Check out of hotel\n");
	printf("3.Get your total bill\n4.Find out the available rooms\n");
	scanf("%d",&n);
	return (n);
}

void cs_info(customer *c) {
	printf("Please enter the information of customer\n");
	printf("Name :\n");
	scanf("%s", c->cs_name);
	printf("Address :\n");
	scanf("%s", c->add);
	printf("nation :\n");
	scanf("%s", c->nation);
	printf("Age :\n");
	scanf("%d", &c->age);
	printf("Mobile no :\n");
	scanf("%ld", &c->mob);
	printf("UID No :\n");
	scanf("%lf", &c->uid);
	printf("Advance to be paid :\n");
	scanf("%d", &c->advance);
	printf("Type of room needed\n");
	scanf("%d", &c->r_type);
}

void date_info(date *d) {
	printf("Enter the date day-month-year\n");
	scanf("%d%d%d",&d->day, &d->month, &d->year);
}

int main() {
	int n;
	char cn[20];
	list l;
	customer c;
	date d1, d2;
	printf("Welcome to hotel GRAND :\n");
	printf("Total rooms in hotel are: 500\n");
	printf("Single rooms are: 300\nDouble rooms are: 200");
	printf("Cost for one day:\nSingle room stay is:'350'\nDouble room stay is:'600'\n");
	while(1) {
		n = options();
		switch(n) {
			case 1:
				cs_info(&c);
				printf("Entry Date:\n");
				date_info(&d1);
				printf("Exit Date:\n");
				date_info(&d2);
				checkin(&l, &c, &d1, &d2);
				traverse(&l);
				break;
			case 2:
				printf("Enter the name of Customer who want to Checkout\n");
				scanf("%s", cn);
				checkout(&l, &c, &d1, &d2, cn);
				traverse(&l);
				break;
			case 3:
				total_bill(&c, &d1, &d2);
				printf("Your total bill is:%d\n",c.total_bill);
				break;
			case 4:
				rooms();
				break;
			default:
				printf("SORRY we don't get you\nPlease enter the valid option\n");
		}
	}
	return 0;
}
