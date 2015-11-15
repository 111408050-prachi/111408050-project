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

/*structure for hotel*/
typedef struct customer{
	int age;
	double uid;
	long mob;
	char cs_name[20];
	char add[50];
	char nation[20];
	int advance;
	int r_type;
	int total_bill;
}customer;

typedef struct date{
	int day;
	int month;
	int year;
}date;

/*doubly circular null terminated list*/
typedef struct node {
	customer cs;
	date entry, exit;
	struct node *next, *prev;
}node;

typedef struct list {
	struct node *head, *tail;
	int length;
}list;
void rooms();
/*hotel functions*/
void checkin(list *l, customer *c, date *de1, date *de2 );
void checkout(list *l, customer *c, date *de1, date *de2, char cn[20]);
void total_bill(customer *c, date *de1, date *de2);
int stay(date *de1, date *de2);
void rooms();

/*list functions*/
void init(list *l);
void traverse(list *l);
void insert(list *l, customer *c, date *de1, date *de2, int pos);
void remov(list *l, char name[20]);
void append(list *l, customer *c, date *de1, date *de2);
int length(list *l);
