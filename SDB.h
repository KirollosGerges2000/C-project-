#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED

typedef struct{

int ID;
int student_year;
int course_ID[3];
int grades[3];
struct students *next;

}students;
students *head=NULL;
bool SDB_is_ID_exist(int Ident);

void get_list_ID(void);

bool SDB_isfull(void);

int SDB_getusedsize(void);

void print_entry();

void add_entry(void);

void deleted_entry();


#endif // SDB_H_INCLUDED
