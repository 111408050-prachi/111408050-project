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

int total_rooms = 500;
int single = 300;
int doub = 200;
int single_room  = 1;
int double_room = 2;

void init(list *l) {
	l->head = l->tail = NULL;
	l->length = 0;
}

void insert(list *l, customer *c, date *de1, date *de2, int pos) {
	node *p, *tmp;
	int i;
	if(pos < 0 || pos > l->length)		
		return;
	tmp = (node *)malloc(sizeof(node));
	/*filling infomation of customer*/
	strcpy(tmp->cs.cs_name, c->cs_name);
	strcpy(tmp->cs.add, c->add);
	strcpy(tmp->cs.nation, c->nation);
	tmp->cs.age = c->age;
	tmp->cs.uid = c->uid;
	tmp->cs.mob = c->mob;
	tmp->cs.advance = c->advance;
	tmp->cs.total_bill = c->total_bill;
	/*customer info ends*/
	/*info about booking*/
	tmp->entry.day = de1->day;
	tmp->entry.month = de1->month;
	tmp->entry.year = de1->year;
	tmp->exit.day = de2->day;
	tmp->exit.month = de2->month;
	tmp->exit.year = de2->year;
	/*booking details ends*/
	if(l->head == NULL) {
		tmp->next = tmp->prev = NULL;
		l->head = l->tail = tmp;
		l->length = 1;
		return;
	}
	
	p = l->head;
	for(i = 0; i < pos - 1; i++)
		p = p->next;
	if(pos == 0)
		p = p->prev;
	
	if(pos != 0 && pos != (l->length)) {
	tmp->prev = p;	
	tmp->next = p->next;
	p->next->prev = tmp;
	p->next = tmp;
	}
	if(pos == l->length) {
		p->next = tmp;
		tmp->prev = p;
		tmp->next = NULL;
		l->tail = tmp;
	}

	if(pos == 0) {
		p->prev = tmp;
		tmp->next = p;
		tmp->prev = NULL;
		l->head = tmp;
	}

	(l->length)++;
}

void remov(list *l, char name[20]) {  //will return the total bill 
	node *p;
	p = l->head;
	while(p) {
		if(strcmp(p->cs.cs_name, name) != 0)
			p = p->next;
		else
			break;
	} 
	/*p points to node which need to be removed*/
	if(p != l->head && p != l->tail) {
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}
	if(p == l->head) {
		p->next->prev = NULL;
		l->head = p->next;
	}
	if(p == l->tail) {
		p->prev->next = NULL;
		l->tail = p->prev;
	}
	free(p);
	(l->length)--;
}

void traverse(list *l) {                              
	printf("[ ");
	node *p = l->head;
	while(p != l->tail) {
		printf("Name: %s\n", p->cs.cs_name);
		printf("Age: %d\n",p->cs.age);
		printf("Address: %s\n",p->cs.add);
		printf("Country: %s\n",p->cs.nation);
		printf("UID Number: %lf\n",p->cs.uid);
		printf("Contact Number: %ld\n",p->cs.mob);
		p = p->next;
	}
	if(p) {
		printf("Name: %s\n", p->cs.cs_name);
		printf("Age: %d\n",p->cs.age);
		printf("Address: %s\n",p->cs.add);
		printf("Country: %s\n",p->cs.nation);
		printf("UID Number: %lf\n",p->cs.uid);
		printf("Contact Number: %ld\n",p->cs.mob);
		p = p->next;
	}
	printf(" ]\n");
}

void print_cs(customer *c) {
	printf("Name: %s\n", c->cs_name);
	printf("Age: %d\n", c->age);
	printf("Address: %s\n", c->add);
	printf("Country: %s\n", c->nation);
	printf("UID Number: %lf\n", c->uid);
	printf("Contact Number: %ld\n", c->mob);
}

void append(list *l, customer *c, date *de1, date *de2) {
	node *tmp;
	tmp = (node *)malloc(sizeof(node));
	/*filling infomation of customer*/
	strcpy(tmp->cs.cs_name, c->cs_name);
	strcpy(tmp->cs.add, c->add);
	strcpy(tmp->cs.nation, c->nation);
	tmp->cs.age = c->age;
	tmp->cs.uid = c->uid;
	tmp->cs.mob = c->mob;
	tmp->cs.advance = c->advance;
	tmp->cs.total_bill = c->total_bill;
	/*info about booking*/
	tmp->entry.day = de1->day;
	tmp->entry.month = de1->month;
	tmp->entry.year = de1->year;
	tmp->exit.day = de2->day;
	tmp->exit.month = de2->month;
	tmp->exit.year = de2->year;
	if(l->head == NULL) {
		tmp->next = tmp->prev = NULL;
		l->head = l->tail = tmp;
		l->length = 1;
		return;
	}
	l->tail->next = tmp;
	tmp->prev = l->tail;
	tmp->next = NULL;
	l->tail = tmp;
	(l->length)++;
}

int length(list *l) {
	return l->length;	
}

int stay(date *de1, date *de2) {
	int diff = 0;
	if((de1->month) == (de2->month) && (de1->year) == (de2->year)) {
		if((de1->day) > (de2->day))
			diff = (de1->day) - (de2->day);
		else
			diff = (de2->day) - (de1->day);
	}
	if((de1->year) == (de2->year)) {
		if((de1->month) > (de2->month))
			return -1; //cause entry month cant be greater than exit till the year is same
		if((de1->month) < (de2->month))
			diff = ((30) - (de1->day)) + (de2->day);
	}
	return diff;
}

void checkin(list *l, customer *c, date *de1, date *de2) {
	int n;
	append(l, c, de1, de2);
	int t = c->r_type;
	printf("Your booking is done for the ");
	if(t == 1) {
		printf("single room\n");
		(single)--;
	}
	if(t == 2) {
		printf("double room\n");
		(doub)--;
	}
	n = stay(de1, de2);
	printf("Hope you will enjoy the stay of '%d' days\n", n);
	printf("THANK YOU\n");
	(total_rooms)--;
}

void checkout(list *l, customer *c, date *de1, date *de2, char cn[20]) {
	int bill;
	total_bill(c, de1, de2);
	bill = c->total_bill;
	remov(l, cn);
	printf("Your total bill is: %d\n",bill);
	printf("Hope to see you again\n");
	if(c->r_type == 1)
		(single)++;
	if(c->r_type == 2)
		(doub)++;
	(total_rooms)++;
}

void total_bill(customer *c, date *de1, date *de2) {
	int total;
	int adv = c->advance;
	int n = stay(de1, de2);
	if(c->r_type == 1) 
		total = n * 350;
	if(c->r_type == 2)
		total = n * 600;
	c->total_bill = (total - adv);
}

void rooms() {
	printf("Total Available rooms in hotel are:%d\n",total_rooms);
	printf("Single Available rooms are:%d\nDouble rooms are:%d\n", single, doub);
}










